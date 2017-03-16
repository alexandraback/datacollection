using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    public static class Problem_A
    {
        public static void Run()
        {
            List<string> output = new List<string>();

            // Open the file to read from. 
            using (StreamReader sr = File.OpenText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\A-large.in"))
            {
                int testCases = Int32.Parse(sr.ReadLine());
                for (int caseNum = 0; caseNum < testCases; caseNum++)
                {
                    string testCase = sr.ReadLine();
                    string [] parsedCase = testCase.Split(' ');
                    int maxShyness = Int32.Parse(parsedCase[0]);
                    int friendsRequired = 0;
                    int peopleStanding = 0;
                    for(int shynessLevel = 0; shynessLevel <= maxShyness; ++shynessLevel)
                    {
                        int shyPeople = parsedCase[1][shynessLevel] - '0';
                        peopleStanding += shyPeople;

                        if (peopleStanding <= shynessLevel)
                        {
                            peopleStanding++;
                            friendsRequired++;
                        }
                    }

                    output.Add(String.Format("Case #{0}: {1}", caseNum + 1, friendsRequired));
                }
            }


            using (StreamWriter sw = File.CreateText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\A-large.out"))
            {
                foreach (var line in output)
                {
                    sw.WriteLine(line);
                }
            }
            

        }
    }
}
