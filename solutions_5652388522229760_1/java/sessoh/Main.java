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
			pw.println("Case #"+(t+1)+": "+analyze(Integer.parseInt(br.readLine())));
			pw.flush();
		}

		pw.close();
		br.close();
	}
	
	private static String analyze(int N) {
		if (N == 0) return "INSOMNIA";
		boolean[] used = new boolean[10];
		for (int i = 1; i < 100; i++) {
			int n = N * i;
			while (n > 0) {
				used[n%10] = true;
				n /= 10;
			}
			int c = 0;
			for (int j = 0; j < 10; j++) if (used[j]) c++;
			if (c == 10) return ""+(N * i);
		}
		return "INSOMNIA";
	}
}
