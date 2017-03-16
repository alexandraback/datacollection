import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Fashion {
  
  static Reader sc = new Reader();
  static PrintWriter out = new PrintWriter(System.out);
  
  public static void main(String[] args) throws IOException {
    int t = sc.nextInt();
    
    for (int cas = 1; cas <= t; cas++) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      int c = sc.nextInt();
      int limit = sc.nextInt();

      ArrayList<ArrayList<Integer>> added = new ArrayList<ArrayList<Integer>>();
      
      for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
          for (int k = 1; k <= c; k++) {
            ArrayList<Integer> cur = new ArrayList<Integer>();
            cur.add(i);
            cur.add(j);
            cur.add(k);
            if (check(added, cur, limit)) {
              added.add(cur);
            }
          }
        }
      }
      
      out.println("Case #" + cas + ": " + added.size());
      for (int i = 0; i < added.size(); i++) {
        print(added.get(i));
      }
    }
    
    out.close();
  }
  
  static boolean check (ArrayList<ArrayList<Integer>> added, ArrayList<Integer> cur, int limit) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) {
          continue;
        }
        int count = 0;
        for (ArrayList<Integer> aux : added) {
          if (cur.get(i) ==  aux.get(i) && cur.get(j) ==  aux.get(j)) {
            count++;
          }
        }
        if (count >= limit) {
          return false;
        }
      }
    }
    
    return true;
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
