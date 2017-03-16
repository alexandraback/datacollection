import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

// Round 1A 2012
// Problem A

public class ProblemA {

	public static final String file = "A-small";
	
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File(file + ".in"));
		PrintStream output = new PrintStream(new File(file + ".out"));
		
		int cases = sc.nextInt();
		
		for(int c = 0; c < cases; c++){
			int typed = sc.nextInt();
			int length = sc.nextInt();
			
			double[] prob = new double[typed];
			for(int p = 0; p < typed; p++)
				prob[p] = sc.nextDouble();
			
			int giveUp = length + 2;
			
			int combos = (int) Math.pow(2, typed);
			
			int[][] expected = new int[combos][typed + 1];
			double[] pwProb = new double[combos];
			for(int i = 0; i < combos; i++){
				String bin = Integer.toBinaryString(i);
				while(bin.length() < typed)
					bin = "0" + bin;

				pwProb[i] = 1;
				int firstIncorrect = -1;
				for(int j = 0; j < typed; j++){
					if(bin.charAt(j) == '1')
						pwProb[i] *= prob[j];
					else{
						if(firstIncorrect == -1)
							firstIncorrect = j;
						pwProb[i] *= 1 - prob[j];
					}
				}
				for(int j = 0; j <= typed; j++){
					if(firstIncorrect < typed - j && firstIncorrect != -1)
						expected[i][j] = j * 2 + length - typed + giveUp;
					else
						expected[i][j] = j * 2 + length - typed + 1;
				}
			}
			
			double[] overallE = new double[typed + 1];
			double minE = giveUp;
			for(int e = 0; e <= typed; e++){
				for(int i = 0; i < combos; i++){
					overallE[e] += expected[i][e] * pwProb[i];
				} 
				minE = Math.min(overallE[e], minE);
			}
						
			System.out.printf("Case #%d: %6f\n", c + 1, minE);
			output.printf("Case #%d: %6f\n", c + 1, minE);
		}

	}
}