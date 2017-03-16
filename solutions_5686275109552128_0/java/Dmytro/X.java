import java.util.*;
import java.io.*;

public class X {


	
	void solve() {
		int d = in.nextInt();
		ArrayList<Integer> p = new ArrayList<Integer>();
		for (int i = 0; i < d; i++)
		{
			int x = in.nextInt();
			p.add(x);
		//	System.out.print(x+" ");
		}
		//System.out.println();
		Collections.sort(p, Collections.reverseOrder());
		int min = 10;
		//System.out.println("e c min");
		for (int e = 9; e >= 1; e--) {
			int i = 0;
			int c = 0;
			while (i < p.size() && p.get(i) > e) {
				c += (p.get(i)-1)/e;
				i+=1;
			}
			min = Math.min(e+c, min);
			//\System.out.println(e+" " + c+" "+min);
		}
		out.println(min);
		out.flush();
	}

	/*************************************************************************/

	public static void main(String[] args) throws Exception {
		main1();
	}

	public static void main0() {
		String s = "";
		solveProblem0(s);
	}

	public static void main1() throws Exception {
		String load = "C:/Users/dmytrobukhantsov/Downloads/b-small-attempt1.in";
		String save = "C:/Users/dmytrobukhantsov/Downloads/b-small-attempt1.out";
		solveProblem1(load, save);
	}

	/*************************************************************************/

	static void solveAllCases() {
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			System.out.println("Solving case #" + t + ": .....................................................");
			new X().solve();
		}
	}

	public static void solveProblem0(String s) {
		in = new Scanner(s);
		out = new PrintWriter(System.out);
		solveAllCases();
		out.flush();
	}

	public static void solveProblem1(String load, String save)
			throws FileNotFoundException {
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		solveAllCases();
		out.close();
	}

	static Scanner in;
	static PrintWriter out;
}
