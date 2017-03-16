package gcj;

import java.io.*;
import java.util.*;

public class quaternion {
	
	static final int ii = (int) 'i';
	static final int jj = (int) 'j';
	static final int kk = (int) 'k';
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("quaternion.in"));
				//new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("quaternion.out")));
				//new OutputStreamWriter(System.out)));
		int t = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= t; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			//int numChars = Integer.parseInt(st.nextToken());
			st.nextToken();
			int repeat = Integer.parseInt(st.nextToken());
			String letters = br.readLine().trim();
			
			int total = totalProd(letters);
			int rtotal = 1;
			for (int i = 0; i < repeat; i++) {
				rtotal = quatmul(rtotal, total);
			}
			if (rtotal != -1) { // i * j * k = -1
				out.printf("Case #%d: NO\n", tc);
				continue;
			}
			
			// we just need to check if there's an "ij" now,
			// and 8 repetitions of the string suffices easily
			String rletters = "";
			for (int i = 0; i < 8 && i < repeat; i++) {
				rletters = rletters.concat(letters);
			}
			int totalProd = 1;
			int index;
			for (index = 0; index < rletters.length(); index++) {
				totalProd = quatmul(totalProd, (int) rletters.charAt(index));
				if (totalProd == (int) 'i') {
					break;
				}
			}
			if (totalProd != (int) 'i') {
				// end of loop reached without finding 'i'
				out.printf("Case #%d: NO\n", tc);
				continue;
			}
			index++;
			for (totalProd = 1; index < rletters.length(); index++) {
				totalProd = quatmul(totalProd, (int) rletters.charAt(index));
				if (totalProd == (int) 'j') {
					break;
				}
			}
			if (totalProd != (int) 'j') {
				// end of loop reached without finding 'j'
				out.printf("Case #%d: NO\n", tc);
			}
			else {
				out.printf("Case #%d: YES\n", tc);
			}
		}
		out.flush();
		System.exit(0);
	}
	
	static int quatmul(int a, int b) {
		int mul = 1;
		if (a < 0) {
			a = -a;
			mul *= -1;
		}
		if (b < 0) {
			b = -b;
			mul *= -1;
		}
		if (a == 1) {
			return mul * b;
		}
		if (a == ii) {
			if (b == 1) return mul * ii;
			if (b == ii) return mul * -1;
			if (b == jj) return mul * kk;
			if (b == kk) return mul * -jj;
		}
		if (a == jj) {
			if (b == 1) return mul * jj;
			if (b == ii) return mul * -kk;
			if (b == jj) return mul * -1;
			if (b == kk) return mul * ii;
		}
		if (a == kk) {
			if (b == 1) return mul * kk;
			if (b == ii) return mul * jj;
			if (b == jj) return mul * -ii;
			if (b == kk) return mul * -1;
		}
		throw new IllegalArgumentException();
	}
	
	static int totalProd(String expr) {
		int res = 1;
		for (int i = 0; i < expr.length(); i++) {
			res = quatmul(res, (int) expr.charAt(i));
		}
		return res;
	}
	
}
