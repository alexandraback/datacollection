import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	static short[] boxTypes;
	static short[] toyTypes; 
	static long[] boxNumbers; 
	static long[] toyNumbers; 
	static long[] cumulativeToys;
	static long[] cumulativeBox;
	
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(System.in);
		int numTestCases = Integer.valueOf(scanner.nextLine());
		for ( int i =0; i < numTestCases; i++ ) {
			String line = scanner.nextLine();
			Scanner lineScanner = new Scanner(line);
			int N = lineScanner.nextInt();
			int M = lineScanner.nextInt();
			boxTypes = new short[N];
			toyTypes = new short[M];
			boxNumbers = new long[N];
			toyNumbers = new long[M];
			line = scanner.nextLine();
			lineScanner = new Scanner(line);
			for ( int j = 0; j < N; j++) {
				boxNumbers[j] = lineScanner.nextLong();
				boxTypes[j] = lineScanner.nextShort();
			}
			lineScanner.close();
			line = scanner.nextLine();
			lineScanner = new Scanner(line);
			for ( int j = 0; j < M; j++) {
				toyNumbers[j] = lineScanner.nextLong();
				toyTypes[j] = lineScanner.nextShort();
			}
			lineScanner.close();
			//Done reading.
			
			cumulativeToys = new long[M];
			cumulativeToys[M-1] = toyNumbers[M-1];
			for ( int j = M-2; j>= 0 ; j--) {
				cumulativeToys[j] = toyNumbers[j] + cumulativeToys[j+1];
			}
			cumulativeBox = new long[N];
			cumulativeBox[N-1] = boxNumbers[N-1];
			for ( int j = N-2; j>= 0 ; j--) {
				cumulativeBox[j] = boxNumbers[j] + cumulativeBox[j+1];
			}

			long totalUnits = 0;
			for ( int k = 0; k < N; k++ ) {
				if ( findToyRemaining(boxTypes[k]) == null) {
					boxNumbers[k] = 0;
					cumulativeBox[k] = 0;
					continue;
				}
				long maxRemaining = 0;
				int indexToUse = -1;
				for ( int j = k; j < N; j++ ) {
					Long boxRemaining = findToyRemaining(boxTypes[j]);
					if ( boxRemaining == null ) {
						boxNumbers[j] = 0;
						cumulativeBox[j] = 0;
						//No cigar
						continue;
					} else {
						long currRemaining = Math.min(boxRemaining, cumulativeBox[j]);
						if ( currRemaining > maxRemaining ) {
							maxRemaining = currRemaining;
							indexToUse = j;
						}
					}
				}
				int toyIndex= findToyNumber(boxTypes[indexToUse]);
				long numUsed = Math.min(boxNumbers[indexToUse], toyNumbers[toyIndex]);
				totalUnits += numUsed;
				
				boxNumbers[indexToUse] -=numUsed;
				cumulativeBox[indexToUse] -= numUsed;
				for ( int del = 0; del < toyIndex; del ++ ) {
					toyNumbers[del]	= 0;
					cumulativeToys[del] = 0;
				}
				toyNumbers[toyIndex] -= numUsed;
				cumulativeToys[toyIndex] -= numUsed;
				
				k = indexToUse-1;
				if ( boxNumbers[indexToUse] == 0 ) {
					k++;
				}
				
			}
			System.out.printf("Case #%d: %d\n", i+1, totalUnits);

		}
		scanner.close();
		
	}


	private static Integer findToyNumber(short boxType) {
		// TODO Auto-generated method stub
		for ( int i = 0; i < toyTypes.length; i++ ) {
			if ( boxType == toyTypes[i] && toyNumbers[i] > 0) {
				return i;
			}
		}
		return null;
		
	}


	private static Long findToyRemaining(short boxType) {
		Integer toyIndex = findToyNumber(boxType);
		
		return (toyIndex == null)? null : cumulativeToys[toyIndex];
	}
	
}
