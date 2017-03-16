package googlecodejam;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class BullsEye {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		Scanner k = new Scanner(System.in);

		int T = k.nextInt();
		k.nextLine();
		
		String[] solution = new String[T];
		
		for (int x = 1; x <= T; x++)
		{
			long radius = k.nextLong();
			long mL = k.nextLong();
			k.nextLine();
			//1 mL = pi sq units
			
			long subtractBy = (radius)*2 + 1;
			
			long rings = 0;
			while (mL > 0)
			{
				mL -= subtractBy;
				subtractBy += 4;
				if (mL >= 0)
					rings++;
			}
			
			solution[x-1] = "Case #" + x + ": " + rings;
		}
		printOutAnswers(solution);
	}
	public static void printOutAnswers(String[] solution) throws IOException
	{
		//print out caseStorer and write to a file
		PrintWriter out = new PrintWriter(new FileWriter("/Users/davidlong"+
		"/Desktop/javaoutputs/BullsEye.txt"));
		
		for (int x = 0; x < solution.length; x++)
		{
			out.println(solution[x]);
			System.out.println(solution[x]);
		}
		
		out.close();
	}
}
