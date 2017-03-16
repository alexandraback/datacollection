using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam___Round_1C
{
    class Problem_A
    {
        public static void Run()
        {
            List<string> output = new List<string>();

            // Open the file to read from. 
            using (StreamReader sr = File.OpenText(@"E:\Documents\Google Drive\Coding\Google Code Jam - Round 1C\Google Code Jam - Round 1C\A-large.in"))
            {
                int testCases = Int32.Parse(sr.ReadLine());
                for (int caseNum = 0; caseNum < testCases; caseNum++)
                {
                    string[] testCase = sr.ReadLine().Split(' ');
                    int rows = int.Parse(testCase[0]);
                    int cols = int.Parse(testCase[1]);
                    int width = int.Parse(testCase[2]);

                    int attackCols = cols/width;

                    int attacksUntilFirstHit = attackCols*rows;

                    int maxAttacksAfterHit = width;

                    int spacingBetweenAttackCols = cols/attackCols;

                    if (cols - (attackCols - 1)*spacingBetweenAttackCols == width)
                    {
                        maxAttacksAfterHit--;
                    }


                    output.Add(String.Format("Case #{0}: {1}", caseNum + 1, attacksUntilFirstHit + maxAttacksAfterHit));
                }
            }


            using (StreamWriter sw = File.CreateText(@"E:\Documents\Google Drive\Coding\Google Code Jam - Round 1C\Google Code Jam - Round 1C\A-large.out"))
            {
                foreach (var line in output)
                {
                    sw.WriteLine(line);
                }
            }


        }
    }
}
