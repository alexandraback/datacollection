import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numTestCases = Integer.valueOf(scanner.nextLine());
		for ( int i =0; i < numTestCases; i++ ) {
			String line = scanner.nextLine();
			Scanner lineScanner = new Scanner(line);
			int A = lineScanner.nextInt();
			int B = lineScanner.nextInt();
			line = scanner.nextLine();
			lineScanner = new Scanner(line);
			double[] p = new double[A];
			for ( int j =0; j < A; j++) {
				p[j] = lineScanner.nextDouble();
			}
			
			ArrayList<Double> expectations = new ArrayList<Double>();
			//Pres enter
			expectations.add((double) (B+2));
			double accumulateProb = 1;
			for (int n=A; n >= 0; n-- ) {
				double currExp = (1-accumulateProb)*(B+1) + (B-A+2*n+1); 
				expectations.add(currExp);
				if ( n == 0 ) break;
				accumulateProb *= p[A-n];
			}
			
			Collections.sort(expectations);
			
			System.out.printf("Case #%d: %f\n", i+1, expectations.get(0));
		}
		
	}
	
}
