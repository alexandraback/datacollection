import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class ProbA
{


	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer myTokens = new StringTokenizer(in.readLine());
		
		int T = Integer.parseInt(myTokens.nextToken());
		
		for (int i=0; i<T; i++)
		{
			myTokens = new StringTokenizer(in.readLine());
			
			String x = myTokens.nextToken();
			
			String myLast = "" + x.charAt(0);
			
			for (int j=1; j<x.length(); j++)
			{
				if (x.charAt(j)-myLast.charAt(0) >= 0)//myLast.charAt(myLast.length()-1)-x.charAt(j))
				{
					myLast = x.charAt(j) + myLast;
				}
				else
				{
					myLast = myLast + x.charAt(j);
				}
			}
			
			System.out.println("Case #" + (i+1) + ": " + myLast);
			
		}
		

	}

}
