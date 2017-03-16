import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Bullseye
{

	/** @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output.txt")));
		
		int numCases = in.nextInt();
		
		for (int testCase = 1; testCase <= numCases; testCase++)
		{
			int r = in.nextInt();
			int mili = in.nextInt();
			
			int numBlacks = 0;
			
			for (numBlacks = 0; mili >= 0; numBlacks++)
			{
				mili -= ((r+1)*(r+1)-r*r);
				r+=2;
			}
			
			out.println("Case #" + testCase + ": " + (numBlacks-1));
			
			
		}
		out.close();
		
		
		
		

	}

}
