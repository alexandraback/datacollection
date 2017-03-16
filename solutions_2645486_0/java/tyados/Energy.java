package energy;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Energy {
	
	final static BigInteger TWO = new BigInteger("2");
	final static BigInteger THREE = new BigInteger("3");

	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("B-small-attempt0.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("small.out"));
		
		int T = Integer.parseInt(in.readLine());
		for (int CASE = 1; CASE <= T;CASE ++) {
			
			int E, R, N;
			StringTokenizer st = new StringTokenizer(in.readLine());
			E = Integer.parseInt(st.nextToken());
			R = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			long[] num = new long[N];
			st = new StringTokenizer(in.readLine());
			for (int i = 0;i < N;i++) {
				num[i] = Long.parseLong(st.nextToken());
			}
			long y = 0;
			int D = Math.max(E - R, 0);
			long maxo = 0;
			for (int i = 0;i < N;i++) {
				if (maxo < num[i])
					maxo = num[i];
			}
			int X = 0;
			if (D == 0) {
				X = E;
			} else {
				X = R;
			}
			for (int i = 0;i < N;i++) {
				y += num[i] * X;
			}
			y += (D * maxo);
			
			out.println("Case #"+CASE+": " + y);
		}
		out.close();
		in.close();
	}

	
}
