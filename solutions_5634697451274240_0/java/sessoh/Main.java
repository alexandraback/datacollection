import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			pw.println("Case #"+(t+1)+": "+analyze(br.readLine()));
			pw.flush();
		}

		pw.close();
		br.close();
	}
	
	private static int analyze(String S) {
		int answer = 0;
		char c = S.charAt(0);
		for (int i = 1; i < S.length(); i++) {
			if (c != S.charAt(i)) {
				c = S.charAt(i);
				answer++;
			}
		}
		if (c == '-') answer++;
		return answer;
	}
}
