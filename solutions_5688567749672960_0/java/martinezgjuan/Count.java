import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Count {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  static int reverse(int input) {
    StringBuilder sb = new StringBuilder();
    sb.append(input);
    return Integer.parseInt(sb.reverse().toString());
  }
  
  static int[] distanceTo;
  static Edge[] edgeTo;
  static final int INF = Integer.MAX_VALUE / 2;

  
  public static class Pair<U extends Comparable<U>, V extends Comparable<V>> implements
          Comparable<Pair<U, V>> {
    public final U first;
    public final V second;

    public Pair(U first, V second) {
      this.first = first;
      this.second = second;
    }

    public int compareTo(Pair<U, V> that) {
      int value = this.first.compareTo(that.first);
      if (value != 0)
        return value;
      return this.second.compareTo(that.second);
    }

    @Override
    public boolean equals(Object other) {
      if (!(other instanceof Pair)) {
        return false;
      }
      Pair that = (Pair<U, V>) other;
      return this.first.equals(that.first) && this.second.equals(that.second);
    }

    @Override
    public int hashCode() {
      return 31 * (527 + first.hashCode()) + second.hashCode();
    }

    @Override
    public String toString() {
      return "(" + first + ", " + second + ")";
    }
  }

  static void dijkstra(GraphWE graph, int source, int dest) {
    edgeTo = new Edge[graph.getNumVertices()];
    distanceTo = new int[graph.getNumVertices()];
    Arrays.fill(distanceTo, INF);
    PriorityQueue<Pair<Integer, Integer>> queue = new PriorityQueue<Pair<Integer, Integer>>();
    distanceTo[source] = 0;

    queue.add(new Pair<Integer, Integer>(0, source));

    while (!queue.isEmpty()) {
      Pair<Integer, Integer> elem = queue.poll();
      int cur = elem.second;
      if (cur == dest) {
        break;
      }
      if (elem.first > distanceTo[cur]) {
        continue;
      }
      for (Edge edge : graph.adj(cur)) {
        if (distanceTo[edge.to] > distanceTo[edge.from] + edge.weight) {
          distanceTo[edge.to] = distanceTo[edge.from] + edge.weight;
          edgeTo[edge.to] = edge;
          queue.add(new Pair<Integer, Integer>(distanceTo[edge.to], edge.to));
        }
      }
    }
  }
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    GraphWE graph = new GraphWE(1_000_002);
       
    for (int i = 1; i <= 1000000; i++) {
      int rev = reverse(i);      
      graph.addDEdge(i, i+1, 1);
      if (rev != i) {
        graph.addDEdge(i, rev, 1);
      }
    }
    
    dijkstra(graph, 1, -1);
      
    for (int cas = 1; cas <= t; cas++) {
      out.println("Case #" + cas + ": " + (distanceTo[sc.nextInt()] + 1)); 
    }
    
    out.close();
  }
  
  final private static double EPS = 1e-9;
  
  static ArrayDeque<Edge> pathTo(int dest) {
    ArrayDeque<Edge> path = new ArrayDeque<Edge>();
    if (distanceTo[dest] == INF)
      return null;

    for (Edge edge = edgeTo[dest]; edge != null; edge = edgeTo[edge.from])
      path.addFirst(edge);
    return path;
  }
  
  static class GraphWE {
    private final int numVertices;
    private int numEdges = 0;
    private ArrayDeque<Edge>[] adj;

    @SuppressWarnings("unchecked")
    public GraphWE(int numVertices) {
      this.numVertices = numVertices;
      adj = (ArrayDeque<Edge>[]) new ArrayDeque[numVertices];
      for (int v = 0; v < numVertices; v++) {
        adj[v] = new ArrayDeque<Edge>();
      }
    }

    @SuppressWarnings("unchecked")
    public GraphWE(int numVertices, Iterable<Edge> edges) {
      this.numVertices = numVertices;
      adj = (ArrayDeque<Edge>[]) new ArrayDeque[numVertices];
      for (int v = 0; v < numVertices; v++) {
        adj[v] = new ArrayDeque<Edge>();
      }
      for (Edge edge : edges)
        addUEdge(edge);
    }

    public int getNumVertices() {
      return numVertices;
    }
    
    public int getNumEdges() {
      return numEdges;
    }
    
    public void addDEdge(Edge e) {
      adj[e.from].add(e);
      numEdges++;
    }

    public void addDEdge(int from, int to, int weight) {
      adj[from].add(new Edge(from, to, weight));
      numEdges++;
    }

    public void addUEdge(Edge edge) {
      adj[edge.from].add(edge);
      adj[edge.to].add(new Edge(edge.to, edge.from, edge.weight));
      numEdges++;
    }

    public void addUEdge(int from, int to, int weight) {
      adj[from].add(new Edge(from, to, weight));
      adj[to].add(new Edge(to, from, weight));
      numEdges++;
    }

    public ArrayDeque<Edge> adj(int node) {
      return adj[node];
    }

    public String toString() {
      StringBuilder result = new StringBuilder(numVertices + numEdges);
      result.append("Nodes: " + numVertices + " Edges: " + numEdges + "\n");
      for (int act = 0; act < numVertices; act++) {
        result.append(act + " -> ");
        int count = 0;
        for (Edge e : adj(act)) {
          if (count != 0)
            result.append(", ");
          result.append("(" + e.to + " <" + e.weight + ">)");
          count++;
        }
        result.append('\n');
      }
      return result.toString();
    }
  }

  static class Edge implements Comparable<Edge> {
    public final int from, to, weight;

    Edge(int from, int to, int weight) {
      this.from = from;
      this.to = to;
      this.weight = weight;
    }

    Edge(int from, int to) {
      this.from = from;
      this.to = to;
      this.weight = 1;
    }

    public int compareTo(Edge that) {
      if (Math.abs(this.weight - that.weight) > EPS)
        return Double.compare(this.weight, that.weight);
      if (this.from == that.from)
        return Integer.compare(this.to, that.to);
      return Integer.compare(this.from, that.from);
    }

    public String toString() {
      return "(" + from + ", " + to + ", <" + weight + ">)";
    }
  }

  
  
  static class Reader {
    final private int BUFFER_SIZE = 1 << 12; private byte[] buffer; private int bufferPointer, bytesRead; private boolean eof = false;
    public Reader() {buffer = new byte[BUFFER_SIZE];bufferPointer = bytesRead = 0;}
    public boolean reachedEOF() {return eof;}
    private void fillBuffer() throws IOException {bytesRead = System.in.read(buffer, bufferPointer = 0, BUFFER_SIZE); if (bytesRead == -1) { buffer[0] = -1;eof = true;}}
    private byte read() throws IOException {if (bufferPointer == bytesRead)fillBuffer();return buffer[bufferPointer++];}
    public String next() throws IOException {StringBuilder sb = new StringBuilder();byte c;while ((c = read()) <= ' ') {if (c == -1)return null;};do {sb.append((char) c);} while ((c = read()) > ' ');if (sb.length() == 0)return null;return sb.toString();}
    public String nextLine() throws IOException {StringBuilder sb = new StringBuilder();byte c;boolean read = false;while ((c = read()) != -1) {if (c == '\n') {read = true;break;}if (c >= ' ')sb.append((char) c);}if (!read)return null;return sb.toString();}
    public int nextInt() throws IOException {int ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public long nextLong() throws IOException {long ret = 0;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10L + c - '0';} while ((c = read()) >= '0' && c <= '9');if (neg)return -ret;return ret;}
    public double nextDouble() throws IOException {double ret = 0, div = 1;byte c = read();while (c <= ' ')c = read();boolean neg = (c == '-');if (neg)c = read();do {ret = ret * 10 + c - '0';} while ((c = read()) >= '0' && c <= '9');if (c == '.')while ((c = read()) >= '0' && c <= '9')ret += (c - '0') / (div *= 10);if (neg)return -ret;return ret;}
    public int[] nextIntArrray(int n) throws IOException {int[] a = new int[n];for (int i = 0; i < n; i++)a[i] = nextInt();return a;}
    public int[][] nextIntMatrix(int n, int m) throws IOException {int[][] map = new int[n][m];for (int i = 0; i < n; i++)map[i] = nextIntArrray(m);return map;}
    public char[][] nextCharacterMatrix(int n) throws IOException {char[][] a = new char[n][];for (int i = 0; i < n; i++)a[i] = next().toCharArray();return a;}
    public void close() throws IOException {if (System.in == null)return;System.in.close();}
  }
  
  static void print(int[] A) {for(int i=0;i<A.length;i++){if(i!=0) out.print(' ');out.print(A[i]);}out.println();}
  static <T> void print(Iterable<T> A) {int i = 0;for(T act : A){if(i!=0)out.print(' ');out.print(act);i++;}out.println();}
  static void printPlus1(Iterable<Number> A) {int i = 0;for(Number act : A){if(i!=0)out.print(' ');out.print(act.longValue() + 1L);i++;}out.println();}
  static void debug(Object... o) { System.err.println(Arrays.deepToString(o)); }
  
  /*
  long s = System.currentTimeMillis();
  debug(System.currentTimeMillis()-s+"ms");
   */
}
