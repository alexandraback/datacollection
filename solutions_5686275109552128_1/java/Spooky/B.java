package qual2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));
	
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			int n = in.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) a[i] = in.nextInt();
			
			int best = Integer.MAX_VALUE;
			for (int i = 1; i <= 1000; i++) {
				int curr = i;
				for (int j = 0; j < n; j++) {
					int k = (a[j] + i - 1) / i;
					curr += k - 1;
				}
				if (curr < best) best = curr;
			}
			out.println(best);
		}

		out.flush();
	}

}
