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
			int numBlocks = input.nextInt();
			
			Vector<Double> myBlocksOriginal = new Vector<Double>();
			for(int i = 0; i < numBlocks; ++i)
			{
				myBlocksOriginal.add(input.nextDouble());
			}
			Collections.sort(myBlocksOriginal);
			
			Vector<Double> hisBlocksOriginal = new Vector<Double>();
			for(int i = 0; i < numBlocks; ++i)
			{
				hisBlocksOriginal.add(input.nextDouble());
			}
			Collections.sort(hisBlocksOriginal);
			
			Vector<Double> myBlocks = new Vector<Double>();
			Vector<Double> hisBlocks = new Vector<Double>();
			for(int i = 0; i < numBlocks; ++i)
			{
				myBlocks.add(myBlocksOriginal.get(i));
				hisBlocks.add(hisBlocksOriginal.get(i));
			}
			

			int cheatScore = 0;
			int normalScore = 0;
			
			//Cheat War
			//I say always win (if i can) so he plays the lowest
			while(myBlocks.size() > 0)
			{
				//If i have one thats higher than his lower play that
				int chosen = -1;
				for(int i = 0; i < myBlocks.size(); ++i)
				{
					if(myBlocks.get(i) > hisBlocks.get(0))
					{
						chosen = i;
						break;
					}
				}
				
				if(chosen != -1)
				{
					++cheatScore;
					myBlocks.remove(chosen);
					hisBlocks.remove(0);
				}
				else
				{
					myBlocks.remove(0);
					hisBlocks.remove(0);
				}
			}
			
			myBlocks = new Vector<Double>();
			hisBlocks = new Vector<Double>();
			for(int i = 0; i < numBlocks; ++i)
			{
				myBlocks.add(myBlocksOriginal.get(i));
				hisBlocks.add(hisBlocksOriginal.get(i));
			}
			
			//War
			//He picks closest highest one i pick smallest
			while(myBlocks.size() > 0)
			{
				int chosen = -1;
				for(int i = 0; i < hisBlocks.size(); ++i)
				{
					if(hisBlocks.get(i) > myBlocks.get(0))
					{
						chosen = i;
						break;
					}
				}
				
				//Play the winner
				if(chosen != -1)
				{
					hisBlocks.remove(chosen);
				}
				else//Play the lowest
				{
					hisBlocks.remove(0);
					++normalScore;
				}
				//Remove my lowest
				myBlocks.remove(0);
			}
			
			answerSheet.println("Case #" + caseNumber + ": " + cheatScore + " " + normalScore);
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

