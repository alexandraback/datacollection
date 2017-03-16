import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class DecietfulWar {

	public final static String INPUT_FILE_NAME = "D-small-attempt0.in";
	public final static String OUTPUT_FILE_NAME = "WarOut.txt";
	
	public static void main(String[] args) {
		try(Scanner in = new Scanner(new FileReader(INPUT_FILE_NAME));
				PrintWriter out = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME)))
		{
			int numT = in.nextInt();
			for(int t = 1; t <= numT; t ++)
			{
				int numBlocks = in.nextInt();
				NumData[] list = new NumData[numBlocks*2];
				for(int i = 0; i < numBlocks; i ++)
				{
					list[i] = new NumData(in.nextDouble(),false);
				}
				for(int i = 0; i < numBlocks; i ++)
				{
					list[i+numBlocks] = new NumData(in.nextDouble(),true);
				}
				Arrays.sort(list);
				
				int kScoreDeciet = 0;
				for(int i = 0; i < numBlocks*2; i ++)
				{
					if(list[i].isKen)
					{
						kScoreDeciet ++;
					}
					else
					{
						kScoreDeciet --;
						if(kScoreDeciet < 0)kScoreDeciet = 0;
					}
				}
				int nScoreDeciet = numBlocks - kScoreDeciet;
				
				int nScoreNormal = 0;
				for(int i = numBlocks*2-1; i >= 0; i--)
				{
					if(list[i].isKen)
					{
						nScoreNormal ++;
					}
					else
					{
						nScoreNormal --;
						if(nScoreNormal < 0)nScoreNormal = 0;
					}
				}
				out.println("Case #" + t + ": " + nScoreDeciet + " " + nScoreNormal);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	private static class NumData implements Comparable<NumData>
	{
		double val;
		boolean isKen;
		
		public NumData(double v, boolean k)
		{
			val = v;
			isKen = k;
		}

		@Override
		public int compareTo(NumData arg0) {
			if(val > arg0.val)return 1;
			return -1;
		}
	}
}
