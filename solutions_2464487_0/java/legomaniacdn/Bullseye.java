import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Bullseye
{

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException
	{
		// ///////////////////////////////////////////////////////////////////
		long start = System.nanoTime();
		// ///////////////////////////////////////////////////////////////////
		//Scanner inFile = new Scanner(new File("p1.txt"));
		 Scanner inFile = new Scanner(new File("A-small-attempt0.in"));
		// Scanner inFile = new Scanner(new File("A-Large.in"));
		PrintWriter out = new PrintWriter("p1out.txt");
		int numberOfTimes = inFile.nextInt();

		for (int times = 1; times <= numberOfTimes; times++)
		{
			long radius = inFile.nextLong();
			long paint = inFile.nextLong();
			long paintUsed =2*radius+1;
			int noOfRings=0;
			while (paintUsed <= paint)
			{
				paint-=paintUsed;
				radius+=2;
				paintUsed=2*radius+1;
				noOfRings++;
			}
			System.out.println("Case #"+times+" "+noOfRings);
			out.println("Case #"+times+": "+noOfRings);
		}
		inFile.close();
		out.close();
		// ///////////////////////////////////////////////////////////////////
		long stop = System.nanoTime();
		System.out.printf("Run time: %.1f ms%n", (stop - start) / 1000000.0);
		System.out.println("End of Program");
		// ///////////////////////////////////////////////////////////////////

	}

}
