import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class PasswordFix 

{
	public static void main(String[] args) 
	{
		Scanner scan = null;
		try
		{
			scan = new Scanner(new File(args[0]));
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found!");
			return;
		}
		if (!scan.hasNext())
		{
			System.err.println("Nothing in File!");
			return;
		}
		int testCases = Integer.parseInt(scan.nextLine());
		int typed;
		int total;
		double enter;
		double keepGoing;
		double probAllRight;
		double lowest;
		int caseNum = 1;
		while (scan.hasNext())
		{
			typed = scan.nextInt();
			total = scan.nextInt();
			lowest = 0;
			probAllRight = 1;
			double[] probs = new double[typed];
			for (int i = 0; i < typed; i++)
			{
				probs[i] = scan.nextDouble();
				probAllRight = probs[i] * probAllRight;
			}
			keepGoing = (probAllRight * (total - typed) + 1) + ((1.0-probAllRight) * (total+ 2 + (total - typed)));
			enter = 2 + total;
			if (keepGoing < enter)
			{
				lowest = keepGoing;
			}
			else
			{
				lowest = enter;
			}
			double backspace;
			double right;
			for (int back = 1; back < typed; back++)
			{
				right = 1;
				for (int x = 0; x < typed; x++)
				{
					if(x < typed - back)
					{
						right = right * probs[x];
					}
					else
					{
						right = right * (1 - probs[x]);
					}
				}
				backspace = ((probAllRight + right) * (back + back + (total - typed) + 1)) + (((1-probAllRight) - right) * (2 + total + back + back + (total-typed)));
				if (backspace < lowest)
				{
					lowest = backspace;
				}
				back++;
			}
			System.out.print("Case #" + caseNum  + ": " + lowest);
			if(caseNum != testCases)
			{
				System.out.println();
			}
			caseNum++;
		}
	}

}
