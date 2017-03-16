import java.util.*;
import java.io.*;

public class X {

	void solve() {
		int x = in.nextInt();
		int r = in.nextInt();
		int c = in.nextInt();
		String winer = "";
		if ((r*c)%x != 0) {
			winer =("RICHARD");
		} else if (x-Math.max(r,c)+1 > Math.min(r,c)){
			winer =("RICHARD");
		} else if ((x+1)/2 > Math.min(r,c)){
			winer =("RICHARD");
		} else if (r >= x && c >= x){
			winer =("GABRIEL");
		} else {
			if (Math.min(r,c) == 2 && Math.max(r,c)==4)winer =("RICHARD");
			else winer =("GABRIEL");
		}
		out.println(winer);
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
		String load = "C:/Users/dmytrobukhantsov/Downloads/d-small-attempt0.in";
		String save = "C:/Users/dmytrobukhantsov/Downloads/d-small-attempt0.out";
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
