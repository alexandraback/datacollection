import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class ProbB {
	public static int solve(int N, int S, int p, int[] scores) {
		int count = 0;
		for(int i = 0; i<scores.length; i++) {
			if(p*3<=scores[i]) count++;
			else if(Math.max(0, p-1)*2+p <=scores[i]) count++;
			else  {
				int tmp = scores[i] - p;
				if(Math.max(0, p-2) *2 <= tmp) {
					if(S > 0) {
						count++; S--;
					}
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for(int i=1; i<=T; i++) {
			line = in.readLine();
			String[] comp = line.split("\\s+");
			int N = Integer.parseInt(comp[0]);
			int S = Integer.parseInt(comp[1]);
			int p = Integer.parseInt(comp[2]);
			int[] scores = new int[N];
			for(int j = 0; j<N; j++)
				scores[j] = Integer.parseInt(comp[3+j]);
			
			out.print("Case #" + i+ ": ");
			out.println(solve(N, S, p, scores));
		}
		
		out.flush();
		in.close();
		out.close();
	}
}
