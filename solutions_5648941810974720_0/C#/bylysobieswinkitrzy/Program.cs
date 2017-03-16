using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CJ2ndRound
{
    class Program
    {
        static string[] nums = new string[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

        static Tuple<List<char>,bool> DoFor(List<char> line, int cnt)
        {
            List<char> removed = new List<char>();
            var num = nums[cnt].ToList();
            var newLine = line;
            bool ok = false;
            foreach (var c in num)
            {
                if (line.Contains(c))
                {
                    ok = true;
                    newLine.RemoveAt(line.IndexOf(c));
                    removed.Add(c);
                }
                else
                {
                    ok = false;
                    newLine.AddRange(removed);
                    break;
                }
            }
            return new Tuple<List<char>, bool>(newLine, ok);
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("A-small-attempt1.in");

            int noOfCases = int.Parse(lines[0]);



            List<string> output = new List<string>();

 

            for (int i = 1; i <= noOfCases; i++)
            {

                var line = lines[i].ToList();
                string outs = String.Empty;

                List<int> endnums = new List<int>();

                while (line.Contains('W')) //two
                {
                    var x = DoFor(line, 2);
                    if (x.Item2)
                    {
                        line = x.Item1;
                        endnums.Add(2);
                    }
                }

                while (line.Contains('U')) //four
                {
                    var x = DoFor(line, 4);
                    if (x.Item2)
                    {
                        line = x.Item1;
                        endnums.Add(4);
                    }
                }

                while (line.Contains('X')) //six
                {
                    var x = DoFor(line, 6);
                    if (x.Item2)
                    {
                        line = x.Item1;
                        endnums.Add(6);
                    }
                }

                while (line.Contains('G')) //eight
                {
                    var x = DoFor(line, 8);
                    if (x.Item2)
                    {
                        line = x.Item1;
                        endnums.Add(8);
                    }
                }

                for (int k = 0; k < nums.Length; k++)
                {
                    var num = nums[k];
                    List<char> removed = new List<char>();

                    bool ok = false;
                    List<char> test = num.ToList();
                    foreach (char c in test)
                    {
                        if (line.Contains(c))
                        {
                            ok = true;
                            line.RemoveAt(line.IndexOf(c));
                            removed.Add(c);
                        }
                        else
                        {
                            ok = false;
                            line.AddRange(removed);
                            break;
                        }
                    }
                    if (ok)
                    {
                        endnums.Add(nums.ToList().IndexOf(num));
                        k--;
                    }
                }
                //Console.WriteLine(line.Count);
                if (line.Count > 0)
                {
                    Console.WriteLine(new String(line.ToArray()));
                    Console.WriteLine(lines[i]);
                }
                var ooo = new String(endnums.OrderBy(x => x).Select(x => x.ToString()[0]).ToArray());
                Console.WriteLine(ooo);
                output.Add(String.Format("Case #{0}: {1}", i, ooo));
            }
            File.WriteAllLines("output.out", output);
            Console.WriteLine("Done.");
            Console.ReadKey();
        }
    }
}
