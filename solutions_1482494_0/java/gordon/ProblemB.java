import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

// Round 1A 2012
// Problem B

public class ProblemB {

	public static final String file = "B-small";

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File(file + ".in"));
		PrintStream output = new PrintStream(new File(file + ".out"));

		int cases = sc.nextInt();

		for(int c = 0; c < cases; c++){
			int levels = sc.nextInt();
			int[][] details = new int[levels][2];
			boolean[][] complete = new boolean[levels][2];
			int levelsCompleted = 0;

			for(int l = 0; l < levels; l++){
				details[l][0] = sc.nextInt();
				details[l][1] = sc.nextInt();
			}

			int count = 0;
			int stars = 0;

			while(true){
				int best = -1;
				for(int l = 0; l < levels; l++){
					if(details[l][1] <= stars && !complete[l][1])
						best = l;
				}
				if(best != -1){
					if(complete[best][0])
						stars++;
					else
						stars += 2;
					complete[best][0] = true;
					complete[best][1] = true;
					levelsCompleted++;
					count++;
					continue;
				}

				for(int l = 0; l < levels; l++){
					if(details[l][0] <= stars && !complete[l][0]){
						if(best == -1)
							best = l;
						else if(details[l][1] > details[best][1])
							best = l;
					}
				}
				if(best != -1){
					stars++;
					count++;
					complete[best][0] = true;
					continue;
				}

				break;
			}

			if(levelsCompleted == levels){
				System.out.printf("Case #%d: %s\n", c + 1, count);
				output.printf("Case #%d: %s\n", c + 1, count);
			}
			else{
				System.out.printf("Case #%d: Too Bad\n", c + 1);
				output.printf("Case #%d: Too Bad\n", c + 1);
			}
		}

	}
}