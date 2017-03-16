import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class ManageYourEnergy
{
	
	static int mostEnergy = 0;
	static int origE;
	static int E;
	static int regain;
	static int numActivities;
	static int [] values;
	static int totalValue;
	static int currentActivity;

	/** @param args
	 * @throws IOException 
	 */
	
	
	
	public static void recurse()
	{
		if (!(currentActivity < numActivities))
		{
			mostEnergy = Math.max(mostEnergy, totalValue);
			return;
		}
		
		
		
		for (int i = 0; i <= E; i++)
		{
			totalValue += i * values[currentActivity];
			//if (mostEnergy!=114)
			//System.out.println(currentActivity + " " + i + " " + mostEnergy + " " + E);
			int beforeE = E;
			E -= i;
			E = Math.min(origE,E+regain);
			currentActivity++;
			recurse();
			currentActivity--;	
			totalValue -= i * values[currentActivity];
			E = beforeE;
		}
	}
		
	
	public static void main(String[] args) throws IOException
	{

		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output.txt")));
		
		int numCases = in.nextInt();
		
		for (int testCase = 1; testCase <= numCases; testCase++)
		{
			 E = in.nextInt();
			 origE = E;
			 regain = in.nextInt();
			 numActivities = in.nextInt();
			 values = new int [numActivities];
			 totalValue = 0;
			 currentActivity = 0;
			
			for (int activity = 0; activity < numActivities; activity++)
				values[activity] = in.nextInt();
			
			recurse();
			
			out.println("Case #" + testCase + ": " + mostEnergy);
			mostEnergy = 0;
		}
		out.close();
	}

}
