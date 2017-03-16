import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;


public class RecycledNumbers {

	
	public static void main(String[] args) throws FileNotFoundException {

		// ////////////////////////////////////
		// Begin Code Jam regular code //
		// ////////////////////////////////////

		Scanner inFile = new Scanner(new File("C-large.in"));
		PrintStream outFile = new PrintStream(new File("C-large-out.txt"));

		int numCases = inFile.nextInt();
		inFile.nextLine(); // Gets rid of newline char

		// ////////////////////////////////////
		// End Code Jam regular code //
		// ////////////////////////////////////

		for (int i = 1; i <= numCases; i++) {
			int A = inFile.nextInt();
			int B = inFile.nextInt();
			
			int recycleCount = 0;
			for(int n = A; n < B; n++) {
				HashSet<Integer> recycled = new HashSet<Integer>();
				for(int j=1; j<numDigits(n); j++) {
					int shifted = shiftNumPlaces(n,j);
					if(shifted <= B && shifted > n && numDigits(shifted) == numDigits(n) && !recycled.contains(Integer.valueOf(shifted))) {
						recycleCount++;
						recycled.add(Integer.valueOf(shifted));
						//System.out.println("recycled (" + n + "," + shifted + ")");
					} else {
						//System.out.println("skipped (" + n + "," + shifted + ")");
					}
				}
			}
			printCase(outFile, i, recycleCount);
		}
	}
	
	
	private static void printCase(PrintStream outStream, int i, int n) {
		outStream.println("Case #" + i +": " + n);
	}
	
	
	private static int numDigits(int n) {
		int count = 0;
		while(n != 0) {
			n = n / 10;
			count++;
		}
		return count;
	}
	
	
	private static int shiftNumPlaces(int n, int shiftAmount) {
		//String numStr = Integer.toString(n);
		String savedDigits = "";
		for(int i=0; i<shiftAmount; i++) {
			savedDigits = (n%10) + savedDigits;
			n = n / 10;
		}
		String shifted = savedDigits + n;
		return Integer.parseInt(shifted);
	}

}
