import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("A.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));

		int T = Integer.parseInt(br.readLine());
		
		for (int t = 0; t < T; t++) {
			String S = br.readLine();
			StringBuilder sb = new StringBuilder();
			char o = S.charAt(0);
			sb.append(o);
			for (int i = 1; i < S.length(); i++) {
				char n = S.charAt(i);
				if (n < o) {
					sb.append(n);
				} else {
					sb.insert(0, n);
					o = n;
				}
			}
			pw.println("Case #"+(t+1)+": "+sb);
			pw.flush();
		}
		
		pw.close();
		br.close();
	}
}
