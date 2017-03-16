package qualification;

import java.util.Scanner;

public class Dancing {
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int num = scan.nextInt();
		for(int i=0; i<num; i++)
		{
			int numOfGooglers = scan.nextInt();
			int numOfSurprizes = scan.nextInt();
			int score = scan.nextInt();
			int[] totalScores = new int[numOfGooglers];
			for(int j=0; j<numOfGooglers; j++)
				totalScores[j] = scan.nextInt();
			
			System.out.println("Case #" + (i+1) + ": " + solve(numOfSurprizes, totalScores, score));
			
		}
	}

	private static int solve(int numOfSurprizes, int[] totalScores, int score) {
		int count = 0;
		int surprisesLeft = numOfSurprizes;
		for(int i=0; i<totalScores.length; i++) {
			if(totalScores[i]/3 + (totalScores[i]%3 != 0 ? 1 : 0) >= score)
				count++;
			else if(surprisesLeft > 0) {
				if(totalScores[i] > 0 && (totalScores[i]/3 + (totalScores[i]%3 == 2 ? 2 : 0) >= score || totalScores[i]/3 + 1 >= score)) {
					count++;
					surprisesLeft--;
				}
			}
		}
		return count;
	}

}
