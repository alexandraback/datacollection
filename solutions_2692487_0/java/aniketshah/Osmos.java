import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Osmos {

	public static int changesNeededToPassLevel(double myMote, int[] otherMotes, int changesMade)
	{
		Arrays.sort(otherMotes);
		for(int i=0; i<otherMotes.length; i++)
		{
			if (otherMotes[i] < myMote)
			{
				// Gobble and go on
				myMote += otherMotes[i];
			}
			else
			{
				// Find out whether this is the last element?
				if (i == otherMotes.length - 1)
				{
					changesMade++;
				}
				else
				{
					// Edge case
					if(myMote == 1 || myMote == 0)
					{
						changesMade = changesMade + (otherMotes.length - i);
						break;
					}
					else
					{
						// Compare cost of removing all of them
						// .. and gobbling + going on
						int costToRemoveAll = (otherMotes.length - i);
						int costToGobbleNode = 0;
						double myMoteCopy = myMote;
						
						// Continue changing until it can gobble again
						while (myMoteCopy <= otherMotes[i])
						{
							myMoteCopy = myMoteCopy + (myMoteCopy - 1);
							costToGobbleNode++;
						}
						
						int[] otherMotesCopy = Arrays.copyOfRange(otherMotes, i+1, otherMotes.length);
						int costToCoverOtherNodes = changesNeededToPassLevel(myMoteCopy + otherMotes[i], otherMotesCopy, 0);
						if (costToRemoveAll < costToGobbleNode + costToCoverOtherNodes)
						{
							changesMade = changesMade + costToRemoveAll;
							break;
						}
						else
						{
							changesMade = changesMade +  costToGobbleNode + costToCoverOtherNodes;
							break;
						}			
					}			
					
				}
			}
		}
		return changesMade;
	}
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
//		int[] otherMotes= {2,1};
//		System.out.println(changesNeededToPassLevel(2, otherMotes));
//		int [] otherMotes2 = {25, 20, 9, 100};
//		System.out.println(changesNeededToPassLevel(10, otherMotes2));
//		int [] otherMotes3 = {2, 1, 1, 6};
//		System.out.println(changesNeededToPassLevel(2, otherMotes3));
//		int [] otherMotes4 = {1, 1, 1, 1};
//		System.out.println(changesNeededToPassLevel(1, otherMotes4));
		BufferedReader in
		   = new BufferedReader(new FileReader("/Users/aniket/Desktop/A-small-attempt3.in.txt"));
		PrintWriter out
		   = new PrintWriter(new BufferedWriter(new FileWriter("/Users/aniket/Desktop/A-small-attempt3.out.txt")));
		int caseCounter = 1;
		String line = null;
		double myMote = 0;
		int lineNumber = 0;
		boolean ignoreFirstLine = true;
		int[] otherMotes = null;
		while( (line = in.readLine()) != null)
		{
			if(ignoreFirstLine)
			{
				ignoreFirstLine = false;
				continue;
			}
			lineNumber ++;
			line = line.trim();
			if (lineNumber % 2 == 0)
			{
				String[] otherMotesRaw = line.split(" ");
				otherMotes = new int[otherMotesRaw.length];
				for (int i = 0; i< otherMotesRaw.length; i++)
				{
					otherMotes[i] = Integer.parseInt(otherMotesRaw[i]);
				}
				out.write("Case #" + Integer.toString(caseCounter) + ": " + Integer.toString(changesNeededToPassLevel(myMote, otherMotes, 0)) + "\n");
				caseCounter ++;	
			}
			else
			{
				myMote = Double.parseDouble(line.split(" ")[0]);
			}
		}
		in.close();
		out.flush();
		out.close();
		System.out.println("Program completed successfully!");
	}

}
