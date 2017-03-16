import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collection;
import java.util.Map;
import java.util.List;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		int keyCount = in.readInt();
		int count = in.readInt();
		int[] initial = new int[200];
		for (int i = 0; i < keyCount; i++)
			initial[in.readInt() - 1]++;
		int[] toOpen = new int[count];
		int[][] keys = new int[count][];
		for (int i = 0; i < count; i++) {
			toOpen[i] = in.readInt() - 1;
			int size = in.readInt();
			keys[i] = new int[size];
			for (int j = 0; j < size; j++)
				keys[i][j] = in.readInt() - 1;
		}
		int[] current = new int[200];
		boolean[] can = new boolean[1 << count];
		boolean[] good = new boolean[1 << count];
		can[0] = true;
		Graph<Integer> graph = new Graph<Integer>();
		for (int i = 0; i < (1 << count); i++) {
			if (!can[i])
				continue;
			System.arraycopy(initial, 0, current, 0, 200);
			for (int j = 0; j < count; j++) {
				if ((i >> j & 1) == 1) {
					current[toOpen[j]]--;
					for (int k : keys[j])
						current[k]++;
				}
			}
			for (int j = 0; j < count; j++) {
				if ((i >> j & 1) == 1 || current[toOpen[j]] == 0)
					continue;
				graph.addSimpleEdge(i, i + (1 << j));
				can[i + (1 << j)] = true;
			}
		}
		if (!can[(1 << count) - 1]) {
			out.printLine("Case #" + testNumber + ": IMPOSSIBLE");
			return;
		}
		good[(1 << count) - 1] = true;
		for (int i = (1 << count) - 1; i >= 0; i--) {
			if (!good[i])
				continue;
			for (Edge<Integer> edge : graph.getInbound(i))
				good[edge.getSource()] = true;
		}
		out.print("Case #" + testNumber + ":");
		int state = 0;
		for (int i = 0; i < count; i++) {
			int to = Integer.MAX_VALUE;
			for (Edge<Integer> edge : graph.getOutbound(state)) {
				if (can[edge.getDestination()] && good[edge.getDestination()])
					to = Math.min(to, edge.getDestination());
			}
			out.print("", Integer.bitCount(to - state - 1) + 1);
			state = to;
		}
		out.printLine();
    }
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public String next() {
		return readString();
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

    public void printLine() {
		writer.println();
	}

    public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class Graph<V> {
	protected int vertexCount;
	protected int edgeCount;

	protected Map<V, Integer> map = new HashMap<V, Integer>();

	public V[] vertices;
	public int[] firstOutbound;
	public int[] firstInbound;

	public Edge<V>[] edges;
	public int[] nextInbound;
	public int[] nextOutbound;
	public int[] from;
	public int[] to;
	public long[] weight;
	public long[] capacity;
	public int[] reverseEdge;
	public boolean[] removed;

	public Graph() {
		this(10);
	}

	public Graph(int vertexCapacity) {
		this(vertexCapacity, vertexCapacity);
	}

	public Graph(int vertexCapacity, int edgeCapacity) {
		//noinspection unchecked
		vertices = (V[]) new Object[vertexCapacity];
		firstOutbound = new int[vertexCapacity];
		firstInbound = new int[vertexCapacity];

		//noinspection unchecked
		edges = new Edge[edgeCapacity];
		from = new int[edgeCapacity];
		to = new int[edgeCapacity];
		nextInbound = new int[edgeCapacity];
		nextOutbound = new int[edgeCapacity];
		weight = new long[edgeCapacity];
		capacity = new long[edgeCapacity];
		reverseEdge = new int[edgeCapacity];
		removed = new boolean[edgeCapacity];
	}

	public int addEdge(int fromID, int toID, long weight, long capacity, int reverseEdge) {
		ensureEdgeCapacity(edgeCount + 1);
		if (firstOutbound[fromID] != -1)
			nextOutbound[edgeCount] = firstOutbound[fromID];
		else
			nextOutbound[edgeCount] = -1;
		firstOutbound[fromID] = edgeCount;
		if (firstInbound[toID] != -1)
			nextInbound[edgeCount] = firstInbound[toID];
		else
			nextInbound[edgeCount] = -1;
		firstInbound[toID] = edgeCount;
		this.from[edgeCount] = fromID;
		this.to[edgeCount] = toID;
		this.weight[edgeCount] = weight;
		this.capacity[edgeCount] = capacity;
		this.reverseEdge[edgeCount] = reverseEdge;
		edges[edgeCount] = createEdge(edgeCount);
		return edgeCount++;
	}

	protected GraphEdge createEdge(int id) {
		return new GraphEdge(id);
	}

	public Edge<V> addFlowWeightedEdge(V from, V to, long weight, long capacity) {
		int fromID = resolveOrAdd(from);
		int toID = resolveOrAdd(to);
		if (capacity == 0) {
			int result = addEdge(fromID, toID, weight, 0, -1);
			return edges[result];
		} else {
			int lastEdgeCount = edgeCount;
			addEdge(toID, fromID, -weight, 0, lastEdgeCount + entriesPerEdge());
			int result = addEdge(fromID, toID, weight, capacity, lastEdgeCount);
			return edges[result];
		}
	}

	protected int entriesPerEdge() {
		return 1;
	}

	public Edge<V> addWeightedEdge(V from, V to, long weight) {
		return addFlowWeightedEdge(from, to, weight, 0);
	}

	public Edge<V> addSimpleEdge(V from, V to) {
		return addWeightedEdge(from, to, 1);
	}

	public int resolve(V vertex) {
		if (map.containsKey(vertex))
			return map.get(vertex);
		throw new IllegalArgumentException();
	}

	private void removeEdgeByID(int id) {
		removed[id] = true;
		edges[id] = null;
	}

	public Iterable<Edge<V>> getOutbound(V vertex) {
		return getOutboundByID(resolve(vertex));
	}

	public Iterable<Edge<V>> getOutboundByID(final int id) {
		return new Iterable<Edge<V>>() {
			public Iterator<Edge<V>> iterator() {
				return new EdgeIterator(id, firstOutbound, nextOutbound);
			}
		};
	}

	public Iterable<Edge<V>> getInbound(V vertex) {
		return getInboundByID(resolve(vertex));
	}

	public Iterable<Edge<V>> getInboundByID(final int id) {
		return new Iterable<Edge<V>>() {
			public Iterator<Edge<V>> iterator() {
				return new EdgeIterator(id, firstInbound, nextInbound);
			}
		};
	}

	private int resolveOrAdd(V vertex) {
		if (map.containsKey(vertex))
			return map.get(vertex);
		ensureVertexCapacity(vertexCount + 1);
		map.put(vertex, vertexCount);
		vertices[vertexCount] = vertex;
		firstInbound[vertexCount] = firstOutbound[vertexCount] = -1;
		return vertexCount++;
	}

	protected void ensureEdgeCapacity(int size) {
		if (from.length < size) {
			int newSize = Math.max(size, 2 * from.length);
			edges = resize(edges, newSize);
			from = resize(from, newSize);
			to = resize(to, newSize);
			nextInbound = resize(nextInbound, newSize);
			nextOutbound = resize(nextOutbound, newSize);
			weight = resize(weight, newSize);
			capacity = resize(capacity, newSize);
			reverseEdge = resize(reverseEdge, newSize);
			removed = resize(removed, newSize);
		}
	}

	protected void ensureVertexCapacity(int size) {
		if (firstInbound.length < size) {
			int newSize = Math.max(size, 2 * firstInbound.length);
			vertices = resize(vertices, newSize);
			firstInbound = resize(firstInbound, newSize);
			firstOutbound = resize(firstOutbound, newSize);
		}
	}

	protected int[] resize(int[] array, int size) {
		int[] newArray = new int[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	protected boolean[] resize(boolean[] array, int size) {
		boolean[] newArray = new boolean[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private long[] resize(long[] array, int size) {
		long[] newArray = new long[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private Edge<V>[] resize(Edge<V>[] array, int size) {
		@SuppressWarnings("unchecked")
		Edge<V>[] newArray = new Edge[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	private V[] resize(V[] array, int size) {
		@SuppressWarnings("unchecked")
		V[] newArray = (V[]) new Object[size];
		System.arraycopy(array, 0, newArray, 0, array.length);
		return newArray;
	}

	protected class GraphEdge implements Edge<V> {
		protected int id;

		protected GraphEdge(int id) {
			this.id = id;
		}

		public V getSource() {
			return vertices[from[id]];
		}

		public V getDestination() {
			return vertices[to[id]];
		}

		}

	private class EdgeIterator implements Iterator<Edge<V>> {
		private int edgeID;
		private final int[] next;
		private int lastID = -1;

		public EdgeIterator(int id, int[] first, int[] next) {
			this.next = next;
			first[id] = edgeID = nextEdge(first[id]);
		}

		private int nextEdge(int id) {
			while (id != -1 && removed[id])
				id = next[id];
			return id;
		}

		public boolean hasNext() {
			return edgeID != -1;
		}

		public Edge<V> next() {
			if (edgeID == -1)
				throw new NoSuchElementException();
			lastID = edgeID;
			edgeID = next[lastID] = nextEdge(next[lastID]);
			return edges[lastID];
		}

		public void remove() {
			if (lastID == -1)
				throw new IllegalStateException();
			removeEdgeByID(lastID);
			lastID = -1;
		}
	}
}

interface Edge<V> {
	public V getSource();
	public V getDestination();
	}

