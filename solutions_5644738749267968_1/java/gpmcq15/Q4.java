import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Q4
{
	public static void main(String[] args) throws IOException
	{
		File input = new File("CodeJamInput.in");
		File output = new File("CodeJamOutput.txt");
		FileWriter writer = new FileWriter(output);
		Scanner scan = new Scanner(input);
		
		
		int testCases = scan.nextInt();
		int DWScore;
		int WScore;
		double[] NBlocks;
		double[] KBlocks;
		double[] origN;
		double[] origK;
		int blockNum;
		for (int i = 1; i <= testCases; i++)
		{
			DWScore = 0;
			WScore = 0;
			blockNum = scan.nextInt();
			NBlocks = new double[blockNum];
			KBlocks = new double[blockNum];
			for (int a = 0; a < blockNum; a++)
			{
				NBlocks[a] = scan.nextDouble();
			}
			Arrays.sort(NBlocks);
			origN = NBlocks.clone();
			for (int a = 0; a < blockNum; a++)
			{
				KBlocks[a] = scan.nextDouble();
			}
			Arrays.sort(KBlocks);
			origK = KBlocks.clone();
			for(double a: NBlocks)
			{
				for (int b = 0; b < KBlocks.length; b++)
				{
					if (KBlocks[b]>a)
					{
						KBlocks[b] = 0.0;
						Arrays.sort(KBlocks);
						break;
					}
					else if (b==KBlocks.length-1)
					{
						for (int c = 0; c < KBlocks.length; c++)
						{
							if (KBlocks[c]>0) KBlocks[c]=0.0;
						}
						Arrays.sort(KBlocks);
						WScore++;
					}
				}
			}
			for (int a = 0; a < blockNum; a++)
			{
				NBlocks[a] = origN[a];
				KBlocks[a] = origK[a];
			}
			Arrays.sort(KBlocks);
			boolean done =false;
			for(double a : KBlocks)
			{
				Arrays.sort(NBlocks);
				for (int b = 0; b < NBlocks.length; b++)
				{
					if (NBlocks[b]>a)
					{
						NBlocks[b] = 0.0;
						DWScore++;
						break;
					}
					else if (b==NBlocks.length-1)
					{
						done = true;
						break;
					}
				}
				if (done) break;
			}
			
			writer.write("Case #" + i + ": " + DWScore + " " + WScore + "\n");
		}
		
		
		scan.close();		
		writer.close();
		System.out.println("Done");
	}
}