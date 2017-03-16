import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.HashSet;
import java.util.Set;


public class Password {

	
	public static void main(String [] args) throws NumberFormatException, IOException
	{

		BufferedReader in = new BufferedReader(new StringReader(args[0]));
		int rows = Integer.parseInt(in.readLine());
		for ( int i = 1; i <= rows; i++)
		{
			String line = in.readLine();
			String[] vals = line.split(" ");
			int charsTyped = Integer.parseInt(vals[0]);
			int totalChars = Integer.parseInt(vals[1]);
			
			line = in.readLine();
			vals = line.split(" ");
			
			double [] probs = new double[charsTyped];
			for ( int j=0; j < charsTyped; j++)
			{
				probs[j]=Double.parseDouble(vals[j]);
			}
			
			double [] cumProb = new double[charsTyped+1];
			cumProb[0]=1.0;
			for ( int j=1; j <= charsTyped; j++ )
			{
				cumProb[j]=cumProb[j-1]*probs[j-1];
			}
			
			double [] keystrokes = new double[charsTyped+2];
			

			double startOver = 1 + //enter
					totalChars + 1; //doing it again

			double min = startOver;
			for ( int j = 0; j <=charsTyped; j++ )
			{
				keystrokes[j] = j + //backspaces
						(totalChars - (charsTyped-j) ) // remaining chars
						+ 1 // enter
						+ ((1-cumProb[charsTyped-j])*(totalChars+1)) // chance of doing it all again
						;
				if ( keystrokes[j] < min )
				{
					min = keystrokes[j];
				}
			}
			
			
			System.out.println("Case #"+i+": " + min);
			
			
		}
	}
	
	
}
