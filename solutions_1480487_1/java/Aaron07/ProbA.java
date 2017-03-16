import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class ProbA {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-large.out"));
		String line;
		
		line = br.readLine();
		int T = Integer.parseInt(line);
		
		for(int i = 0; i < T; i++)
		{
			line = br.readLine();
			String[] tokens = line.split(" ");
			int N = Integer.parseInt(tokens[0]);
			//int[] jscores = new int[N];
			Pair[] parts = new Pair[N];
			int X = 0;
			for(int j = 0; j < N; j++)
			{
				parts[j] = new Pair();
				parts[j].jscore = Integer.parseInt(tokens[j+1]);
				parts[j].no = j;
				
				X += parts[j].jscore;
			}
			
			Pair.sortby = 0;
			Arrays.sort(parts);
			
//			if(i == 9)
//				System.out.println("here");
			
			double left = X;
			for(int j = N; j >= 0; j--)
			{
				if(j != N)
					left -= parts[j].jscore;
				
				double avg = (left + (double)X) / (double) j;
				if(avg > parts[j - 1].jscore)
				{
					for(int k = 0; k < j; k++)
					{
						parts[k].yscore = (avg - parts[k].jscore) / X * 100;
					}
					break;
				}
				
			}
			
			Pair.sortby = 1;
			Arrays.sort(parts);
			
			String oline = "Case #" + (i + 1) + ":";
			for(int j = 0; j < N; j++)
			{
				oline += " " + parts[j].yscore;
			}
			
			System.out.println(oline);
			bw.write(oline + "\n");
		}
		
		br.close();
		bw.close();

	}
	

}
class Pair implements Comparable
{
	static int sortby = 0;
	
	int no;
	int jscore;
	double yscore = 0.0;
	@Override
	public int compareTo(Object arg0) 
	{
		Pair p = (Pair) arg0;
		if (sortby == 0)
			return this.jscore - p.jscore;
		else
			return this.no - p.no;
	}
}
