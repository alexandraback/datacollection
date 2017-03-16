import java.util.*;
import java.io.*;

public class B {
	public static int solve(int T, int P) {
		int[] score = new int[3];
		
		score[0] = T/3;
		score[1] = (T-score[0]) / 2;
		score[2] = (T-score[0]-score[1]);
		
		Arrays.sort(score);
		int dif = score[2] - score[0];
		
		if (dif > 2) {
			System.err.println("ERROR");
			System.exit(-1);
		}
		//System.err.println("BEFORE ARRANGE NUM "+T+": "+score[0]+" "+score[1]+" "+score[2]);
		
		if (score[2] >= P) {
			if (dif == 2) return 1;
			else return 0;
		}
		
		// try to make it interesting
		if (dif < 2) {
			score[2]++;
			score[1]--;
			Arrays.sort(score);
			dif = score[2] - score[0];
		}
		
		if (score[0] < 0 || score[0] > 10 || score[1] < 0 || score[1] > 10 || score[2] < 0 || score[2] > 10 || dif > 2) {
			return -1;
		}
		
		//System.err.println("AFTER ARRANGE NUM "+T+": "+score[0]+" "+score[1]+" "+score[2]);
		
		if (score[2] >= P) {
			if (dif == 2) return 1;
			else return 0;
		}
		
		return -1;
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int N, S, P, used, can;
		
		for(int caseNo = 1;caseNo <= T; caseNo++) {
			N = in.nextInt();
			S = in.nextInt();
			P = in.nextInt();
			used = 0;
			can = 0;
			
			for(int i=0;i<N;i++) {
				int ret = solve(in.nextInt(), P);
				
				if (ret == 0) { // didint need surprise
					can++;
				} else if (ret == 1 && used < S) { // need surprise
					used++;
					can++;
				}
			}
			System.out.println("Case #"+caseNo+": "+can);
			
		}
	}
}