package gc_1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Bsmall {

	public static void main(String[] args) throws FileNotFoundException {
		InputStream is = System.in;
		is = new FileInputStream(new File("A.txt"));
		FastScanner sc = new FastScanner(new InputStreamReader(is));
		PrintWriter pr = new PrintWriter(new File("A.out"));
		int T = sc.nextInt();
//		System.out.println(Arrays.toString("09?".getBytes()));
		for (int t=1; t<=T; t++) {
			byte[] a=sc.next().getBytes();
			byte[] b=sc.next().getBytes();
			int L = a.length;
			int A[] = new int[L+1];
			int B[] = new int[L+1];
			A[0] = 1;
			B[0] = 1;
			for (int i=0; i<L; i++) {
				if (a[i]==63) A[i+1]=-1; else A[i+1]=a[i]-48;
				if (b[i]==63) B[i+1]=-1; else B[i+1]=b[i]-48;
			}
//			System.out.print(Arrays.toString(A));
//			System.out.println(Arrays.toString(B));

			int max = (int) Math.pow(10, L);
			int difs[][] = new int[max][max];
//			System.out.println(max);
			int k = Integer.MAX_VALUE;
			int max2 = max*2;
			for (int i=max; i<max2; i++) {
				for (int j=max; j<max2; j++) {
					difs[i-max][j-max] = Integer.MAX_VALUE;
					int ii[] = new int[L+1];
					int jj[] = new int[L+1];
					int ttt = i;
					int tttt = L;
					while(ttt>0) {
						ii[tttt] = ttt%10;
						ttt/=10;
						tttt--;
					}
					ttt = j;
					tttt = L;
					while(ttt>0) {
						jj[tttt] = ttt%10;
						ttt/=10;
						tttt--;
					}
					boolean qq = false;
					for (int q=1; q<=L; q++) {
						if (A[q]!=-1) {
							if (A[q]!=ii[q]) {
								qq = true;
								break;
							}
						}
						if (B[q]!=-1) {
							if (B[q]!=jj[q]) {
								qq = true;
								break;
							}
						}
					}
					if (qq) continue;
					int dd = Math.abs(i-j);
					if (dd<k) {
						k = dd;
					}
					difs[i-max][j-max] = dd;
				}
			}
			String I = "";
			String J = "";
			l:for (int i=0; i<max; i++) {
				for (int j=0; j<max; j++) {
					if (difs[i][j]==k) {
						I = i+"";
						J = j+"";
						break l;
					}
				}
			}
			while(I.length()<L) I="0"+I;
			while(J.length()<L) J="0"+J;
			System.out.println("Case #"+t+": "+I+" "+J);
			pr.println("Case #"+t+": "+I+" "+J);
			
		}
		pr.close();
	}

	static class FastScanner {
	    BufferedReader br;
	    StringTokenizer st;

	    FastScanner(Reader in) {
	        br = new BufferedReader(in);
	    }

	    String next() {
	        while (st == null || !st.hasMoreTokens()) {
	            try {
	                st = new StringTokenizer(br.readLine());
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	        }
	        return st.nextToken();
	    }

	    int nextInt() {
	        return Integer.parseInt(next());
	    }
	}

}

