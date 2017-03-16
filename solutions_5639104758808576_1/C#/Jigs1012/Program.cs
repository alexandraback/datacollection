using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StandingOvationTemp
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"A-large.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"A-large-Out.in", false))
                {

                    int Cases = Convert.ToInt32(sr.ReadLine());

                    for (int i = 0; i < Cases; i++)
                    {
                        string[] Value = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToArray();
                        int[] People = Value[1].ToString().Select(x => x - '0').ToArray();

                        int NewPeople = 0, Flag = 0;

                        for (int j = 0; j < People.Length; j++)
                        {
                            if (j == 0 && People[j] > 0) Flag = People[j];

                            else if (j <= Flag) Flag += People[j];

                            else if (j > Flag && People[j] > 0)
                            {
                                NewPeople += (j - Flag);
                                Flag += People[j] + NewPeople;
                            }
                        }
                        Console.WriteLine("Case #" + (i + 1) + ": " + NewPeople);
                        sw.WriteLine("Case #" + (i + 1) + ": " + NewPeople);
                    }
                    Console.ReadLine();
                }
            }
        }
    }
}
