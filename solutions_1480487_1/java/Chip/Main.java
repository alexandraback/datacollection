import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(System.in);
		int numTestCases = Integer.valueOf(scanner.nextLine());
		for ( int i =0; i < numTestCases; i++ ) {
			String line = scanner.nextLine();
			Scanner lineScanner = new Scanner(line);
			int N = lineScanner.nextInt();
			int[] numbers = new int[N];
			int sum = 0;
			int minIndex = 0;
			HashSet<Integer> minNumbers = new HashSet<Integer>();
			for ( int j = 0; j < N; j++ ) {
				numbers[j] = lineScanner.nextInt();
				if ( numbers[j] < numbers[minIndex]) {
					minIndex = j;
					minNumbers = new HashSet<Integer>();
					minNumbers.add(j);
				} else if ( numbers[j] == numbers[minIndex] ) {
					minNumbers.add(j);
				}
				sum+= numbers[j];
			}
			
			lineScanner.close();
			
			double[] answers = new double[N];
			System.out.printf("Case #%d:", i+1);
			double addConst = 100.0d;
			while ( addConst > 0.0d ) {
				HashSet<Integer> currMinNums = new HashSet<Integer>();
				int currMinIndex = -1;
				for ( int j=0; j < N; j++  ) {
					if ( !minNumbers.contains(j) ) {
						if (  currMinIndex == -1 || numbers[j] < numbers[currMinIndex] ) {
							currMinNums = new HashSet<Integer>();
							currMinIndex = j;
							currMinNums.add(j);
						} else if ( numbers[j] == numbers[currMinIndex] ) {
							currMinNums.add(j);
						}
					}
				}
				
				if ( currMinIndex == -1 ) {
					//Already at max
					for ( Integer indexes : minNumbers ) {
						answers[indexes] += addConst/minNumbers.size();
					}		
					break;
				}
 				//How much to add?
				double toAdd = ((numbers[currMinIndex]-numbers[minIndex])*100.0*minNumbers.size())/sum;
				//Do I have that much? 
				if ( toAdd > addConst) {
					//Add what I have
					for ( Integer indexes : minNumbers ) {
						answers[indexes] += addConst/minNumbers.size();
					}		
					break;
				} else {
					//Add it.
					for ( Integer indexes : minNumbers ) {
						answers[indexes] += toAdd/minNumbers.size();
					}
					addConst -=toAdd;
				}
				//Now all are upto currMinIndex
				minNumbers.addAll(currMinNums);
				minIndex = currMinIndex;	
			}
			
		
			for ( int j = 0; j<N; j++) {
				System.out.printf(" %f", answers[j]);
			}
			
			System.out.printf("\n");
		}
		scanner.close();
		
	}
	
}
