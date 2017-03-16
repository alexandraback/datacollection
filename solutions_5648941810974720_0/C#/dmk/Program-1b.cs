using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program1b
    {
        readonly static string INOUT = @"C:\Users\Derek\Documents\visual studio 2015\Projects\CodeJam\CodeJam\inout\rnd1b\";
        readonly static string MODE = "small";

        static void Main(string[] args)
        {
            SolveA();
        }
                

        static void SolveA()
        {
            string[] lines = File.ReadAllLines(INOUT + @"A-" + MODE + @".in");
            using (StreamWriter file = new StreamWriter(INOUT + @"A-" + MODE + @".out"))
            {
                int T = int.Parse(lines[0]);
                for (int i = 1; i <= T; i++)
                {
                    string s = lines[i];
                    List<int> nums = new List<int>();
                    while (s.Length > 0)
                    {
                        if (s.Contains("Z"))
                        {
                            nums.Add(0);
                            s = s.Remove(s.IndexOf('Z'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                            s = s.Remove(s.IndexOf('R'), 1);
                            s = s.Remove(s.IndexOf('O'), 1);
                        }
                        else if (s.Contains("W"))
                        {
                            nums.Add(2);
                            s = s.Remove(s.IndexOf('T'), 1);
                            s = s.Remove(s.IndexOf('W'), 1);
                            s = s.Remove(s.IndexOf('O'), 1);
                        }
                        else if (s.Contains("U"))
                        {
                            nums.Add(4);
                            s = s.Remove(s.IndexOf('F'), 1);
                            s = s.Remove(s.IndexOf('O'), 1);
                            s = s.Remove(s.IndexOf('U'), 1);
                            s = s.Remove(s.IndexOf('R'), 1);
                        }
                        else if (s.Contains("X"))
                        {
                            nums.Add(6);
                            s = s.Remove(s.IndexOf('S'), 1);
                            s = s.Remove(s.IndexOf('I'), 1);
                            s = s.Remove(s.IndexOf('X'), 1);
                        }
                        else if (s.Contains("G"))
                        {
                            nums.Add(8);
                            s = s.Remove(s.IndexOf('E'), 1);
                            s = s.Remove(s.IndexOf('I'), 1);
                            s = s.Remove(s.IndexOf('G'), 1);
                            s = s.Remove(s.IndexOf('H'), 1);
                            s = s.Remove(s.IndexOf('T'), 1);
                        }
                        else if (s.Contains("O"))
                        {
                            nums.Add(1);
                            s = s.Remove(s.IndexOf('O'), 1);
                            s = s.Remove(s.IndexOf('N'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                        }
                        else if (s.Contains("F"))
                        {
                            nums.Add(5);
                            s = s.Remove(s.IndexOf('F'), 1);
                            s = s.Remove(s.IndexOf('I'), 1);
                            s = s.Remove(s.IndexOf('V'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                        }
                        else if (s.Contains("R"))
                        {
                            nums.Add(3);
                            s = s.Remove(s.IndexOf('T'), 1);
                            s = s.Remove(s.IndexOf('H'), 1);
                            s = s.Remove(s.IndexOf('R'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                        }
                        else if (s.Contains("V"))
                        {
                            nums.Add(7);
                            s = s.Remove(s.IndexOf('S'), 1);
                            s = s.Remove(s.IndexOf('V'), 1);
                            s = s.Remove(s.IndexOf('N'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                        }
                        else if (s.Contains("N"))
                        {
                            nums.Add(9);
                            s = s.Remove(s.IndexOf('I'), 1);
                            s = s.Remove(s.IndexOf('N'), 1);
                            s = s.Remove(s.IndexOf('N'), 1);
                            s = s.Remove(s.IndexOf('E'), 1);
                        }
                    }

                    nums.Sort();
                    string r = "";
                    for (int j = 0; j < nums.Count; j++)
                        r += nums[j].ToString();

                    file.WriteLine(String.Format("Case #{0}: {1}", i, r));
                }
            }
        }
    }
}
