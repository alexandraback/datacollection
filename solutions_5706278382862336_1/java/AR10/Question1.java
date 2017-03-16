import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class Question1 
{
	public static void main(String[] args)
	{
		StringMatch("C:\\CodeJam\\1C\\A-small-attempt0.in");
	}
	
	public static int GCD(int a, int b) 
	{
		   if (b==0) return a;
		   return GCD(b,a%b);
	}

	public static void StringMatch(String filePath)
	{
		try 
		{
			BufferedReader bufferedReader = new BufferedReader(new FileReader(filePath));
			String line;
			boolean firstline = true;
			int testCases  = 0;

			testCases = Integer.parseInt(bufferedReader.readLine());
			int caseNo = 1;

			while (caseNo<=testCases) 
			{
				String f = bufferedReader.readLine();
				StringTokenizer st = new StringTokenizer(f,"/");
				int num = Integer.parseInt(st.nextToken());
				int denom = Integer.parseInt(st.nextToken());
				
				int gcd = GCD(num,denom);
				double p = num/gcd;
				double q = denom/gcd;
				
				
				int denomlog = (int)(Math.log(q)/Math.log(2));
				if(Math.pow(2, denomlog)!=q)
				{
					System.out.println("Case #"+caseNo+": "+"impossible");
					caseNo++;
					continue;
				}
				
				double frac = p/q;
				
				//double numgen = Math.log(frac)/Math.log(2);
				int numgen = 0;
				for(int i=0; i<40; i++)
				{
					double small = 1/Math.pow(2, i);
					double big = 1/Math.pow(2, i+1);
					
					if(big<=frac && frac<small)
					{
						numgen = i+1;
						break;
					}
						
				}
				System.out.println("Case #"+caseNo+": "+numgen);
				
				caseNo++;
			}

		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		} 
	}
	
}
