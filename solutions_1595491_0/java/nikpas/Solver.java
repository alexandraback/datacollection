import java.util.ArrayList;
import java.util.Collections;

public class Solver {
	int S;
	int p;
	ArrayList<Integer> scores;

	Solver(int S, int p, ArrayList<Integer> scores) {
		this.S = S;
		this.p = p;
		this.scores = scores;
	}

	static int getMaxScoreNoSuprise(int n) {
		int base = n / 3 - 1;
		if (base < 0)
			base = 0;

		int max = 0;
		for (int i = base; i <= base + 3; i++)
			for (int j = base; j < base + 3; j++)
				for (int k = base; k < base + 3; k++) {
					if (Math.abs(i - j) <= 1 && Math.abs(i - k) <= 1
							&& Math.abs(j - k) <= 1 && (i + j + k) == n) {
						max = Math.max(max, Math.max(i, Math.max(j, k)));
					}

				}
		return max;

	}

	static int getMaxScoreWithSuprise(int n) {
		int base = n / 3 - 1;
		if (base < 0)
			base = 0;

		int max = 0;
		for (int i = base; i <= base + 4; i++)
			for (int j = base; j < base + 3; j++)
				for (int k = base; k < base + 3; k++) {
					if (Math.abs(i - j) <= 2 && Math.abs(i - k) <= 2
							&& Math.abs(j - k) <= 2 && (i + j + k) == n) {
						max = Math.max(max, Math.max(i, Math.max(j, k)));
					}

				}
		return max;
	}

	int solve() {
		
		Collections.sort(scores);
		
//		for(int score : scores)
	//		System.out.println(getMaxScoreNoSuprise(score) + " " + getMaxScoreWithSuprise(score));
		
		int surprises =0 ;
		for(int i=0;i<scores.size();i++)
		{
			if (surprises < S  && getMaxScoreWithSuprise(scores.get(i)) >= p && getMaxScoreNoSuprise(scores.get(i))<p ) //count only useful surprises
				surprises++;			
		}
		
		int pScores = 0;
		 
		for(int i=0;i<scores.size();i++)
		{
			if (getMaxScoreNoSuprise(scores.get(i))>=p )
				pScores++;			
		}
		
		return surprises + pScores;
	}

}
