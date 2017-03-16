package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class FractilesLarge {

	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/D-large.in");
		BufferedReader obj = new BufferedReader(fileReader);
		String l = obj.readLine();
		int t = Integer.parseInt(l);
		System.out.println(t);
		PrintWriter write = new PrintWriter(new File("/home/parikh/output.txt"));
		for (int k = 1; k <= t; k++) {
			l = obj.readLine();
			String sp[] = l.split(" ");
			int K = Integer.parseInt(sp[0]);
			int C = Integer.parseInt(sp[1]);
			int S = Integer.parseInt(sp[2]);
			System.out.println("Case " + k);
			String ans = "";
			if (K == 1) {
				for (int i = 1; i <= K; i++)
					ans += i + " ";
				write.println("Case #" + k + ": " + ans);
			} else {
				int required = K / C;
				int v = K / C;
				;
				if (K % C != 0)
					required++;
				if (required > S) {
					write.println("Case #" + k + ": " + "IMPOSSIBLE");
					continue;
				}
				long arr[] = new long[C + 1];
				arr[0] = 1;
				for (int i = 1; i <= C; i++){
					arr[i] = K * arr[i - 1];
					System.out.println(i + " " +arr[i]);
				}
				
				for (int i = 0; i < v; i++) {
					long st = i*C+1;
					long val = (st-1)*arr[C-1]+1;
					long node =st+1;
					System.out.println(st);
					for (int j = 1; j < C; j++) {
						val += (node-1)*arr[C - j-1];
						node++;
					}
					ans += val + " ";

				}
				
				if (K%C!=0){
					long st  = v*C +1;
					System.out.println(st);
					long val = (st-1)*arr[C-1]+1;
					long node =st+1;
					System.out.println(val );
					for (int j = 1; j < K%C; j++) {
						val += (node-1)*arr[C - j-1];
						node++;
					}
					ans += val + " ";
				}
				write.println("Case #" + k + ": " + ans);
				System.out.println(ans);

			}

		}
		obj.close();
		write.close();

	}

}
