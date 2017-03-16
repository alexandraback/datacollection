package gcj;

import java.awt.Point;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.security.acl.LastOwnerException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Calendar;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.Iterator;

public class Jam2016_1C {
	//10^4 <  Short.MAX_VALUE (2^15)   < 10^5
	//10^9 <  Integer.MAX_VALUE (2^31) < 10^10
	//10^18 < Long.MAX_VALUE (2^63)    < 10^20

	//static String size = "sample";
	//static String size = "small";
	//static String size = "large"=
	// path: C:\Users\Lucas\workspace_tc\CodeJam\src\gcj\Jam2016_1C.java
	static String filename = "C:\\Users\\Lucas\\Downloads\\B-small-attempt0";

	static String outputfile = filename + ".out";
	static MyScanner scan;
	static PrintStream out;

	public static void main(String[] args) throws NumberFormatException, IOException {
		scan = new MyScanner(new FileInputStream(filename+".in"));
		out = new PrintStream(new BufferedOutputStream(new FileOutputStream(outputfile)));
		System.out.println(Calendar.getInstance().getTime()+" - Started writing to: "+outputfile);
		
//		SenateEvacuation();
		Slides();

		System.out.println(Calendar.getInstance().getTime()+" - Finished writing to: "+outputfile);
		scan.close();
		out.close();
	}

	public static void Slides() {
		int tests = scan.nextInt();

		for (int test = 0; test < tests; test++) {
			int b = scan.nextInt();
			int m = scan.nextInt();
			out.println("Case #" +(test + 1) + ": " + Slides(b, m));
		}
	}
	
	public static String Slides(int b, int m) {
		int TOTAL = 0;
		for (int i = 0; i < b; i++) {
			TOTAL += i;
		}
		boolean found = false;
		StringBuilder sb = new StringBuilder();

		int N = 1 << TOTAL;
		for (int n = 0; n < N; n++) {
			boolean[] active = new boolean[TOTAL];
			for (int i = 0; i < TOTAL; i++) {
				if (((1 << i) & n) != 0) {
					active[i] = true;
				}
			}
			
			boolean[][] conn = new boolean[b][b];
			int k = 0;
			int numActive = 0;
			HashMap<Integer, ArrayList<Integer>> g = new HashMap<>();
			for (int y = 0; y < conn.length; y++) {
				for (int x = y+1; x < conn.length; x++) {
					if (active[k]) {
						numActive++;
						conn[y][x] = true;
						if (!g.containsKey(y)) {
							g.put(y, new ArrayList<Integer>());
						}
						ArrayList<Integer> list = g.get(y); 
						list.add(x);
					}
					k++;
				}
			}
			if (numActive > 0) { 
				ArrayList<Integer> ord = new ArrayList<>();
				topSort(ord, g);
				int[] ways = new int[b];
				ways[ord.get(0)] = 1;
				for (int i = 0; i < ord.size(); i++) {
					ArrayList<Integer> children = g.get(ord.get(i));
					if (children != null) {
						for (int j = 0; j < children.size(); j++) {
							ways[children.get(j)] += ways[ord.get(i)];
						}
					}
				}
				if (ways[b-1] == m) {
					found = true;
					sb.append("POSSIBLE");
					for (int y = 0; y < conn.length; y++) {
						sb.append("\n");
						for (int x = 0; x < conn.length; x++) {
							if (conn[y][x]) {
								sb.append('1');
							} else {
								sb.append('0');
							}
						}
					}
					break;
				}
			}
		}
		if (found) {
			return sb.toString();
		} else {
			return "IMPOSSIBLE";
		}
	}
	

	public static boolean topSort(ArrayList<Integer> order, HashMap<Integer, ArrayList<Integer>> graphRef) {
		
		// Create a copy of the graph
		HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
		for (Integer key: graphRef.keySet()) {
			graph.put(key, (ArrayList<Integer>) graphRef.get(key).clone());
		}
		
		// Count number of incoming edges
		HashMap<Integer, Integer> numIncoming = new HashMap<>();
		for (Integer key: graph.keySet()) {
			ArrayList<Integer> children = graph.get(key);
			for (Integer child: children) {
				numIncoming.put(child, numIncoming.containsKey(child) ? numIncoming.get(child) + 1 : 1);
			}
		}
		
		// Select vertices with no incoming edges
		Stack<Integer> roots = new Stack<>(); // Doesn't have to be a stack!
		for (Integer key: graph.keySet()) {
			if (!numIncoming.containsKey(key) || numIncoming.get(key) == 0) {
				roots.push(key);
			}
		}
		
		// Build the ordering
		while (!roots.isEmpty()) {
			Integer top = roots.pop();
			order.add(top);
			ArrayList<Integer> children = graph.get(top);
			if (children != null) {
				for (int i = 0; i < children.size(); i++) {
					Integer rem = children.remove(i--);
					numIncoming.put(rem, numIncoming.get(rem) - 1);
					if (numIncoming.get(rem) == 0) {
						roots.push(rem);
					}
				}
			}
		}
		
		// Count number of edges
		int edges = 0;
		for (Integer key: graph.keySet()) {
			edges += graph.get(key).size();
		}
		
		return edges > 0 ? false : true;
	}
	
	public static String SenateEvacuation(int n, int[] a) {
		int total = 0;
		for (int i = 0; i < a.length; i++) {
			total += a[i];
		}
		String out = "";
		
		while (total > 0) {
			int numP = 0;
			ArrayList<Integer> num = new ArrayList<>();
			for (int i = 0; i < a.length; i++) {
				if (a[i] > 0) {
					numP++;
					num.add(a[i]);
				}
			}
			boolean eq = true;
			for (int i = 1; i < num.size(); i++) {
				if (!num.get(0).equals(num.get(i))) {
					eq = false;
					break;
				}
			}
			
			if (numP == 2 && eq) {
				for (int i = 0; i < a.length; i++) {
					if (a[i] > 0) {
						out += (char)('A' + i);
						total--;
					}
				}
			} else {
				int max = 0;
				int maxN = 0;
				for (int i = 0; i < a.length; i++) {
					if (a[i] > max) {
						max = a[i];
						maxN = i;
					}
				}
				a[maxN]--;
				max--;
				total--;
				out += (char)('A' + maxN);
				
				if (max > total - max) {
					System.out.println("majority violation");
				}
			}
			out += " ";
		}
		return out;
	}

	public static void SenateEvacuation() {
		int tests = scan.nextInt();

		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int[] a = scan.nextIntArray(n);
			out.println("Case #" +(test + 1) + ": " + SenateEvacuation(n, a));
		}
	}
	
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner(InputStream in) {
			this.br = new BufferedReader(new InputStreamReader(in));
		}

		public void close() {
			try {
				this.br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextLong();
			}
			return a;
		}

		int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = this.nextInt();
			}
			return a;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine(){
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

}