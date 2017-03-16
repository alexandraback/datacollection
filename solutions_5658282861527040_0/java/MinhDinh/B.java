package b;
import java.util.*;import java.text.*;import java.math.*;import java.util.regex.*;import java.awt.geom.*;import java.io.*;
import a.A;
import static java.lang.Math.*;import static java.lang.Character.*;import static java.lang.Integer.*;import static java.lang.Double.*;import static java.lang.Long.*;import static java.lang.System.*;import static java.util.Arrays.*; 

class Solver {
	public static final String FILE_NAME = "b"; 
//	public static final String FILE_NAME = "B-small-attempt0"; 
//	public static final String FILE_NAME = "B-large"; 
	
	public static final String FOLDER_NAME = "/Users/minh/Documents/workspace/GoogleCodeJam/src/b/";
	public static final String INPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".in";
	public static final String OUTPUT_FILE_NAME = FOLDER_NAME + FILE_NAME + ".out";
	
	final int INF = Integer.MAX_VALUE/10;
	int a,b,k;
	int n;

	public void input() throws Exception{
		String s = in.readLine();
		String[] ss = s.split("[ ]+");
		a = new Integer (ss[0]);
		b = new Integer (ss[1]);
		k = new Integer (ss[2]);
	}
	
	private String outputString () {
		return "Case #"+(B.CURRENT_TEST+1)+": ";
	}
	public void output() throws IOException {
		out.write(outputString() + ret);
		out.newLine();
		
		System.out.println(outputString() + ret);
	}
	
	int ret = 0;

	public void process() throws Exception{
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int x = i&j;
				if (x<k) ret++;
			}
		}
	}

	void debug(Object...os) { 
		System.err.println(Arrays.deepToString(os));
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
public class B {
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

