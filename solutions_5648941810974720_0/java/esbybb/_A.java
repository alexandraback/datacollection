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

public class _A {

	public static void main(String[] args) throws FileNotFoundException {
		InputStream is = System.in;
		is = new FileInputStream(new File("A.txt"));
		FastScanner sc = new FastScanner(new InputStreamReader(is));
		PrintWriter pr = new PrintWriter(new File("A.out"));
		int T = sc.nextInt();
		for (int t=1; t<=T; t++) {
			byte[] s = sc.next().getBytes();
			int c[] = new int[27];
			int tc[] = new int[10];
			int d[] = new int[10];
			for (byte i: s) {
				c[i-65]++;
			}
			boolean R = true;
			while(R) {
				boolean k=true;
				for (int C:c) if (C>0) {k=false; break;};
				if (k) break;
				R = false;
				tc[0] = Math.min(c[25], c[4]); 
				tc[0] = Math.min(tc[0], c[17]); 
				tc[0] = Math.min(tc[0], c[14]);
				if (tc[0]==c[25]) { R = true; 
				c[25]-=tc[0]; 
				c[4]-=tc[0]; 
				c[17]-=tc[0]; 
				c[14]-=tc[0]; 
				d[0]+=tc[0]; };
				
				tc[6] = Math.min(c[18], c[8]); 
				tc[6] = Math.min(tc[6], c[23]); 
				if (tc[6]==c[23]) { R = true; 
				c[18]-=tc[6]; 
				c[8]-=tc[6]; 
				c[23]-=tc[6]; 
				d[6]+=tc[6]; };
				
				tc[2] = Math.min(c[19], c[22]); 
				tc[2] = Math.min(tc[2], c[14]); 
				if (tc[2]==c[22]) { R = true; 
				c[19]-=tc[2]; 
				c[22]-=tc[2]; 
				c[14]-=tc[2]; 
				d[2]+=tc[2]; };
				
				tc[7] = Math.min(c[18], c[21]); 
				tc[7] = Math.min(tc[7], c[13]); 
				tc[7] = Math.min(tc[7], c[4]/2);
				if (tc[7]==c[18]) { R = true; 
				c[18]-=tc[7]; 
				c[21]-=tc[7]; 
				c[13]-=tc[7]; 
				c[4]-=2*tc[7]; 
				d[7]+=tc[7]; };
				
				tc[4] = Math.min(c[5], c[14]); 
				tc[4] = Math.min(tc[4], c[20]); 
				tc[4] = Math.min(tc[4], c[17]);
				if (tc[4]==c[20]) { R = true; 
				c[5]-=tc[4]; 
				c[14]-=tc[4]; 
				c[20]-=tc[4]; 
				c[17]-=tc[4]; 
				d[4]+=tc[4]; };
				
				tc[3] = Math.min(c[19], c[7]); 
				tc[3] = Math.min(tc[3], c[17]); 
				tc[3] = Math.min(tc[3], c[4]/2);
				if (tc[3]==c[7]) { R = true; 
				c[19]-=tc[3]; 
				c[7]-=tc[3]; 
				c[17]-=tc[3]; 
				c[4]-=2*tc[3]; 
				d[3]+=tc[3]; };
				
				tc[1] = Math.min(c[14], c[4]); 
				tc[1] = Math.min(tc[1], c[13]); 
				if (tc[1]==c[14]) { R = true; 
				c[4]-=tc[1]; 
				c[13]-=tc[1]; 
				c[14]-=tc[1]; 
				d[1]+=tc[1]; };
				
				tc[5] = Math.min(c[5], c[8]); 
				tc[5] = Math.min(tc[5], c[21]); 
				tc[5] = Math.min(tc[5], c[4]);
				if (tc[5]==c[5]) { R = true; 
				c[5]-=tc[5]; 
				c[8]-=tc[5]; 
				c[21]-=tc[5]; 
				c[4]-=tc[5]; d[5]+=tc[5]; };

				tc[8] = Math.min(c[4], c[8]); 
				tc[8] = Math.min(tc[8], c[6]); 
				tc[8] = Math.min(tc[8], c[7]); 
				tc[8] = Math.min(tc[8], c[19]);
				if (tc[8]==c[6]) { R = true; 
				c[4]-=tc[8]; 
				c[8]-=tc[8]; 
				c[6]-=tc[8]; 
				c[7]-=tc[8]; 
				c[19]-=tc[8]; 
				d[8]+=tc[8]; };

				tc[9] = Math.min(c[8], c[4]); 
				tc[9] = Math.min(tc[9], c[13]/2);
				if (tc[9]>0) { R = true; 
				c[8]-=tc[9]; 
				c[4]-=tc[9]; 
				c[13]-=2*tc[9]; 
				d[9]+=tc[9]; };
			}
			System.out.print("Case #"+t+": ");
			pr.print("Case #"+t+": ");
			for (int tt=0; tt<10; tt++) {
				for (int j=1; j<=d[tt]; j++) { System.out.print(tt); pr.print(tt); }
			}
			int a=0;
			for (int DD:c ) if (DD>0) {
				System.out.println(s+" "+Arrays.toString(c));
				a=a/a;
			}
			if (t<T){pr.println(); System.out.println();};
//			System.out.println("Case #"+t+": "+b);
//			pr.println("Case #"+t+": "+b);
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

