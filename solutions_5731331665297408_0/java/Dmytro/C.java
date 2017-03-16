package C;
import java.util.*;
import java.io.*;


public class C {
	
	int N;
	int M;
	
	int[][] a;
	int[] idx;
	
	boolean check(int c) {
		LinkedList<Integer> queue = new LinkedList<Integer>();
		HashSet<Integer> visited = new HashSet<Integer>();
		if (c != 0) {
			queue.add(0);
		}
		else { 
			queue.add(1);
		}
		
		while (!queue.isEmpty()) {
			int v = queue.pop();
			visited.add(v);
			for (int cc = 0; cc < N; cc++) {
				if (a[v][cc] == 1 && cc != c && !visited.contains(cc)) {
					queue.push(cc);
				}
			}
		}
		if (visited.size() != N - 1)
			return false;
		else 
			return true;
	}
	
	
	String dirty(int c) {
		LinkedList<Integer> queue = new LinkedList<Integer>();
		LinkedList<Integer> visited = new LinkedList<Integer>();
		queue.push(c);
		
		while (!queue.isEmpty()) {
			int v = queue.pop();
			visited.add(v);
			int min = Integer.MAX_VALUE;
			int go = -1;
			for (int cc = 0; cc < N; cc++) {
				if (a[v][cc] == 1 && !visited.contains(cc)) {
					if (idx[cc] < min) {
						min = idx[cc];
						go = cc;
					}
				}
				queue.push(go);
			}
		}
		String res = "";
		for (Integer i : visited) {
			res = res + (""+i);
		}
		return res;
	}
	
	LinkedList<Integer> visited = new LinkedList<Integer>();
	
	String dirty0(int c) {
		visited = new LinkedList<Integer>();
		dirty1(c);
		String res = "";
		for (Integer i : visited) {
			res = res + (""+idx[i]);
		}
		return res;
	}
	
	void dirty1(int c) {
		visited.add(c);
		while (true) {
			int go = -1;
			int min = Integer.MAX_VALUE;
			boolean stop = true;
			for (int v = 0; v < N; v++) {
				if (a[v][c] == 1 && !visited.contains(v)) {
					if (idx[v] < min) {
						min = idx[v];
						go = v;
					}
					stop = false;
				}
			}
			if (go != -1) {
				dirty1(go);
			} 
			if (stop)
				break;
		}
	}
	
	void solve() {
		System.out.println("-------------------------------------------------");
		
		N = in.nextInt();
		M = in.nextInt();
		
		a = new int[N][];
		idx = new int[N];
		for (int c = 0; c < N; c++) {
			idx[c] = in.nextInt();
			a[c] = new int[N];
		}
		
		for (int f = 0; f < M; f++) {
			int i = in.nextInt();
			int j = in.nextInt();
			System.out.println("i=" + i +" j=" + j );
			a[i-1][j-1] = 1;
			a[j-1][i-1] = 1;
		}
		
		String min = dirty0(0);
		for (int i = 1; i < N; i++) {
			String val = dirty0(i);
			if (val.compareTo(min) == -1) {
				min = val;
			}
		}
		System.out.println(" min=" +  min );
		
		out.println(min); 
		out.flush();
	}
	
	/*************************************************************************/
	
	public static void main(String[] args) throws Exception {
		main1();
	}
	
	public static void main0() {
		String s = "4\r\n" + 
				"3 2\r\n" + 
				"10001\r\n" + 
				"20000\r\n" + 
				"10000\r\n" + 
				"1 2\r\n" + 
				"2 3\r\n" + 
				"5 4\r\n" + 
				"36642\r\n" + 
				"28444\r\n" + 
				"50012\r\n" + 
				"29651\r\n" + 
				"10953\r\n" + 
				"1 4\r\n" + 
				"2 3\r\n" + 
				"2 5\r\n" + 
				"4 5\r\n" + 
				"5 5\r\n" + 
				"36642\r\n" + 
				"28444\r\n" + 
				"50012\r\n" + 
				"29651\r\n" + 
				"10953\r\n" + 
				"1 2\r\n" + 
				"1 4\r\n" + 
				"2 3\r\n" + 
				"2 5\r\n" + 
				"4 5\r\n" + 
				"6 6\r\n" + 
				"10001\r\n" + 
				"10002\r\n" + 
				"10003\r\n" + 
				"10004\r\n" + 
				"10005\r\n" + 
				"10006\r\n" + 
				"1 2\r\n" + 
				"1 6\r\n" + 
				"2 3\r\n" + 
				"2 4\r\n" + 
				"3 5\r\n" + 
				"4 5"; 
				
		solveProblem0(s);
	}
	
	public static void main1() throws Exception {

		String name = "C-small-attempt1";
		
		String path = "/Users/dmytro/Workspace/GCJ/";
		String load = path + name + ".in";
		String save = path + name + ".out";
		//load = "1.in";
		//save = "1.out";
		
		solveProblem1(load, save);
	}
	
	/*************************************************************************/

	static void solveAllCases() {
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": "); 
			out.flush();
			new C().solve();
		}
	}
	
	public static void solveProblem0(String s) {
		in = new Scanner(s);
		out = new PrintWriter(System.out);
		solveAllCases();
		out.flush();
		in.close();
	}
	
	public static void solveProblem1(String load, String save) throws FileNotFoundException {
		//System.out.close();
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		solveAllCases();
		out.close();
		in.close();
	}

	static Scanner in;
	static PrintWriter out;
}
