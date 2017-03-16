package c;

import java.util.*;import java.text.*;import java.math.*;import java.util.regex.*;import java.awt.geom.*;import java.io.*;
import a.A;
import static java.lang.Math.*;import static java.lang.Character.*;import static java.lang.Integer.*;import static java.lang.Double.*;import static java.lang.Long.*;import static java.lang.System.*;import static java.util.Arrays.*; 

class Solver {
	public static final String FILE_NAME = "C"; 
	//	public static final String FILE_NAME = "C-small-attempt0"; 
	//	public static final String FILE_NAME = "C-large"; 

	public static final String FOLDER_NAME = "/Users/minh/Documents/workspace/GoogleCodeJam/src/c/";
	public static final String INPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".out";

	final int INF = Integer.MAX_VALUE/10;
	int m;
	int n;

	String[] c;
	int[][] a;
	public void input() throws Exception{
		String s = in.readLine();
		String[] ss = s.split("[ ]+");
		n = new Integer(ss[0]);
		m = new Integer(ss[1]);
		c = new String[n];
		for (int i = 0; i < n; i++) {
			c[i] = in.readLine();
		}
		a=new int[n][n];
		for (int i = 0; i < m; i++) {
			s = in.readLine();
			ss = s.split("[ ]+");
			int u = new Integer(ss[0])-1;
			int v = new Integer(ss[1])-1;
			a[u][v] = 1;
			a[v][u] = 1;
		}
	}

	private String outputString () {
		return "Case #"+(C.CURRENT_TEST+1)+": ";
	}
	public void output() throws IOException {
		out.write(outputString() + ret);
		out.newLine();

		System.out.println(outputString() + ret);
	}

	String ret = "";
	void updateRet (String s) {
		if (ret.isEmpty()) ret = s;
		if (ret.compareTo(s)>0) ret = s;
	}
	int start;
	int[] p ;
	public void process() throws Exception{
		p = new int[n];
		for (int i = 0; i < n; i++) p[i] = i;
		do {
			if (ok()) {
				String s = "";
				for (int i = 0; i < n; i++) s+= c[p[i]];
				updateRet (s);
			}
		} while (NEXTPERM(p));
	}
	boolean ok () {
//		debug (p);
		int[] stack = new int[n];
		start = p[0];
		stack[0] = start;
		int s = 0;

		for (int i = 1; i < n; i++) {
			int v = p[i];
			int index = -1;
			for (int j = s; j >= 0; j--) {
				int u = stack[j];
				if (a[u][v]==1) {
					index = j;
					break;
				}
			}
			if(index==-1) return false;
			stack[index+1] = v;
			s = index+1;
		}
		return true;
	}
	void debug(Object...os) { 
		System.err.println(Arrays.deepToString(os));
	} 

	public static boolean NEXTPERM (int[] a) { 
		int i = a.length, j = i + 1; 
		while (--i > 0 && a[i - 1] >= a[i]); 
		if (i == 0)return false; 
		while (--j > 0 && a[j - 1] <= a[i - 1]); 
		int x = a[j - 1]; 
		a[j - 1] = a[i - 1]; 
		a[i - 1] = x; 
		j = a.length - 1; 
		while (i < j) { 
			x = a[j];
			a[j--] = a[i]; 
			a[i++] = x;
		} 
		return true; 
	}

	BufferedReader in;
	BufferedWriter out;

	public Solver(BufferedReader in, BufferedWriter out ){
		this.in = in;
		this.out = out;
	}

	int[] parseArrInt (String s) {
		s = s.trim();
		ArrayList<Integer> list = new ArrayList<Integer> ();
		String[] ss = s.split("[ ]+");
		for(String x:ss) list.add(new Integer(x));
		int[] ret = new int[list.size()];
		for (int i = 0; i < ret.length; i++) {
			ret[i] = list.get(i);
		}
		return ret;
	}

	// Bit Operators
	int SET(int mask, int u) { return mask | (1 << u);}
	boolean CHECK(int mask, int u) {return (mask & (1 << u)) != 0;}
	int FLIP(int mask, int u) {return mask ^ (1 << u);}
	int CLEAR(int mask, int u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
	long SET(long mask, long u) { return mask | (1L << u);}
	boolean CHECK(long mask, long u) {return (mask & (1L << u)) != 0;}
	long FLIP(long mask, long u) {return mask ^ (1L << u);}
	long CLEAR(long mask, long u) {if (CHECK(mask, u)) return FLIP(mask, u);return mask;}
}

/**
 * @author minh
 *
 */
public class C {
	static BufferedReader in;
	static BufferedWriter out;
	static int NUMBER_OF_TEST, CURRENT_TEST;

	public static void main(String[] args) throws java.lang.Exception {
		in =  new BufferedReader(new FileReader(new File (Solver.INPUT_FILE_NAME)));
		out = new BufferedWriter(new FileWriter(new File (Solver.OUTPUT_FILE_NAME)));

		//		int[] temp = solver.parseArrInt(in.readLine());
		//		// code here
		//		NUMBER_OF_TEST = temp[0];
		//		Solver solver = new Solver(in, out);
		//		solver.input();
		//		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
		//			solver.process();
		//			solver.output();
		//		}
		//		

		NUMBER_OF_TEST = new Integer(in.readLine());
		for(CURRENT_TEST = 0;CURRENT_TEST<NUMBER_OF_TEST;CURRENT_TEST++) {
			Solver solver = new Solver(in, out);
			solver.input();
			solver.process();
			solver.output();
		}

		in.close();
		out.close();
	}
}

