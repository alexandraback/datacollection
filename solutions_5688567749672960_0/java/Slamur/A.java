import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;

// Solution is at the bottom of code

public class A implements Runnable{
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new A(), "", 128 * (1L << 20)).start();
	}
	
	/////////////////////////////////////////////////////////////////////
	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		String fileName = "A-small-attempt0.in";
		
		if (fileName.isEmpty()){
			in = new BufferedReader(new FileReader("input.txt"));
		}else{
			in = new BufferedReader(new FileReader(fileName));
		}
		
		out = new OutputWriter("output.txt");
	}
	
	////////////////////////////////////////////////////////////////
	
	long timeBegin, timeEnd;

	void time(){
		timeEnd = System.currentTimeMillis();
		System.err.println("Time = " + (timeEnd - timeBegin));
	}
	
	/////////////////////////////////////////////////////////////////////
	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			Locale.setDefault(Locale.US);
			
			init();
			solve();
			
			out.close();
			time();
		}catch (Exception e){
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	/////////////////////////////////////////////////////////////////////
	
	String delim = " ";
	
	String readString() throws IOException{
		while(!tok.hasMoreTokens()){
			try{
				tok = new StringTokenizer(in.readLine());
			}catch (Exception e){
				return null;
			}
		}
		
		return tok.nextToken(delim);
	}
	
	String readLine() throws IOException{
		return in.readLine();
	}
	
	/////////////////////////////////////////////////////////////////
	
	final char NOT_A_SYMBOL = '\0';
	
	char readChar() throws IOException{
		int intValue = in.read();
		
		if (intValue == -1){
			return NOT_A_SYMBOL;
		}
		
		return (char) intValue;
	}
	
	char[] readCharArray() throws IOException{
		return readLine().toCharArray();
	}
	
	/////////////////////////////////////////////////////////////////
	
	int readInt() throws IOException{
		return Integer.parseInt(readString());
	}
	
	int[] readIntArray(int size) throws IOException{
		int[] array = new int[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readInt();
		}
		
		return array;
	}
	
	///////////////////////////////////////////////////////////////////
	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	long[] readLongArray(int size) throws IOException{
		long[] array = new long[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readLong();
		}
		
		return array;
	}
	
	////////////////////////////////////////////////////////////////////
	
	double readDouble() throws IOException{
		return Double.parseDouble(readString());
	}
	
	double[] readDoubleArray(int size) throws IOException{
		double[] array = new double[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readDouble();
		}
		
		return array;
	}
	
	////////////////////////////////////////////////////////////////////
		
	BigInteger readBigInteger() throws IOException {
		return new BigInteger(readString());
	}
	
	BigDecimal readBigDecimal() throws IOException {
		return new BigDecimal(readString());
	}
	
	/////////////////////////////////////////////////////////////////////
	
	Point readPoint() throws IOException{
		int x = readInt();
		int y = readInt();
		return new Point(x, y);
	}
	
	Point[] readPointArray(int size) throws IOException{
		Point[] array = new Point[size];
		
		for (int index = 0; index < size; ++index){
			array[index] = readPoint();
		}
		
		return array;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	List<Integer>[] readGraph(int vertexNumber, int edgeNumber)
	throws IOException{
		@SuppressWarnings("unchecked")
		List<Integer>[] graph = new List[vertexNumber];
		
		for (int index = 0; index < vertexNumber; ++index){
			graph[index] = new ArrayList<Integer>();
		}
		
		while (edgeNumber-- > 0){
			int from = readInt() - 1;
			int to = readInt() - 1;
			
			graph[from].add(to);
			graph[to].add(from);
		}
		
		return graph;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static class IntIndexPair {
		
		static Comparator<IntIndexPair> increaseComparator = new Comparator<IntIndexPair>() {
			
			@Override
			public int compare(IntIndexPair indexPair1, IntIndexPair indexPair2) {
				int value1 = indexPair1.value;
				int value2 = indexPair2.value;
				
				if (value1 != value2) return value1 - value2;
				
				int index1 = indexPair1.index;
				int index2 = indexPair2.index;
				
				return index1 - index2;
			}
		};
		
		static Comparator<IntIndexPair> decreaseComparator = new Comparator<IntIndexPair>() {
			
			@Override
			public int compare(IntIndexPair indexPair1, IntIndexPair indexPair2) {
				int value1 = indexPair1.value;
				int value2 = indexPair2.value;
				
				if (value1 != value2) return -(value1 - value2);
				
				int index1 = indexPair1.index;
				int index2 = indexPair2.index;
				
				return index1 - index2;
			}
		};
		
		int value, index;

		public IntIndexPair(int value, int index) {
			super();
			this.value = value;
			this.index = index;
		}		
	}
	
	IntIndexPair[] readIntIndexArray(int size) throws IOException {
		IntIndexPair[] array = new IntIndexPair[size];
		
		for (int index = 0; index < size; ++index) {
			array[index] = new IntIndexPair(readInt(), index);
		}
		
		return array;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	static class OutputWriter extends PrintWriter{

		final int DEFAULT_PRECISION = 12;
		
		int precision;
		String format, formatWithSpace;
		
		{
			precision = DEFAULT_PRECISION;
			
			format = createFormat(precision);
			formatWithSpace = format + " ";
		}
		
		public OutputWriter(OutputStream out) {
			super(out);
		}

		public OutputWriter(String fileName) throws FileNotFoundException {
			super(fileName);
		}
		
		public int getPrecision() {
			return precision;
		}

		public void setPrecision(int precision) {
			precision = max(0, precision);
			this.precision = precision;
			
			format = createFormat(precision);
			formatWithSpace = format + " ";
		}
		
		private String createFormat(int precision){
			return "%." + precision + "f";
		}
		
		@Override
		public void print(double d){
			printf(format, d);
		}
		
		public void printWithSpace(double d){
			printf(formatWithSpace, d);
		}

		public void printAll(double...d){
			for (int i = 0; i < d.length - 1; ++i){
				printWithSpace(d[i]);
			}
			
			print(d[d.length - 1]);
		}
		
		@Override
		public void println(double d){
			printlnAll(d);
		}
		
		public void printlnAll(double... d){
			printAll(d);
			println();
		}
	}
	
	/////////////////////////////////////////////////////////////////////
	
	int[][] steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
	int[][] steps8 = {
			{-1, 0}, {1, 0}, {0, -1}, {0, 1},
			{-1, -1}, {1, 1}, {1, -1}, {-1, 1}
	};
	
	boolean check(int index, int lim){
		return (0 <= index && index < lim);
	}
	
	/////////////////////////////////////////////////////////////////////
	
	boolean checkBit(int mask, int bit){
		return (mask & (1 << bit)) != 0;
	}
	
	/////////////////////////////////////////////////////////////////////
	
	final static int MAX_N = 10 * 1000 * 1000;
	
	long[] tenPows = new long[19];
	
	void solve() throws IOException{
		tenPows[0] = 1;
		for (int i = 1; i < 19; ++i) {
			tenPows[i] = tenPows[i-1] * 10;
		}
		
		int tests = readInt();
		for (int test = 1; test <= tests; ++test) {
			out.print("Case #" + test + ": "); // need space?
			
			long n = readLong();
			
			long bruteAnswer = bfs((int)n);
			
//			System.err.print(n);
			long myAnswer = fast(n);
//			System.err.println();
			
			if (bruteAnswer != myAnswer) {
				System.err.println(n + " " + bruteAnswer + " " + myAnswer);
			}
			out.print(myAnswer);
			
			out.println();
		}
	}
	
	long bfs(int end) {
		boolean[] used = new boolean[MAX_N];
		used[1] = true;
		
		int[] distances = new int[MAX_N];
		distances[1] = 1;
		
		int[] parents = new int[MAX_N];
		Arrays.fill(parents, -1);
		
		Queue<Integer> queue = new ArrayDeque<Integer>();
		queue.add(1);
		
		while (queue.size() > 0) {
			int from = queue.poll();
			
			if (from == end) {
//				for (int cur = end; cur != -1; cur = parents[cur]) {
//					System.err.print(cur + " <- ");
//				}
//				System.err.println();
				return distances[from];
			}
			
			int to = from + 1;
			if (!used[to]) {
				parents[to] = from;
				used[to] = true;
				distances[to] = distances[from] + 1;
				queue.add(to);
			}
			
			to = reverse(from);
			if (!used[to]) {
				parents[to] = from;
				used[to] = true;
				distances[to] = distances[from] + 1;
				queue.add(to);
			}
		}
		
		return -1;
	}
	
	int reverse(int x) {
		int res = 0;
		
		while (x > 0) {
			res = res * 10 + (x % 10);
			x /= 10;
		}
		
		return res;
	}
	
	long reverse(long x) {
		long res = 0;
		
		while (x > 0) {
			res = res * 10 + (x % 10);
			x /= 10;
		}
		
		return res;	
	}
	
	long fast(long x) {
		if (x < 20) {
//			System.err.print(" <- " + x);
			return x;
		}
		
		long result = 0;
		
		int length = getLength(x);
		
		// 1 -> 1
		// 2 -> 1
		// 3 -> 1
		// 4 -> 2
		// 5 -> 2
		
		long pow = tenPows[length >> 1];
		
		long tail = x % pow;
		if (tail == 0) {
			result = 1 + fast(x - 1);
		} else {
			long nextX = x - tail + 1;
			result += (tail - 1);
//			System.err.print(" <- " + nextX);
			
			long reverseNextX = reverse(nextX);
			if (reverseNextX < nextX) {
				nextX = reverseNextX;
				++result;
				
//				System.err.print(" <- " + nextX);
			}
			
			// 123 -> 121 -> 100 -> 99
			// 431 -> 134 -> 100 -> 99
			// 3456 -> 3401 -> 1043 -> 1000 -> 999
			
			if (length % 2 == 1) pow *= 10;
			tail = (nextX % pow);
			nextX -= tail;
			result += tail;
			
//			System.err.print(" <- " + nextX);
			
			nextX--;
			++result;
			
//			System.err.print(" <- " + nextX);
			
			result += fast(nextX);
		}	
		
		return result;
	}
	
	int getLength(long x) {
		int length = 0;
		while (x > 0) {
			++length;
			x /= 10;
		}
		return length;
	}
}

