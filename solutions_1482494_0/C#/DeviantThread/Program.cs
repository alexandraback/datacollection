using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utilities;
using System.Numerics;
using System.Text.RegularExpressions;
using Numerics;

namespace GoogleCodeJam2012
{
	class Program
	{
		static void Main(string[] args)
		{
            string infile1 = @"\\cs\files\Student_Home\borriej\Downloads\A-small-attempt0.in";
            string outfile1 = @"\\cs\files\Student_Home\borriej\Downloads\A-small-attempt0.out";

            string infile2 = @"\\cs\files\Student_Home\borriej\Downloads\B-small-attempt0.in";
            string outfile2 = @"\\cs\files\Student_Home\borriej\Downloads\B-small-attempt0.out";

            string infile3 = @"\\cs\files\Student_Home\borriej\Downloads\C-small-attempt0.in";
            string outfile3 = @"\\cs\files\Student_Home\borriej\Downloads\C-small-attempt0.out";
            
			//Problem1(infile1, outfile1);

			Problem2(infile2, outfile2);

			//Problem3(infile3, outfile3);

			//Console.Read();
		}

		static void Problem1(string inFile, string outFile)
		{
			Console.WriteLine("Problem 1");
			using(TextReader tr = new StreamReader(inFile))
			using(TextWriter tw = new StreamWriter(outFile))
			{

				int numOfCases = int.Parse(tr.ReadLine());

				for(int caseNum = 1; caseNum <= numOfCases; caseNum++)
				{
					int len = int.Parse(tr.ReadLine());

                    string[] line = tr.ReadLine().Split(' ');
                    int numCharsAlreadyTyped = int.Parse(line[0]);
                    int totalChars = int.Parse(line[1]);

                    decimal[] numbers = tr.ReadLine().Split(' ').Select(x => decimal.Parse(x)).ToArray();
                    List<decimal> results = new List<decimal>();

                    for (int backspacecount = 1; backspacecount < numCharsAlreadyTyped; backspacecount++)
                    {


                    }


                    decimal KeepTyping = ((totalChars - numCharsAlreadyTyped + 1) * (numbers.Aggregate((prev, next) => prev * next))) + ((totalChars - numCharsAlreadyTyped + 1 + totalChars + 1) * (1 - numbers.Sum()));
                    decimal EnterRightAway = totalChars + 2;




                    decimal result = results.Min();
					tw.WriteLine("Case #{0}: {1}", caseNum, result.ToString());
				}
			}
		}

		static void Problem2(string inFile, string outFile)
		{
			Console.WriteLine("Problem 2");
			using(TextReader tr = new StreamReader(inFile))
			using(TextWriter tw = new StreamWriter(outFile))
			{

				int numOfCases = int.Parse(tr.ReadLine());

				for(int caseNum = 1; caseNum <= numOfCases; caseNum++)
				{


                    int N = int.Parse(tr.ReadLine());
                    List<KingdomNode> levels = new List<KingdomNode>();
                    for (int i = 0; i < N; i++)
                    {
                        string[] line = tr.ReadLine().Split(' ');
                        int a = int.Parse(line[0]);
                        int b = int.Parse(line[1]);

                        levels.Add(new KingdomNode(a, b));
                    }

                    int levelsBeat = 0;
                    int starCount = 0;
                    bool bChanged = true;
                    while (bChanged && levels.Any(x => !x.finishedTwoStar))
                    {
                        bChanged = false;
                        //highest two star that we can
                        KingdomNode level = levels.Where(x => !x.finishedTwoStar && starCount >= x.twoStar).OrderByDescending(x => x.twoStar).FirstOrDefault();
                        if (level != null)
                        {
                            if (level.finishedOneStar)
                                starCount++;
                            else
                                starCount += 2;

                            levelsBeat++;
                            level.finishedTwoStar = true;
                            bChanged = true;
                            continue;
                        }


                        level = levels.Where(X => !X.finishedOneStar && !X.finishedTwoStar && starCount >= X.oneStar).OrderByDescending(x => x.twoStar).FirstOrDefault();

                        if (level != null)
                        {
                            starCount++;
                            levelsBeat++;
                            level.finishedOneStar = true;
                            bChanged = true;
                            continue;
                        }
                    }

                    if(levels.Any(x => !x.finishedTwoStar))
                        tw.WriteLine("Case #{0}: Too Bad", caseNum);
                    else
					    tw.WriteLine("Case #{0}: {1}", caseNum, levelsBeat);
				}
			}
		}

	
		static void Problem3(string inFile, string outFile)
		{
			Console.WriteLine("Problem 3");
			using(TextReader tr = new StreamReader(inFile))
			using(TextWriter tw = new StreamWriter(outFile))
			{

				int numOfCases = int.Parse(tr.ReadLine());

				for(int caseNum = 1; caseNum <= numOfCases; caseNum++)
				{


				}
			}
		}


	}

    class KingdomNode
    {
        public int oneStar;
        public int twoStar;
        public bool finishedOneStar;
        public bool finishedTwoStar;

        public KingdomNode(){}

        public KingdomNode(int one, int two)
        {
            oneStar = one;
            twoStar = two;
        }
    }
}
