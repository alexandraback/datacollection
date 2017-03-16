package gcj;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;



public class A {

	private Integer solve(Scanner in) {
		int mySize = in.nextInt();
		int noOfMotes = in.nextInt();
		
	
		int[] motes = new int[noOfMotes];
		for (int i = 0; i< noOfMotes; i++) {
			motes[i] = in.nextInt();
			
		}
		
		if (mySize <= 1) {
			return noOfMotes;
		}
		
		Arrays.sort(motes);

		int result =go(motes,  noOfMotes, mySize, 0, 0);
		
		return result;
		
	}
	
	public int go(int[] motes, int noOfMotes, int mySize, int position, int currentScore) {
		if (currentScore > noOfMotes) {
			return 1000;
		}
		if (mySize > motes[noOfMotes - 1]) {
			return 0;
		}
		
		while (position < noOfMotes && motes[position] < mySize ) {
			mySize += motes[position];
			position++;
		}	// jemy do oporu
			
		if (position == noOfMotes) {	// jezli zjedlismy wszystko to zwracamy ilosc zmian
			return 0;
		}
		
		/// jezeli nie
		int motesLeft = noOfMotes - position;
		// mnozmy sie i sprawdzamy co dalej
		mySize += (mySize - 1);
		int mateScore = 1 + go(motes, noOfMotes, mySize, position, currentScore + 1);
		
		return (mateScore < motesLeft ? mateScore : motesLeft);
	}
	
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args)  throws FileNotFoundException{
		
		Scanner in = new Scanner(new File("dane\\in"));
	    PrintWriter out = new PrintWriter("dane\\out");
		
		
	    in.useLocale(Locale.US);
	    int T = in.nextInt();
	    in.nextLine();
	    //System.out.println("T "+T);
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
      //      System.out.println(s);
        }
        out.close();
	}

}

