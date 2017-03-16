import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			int D = Integer.parseInt(br.readLine());
			int[] P = new int[D];
			String[] str = br.readLine().split(" ");
			for (int i = 0; i < D; i++) P[i] = Integer.parseInt(str[i]);
		
			pw.println("Case #"+(t+1)+": "+analyze(D, P));
			pw.flush();
		}
		
		pw.close();
		br.close();
	}
	
	private static int analyze(int D, int[] P) {
		Arrays.sort(P);
		int answer = P[D-1];
		int L = P[D-1];
		for (int i = 1; i <= L; i++) {
			int s = 0;
			int p = 0;
			for (int j = 0; j < D; j++) {
				int t = (P[j]+i-1)/i;
				s += t-1;
				p = Math.max(p, (P[j]+t-1)/t);
			}
			answer = Math.min(answer, s+p);
		}
		return answer;
	}
}
