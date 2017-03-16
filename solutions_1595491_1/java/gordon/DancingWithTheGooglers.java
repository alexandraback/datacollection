import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

// Qualification Round 2012
// Problem A

public class DancingWithTheGooglers {

	public static void main(String[] args) {
		Scanner sc = null;
		try {
			sc = new Scanner(new File("B-large.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		PrintStream output = null;

		try {
			output = new PrintStream(new File("B-large.out"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		int[][] maxScores = new int[31][2];

		for(int i = 0; i < 31; i++){
			maxScores[i][0] = (int) Math.round((i + 1) / 3.0);
			if(i < 2 || i > 28)
				maxScores[i][1] = -1;
			else
				maxScores[i][1] = (int) Math.round((i + 3) / 3.0);
		}
		
		int cases = sc.nextInt();
		sc.nextLine();

		for(int c = 0; c < cases; c++){
			int googlers = sc.nextInt();
			int surprises = sc.nextInt();
			int p = sc.nextInt();

			int count = 0;

			for(int s = 1; s <= googlers; s++){
				int score = sc.nextInt();
				
				if(maxScores[score][0] >= p)
					count++;
				else if (maxScores[score][1] >= p && surprises > 0){
					count++;
					surprises--;
				}
			}

			System.out.printf("Case #%d: %s\n", c + 1, count);
			output.printf("Case #%d: %s\n", c + 1, count);
		}

	}
}