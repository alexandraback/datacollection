import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QA {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(
				new File("a-small.out")));

		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			out.print("Case #" + (i + 1) + ":");

			int n = in.nextInt();

			int total = 0;

			int[] points = new int[n];
			int[] min = new int[n];

			for (int j = 0; j < n; j++) {
				points[j] = in.nextInt();
				total += points[j];
			}
			
			for(int j = 0; j < n; j++){
				int temp = Integer.MAX_VALUE;
				for(int k = 0; k < n; k++){
					if(j == k)
						continue;
					if(points[k] < temp)
						temp = points[k];
				}
				min[j] = temp;
			}

			int n2 = n;
			double avg = total * 2.0 / (n);
			int origTotal = total;
			
			boolean[] temp = new boolean[n];
			for (int j = 0; j < n; j++) {
				//if (points[j] > min[j] + avg) {
					
				if (points[j] > avg) {
					total -= points[j];
					n2--;
					temp[j] = false;
				} else {
					temp[j] = true;
				}
			}

			for (int j = 0; j < n; j++) {
				if (temp[j]) {
					//if (total != 0) {
						double b = 100.0 * (((total + origTotal) / (1.0 * n2)) - points[j])
								/ (origTotal);
						out.print(" " + b);
					//} else {
					//	out.print(" " + 0.0);
					//}
				} else {
					out.print(" " + 0.0);
				}
			}

			out.println();
		}

		in.close();
		out.close();
	}
}
