package QR;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	static PrintWriter writer;

	public static void main(String[] args) throws IOException {
		writer = new PrintWriter(new FileWriter("out"));
		Scanner reader = new Scanner(new FileReader("in"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			int L = reader.nextInt();
			int X = reader.nextInt();
			String S = reader.next();
			boolean canDo = solve(L, X, S);
			System.out.println(canDo);
			writer.printf("Case #%d: %s\n", tc, canDo ? "YES" : "NO");
		}
		writer.close();
		reader.close();
	}
	
	static final int ONE = 0, I = 1, J = 2, K = 3, mONE = 4, mI = 5, mJ = 6, mK = 7;
	
	static int multiply(int x, int y) {
		boolean negx = x >= 4;
		boolean negy = y >= 4;
		if(negx) x -= 4;
		if(negy) y -= 4;
		int res = -1;
		if(x == ONE) res = y;
		else if(y == ONE) res = x;
		else if(x == I && y == I) res = mONE;
		else if(x == I && y == J) res = K;
		else if(x == I && y == K) res = mJ;
		else if(x == J && y == I) res = mK;
		else if(x == J && y == J) res = mONE;
		else if(x == J && y == K) res = I;
		else if(x == K && y == I) res = J;
		else if(x == K && y == J) res = mI;
		else if(x == K && y == K) res = mONE;
		if(negx == negy) return res;
		if(res >= 4) return res - 4;
		return res + 4;
	}
	
	static String toStr(int x) {
		if(x == ONE)  return "  1";
		if(x == I)    return "  i";
		if(x == J)    return "  j";
		if(x == K)    return "  k";
		if(x == mONE) return " -1";
		if(x == mI)   return " -i";
		if(x == mJ)   return " -j";
		if(x == mK)   return " -k";
		return "  ?";
	}
	
	static int getValue(char c) {
		if(c == '1') return ONE;
		if(c == 'i') return I;
		if(c == 'j') return J;
		return K;
	}

	static String s;

	static boolean solve(int L, int X, String S) {
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < X; i++) {
			sb.append(S);
		}
		s = sb.toString();
		memo = new Boolean[s.length() + 1][3][8];
		return aux(0, 0, ONE);
	}
	
	static Boolean[][][] memo;
	
	static boolean aux(int i, int k, int cur) {
		if(memo[i][k][cur] != null) return memo[i][k][cur];
		if(i == s.length()) {
			return k == 2 && cur == K;
		} else if(k == 2) {
			int val = cur;
			for(int t = i; t < s.length(); t++) {
				val = multiply(val, getValue(s.charAt(t)));
			}
			return val == K;
		} else {
			boolean ok = false;
			if(checkOk(k, cur)) {
				ok |= aux(i + 1, k + 1, getValue(s.charAt(i)));
			}
			ok |= aux(i + 1, k, multiply(cur, getValue(s.charAt(i))));
			memo[i][k][cur] = ok;
			return ok;
		}
	}
	
	static boolean checkOk(int k, int cur) {
		return (k == 0 && cur == I) || (k == 1 && cur == J) || (k == 2 && cur == K);
	}
	
}
