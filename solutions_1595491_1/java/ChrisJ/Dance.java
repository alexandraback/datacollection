import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Dance {
	
	/* Returns pair (max if not surprising, max if surprising */
	private static int[] max(int score) {
		int max, maxsurpr;
		
		if(score == 0) {
			max = 0;
			maxsurpr = 0;
		} else if(score == 1) {
			max = 1;
			maxsurpr = 1;
		} else if(score == 2) {
			max = 1;
			maxsurpr = 2;
		} else if((score % 3) == 0) {
			max = score/3;
			maxsurpr = score/3 + 1;
		} else if((score % 3) == 1) {
			max = score/3 + 1;
			maxsurpr = score/3 + 1;
		} else {
			max = score/3 + 1;
			maxsurpr = score/3 + 2;
		}
		
		return new int[] {max, maxsurpr};
	}
	
	private static int process(String l) {
		String[] parts = l.split(" ");
		int N = Integer.parseInt(parts[0]);
		int S = Integer.parseInt(parts[1]);
		int p = Integer.parseInt(parts[2]);
		
		if(parts.length != N+3) {
			System.err.println("Error: " + l);
		}
		
		int good = 0;
		
		for(int i=0; i<N; i++) {
			int[] max = max(Integer.parseInt(parts[i+3]));
			if(max[0] >= p) good++;
			else {
				if(max[1] >= p && S > 0) {
					good++;
					S--;
				}
			}
		}
		
		return good;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(args[1]);
		
		// number of testcases
		String sCount = in.readLine();
		int count = Integer.parseInt(sCount);

		for(int idx=1; idx<=count; idx++) {
			String l = in.readLine();
			out.println("Case #" + idx + ": " + process(l));
		}
		
		out.close();
	}

}
