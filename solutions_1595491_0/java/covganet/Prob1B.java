import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class Prob1B {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			String[] strs = br.readLine().split(" ");
			int n = Integer.parseInt(strs[0]);
			int s = Integer.parseInt(strs[1]);
			int p = Integer.parseInt(strs[2]);
			int[] scores = new int[n];
			for(int i = 0; i < scores.length; i++) {
				scores[i] = Integer.parseInt(strs[3 + i]);
			}
			
			int minNormalScore = Math.max(3 * p - 2, p);
			int surprisingMinScore = Math.max(3 * p - 4, p);
			int res = 0;
			for(int i = 0; i < scores.length; i++) {
				if(scores[i] >= minNormalScore) {
					res++;
				} else if(scores[i] >= surprisingMinScore && s > 0) {
					s--;
					res++;
				}
			}
			
			pw.println("Case #" + x + ": " + res);
		}
		
		br.close();
		pw.close();
	}
}
