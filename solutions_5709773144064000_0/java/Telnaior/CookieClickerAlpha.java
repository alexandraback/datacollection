package tel.cj.cj2014.qualification;

import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;

public class CookieClickerAlpha {

	/**This class is designed to solve Problem B: Cookie Clicker Alpha.
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
		final double initialCPS = 2.0; //It scales! (But it doesn't need to)
		//Like always, start by grabbing the number of test cases needed
		final int CASES = sc.nextInt();
		//Then establish our problem-solving loop
		for(int caseNumber=1; caseNumber<=CASES; caseNumber++)
		{
			//Grab our variables for this case
			double farmPrice = sc.nextDouble();
			double farmBoost = sc.nextDouble();
			double targetValue = sc.nextDouble();
			//And now to start calculating
			boolean keepGoing = true;
			int farmsToBuy = 0;
			double recordTime = -1;
			//Loop control variables declared, so let's go
			while(keepGoing)
			{
				//Initialise more variables (They're all needed, I swear!)
				int farmsLeft = farmsToBuy;
				double timeTaken = 0.0;
				double cookiesPerSecond = initialCPS;
				//Loop farm purchases
				while(farmsLeft > 0)
				{
					timeTaken += (farmPrice/cookiesPerSecond);
					cookiesPerSecond += farmBoost;
					farmsLeft--;
				}
				//We've got all the farms we want, shoot for the goal
				timeTaken += (targetValue/cookiesPerSecond);
				//If this is our first run or we beat the record, set the record
				if(recordTime==-1 || timeTaken<recordTime)
				{
					recordTime = timeTaken;
					farmsToBuy++;
				}
				//If we didn't then we're never going to again, so stop looping
				else
				{
					keepGoing = false;
				}
			}
			//Right, we've finished calculating, so report our best time!
			System.out.print("Case #"+caseNumber+": ");
			System.out.println(recordTime);
		}
	}
}
