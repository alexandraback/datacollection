import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class ProblemB {

	public static void main(String[] args) {
		try (BufferedReader reader = new BufferedReader(new FileReader("B-small.in"))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter("B-small.out"))) {
				String line = reader.readLine();
				int numCases = Integer.parseInt(line);
				
				Scanner scanner;
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					scanner = new Scanner(reader.readLine());
					
					int N = scanner.nextInt(); 	// number of Googlers
					int S = scanner.nextInt(); 	// number of suprising triplets
					int p = scanner.nextInt(); 	// point limit - maximum number of Googlers who could have had the best result of p
					
//					System.out.println(String.format("Case #%d: N_%d S_%d p_%d", caseIdx+1, N, S, p));
					
					int[] t = new int[N];		// total points of Googlers
					for(int idx = 0; idx < N; idx++) {
						t[idx] = scanner.nextInt();
					}
					
					// not suprising : 0 1 29 30
					
					// 2  - 0 0 2 | 3  - 0 1 2 | 4  - 0 2 2
					// 5  - 1 1 3 | 6  - 1 2 3 | 7  - 1 3 3
					// 8  - 2 2 4 | 9  - 2 3 4 | 10 - 2 4 4
					// 11 - 3 3 5 | ...
					// suprising formula: s_max(x) - (x+1)/3+1
					
					// 2  - 0 1 1 | 3  - 1 1 1 | 4  - 1 1 2
					// 5  - 1 2 2 | 6  - 2 2 2 | 7  - 2 2 3
					// 8  - 2 3 3 | 9  - 3 3 3 | 10 - 3 3 4
					// 11 - 3 4 4 | 12 - 4 4 4 | ...
					// unsuprising formula: us_max(x) - (x-1)/3+1
					
					int possibleNotSuprising 	= 0;
					int possibleSuprising 		= 0;
					
					for(int idx = 0; idx < N; idx++) {
//						int max; boolean suprising = false;
						
						int ti = t[idx];
						int us_max = ti < 2 ? ti : Math.min(10, (ti - 1) / 3 + 1);
						if(us_max >= p) {
							possibleNotSuprising++; 
//							max = us_max;
						} else {
							int s_max = ti < 2 ? ti : Math.min(10, (ti + 1) / 3 + 1);
//							max = s_max; suprising = true;
							
							if(s_max >= p) {
								if(ti < 2 || ti > 28) 	possibleNotSuprising++;
								else					possibleSuprising++;
							}
						}
						
//						System.out.println(String.format("Case #%d: G_%d Total_%d Max_%d S?", caseIdx+1, idx+1, ti, max) + Boolean.toString(suprising));
					}
					
					int result = possibleNotSuprising + Math.min(S, possibleSuprising);
					
					String caseOutput = String.format("Case #%d: %d", caseIdx + 1, result);
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}
			}
		} catch(IOException ioEx) {
			ioEx.printStackTrace();
		}
	}

}
