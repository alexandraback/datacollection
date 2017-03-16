import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class DancingWithTheGooglers {

	static final String input_path = "data/input.b.txt";
		
	private static int solve(int N, int S, int p, int[] t) {
		int ans = 0;
		int candidate = 0;
		
		for (int i = 0; i < N; i++) {
			int point = t[i];
			int base = point / 3;
			int residule = point % 3;
			if (base >= p) {
				ans += 1;
				continue;
			}
			
			if (base == p - 1) {
				if (residule > 0)
					ans += 1;
				else if (base > 0)
					candidate += 1;
				continue;
			}
			
			if (base == p - 2 && residule == 2) 
				candidate += 1;
		}
		
		if (S >= candidate)
			ans += candidate;
		else
			ans += S;
//		System.out.println(String.format("%d\t%d", ans, candidate));		
		return ans;
	}
	
	/**
	 * Good luck, Wash :)
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			intext = in.readLine();
			System.out.print(String.format("Case #%d: ", caseIter + 1));
			
			String[] parts = intext.split(" ");
			int N = Integer.parseInt(parts[0]);
			int S = Integer.parseInt(parts[1]);
			int p = Integer.parseInt(parts[2]);
			int[] t = new int[N];
			for (int i = 0; i < N; i ++) 
				t[i] = Integer.parseInt(parts[3 + i]);
			
			System.out.println(solve(N,S,p,t));
		}
		in.close();
	}

}
