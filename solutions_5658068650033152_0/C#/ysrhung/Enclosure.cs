using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Enclosure 
{


	class Enclosure 
	{
	

	static int largestPerfectShape(int N, ref int stoneNeeded)
	{
		int mid = N / 2;
		int enclosed = 0;
		stoneNeeded = 2 * (N - 1);
		for (int i = 0; i < mid; ++i)
		{
			enclosed += 2 * (2 * i + 1);
		}
		enclosed += 2 * mid + 1; 
		
		if (N % 2 == 1)
		{
			;
		}
		else
		{
			enclosed--;
			stoneNeeded += 2;
		}
		return enclosed;
	}
	
	static string solveProblem(StreamReader reader)
	{
		
		string line = reader.ReadLine();
		List<int> input = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
		int N = input[0], M = input[1], K = input[2];
		if (N > M)
		{
			int temp = N;
			N = M;
			M = temp;
		}
		int stoneNeeded = 0;
		int enclosed = largestPerfectShape(N, ref stoneNeeded);
		//Console.WriteLine(N + " " + enclosed + " " + stoneNeeded);
		// N is smaller now
		
		if (K <= 4)
			return K.ToString();
		if (N < 2)
		{
			Console.WriteLine(1);
			return K.ToString();
		}
		else if (N * M - K <= 4)
		{
			stoneNeeded = 2 * N + 2 * (M - 2) - (N * M - K);
			Console.WriteLine(2);
			return stoneNeeded.ToString();
		}
		else 
		{
			if (enclosed < K)
			{
				Console.WriteLine(3);
				int temp = N;
				while (enclosed < K)
				{
					if (K - enclosed == 1)
					{
						stoneNeeded++;
						enclosed++;
					}
					else
					{
						if (temp < M)
						{
							stoneNeeded += 2;
							enclosed += N;
							temp++;
						}
						else
						{
							stoneNeeded += 2;
							enclosed += (N - ((M - temp) * 2 + 1));
							temp++;						
						}
					}
				
				}
			}
			else if (enclosed == K)
			{
				Console.WriteLine(4);
				return stoneNeeded.ToString();
			}
			else
			{
				Console.WriteLine(5);
				int N2 = N;
				enclosed = largestPerfectShape(N2, ref stoneNeeded);
				while (enclosed > K)
				{
					Console.WriteLine(6);
					N2--;
					enclosed = largestPerfectShape(N2, ref stoneNeeded);
				}
				if (enclosed == K)
				{
					Console.WriteLine(7);
					return stoneNeeded.ToString();
				}
				else
				{
				// in between N2 and N2 + 1
					Console.WriteLine(8 + " " + stoneNeeded + " " + enclosed + " " + K);
					if (enclosed + 1 == K)
					{
						stoneNeeded++;
						return stoneNeeded.ToString();
					}						
					else if (enclosed + N >= K)
					{
						stoneNeeded += 2;
						return stoneNeeded.ToString();
					}						
					else if (enclosed + N  + 1 >= K)
					{
						stoneNeeded += 3;
						return stoneNeeded.ToString();					
					}
					else 
					{
						stoneNeeded += 4;
						return stoneNeeded.ToString();					
					}
				}
			}
		}
		return stoneNeeded.ToString();
	}

        static void Main(string[] args)
        {
//			StreamReader reader = new StreamReader("C-small-practice-2.in");
			StreamReader reader = new StreamReader("C-small-attempt2.in");
			//StreamReader reader = new StreamReader("B-large-practice.in");
//			StreamReader reader = new StreamReader("B-small-practice2.txt");
//            StreamReader reader = new StreamReader("C-large-practice-2b.in");
//            StreamReader reader = new StreamReader("C-small-practice.in");
//	    StreamReader reader = new StreamReader("B-large-practice.in");
//            StreamWriter writer = new StreamWriter("output3b.txt");
            StreamWriter writer = new StreamWriter("output.txt");
			string line = reader.ReadLine();
			int total = int.Parse(line);
			StringBuilder results = new StringBuilder();

//            while ((line = reader.ReadLine()) != null)
  //          {
			for (int i = 1; i <= total; ++i)
			{
				Console.WriteLine("Case #" + i.ToString());
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
