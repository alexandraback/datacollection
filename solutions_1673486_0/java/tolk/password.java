import java.io.*;
import java.util.*;

class password {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("password.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("password.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int typed = Integer.parseInt(st.nextToken());
			int total = Integer.parseInt(st.nextToken());
			double[] probs = new double[typed];
			double[] mult = new double[typed];
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < typed; j++) {
				probs[j] = Double.parseDouble(st.nextToken());
				if (j != 0) {
					mult[j] = mult[j-1]*probs[j];
				} else {
					mult[j] = probs[j];
				}
			}
			double answer = Double.MAX_VALUE;
			//keep typing
			answer = Math.min(answer,mult[typed-1]*(total-typed+1) + (1-mult[typed-1])*(total-typed+1+total+1));
			//backspace
			for (int j = 1; j < typed; j++) {
				answer = Math.min(answer,mult[typed-j-1]*(total-(typed-j)+1+j) + (1-mult[typed-j-1])*(total-(typed-j)+1+total+1+j));
			}
			//press enter
			answer = Math.min(answer,total+2);
			out.println("Case #" + (i+1) + ": " + answer);
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
}

