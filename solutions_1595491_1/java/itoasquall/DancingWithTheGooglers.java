package QualificationRound;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class DancingWithTheGooglers {
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("dancingwiththegooglers.in"));
		System.setOut(new PrintStream("dancingwiththegooglers.out"));
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine());
		for(int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			
			String[] parts = bf.readLine().trim().split("[ ]+");
			int N = Integer.parseInt(parts[0]);
			int S = Integer.parseInt(parts[1]);
			int p = Integer.parseInt(parts[2]);
			int[] scores = new int[N];
			for(int i = 3; i < parts.length; i++)
				scores[i - 3] = Integer.parseInt(parts[i]);
			
			if(p == 0) {
				System.out.println(N);
				continue;
			}
			if(p == 1) {
				int count = 0;
				for(int i = 0; i < N; i++)
					if(scores[i] > 0) count++;
				
				System.out.println(count);
				continue;
			}
			
			//p = 8
			// 6 6 8 = 20 surprising
			// 6 7 8 = 21 surprising
			// surprising -> 3 * p - 4 && 3 * p - 3
			
			int normal = 0, surprising = 0;
			for(int i = 0; i < N; i++) {
				if(scores[i] < 3 * p - 4) continue;
				
				if(scores[i] < 3 * p - 2) surprising++;
				else normal++;
			}
			
			if(surprising > S) surprising = S;
			
			System.out.println((normal + surprising));
		}
	}

}
