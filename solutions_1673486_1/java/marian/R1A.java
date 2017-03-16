package jam2012;
import java.io.*;
import java.util.*;
import java.text.*;

// Marian G Olteanu
public class R1A
{
	public static void main(String[] args)
	throws Exception
	{
		BufferedReader inputFile = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
		int cases = Integer.parseInt(inputFile.readLine());
		
		PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
		for (int i = 1; i <= cases; i++)
		{
			String lineT[] = tokenize(inputFile.readLine());
			int A = Integer.parseInt(lineT[0]);
			int B = Integer.parseInt(lineT[1]);
			String lineA[] = tokenize(inputFile.readLine());
			double[] prob = new double[A];
			for (int j = 0; j < A; j++)
				prob[j] = Math.log(Double.parseDouble(lineA[j]));
			
			double[] cummulatedProb = new double[A];
			cummulatedProb[0] = prob[0];
			for (int j = 1; j < cummulatedProb.length; j++)
				cummulatedProb[j] = cummulatedProb[j-1] + prob[j];
			
			double costMin = 2 + B;// enter, password, enter
			int bestJ = -1;
			for (int j = 0; j < A; j++)
			{
				if (Double.parseDouble(lineA[j]) == 0)
					break;
				
				int costBackspace = (A - j - 1);
				int costRest = (B - j - 1) + 1;// last 1: enter
				double probFailure = 1 - Math.exp(cummulatedProb[j]);
				double costHere =  costBackspace + costRest + (B + 1) * probFailure;
				if (costHere < costMin)
				{
					costMin = costHere;
					bestJ = j;
				}
			}
			
			
			String out = formatDouble(costMin, "0.000000");
			
			outFile.println("Case #" + i + ": " + out);
		}
		
		
		outFile.close();
		inputFile.close();
	}
	
	
	
	
	public static String[] tokenize(String input)
	{
		StringTokenizer st = new StringTokenizer(input);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	public static String[] tokenize(String input, String sep)
	{
		StringTokenizer st = new StringTokenizer(input , sep);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	
	
	public static String formatDouble(double myDouble , String format)
	{
		DecimalFormat dfFormat = new DecimalFormat(format);
		FieldPosition f = new FieldPosition(0);
		StringBuffer s = new StringBuffer();
		dfFormat.format(myDouble, s, f);
		return s.toString();
	}
}

