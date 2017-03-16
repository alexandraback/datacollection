package tel.cj.cj2014.qualification;

import java.util.Arrays;
import java.util.Scanner;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Path;
import java.nio.file.Paths;

public class DeceitfulWar {
	/**This class is designed to solve Problem D: Deceitful War.
	 * @param Two arguments: Input filepath and output filepath.
	 * @throws IOException
	 * @author Telnaior
	 */
	public static void main(String[] args) throws IOException
	/**Controller method to set up input and output, then pass to problem-specific method.
	 * 
	 */
	{
		Path inputPath = Paths.get(args[0]);
		Scanner sc = new Scanner(inputPath);
		PrintStream output = new PrintStream(args[1]);
		System.setOut(output);
		run(sc);
		output.close();
	}
	static void run(Scanner sc)
	{
		//Like always, start by grabbing the number of test cases needed
		final int CASES = sc.nextInt();
		//Then establish our problem-solving loop
		for(int caseNumber=1; caseNumber<=CASES; caseNumber++)
		{
			//Grab the block count
			int blockCount = sc.nextInt();
			double[] naomiBlocks = new double[blockCount];
			double[] kenBlocks = new double[blockCount];
			//Then grab the actual block masses...
			for(int i=0; i<blockCount; i++)
			{
				naomiBlocks[i] = sc.nextDouble();
			}
			for(int i=0; i<blockCount; i++)
			{
				kenBlocks[i] = sc.nextDouble();
			}
			//And the key to it all, line them up from least to most!
			Arrays.sort(naomiBlocks);
			Arrays.sort(kenBlocks);
			//wow very super sorter much block many sort
			//Anyways, let's start reporting and send out methods to get our values.
			System.out.print("Case #"+caseNumber+": ");
			System.out.print(deceitfulScore(blockCount, naomiBlocks, kenBlocks));
			System.out.print(" ");
			System.out.println(standardScore(blockCount, naomiBlocks, kenBlocks));
		}
	}
	static int deceitfulScore(int blockCount, double[] naomiBlocks, double[] kenBlocks)
	{
		//Ironically, the deceitful logic is simpler than the simple logic.
		int points = 0;
		for(int i=0; i<blockCount; i++)
		{
			if(naomiBlocks[i]>kenBlocks[points])
			{
				points++;
			}
		}
		return points;
	}
	static int standardScore(int blockCount, double[] naomiBlocks, double[] kenBlocks)
	{
		int points = 0;
		for(int i=0; i<blockCount; i++)
		{
			if(naomiBlocks[blockCount-1-i]>kenBlocks[blockCount-1-i+points])
			{
				points++;
			}
		}
		return points;
	}
}
