import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class ProblemA {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new File("A-large.in"))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter("A-large.out"))) {
				int numCases = scanner.nextInt();
						
				StringBuilder builder = new StringBuilder();
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					builder.setLength(0);
	
					scanner.nextLine();
					int typed = scanner.nextInt();
					int length = scanner.nextInt();
					
					double[] pcorrect = new double[typed];
					
					scanner.nextLine();
					for(int idx = 0; idx < typed; idx++) {
						pcorrect[idx] = Double.parseDouble(scanner.next());
					}
					
					double knEnterNow = 1 + length + 1;
					
					double pWasGood = 1;
					for(double p : pcorrect) pWasGood *= p;
					
					double knKeepTyping = 
							(pWasGood * (length - typed + 1)) +
							((1 - pWasGood) * (2 * length - typed + 2));
					
					double min = Math.min(knEnterNow, knKeepTyping);
					for(int back = 1; back <= typed; back++) {
						int minNeeded = back + back + (length - typed) + 1;
						if(minNeeded > min) break;
						int maxNeeded = minNeeded + length + 1;
						
						double pGoodBefore = 1;
						for(int pi = 0; pi < typed - back; pi++) pGoodBefore *= pcorrect[pi];
						
						double knBack = 
								(pGoodBefore * minNeeded) + 
								((1 - pGoodBefore) * maxNeeded);
						min = Math.min(knBack, min);
					}
					
					builder.append(min);
					String caseOutput = String.format("Case #%d: %s", caseIdx + 1, builder.toString());
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}
			}
		} catch(Throwable scannerEx) {
			scannerEx.printStackTrace();
		}
	}

}
