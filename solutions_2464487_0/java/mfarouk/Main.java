package jam;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("in.in"));
		PrintStream ps = new PrintStream("out.out");

		// loop for the number of test cases
		int T = Integer.parseInt(s.nextLine());

		for (int z = 1; z <= T; z++) {
			ps.print("Case #" + z + ": ");

			
			int r=0; int t=0;
			r = s.nextInt();
			t = s.nextInt();
			
			int count = 0;
			int totalused = 0;
			
			while(totalused < t)
			{
				//if(totalused / t == 0) break;
				totalused += Math.pow(r+1, 2)-Math.pow(r, 2) ; 
				count++;
				r+=2;
			}
			if(totalused > t) count--;
			ps.println(count);
		}

	}

	

}



