import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class DeceitfulWar {
	public static void main(String[] args) throws Exception
	{
		String inputfile = "D:\\in4.txt";
		String outputfile = "D:\\out4.txt";
		
		Scanner in = new Scanner(new File(inputfile));
		FileWriter fstream = new FileWriter(outputfile);
		BufferedWriter out = new BufferedWriter(fstream);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; ++t)
		{
			System.out.println("iteration " + t);
			int N = in.nextInt();
			double[] myBlocks = new double[N];
			double[] hisBlocks = new double[N];
			
			for (int n = 0; n < N; ++n)
				myBlocks[n] = in.nextDouble();
			
			for (int n = 0; n < N; ++n)
				hisBlocks[n] = in.nextDouble();
			
			Arrays.sort(myBlocks);
			Arrays.sort(hisBlocks);

			// play deceitful war
			int deceitfulScore = 0;
			int kenIndex = 0;
			for (int i = 0; i < N; ++i)
			{
				if (myBlocks[i] > hisBlocks[kenIndex])
				{
					++deceitfulScore;
					++kenIndex;
				}
			}
			
			// play normal war
			int regularScore = 0;
			boolean[] kenUsed = new boolean[N];
			for (int i = 0; i < N; ++i)
			{
				// find the nearest larger block
				int blockId = -1;
				for (int j = 0; j < N; ++j)
				{
					if (!kenUsed[j] && hisBlocks[j] > myBlocks[i])
					{
						blockId = j;
						break;
					}
				}
				
				// no larger block
				if (blockId == -1)
				{
					++regularScore;
					for (int j = 0; j < N; ++j)
					{
						if (!kenUsed[j])
						{
							kenUsed[j] = true;
							break;
						}
					}
				}
				else
				{
					kenUsed[blockId] = true;
				}
			}
			
			out.write(String.format("Case #%d: %d %d", t, deceitfulScore, regularScore));
			out.newLine();
		}
		
		System.out.println("done...");
		out.close();
	}
}
