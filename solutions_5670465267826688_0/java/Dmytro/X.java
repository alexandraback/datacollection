import java.util.*;
import java.io.*;

public class X {

	public static int ci(char c) {
		if (c=='e') return 0;
		if (c=='i') return 1;
		if (c=='j') return 2;
		if (c=='k') return 3;
		if (c=='E') return 4;
		if (c=='I') return 5;
		if (c=='J') return 6;
		if (c=='K') return 7;
		throw new RuntimeException("invalid character "+c);
	}
	
	public static char inv(char c) {
		if (c=='e') return 'E';
		if (c=='i') return 'I';
		if (c=='j') return 'J';
		if (c=='k') return 'K';
		if (c=='E') return 'e';
		if (c=='I') return 'i';
		if (c=='J') return 'j';
		if (c=='K') return 'k';
		throw new RuntimeException("invalid character "+c);
	}
	
	public static char m(char a, char b) {
		String[] mult = new String[] {
			"eijkEIJK",
			"iEkJIeKj",
			"jKEiJkeI",
			"kjIEKJie",
			"EIJKeijk",
			"IeKjiEkJ",
			"JkeIjKEi",
			"KJiekjIE"
		};
		return mult[ci(a)].charAt(ci(b));
	}
	
	public static String make(String s) {
		StringBuilder sb = new StringBuilder();
		char akk = 'e';
		for (int i = 0; i < s.length(); i++) {
			akk = m(akk, s.charAt(i));
			sb.append(akk);
		}
		//System.out.println(sb.toString());
		return sb.toString();
	}
	
	public static boolean can(String s)
	{
		//I*k = j
		//K*E = k;				
		if (s.charAt(s.length()-1)=='E')
		for (int i=0; i < s.length();i++)
			if (s.charAt(i)=='i')
				for (int j = i+1; j < s.length(); j++){
					if (s.charAt(j)=='k')
						return true;
				}
		return false;
	}
	
	void solve() {
		int L = in.nextInt();
		int X = in.nextInt();
		String S = in.next();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < X; i++)
			sb.append(S);
		out.println(can(make(sb.toString()))?"YES":"NO");
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
		String load = "C:/Users/dmytrobukhantsov/Downloads/c-small-attempt1.in";
		String save = "C:/Users/dmytrobukhantsov/Downloads/c-small-attempt1.out";
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
