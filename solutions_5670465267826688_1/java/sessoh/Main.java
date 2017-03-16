import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("C.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split(" ");
			int L = Integer.parseInt(str[0]);
			long X = Long.parseLong(str[1]);
			String S = br.readLine();
			pw.println("Case #"+(t+1)+": "+(analyze(L, X, S) ? "YES" : "NO"));
			pw.flush();
		}
		
		pw.close();
		br.close();
	}
	
	static int[][] mul = { { 0, 1, 2, 3, 4, 5, 6, 7 },
						   { 1, 4, 3, 6, 5, 0, 7, 2 },
						   { 2, 7, 4, 1, 6, 3, 0, 5 },
						   { 3, 2, 5, 4, 7, 6, 1, 0 },
						   { 4, 5, 6, 7, 0, 1, 2, 3 },
						   { 5, 0, 7, 2, 1, 4, 3, 6 },
						   { 6, 3, 0, 5, 2, 7, 4, 1 },
						   { 7, 6, 1, 0, 3, 2, 5, 4 } };

	private static boolean analyze(int L, long X, String S) {
		if (L <= 1) return false;
		int[] str = new int[L];
		for (int i = 0; i < L; i++) {
			switch (S.charAt(i)) {
			case 'i':
				str[i] = 1; break;
			case 'j':
				str[i] = 2; break;
			case 'k':
				str[i] = 3; break;
			}
		}

		int[] tn = new int[L];
		int tloop = 8;
		for (int i = 0, c = 0, n = 1; ;) {
			c = mul[c][str[i]];
			if (++i >= L) { if (++n > 10) return false; else i = i - L; }
			if (c == 1) {
				if (tn[i] > 0) { tloop = n - tn[i]; break; }
				tn[i] = n;
			}
		}

		int[] bn = new int[L];
		int bloop = 8;
		for (int i = L-1, c = 0, n = 1; n < 10;) {
			c = mul[str[i]][c];
			if (--i < 0) { if (++n > 10) return false; else i = i + L; }
			if (c == 3) {
				if (bn[i] > 0) { bloop = n - bn[i]; break; }
				bn[i] = n;
			}
		}
		
		int tbloop = Math.min(tloop, bloop);
		
		loop:for (int p = 0; p < L; p++) {
			if (tn[p] == 0) continue;
			int[] mn = new int[L];
			int mloop = 8;
			for (int i = p, c = 0, n = 1; ;) {
				c = mul[c][str[i]];
				if (c == 2) {
					if (mn[i] > 0) { mloop = n - mn[i]; break; }
					mn[i] = n;
				}
				if (++i >= L) { if (++n > 10) continue loop; else i = i - L; }
			}
			long tmbloop = Math.min(tbloop, mloop);
			for (int i = 0; i < L; i++) {
				if (mn[i] > 0 && bn[i] > 0) {
					long cycle = tn[p]+mn[i]+bn[i]-2; 
					if (X >= cycle && (X-cycle)%tmbloop == 0L) return true;
				}
			}
			
		}
		

		
		return false;
	}
	
}
