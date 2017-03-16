using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace SafetyInNumbers1B2012
{
	class MainClass
	{
		
		private static string DoCase(string line, int caseNum)
		{
			Console.WriteLine("Case "+caseNum+'\n');
			string[] splits = line.Split(' ');
			int N = int.Parse(splits[0]);
			int[] j = new int[N];
			
			int X = 0;
			for (int i = 0; i < N; i++)
			{
				j[i] = int.Parse(splits[i+1]);
				X += j[i];
			}
			
			double target = X * 2f / N;
			Console.WriteLine("Target: "+String.Format("{0:0.0###}",target));
			
			int onesThatMatter = 0;
			int xForMatters = 0;
			for (int i = 0; i < N; i++)
			{
				if (j[i] <= target)
				{
					onesThatMatter++;
					xForMatters += j[i];
				}
			}
			
			double revisedTarget = (X + xForMatters) / (float)onesThatMatter;
			
			double[] percents = new double[N];
			for (int i = 0; i < N; i++)
			{
				Console.WriteLine("J: "+j[i]);
				double neededExtra = revisedTarget - j[i];
				Console.WriteLine("needed: "+String.Format("{0:0.0###}",neededExtra));
				double percent = neededExtra / X;
				percent = Math.Max(0, percent);
				percents[i] = percent;
			}
			
			StringBuilder builder = new StringBuilder();
			builder.Append("Case #"+caseNum+":");
			for (int i = 0; i < N; i++)
			{
				double percent = percents[i];
				Console.WriteLine("Final score: "+String.Format("{0:0.0###}",(j[i]+percent*X)));
				percent *= 100;
				builder.Append(" ");
				builder.AppendFormat("{0:0.0#####}", percent);
			}
			Console.WriteLine(builder.ToString());
			return builder.ToString();
		}
		
		public static void Main (string[] args)
		{
			StreamReader reader = new StreamReader("in.txt");
			StreamWriter writer = new StreamWriter("out.txt");
			string casesLine = reader.ReadLine();
			int N = int.Parse(casesLine);
			for (int i = 0; i < N; i++)
			{
				string line = reader.ReadLine();
				string result = DoCase(line, i+1);
				writer.WriteLine(result);
			}
			reader.Close();
			writer.Close();
		}
	}
}
