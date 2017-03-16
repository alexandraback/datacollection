using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Elf
{


	class Elf
	{
	

	static long GCD(long a, long b)
		{
			long Remainder;
		
			while( b != 0 )
			{
				Remainder = a % b;
				a = b;
				b = Remainder;
			}
		  
			return a;
		}

	static bool powOf2(long num)
	{
		while (num > 1)
		{
			if ((num % 2) != 0)
				return false;
			num /= 2;
		}
		return true;
	}
	
	static string solveProblem(StreamReader reader)
	{
		
		string line = reader.ReadLine();
		int tokenPos = line.IndexOf("/");
		long P, Q;
		P = long.Parse(line.Substring(0, tokenPos));
		Q = long.Parse(line.Substring(tokenPos + 1, line.Length - tokenPos - 1));
		long gcd = GCD(P, Q);
		while(gcd > 1)
		{
			Console.WriteLine("GCD = " + gcd);
			P /= gcd;
			Q /= gcd;
			gcd = GCD(P, Q);
		
		}
		if (!powOf2(Q))
			return "impossible";
		int counter = 0;
		while (P < Q)
		{
			counter++;
			P *= 2;
		}
		return counter.ToString();
		
/*		



		int N = int.Parse(line);
		List<string> inputs = new List<string>();

		for (int i = 0; i < N; ++i)
		{
			line = reader.ReadLine();
			inputs.Add(line);
		}
		int minMove = 0;
		List<string> skeletons = new List<string>();
		string skeleton = inputs[0][0].ToString();
		foreach (string s in inputs)
		{
			skeleton  = s[0].ToString();
			foreach (char c in s)
			{
				if (c != skeleton[skeleton.Length-1])
				{
					skeleton = skeleton + c; 
				}
			}
			skeletons.Add(skeleton);
			//Console.WriteLine(skeleton);
		}
		skeleton = skeletons[0];
		foreach (string s in skeletons)
		{
			if (skeleton != s)
			{
				return "Fegla Won";
			}
		}
		List<int> freq = new List<int>();
		for (int i = 0 ; i < N; ++i)
		{
			freq.Add(0);
		}
		foreach (char c in skeleton)
		{		
			for (int i = 0; i < N; ++i)
			{	
				while (inputs[i].Length > 0 && inputs[i][0] == c)
				{
					freq[i]++;
					inputs[i] = inputs[i].Substring(1, inputs[i].Length - 1);
//					Console.WriteLine(i  + " " + inputs[i] + " " + freq[i]);
				}

			}
			int totalFreq = 0;
			foreach (int f in freq)
			{
				totalFreq += f;
			}
			int average = (int) ( (totalFreq + 0.5) / N); 
//			Console.WriteLine(c + " " + totalFreq + " " + average);
			for (int j = 0; j < N; ++j)
			{
				minMove += Math.Abs(average - freq[j]);
				freq[j] = 0;
			}
		}
		*/
		return "";
	}

        static void Main(string[] args)
        {
//			StreamReader reader = new StreamReader("C-small-practice-2.in");
			StreamReader reader = new StreamReader("A-large.in");
			//StreamReader reader = new StreamReader("B-large-practice.in");
//			StreamReader reader = new StreamReader("B-small-practice2.txt");
//            StreamReader reader = new StreamReader("C-large-practice-2b.in");
//            StreamReader reader = new StreamReader("C-small-practice.in");
//	    StreamReader reader = new StreamReader("B-large-practice.in");
//            StreamWriter writer = new StreamWriter("output3b.txt");
            StreamWriter writer = new StreamWriter("output2.txt");
			string line = reader.ReadLine();
			int total = int.Parse(line);
			StringBuilder results = new StringBuilder();

//            while ((line = reader.ReadLine()) != null)
  //          {
			for (int i = 1; i <= total; ++i)
			{
				string tempResult = "Case #" + i.ToString() + ": " + solveProblem(reader);
//				Console.WriteLine(tempResult);
				results.AppendLine(tempResult);
				
			}
		//writer.WriteLine(total);
//	    }
			writer.WriteLine(results.ToString());
            reader.Close();
            writer.Close();
        }
    }
}
