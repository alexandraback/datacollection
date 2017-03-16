import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DanceScores {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dance.out")));
		
		int numberCases = Integer.parseInt(f.readLine());
		String log;
		StringTokenizer st;
		int dancers;
		int bestResult;
		int surprisingTriples;
		int triplesThatSatisfy;
		
		for (int i = 1; i <= numberCases; i++)
		{
			log = "Case #" + i + ": ";
			st = new StringTokenizer(f.readLine());
			
			dancers = Integer.parseInt(st.nextToken());
			surprisingTriples = Integer.parseInt(st.nextToken());
			bestResult = Integer.parseInt(st.nextToken());;
			
			triplesThatSatisfy = calculateNumTriples(dancers, surprisingTriples, bestResult, st);
			
			log += triplesThatSatisfy;
			out.println(log);
		}
		
		out.close();
		System.exit(0);
	}

	private static int calculateNumTriples(int dan, int sur, int bes, StringTokenizer st) 
	{
		int result = 0;
		int surprising = sur;
		int total;
		
		//deal with p = 0 and p = 1, as these cases are special
		if (bes == 0)
		{
			return dan;
		}
		else if (bes == 1)
		{
			while (st.hasMoreTokens())
			{
				if ((Integer.parseInt(st.nextToken())) != 0)
				{
					result++;
				}
			}
			
			return result;
		}
		else
		{
			while (st.hasMoreTokens())
			{
				total = Integer.parseInt(st.nextToken());
				
				if (total >= 3*bes - 2)
				{
					result++;
				}
				else if ((3*bes - 4 <= total) &&
							(total <= 3*bes - 3))
				{
					if (surprising > 0)
					{
						surprising--;
						result++;
					}
				}
			}
			
			return result;
		}
	}

}
