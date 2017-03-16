import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("D.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("D.out"))));
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split(" ");
			int K = Integer.parseInt(str[0]);
			int C = Integer.parseInt(str[1]);
			int S = Integer.parseInt(str[2]);
			pw.println("Case #"+(t+1)+":"+analyze(K, C, S));
			pw.flush();
		}

		pw.close();
		br.close();
	}
	
	private static String analyze(int K, int C, int S) {
		
		if (K == 1) return " 1";
		if (C * S < K) return " IMPOSSIBLE";
		if (C == 1) {
			String answer = "";
			for (int i = 1; i <= K; i++) answer += " "+i;
			return answer;
		}
		
		String answer = "";
		if (K % C > 0) 	answer += " " + position(K, C, S, 0, K%C);
		for (int i = K % C; i < K; i+=C) {
			answer += " " + position(K, C, S, i, i+C);
		}
		return answer;
	}
	
	private static long position(int K, int C, int S, int start, int end) {
		long pos = 0;
		long len = 1;
		for (int i = end; i > start; i--) {
			pos += len * (i-1);
			len *= K;
		}
		pos++;
		return pos;
	}
	
		
	
	
}
