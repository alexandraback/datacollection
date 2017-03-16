import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;

public class A 
{
	public static void main(String[] args) throws Exception
	{
		new A().solve();
	}

	private void solve() throws Exception 
	{
		String inputFile = new String("A-large");
		Scanner in = new Scanner(new File(inputFile));
		PrintWriter out = new PrintWriter(new FileWriter(inputFile+".out"),true);
		
		int numCases = in.nextInt();
		int[]scores;
		int numContestants;
		for(int t=1; t<= numCases; t++)
		{
			numContestants = in.nextInt();
			scores = new int[numContestants];
			int sum = 0;
			for (int i = 0; i < numContestants; i++)
			{
				scores[i] = in.nextInt();
				sum += scores[i];
			}
			
			out.print("Case #" + t + ":");
			System.out.print("Case #" + t + ":");
			DecimalFormat sixDForm = new DecimalFormat("#.######");
			int numRequired = numContestants;
			double addTo = 0;
			for (int i = 0; i < numContestants; i++)
			{
				double scoreNeeded=(2/(double)numContestants) - (double)scores[i]/(double)sum;
				if(scoreNeeded < 0)
				{
					addTo += scoreNeeded;
					numRequired--;
				}
			}
			
			addTo /= numRequired;
			
			for (int i = 0; i < numContestants; i++)
			{
				double scoreNeeded=(2/(double)numContestants) - (double)scores[i]/(double)sum;
				if(scoreNeeded < 0)
					scoreNeeded=0;
				else
					scoreNeeded+=addTo;
				scoreNeeded*=100;
				scoreNeeded = Double.valueOf(sixDForm.format(scoreNeeded));
				out.print(" "+scoreNeeded);
				System.out.print(" "+scoreNeeded);
			}
			out.println();
			System.out.println();
		}
		in.close();
		out.close();
	}
}
