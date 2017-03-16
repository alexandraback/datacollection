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
			String[] str = br.readLine().split(" ");
			pw.println("Case #"+(t+1)+": "+analyze(Integer.parseInt(str[0]), str[1]));
			pw.flush();
		}
		
		pw.close();
		br.close();
	}
	
	private static int analyze(int Smax, String S) {
		int now = 0, answer = 0;
		for (int i = 0; i <= Smax; i++) {
			int s = S.charAt(i) - '0';
			if (s > 0) {
				if (i > now) { answer += i - now; now = i; }
				now += s;
			}
		}
		return answer;
	}
}
