package codejam.network172.com;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.TreeMap;
import java.util.TreeSet;

public class CodeJam {
	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("/home/harry/Downloads/cj.in")));
			PrintWriter out = new PrintWriter(new FileWriter("/home/harry/Downloads/cj.out"));
			jam(in, out);
			out.close();
		} catch (Exception e) {
			System.out.print("Exception thrown: " + e.toString());
		}
	}
	
	private static void jam(BufferedReader in, PrintWriter out) throws NumberFormatException, IOException {
		int cases = Integer.parseInt(in.readLine());
		for (int i = 0; i < cases; i++) {
			solveCase(i, in, out);
		}
	}
	
	private static TreeMap<Integer, TreeSet<Integer>> edges;
	private static ArrayList<TreeSet<Integer>> from;

	private static void solveCase(int c, BufferedReader in, PrintWriter out) throws NumberFormatException, IOException {
		String[] inStrs = in.readLine().split(" ");
		int n = Integer.parseInt(inStrs[0]);
		edges = new TreeMap<Integer, TreeSet<Integer>>();
		from = new ArrayList<TreeSet<Integer>>(n+1);
		from.add(null);
		for (int i = 0; i < n; i++) {
			from.add(new TreeSet<Integer>());
			String[] eStrs = in.readLine().split(" ");
			int m = Integer.parseInt(eStrs[0]);
			for (int j = 0; j < m; j++) {
				int cl = Integer.parseInt(eStrs[j+1]);
				TreeSet<Integer> s = edges.get(cl);
				if (s == null) {
					s = new TreeSet<Integer>();
					edges.put(cl, s);
				}
				s.add(i+1);
			}
		}
		boolean diamond = false;
		for (int i = 1; i <= n; i++) {
			if (processEdges(i, i)) {
				diamond = true;
				//break;
			}
		}
		out.printf("Case #%d: ", c+1);
		if (diamond)
			out.println("Yes");
		else
			out.println("No");
//		for (int i = 1; i <= n; i++) {
//			out.print(i);
//			out.print(": ");
//			TreeSet<Integer> ts = edges.get(i);
//			if (ts != null)
//				for (int j: ts) {
//					out.print(" ");
//					out.print(j);
//				}
//			out.print(" / ");
//			TreeSet<Integer> fs = from.get(i);
//			if (fs != null)
//				for (int j: fs) {
//					out.print(" ");
//					out.print(j);
//				}
//			out.println();
//		}
	}
	
	private static boolean processEdges(int src, int cl) {
		TreeSet<Integer> fs = from.get(cl);
		if (fs != null) {
			if (src != cl) {
				if (fs.contains(src))
					return true;
				fs.add(src);
			}
		}
		TreeSet<Integer> s = edges.get(cl);
		if (s != null)
			for (int dst: s)
				if (processEdges(src, dst))
					return true;
		return false;
	}
}
