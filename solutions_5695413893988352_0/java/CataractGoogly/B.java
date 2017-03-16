package round1b;
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	long bestC;
	long bestJ;
	long bestDiff;

	String solve(String s1, String s2) {
		String[] ans = new String[] { "", "" };
		if (solveEqual(s1, s2, 0, ans)) return ans[0] + " " + ans[1];

		bestC = -1;
		bestJ = -1;
		bestDiff = -1;
		solveLess(s1, s2, 0, false, 0, 0);
		solveGreater(s1, s2, 0, false, 0, 0);
		int N = s1.length();
		return pad(bestC, N) + " " + pad(bestJ, N);
	}

	String pad(long x, int len) {
		String s = Long.toString(x);
		while (s.length() < len) s = "0" + s;
		return s;
	}

	void solveLess(String s1, String s2, int pos, boolean alreadyLess, long C, long J ) {
		if (pos==s1.length() ) {
			long d = Math.abs(C-J);
			if (bestC<0 || (d<bestDiff) || (d==bestDiff && C<bestC) || (d==bestDiff && C==bestC && J<bestJ)) {
				bestC = C;
				bestJ = J;
				bestDiff = d;
			}
			return;
		}
		if (s1.charAt(pos)=='?' && s2.charAt(pos)=='?') {
			if (alreadyLess) {
				solveLess(s1, s2, pos+1, true, 10*C+9, 10*J);
			} else {
				solveLess(s1, s2, pos+1, false, 10*C, 10*J);
				solveLess(s1, s2, pos+1, true, 10*C, 10*J+1);
			}
		}
		else if (s1.charAt(pos)=='?') {
			int dig = s2.charAt(pos)-'0';
			if (alreadyLess) {
				solveLess(s1, s2, pos+1, true, 10*C+9, 10*J+dig);
			} else {
				solveLess(s1, s2, pos+1, false, 10*C+dig, 10*J+dig);
				if (dig>0) solveLess(s1, s2, pos+1, true, 10*C+(dig-1), 10*J+dig);
			}
		}
		else if (s2.charAt(pos)=='?') {
			int dig = s1.charAt(pos)-'0';
			if (alreadyLess) {
				solveLess(s1, s2, pos+1, true, 10*C+dig, 10*J);
			} else {
				solveLess(s1, s2, pos+1, false, 10*C+dig, 10*J+dig);
				if (dig<9) solveLess(s1, s2, pos+1, true, 10*C+dig, 10*J+dig+1);
			}
		}
		else if( alreadyLess || s1.charAt(pos) <= s2.charAt(pos )){
			int dig1 = s1.charAt(pos)-'0';
			int dig2 = s2.charAt(pos)-'0';
			solveLess(s1, s2, pos+1, alreadyLess || s1.charAt(pos)<s2.charAt(pos), 10*C+dig1, 10*J+dig2 );
		}
	}

	void solveGreater(String s1, String s2, int pos, boolean alreadyGreater, long C, long J ) {
		if (pos==s1.length() ) {
			long d = Math.abs(C-J);
			if (bestC<0 || (d<bestDiff) || (d==bestDiff && C<bestC) || (d==bestDiff && C==bestC && J<bestJ)) {
				bestC = C;
				bestJ = J;
				bestDiff = d;
			}
			return;
		}
		if (s1.charAt(pos)=='?' && s2.charAt(pos)=='?') {
			if (alreadyGreater) {
				solveGreater(s1, s2, pos+1, true, 10*C, 10*J+9);
			} else {
				solveGreater(s1, s2, pos+1, false, 10*C, 10*J);
				solveGreater(s1, s2, pos+1, true, 10*C+1, 10*J);
			}
		}
		else if (s1.charAt(pos)=='?') {
			int dig = s2.charAt(pos)-'0';
			if (alreadyGreater) {
				solveGreater(s1, s2, pos+1, true, 10*C, 10*J+dig);
			} else {
				solveGreater(s1, s2, pos+1, false, 10*C+dig, 10*J+dig);
				if (dig<9) solveGreater(s1, s2, pos+1, true, 10*C+(dig+1), 10*J+dig);
			}
		}
		else if (s2.charAt(pos)=='?') {
			int dig = s1.charAt(pos)-'0';
			if (alreadyGreater) {
				solveGreater(s1, s2, pos+1, true, 10*C+dig, 10*J+9);
			} else {
				solveGreater(s1, s2, pos+1, false, 10*C+dig, 10*J+dig);
				if (dig>0) solveGreater(s1, s2, pos+1, true, 10*C+dig, 10*J+dig-1);
			}
		}
		else if( alreadyGreater || s1.charAt(pos) >= s2.charAt(pos )){
			int dig1 = s1.charAt(pos)-'0';
			int dig2 = s2.charAt(pos)-'0';
			solveGreater(s1, s2, pos+1, alreadyGreater || s1.charAt(pos)>s2.charAt(pos), 10*C+dig1, 10*J+dig2 );
		}
	}

	boolean solveEqual(String s1, String s2, int pos, String[] ans) {
		if (pos==s1.length()) return true;
		if (s1.charAt(pos)=='?' && s2.charAt(pos)=='?') {
			ans[0] += "0";
			ans[1] += "0";
			return solveEqual(s1, s2, pos+1, ans);
		}
		if (s1.charAt(pos)=='?') {
			ans[0] += s2.charAt(pos);
			ans[1] += s2.charAt(pos);
			return solveEqual(s1, s2, pos+1, ans);
		}
		if (s2.charAt(pos)=='?') {
			ans[0] += s1.charAt(pos);
			ans[1] += s1.charAt(pos);
			return solveEqual(s1, s2, pos+1, ans);
		}
		if (s1.charAt(pos) != s2.charAt(pos) ) return false;
		ans[0] += s1.charAt(pos);
		ans[1] += s1.charAt(pos);
		return solveEqual(s1, s2, pos+1, ans);
	}

	public static void main(String[] args) {
		try {
			File fin = new File("B-small-attempt1.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("bout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			sc.nextLine();
			for (int cn=1; cn<=T; cn++) {
				String c = sc.next();
				String j = sc.next();
				B b = new B();
				pw.write("Case #" + cn + ": " + b.solve(c, j) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
