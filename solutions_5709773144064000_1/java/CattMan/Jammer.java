import java.util.*;
import java.io.*;

public class Jammer
{
	public Jammer(){};
	
	/**Jams and does the problem*/
	public void jam(Scanner input, PrintWriter answerSheet)
	{
		//Extract the test cases
		int numCases = input.nextInt();
		input.nextLine();
		String data;
		
		
		for(int caseNumber = 1; caseNumber <= numCases; ++caseNumber)
		{
			double farmCost = input.nextDouble();
			double farmInput = input.nextDouble();
			double cookieGoal = input.nextDouble();
			
			double time = 0.0;
			double rate = 2.0;
			while(true)
			{
				//Whats quicker?
				//Buy a farm?
				if((farmCost / rate +  (cookieGoal / (rate + farmInput)) < cookieGoal / rate))
				{
					time += farmCost / rate;
					rate += farmInput;
				}
				else//Wait it out?
				{
					time += cookieGoal / rate;
					break;
				}
			}
			
			answerSheet.println("Case #" + caseNumber + ": " + time);
		}
	}
	
	/** Entry Point. Opens the input file passes it to the jammer.*/
	public static void main(String[] args)
	{
		//Open current directory
		File directory = new File(".");
		
		//Get the newest in file
		
		//Latest file so far
		int latestFileId = -1;
		File[] files = directory.listFiles();
		for(int i = 0; i < files.length; ++i)
		{
			if(files[i].isFile() &&//If we have a file 
			   files[i].getName().endsWith(".in") && // and its an in file
			   (latestFileId == -1 || files[i].lastModified() > files[latestFileId].lastModified()))//And its the newest file)
			{
				latestFileId = i;
			}
		}
		
		if(latestFileId == -1)
		{
			System.out.println("No File!");
			return;
		}
		
		//Get the latest file and pass it in as well as the answer sheet
		Jammer jammer = new Jammer();
		Scanner input;
		PrintWriter output;//Where to write the answer
		try
		{
			input = new Scanner(files[latestFileId]);
			output = new PrintWriter("out.txt", "UTF-8");
		}
		catch(Exception e)
		{
			System.out.println("BAIL! File not found!");
			return;
		}
		jammer.jam(input, output);
		input.close();
		output.close();
	}
};

