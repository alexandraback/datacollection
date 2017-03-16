package round1B_2014;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lottery {

	public static void main (String [] args) throws IOException{

		//Timing
		//long s = System.currentTimeMillis ();

		//Set up the reader and printer
		Scanner in = new Scanner (new File("IN.txt"));
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("OUT.txt")));
		int noCases = in.nextInt();
		
		//Solve the cases
		for (int caseNo = 1; caseNo <= noCases; caseNo++){
			
			int max1 = in.nextInt();
			int max2 = in.nextInt();
			int ticketNo = in.nextInt();
			int count = 0;
			for (int a = 0; a < max1; a++)
				for (int b = 0; b < max2; b++)
				{
					if ((a&b) < ticketNo)
						count++;
				}
			String answer = String.valueOf(count);
			out.println(String.format("Case #%d: %s", caseNo, answer));
			out.flush();//So I can see how my program is doing
		}

		//Close the files
		in.close();
		out.close();

		//Timing
		//long e = System.currentTimeMillis();
		//System.out.println((e - s) / 1000.0);

		//Terminate the program
		System.exit(0);

	} //Main method
}
