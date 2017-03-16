import java.io.*;
import java.util.*;

class B {
	static String a;
	static String b;
	static boolean f;
	static long m;	
	static String ma;
	static String mb;
	static long la;
	static long lb;
	
	static void solve(int i, int c, String aa, String bb) {
		while (i < a.length() && !((c != 0) && (a.charAt(i) == '?' || b.charAt(i) == '?'))) {
			char ca = a.charAt(i);
			char cb = b.charAt(i);
			if (c == 0) {
				if (ca == '?') {
					if (cb == '?') {						
						solve(i+1, 0, aa+"0", bb+"0");
						solve(i+1, -1, aa+"0", bb+"1");
						solve(i+1, 1, aa+"1", bb+"0");						
						return;
					} else {
						solve(i+1, 0, aa+cb, bb+cb);
						if (cb != '9') {
							solve(i+1, 1, aa+(char)((int)cb+1), bb+cb);
						}
						if (cb != '0') {
							solve(i+1, -1, aa+(char)((int)cb-1), bb+cb);
						}
						return;
					} 
				} else {
					if (cb == '?') {
						solve(i+1, 0, aa+ca, bb+ca);
						if (ca != '9') {
							solve(i+1, -1, aa+ca, bb+(char)((int)ca+1));
						}
						if (ca != '0') {
							solve(i+1, 1, aa+ca, bb+(char)((int)ca-1));
						}
						return;
					} else {
						if (ca < cb) c = -1;
						if (ca > cb) c = 1;
					} 
				}
			} 
			aa += ca;
			bb += cb;
			i++;
		}
		
		while (i < a.length()) {
			char ca = a.charAt(i);
			char cb = b.charAt(i);
			if (c == 1) {
				if (ca == '?') ca = '0';
				if (cb == '?') cb = '9';
			} else {
				if (ca == '?') ca = '9';
				if (cb == '?') cb = '0';
			}
			aa += ca;
			bb += cb;
			i++;			
		}
		
		if (i == a.length()) {
			long a1 = Long.parseLong(aa);
			long b1 = Long.parseLong(bb);
			long d1 = a1>=b1 ? a1-b1 : b1-a1;
			if (f || d1 < m || (d1 == m && a1 < la) || (d1 == m && a1 == la && b1 < lb)) {
				f = false;
				m = d1;
				ma = aa;
				mb = bb;
				la = a1;
				lb = b1;
			}
		}	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("B.in"));
        PrintWriter out = new PrintWriter(new File("B.out"));
		
		int tt = in.nextInt();
		in.nextLine();
		for(int tc=1; tc<=tt; ++tc) {            
			String ss = in.nextLine();
			String[] s = ss.split(" ");
			a = s[0];
			b = s[1];
			f = true;
			solve(0, 0, "", "");
			out.println("Case #"+tc+": "+ma+" "+mb);
        }
		
		out.close();
		in.close();
	}
}