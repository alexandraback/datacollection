import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("C-small-1-attempt1.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("C-small-at1.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim()), N;
		long [] D = new long[2];
		long [] T = new long[2];
		for (int c = 1; c <= cases; c++) {
			N = Integer.parseInt(br.readLine().trim());
			for(int i = 0;i < N;i++) {
				st = new StringTokenizer(br.readLine());
				int td = Integer.parseInt(st.nextToken());
				int th = Integer.parseInt(st.nextToken());
				int tt = Integer.parseInt(st.nextToken());
				D[0] = td;
				T[0] = tt;
				if(th == 2) {
					D[1] = td;
					T[1] = tt+1;
				}
			}
			int res = 0;
			if((360-D[0])*T[0] > (360-D[1])*T[1]) {
				long t = D[0];D[0] = D[1];D[1] = t;
				t = T[0];T[0] = T[1];T[1] = t;
			}
			if(T[0] != T[1]) {
				long d = 360*T[1]-D[1]*T[1]-((360-D[0])*T[0]);
				if(d > T[0]*360)
					res = 1;
			}
			out.println("Case #" + c + ": "+res);
		}
		out.close();
	}
}