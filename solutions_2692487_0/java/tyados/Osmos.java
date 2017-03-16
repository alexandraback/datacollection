package osmos;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Osmos {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("small.out"));

		int T = Integer.parseInt(in.readLine());
		for (int CASE = 1; CASE <= T;CASE ++) {
			long A;
			int N;
			StringTokenizer st = new StringTokenizer(in.readLine());
			A = Long.parseLong(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			long[] val = new long[N];
			st = new StringTokenizer(in.readLine());
			for (int i = 0;i < N;i++) {
				val[i] = Long.parseLong(st.nextToken());
			}
			Arrays.sort(val);
			int min = N;
			int count = N;
			long sum = A;
			for (int i = 0; i < N && A != 1;i++) {
				while (sum <= val[i]) {
					count ++;
					sum += (sum - 1);
				}
				sum += val[i];
				count--;
				if (count < min) {
					min = count;
				}
			}
			out.println("Case #"+CASE+": " + min);
		}
		out.close();
		in.close();
	}

}
