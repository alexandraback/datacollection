
import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;

public class Password
{
	public static void main(String[] args)
	{
		try
		{
			Scanner s = new Scanner(new File("password.in"));
			BufferedWriter w = new BufferedWriter(new FileWriter(new File("password.out")));
			int numCases = s.nextInt();
			s.nextLine();
			
			for(int n = 1;n <= numCases; n++)
			{
				int A = s.nextInt();
				int B = s.nextInt(); //total
				int C = B - A; //remaining
				double[] probs = new double[A];
				for(int k = 0; k < A; k++)
					probs[k] = s.nextDouble();
					
				double[] allCorrect = new double[A];
				allCorrect[0] = probs[0];
				for(int k = 1; k < A; k++)
					allCorrect[k] = probs[k] * allCorrect[k-1];
					
				double enterRightAway = B + 2;
				System.out.println(enterRightAway);
				double[] expectedCountAfterNBackspaces = new double[A];
				for(int numBackspaces = 0; numBackspaces < A; numBackspaces++) //A backspaces is never optimal.  Can always hit enter
				{
					double probCorrect = allCorrect[A-numBackspaces-1];
					double probWrong = 1 - probCorrect;
					expectedCountAfterNBackspaces[numBackspaces] = probCorrect * ( (2 * numBackspaces) + C + 1) +
																probWrong * ( (2 * numBackspaces) + C + 1 + B + 1);
				}
				double minExpectedCount = enterRightAway;
				for(int k = 0; k < A; k++)
					if(expectedCountAfterNBackspaces[k] < minExpectedCount)
						minExpectedCount = expectedCountAfterNBackspaces[k];
				
				
				w.write("Case #" + n + ": " + minExpectedCount + "\n");
			}
			
			w.flush();
			w.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
	

}