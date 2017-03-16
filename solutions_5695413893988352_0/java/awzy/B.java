import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("B-small-attempt1.in"));
//		 Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter("B-out-small.txt", "UTF-8");
		// while(sc.hasNext()) {
		int T = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= T; i++) {
			String str = sc.nextLine();
			String a = str.split(" ")[0];
			String b = str.split(" ")[1];
			if (a.length() < b.length())
				a = '?' + a;
			while (a.length() < b.length())
				a = '0' + a;
			if (a.length() > b.length())
				b = '?' + b;
			while (a.length() > b.length())
				b = '0' + b;
			String[] ans = solve(a, b, 0);
			System.out.println("Case #" + i + ": " + ans[0] + " " + ans[1]);
			pw.println("Case #" + i + ": " + ans[0] + " " + ans[1]);
		}
		pw.close();
		// }
	}

	// mode 1 : max min
	// mode -1 : min max
	public static String[] solve(String a, String b, int mode) {
		String[] ans = new String[2];
		if (a.length() == 0) {
			ans[0] = "";
			ans[1] = "";
			return ans;
		}
		if (mode == 0) {
			char ac = a.charAt(0);
			char bc = b.charAt(0);
			// x y
			if ((ac != bc) && (ac != '?') && (bc != '?')) {
//				System.out.println("SEC1 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
				String[] inans;
				if (ac < bc) {
					inans = solve(a.substring(1), b.substring(1), 1);
				} else {
					inans = solve(a.substring(1), b.substring(1), -1);
				}
				ans[0] = ac + inans[0];
				ans[1] = bc + inans[1];
//				System.out.println("ANSSEC1 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
			// ? ?
			} else if ((ac == bc) && (ac == '?')) {
//				System.out.println("SEC2 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
				String[] inans0 = solve(a.substring(1), b.substring(1), 0);
				String[] ans0 = new String[2];
				ans0[0] = '0' + inans0[0];
				ans0[1] = '0' + inans0[1];
				String[] inans1 = solve(a.substring(1), b.substring(1), 1);
				String[] ans1 = new String[2];
				ans1[0] = '0' + inans1[0];
				ans1[1] = '1' + inans1[1];
				String[] inansn1 = solve(a.substring(1), b.substring(1), -1);
				String[] ansn1 = new String[2];
				ansn1[0] = '1' + inansn1[0];
				ansn1[1] = '0' + inansn1[1];
				int mindiff = Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1]));
				mindiff = Math.min(mindiff, Math.abs(Integer.parseInt(ans1[0]) - Integer.parseInt(ans1[1])));
				mindiff = Math.min(mindiff, Math.abs(Integer.parseInt(ansn1[0]) - Integer.parseInt(ansn1[1])));
				if(mindiff == Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1]))) ans = ans0;
				else if(mindiff == Math.abs(Integer.parseInt(ans1[0]) - Integer.parseInt(ans1[1]))) ans = ans1;
				else ans = ansn1;
//				System.out.println("ANSSEC2 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
			// x x
			} else if(ac == bc) {
//				System.out.println("SEC3 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
				String[] inans = solve(a.substring(1), b.substring(1), 0);
				ans[0] = ac + inans[0];
				ans[1] = bc + inans[1];
//				System.out.println("ANSSEC3 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
			// ? x
			} else if (ac == '?') {
//				System.out.println("SEC4 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
				String[] inans0, inans1, inansn1;
				String[] ans0 = new String[2], ans1 = new String[2], ansn1 = new String[2];
				inans0 = solve(a.substring(1), b.substring(1), 0);
				ans0[0] = bc + inans0[0];
				ans0[1] = bc + inans0[1];
				if(bc > '0') {
					inans1 = solve(a.substring(1), b.substring(1), 1);
					ans1[0] = ((char)(bc-1)) + inans1[0];
					ans1[1] = bc + inans1[1];
				}
				if(bc < '9') {
					inansn1 = solve(a.substring(1), b.substring(1), -1);
					ansn1[0] = ((char)(bc+1)) + inansn1[0];
					ansn1[1] = bc + inansn1[1];					
				}
//				System.out.println(Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1])));
				int mindiff = Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1]));
//				System.out.println(mindiff);
				if(bc > '0') {
					mindiff = Math.min(mindiff, Math.abs(Integer.parseInt(ans1[0]) - Integer.parseInt(ans1[1])));
//					System.out.println(Math.abs(Integer.parseInt(ans1[0]) - Integer.parseInt(ans1[1])));
				}
				if(bc < '9') {
					mindiff = Math.min(mindiff, Math.abs(Integer.parseInt(ansn1[0]) - Integer.parseInt(ansn1[1])));
//					System.out.println(Math.abs(Integer.parseInt(ansn1[0]) - Integer.parseInt(ansn1[1])));
				}
				if((bc > '0') && (mindiff == Math.abs(Integer.parseInt(ans1[0]) - Integer.parseInt(ans1[1])))) ans = ans1;
				else if(mindiff == Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1]))) ans = ans0;
				else ans = ansn1;
//				System.out.println("ANSSEC4 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1] + " " + mindiff);
			// x ?
			} else {
//				System.out.println("SEC5 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
				String[] inans0, inans1, inansn1;
				String[] ans0 = new String[2], ans1 = new String[2], ansn1 = new String[2];
				inans0 = solve(a.substring(1), b.substring(1), 0);
				ans0[0] = ac + inans0[0];
				ans0[1] = ac + inans0[1];
				if(ac < '9') {
					inans1 = solve(a.substring(1), b.substring(1), 1);
					ans1[0] = ac + inans1[0];
					ans1[1] = ((char)(ac+1)) + inans1[1];
				}
				if(ac > '0') {
					inansn1 = solve(a.substring(1), b.substring(1), -1);
					ansn1[0] = ac + inansn1[0];
					ansn1[1] = ((char)(ac-1)) + inansn1[1];					
				}
				int mindiff = Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1]));
				if(ac < '9') mindiff = Math.min(mindiff, Math.abs(Integer.parseInt(ans1[0]) - Integer.parseInt(ans1[1])));
				if(ac > '0') mindiff = Math.min(mindiff, Math.abs(Integer.parseInt(ansn1[0]) - Integer.parseInt(ansn1[1])));
				if((ac > '0') && (mindiff == Math.abs(Integer.parseInt(ansn1[0]) - Integer.parseInt(ansn1[1])))) ans = ansn1;
				else if(mindiff == Math.abs(Integer.parseInt(ans0[0]) - Integer.parseInt(ans0[1]))) ans = ans0;
				else ans = ans1;
//				System.out.println("ANSSEC5 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
			}
		} else if (mode == 1) {
//			System.out.println("SEC6 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
			String[] inans = solve(a.substring(1), b.substring(1), 1);
			ans[0] = (a.charAt(0) == '?' ? '9' : a.charAt(0)) + inans[0];
			ans[1] = (b.charAt(0) == '?' ? '0' : b.charAt(0)) + inans[1];
//			System.out.println("ANSSEC6 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
		} else {
//			System.out.println("SEC7 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
			String[] inans = solve(a.substring(1), b.substring(1), -1);
			ans[0] = (a.charAt(0) == '?' ? '0' : a.charAt(0)) + inans[0];
			ans[1] = (b.charAt(0) == '?' ? '9' : b.charAt(0)) + inans[1];
//			System.out.println("ANSSEC7 " + a + " " + b + " " + mode + " " + ans[0] + " " + ans[1]);
		}
		return ans;
	}
}

//// ??7 4?1
