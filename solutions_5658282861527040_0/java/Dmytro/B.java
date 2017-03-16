package B;
import java.util.*;
import java.io.*;


public class B {
	
	
	
	
	void solve() {
		System.out.println("-------------------------------------------------");
		
		int A = in.nextInt();
		int B = in.nextInt();
		int K = in.nextInt();
		
		int c = 0;
		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) {
					c++;
				}
			}
		
		out.println(c); 
		out.flush();
	}
	
	/*************************************************************************/
	
	public static void main(String[] args) throws Exception {
		main1();
	}
	
	public static void main0() {
		String s = "5\r\n" + 
				"3 4 2\r\n" + 
				"4 5 2\r\n" + 
				"7 8 5\r\n" + 
				"45 56 35\r\n" + 
				"103 143 88"; 
				
		solveProblem0(s);
	}
	
	public static void main1() throws Exception {

		String name = "B-small-attempt0";
		
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
			new B().solve();
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
