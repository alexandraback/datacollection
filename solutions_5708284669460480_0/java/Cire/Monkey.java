/*
 * Eric Schneider
 * 5/10
 */

import java.util.Scanner;


public class Monkey {
	
	public static double logProbOfWinning(String Keyboard, String Goal) {
		int [] alph = new int[26];
		char[] k = Keyboard.toCharArray();
		char[] g = Goal.toCharArray();
		double l=0;
		for(char c: k) {
			alph[c-'A']++;
			l++;
		}
		double logl = Math.log(l);
		double logProb = 0;
		for (char c: g) {
			if (alph[c-'A']==0)
				return 1;
			logProb+= Math.log(alph[c-'A']) - logl;
		}
		return logProb;
	}
	
	public static int longest(String Goal) {
		char[] g = Goal.toCharArray();
		int i=1;
		for(; i<Goal.length(); i++) {
			boolean worked = true;
			for(int j = i; j < Goal.length(); j++) {
				if (g[j-i] != g[j]) {
					worked = false;
					break;
				}
			}
			if (worked)
				break;
		}
		return i;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		//Monkey eng = new Brattleship();
		for(int i = 0; i < T; i++) {
			int K = in.nextInt();
			int L = in.nextInt();
			int S = in.nextInt();
			in.nextLine();
			String Keyboard = in.nextLine();
			String Goal = in.nextLine();
			double logProb = Monkey.logProbOfWinning(Keyboard, Goal);
			int needed = 1+(S-L)/Monkey.longest(Goal);
			double prob = Math.exp(logProb);
			if (logProb>.9) {
				prob=0;
				needed=0;
			}
			double expected = needed - prob*(S-L+1); 	
			
			System.out.println("Case #" + (i+1) + ": " + expected);
		}
	}
			
}
