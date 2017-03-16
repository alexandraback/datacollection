import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class ProblemB
{
	Scanner in = null;
	Writer out = null;
	
	private void solve() throws IOException
	{
		int testCount = in.nextInt();
		in.nextLine();
		for (int test = 0; test < testCount; ++test)
		{
			double cost = in.nextDouble();
			double increase = in.nextDouble();
			double target = in.nextDouble();
			in.nextLine();
			
			double time = 0;
			double rate = 2;
			while (true)
			{
				double timeWithoutAnother = target / rate;
				double timeWithAnotherFactory = (cost / rate) + (target / (rate + increase));
				if (timeWithoutAnother <= timeWithAnotherFactory)
				{
					time += timeWithoutAnother;
					break;
				}
				else
				{
					time += cost / rate;
					rate += increase;
				}
			}
			
			out.writeln("Case #" + (test + 1) + ": " + time);
		}
	}
	
	public static void main(String[] args) throws IOException
	{
		new ProblemB();
	}

	private ProblemB() throws IOException
	{
		in = new Scanner(new FileInputStream("ProblemBIn.txt"));
		out = new Writer(new OutputStreamWriter(new FileOutputStream("ProblemBOut.txt"), "utf-8"));
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
