import java.util.*;
import java.io.*;
import java.awt.Point;
import java.math.BigDecimal;
import java.math.BigInteger;

import static java.lang.Math.*;

// Solution is at the bottom of code

public class C_Small implements Runnable{
	
	BufferedReader in;
	OutputWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	public static void main(String[] args){
		new Thread(null, new C_Small(), "", 128 * (1L << 20)).start();
	}
	
	/////////////////////////////////////////////////////////////////////
	
	void init() throws FileNotFoundException{
		Locale.setDefault(Locale.US);
		
		String fileName = "C-small-attempt1.in";
		
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
	
	List<Integer>[] graph;
	String[] zips;
	
	int[] p;
	
	String bestAnswer = "z";
	int[] bestPermutate;
	
	void solve() throws IOException{
		int tests = readInt();
		for (int test = 1; test <= tests; ++test) {
			out.print("Case #" + test + ": "); // need space?
			
			int n = readInt();
			int m = readInt();
			
			zips = new String[n];
			for (int i = 0; i < n; ++i) {
				zips[i] = readLine();
			}
			
			graph = readGraph(n, m);
			
			p = new int[n];
			for (int i = 0; i < n; ++i) {
				p[i] = i;
			}
			
			bestAnswer = "z";
			used = new boolean[n];
			gen(0, n);
			
			out.println(bestAnswer);
//			for (int i: bestPermutate) {
//				out.print((i + 1) + " ");
//			}
//			
//			out.println();
		}
	}
	
	void swap(int i, int j) {
		if (i != j) {
			int tmp = p[i];
			p[i] = p[j];
			p[j] = tmp;
		}
	}
	
	void gen(int cur, int len) {
		if (cur == len) {
			doIt();
		} else {
			for (int i = cur; i < len; ++i) {
				swap(i, cur);
				gen(cur + 1, len);
				swap(i, cur);
			}
		}
	}
	
	void doIt() {
		if (checkPermutate()) {
			StringBuilder curAnswerBuilder = new StringBuilder();
			for (int pElement: p) {
				curAnswerBuilder.append(zips[pElement]);
			}
			
			String curAnswer = curAnswerBuilder.toString();
			if (curAnswer.compareTo(bestAnswer) < 0) {
				bestAnswer = curAnswer;
				bestPermutate = p.clone();
			}
		}
	}
	
	boolean[] used;
	boolean checkPermutate() {
		Arrays.fill(used, false);
		
		int res = dfs(p[0], 1);
		return res == p.length;
	}
	
	int dfs(int from, int cur) {
		used[from] = true;
		
		while (cur != p.length) {
			boolean check = false;
			
			for (int to: graph[from]) {
				if (!used[to]) {
					if (to == p[cur]) {
						check = true;
						cur = dfs(to, cur + 1);
						if (cur == p.length) return cur;
					}
				}
			}
			
			if (!check) {
				break;
			}
		}
		
		return cur;
	}
}

