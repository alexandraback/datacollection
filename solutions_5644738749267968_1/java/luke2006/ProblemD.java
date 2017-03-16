import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemD
{
	Scanner in = null;
	Writer out = null;
	
	private void solve() throws IOException
	{
		int testCount = in.nextInt();
		in.nextLine();
		for (int test = 0; test < testCount; ++test)
		{
			// Input
			int blockCount = in.nextInt();
			ArrayList<Double> aBlocksBase = new ArrayList<Double>();
			ArrayList<Double> bBlocksBase = new ArrayList<Double>();
			for (int i = 0; i < blockCount; ++i)
				aBlocksBase.add(in.nextDouble());
			for (int i = 0; i < blockCount; ++i)
				bBlocksBase.add(in.nextDouble());
			Collections.sort(aBlocksBase);
			Collections.sort(bBlocksBase);
			
			// Play deceitful war
			int deceitfulWarScore = 0;
			ArrayList<Double> aBlocks = new ArrayList<Double>(aBlocksBase);
			ArrayList<Double> bBlocks = new ArrayList<Double>(bBlocksBase);
			
			// Get one slightly bigger than his, then attack and try to minimize losses
			for (int i = 0; i < bBlocks.size(); ++i)
			{
				int best = 0;
				for (int j = 0; j < aBlocks.size(); ++j)
					if (aBlocks.get(j) > bBlocks.get(i))
					{
						best = j;
						++deceitfulWarScore;
						break;
					}
				aBlocks.remove(best);
			}
			
			// Play war
			int warScore = 0;
			aBlocks = new ArrayList<Double>(aBlocksBase);
			bBlocks = new ArrayList<Double>(bBlocksBase);
			for (int i = 0; i < aBlocks.size(); ++i)
			{
				int best = 0;
				for (int j = 0; j < bBlocks.size(); ++j)
					if (bBlocks.get(j) > aBlocks.get(i))
					{
						best = j;
						--warScore;
						break;
					}
				++warScore;
				bBlocks.remove(best);
			}
			
			// Output
			out.writeln("Case #" + (test + 1) + ": " + deceitfulWarScore + " " + warScore);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		new ProblemD();
	}

	private ProblemD() throws IOException
	{
		in = new Scanner(new FileInputStream("ProblemDIn.txt"));
		out = new Writer(new OutputStreamWriter(new FileOutputStream("ProblemDOut.txt"), "utf-8"));
		solve();
		if (in != null)
			in.close();
		if (out != null)
			out.close();
	}
	
	private class Writer extends BufferedWriter
	{
		public Writer(java.io.Writer out)
		{
			super(out);
		}
		
		public void writeln(String str) throws IOException
		{
			write(str);
			newLine();
		}
		
		public void writeln(Object str) throws IOException
		{
			writeln(str.toString());
		}
	}
}
