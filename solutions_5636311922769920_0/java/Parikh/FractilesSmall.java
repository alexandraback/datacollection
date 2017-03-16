package coding;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class FractilesSmall {

	public static void main(String args[]) throws IOException {
		FileReader fileReader = new FileReader(
				"/home/parikh/Downloads/D-small-attempt0.in");
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

			String ans = "";
			for (int i = 1; i <= K; i++)
				ans += i + " ";
			write.println("Case #" + k + ": " + ans);

		}
		obj.close();
		write.close();

	}

}
