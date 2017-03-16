package Round1B;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class SafetyInNumbers {

	public static final double EPS = 1e-9; 
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("safetyinnumbers.in"));
		System.setOut(new PrintStream("safetyinnumbers.out"));
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine().trim());
		for(int t = 1; t <= T; t++) {
			String[] parts = bf.readLine().trim().split("[ ]+");
			int N = Integer.parseInt(parts[0]);
			
			int[] score = new int[N];
			int X = 0;
			for(int i = 0; i < N; i++) {
				score[i] = Integer.parseInt(parts[i + 1]);
				X += score[i];
			}
			int audiencePoints = X;
			
			double minScoreNeeded = (X + audiencePoints) / ((double) N);
			
			boolean newPassed = true;
			int newN = N;
			boolean[] passed = new boolean[N];
			while(newPassed) {
				minScoreNeeded = (X + audiencePoints) / ((double) newN);
				newPassed = false;
				for(int i = 0; i < N; i++) {
					if(passed[i]) continue;
					double scoreLeft = minScoreNeeded - score[i];
					if(scoreLeft < EPS) {
						newN--;
						X -= score[i];
						passed[i] = true;
						newPassed = true;
					}
				}
			}
			
			
			minScoreNeeded = (X + audiencePoints) / ((double) newN);
			
			StringBuilder solution = new StringBuilder();
			for(int i = 0; i < N; i++) {
				if(passed[i]) {
					solution.append("0.0 ");
					continue;
				}
				
				double scoreLeft = minScoreNeeded - score[i];
				scoreLeft /= audiencePoints;
				scoreLeft *= 100d;
				solution.append(scoreLeft + " ");
			}
			
			System.out.println("Case #" + t + ": " + solution.toString().trim());
		}

	}

}
