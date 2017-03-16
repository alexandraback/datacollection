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
            SolveB();
        }


        static void SolveB()
        {
            string[] lines = File.ReadAllLines(INOUT + @"B-" + MODE + @".in");
            using (StreamWriter file = new StreamWriter(INOUT + @"B-" + MODE + @".out"))
            {
                int T = int.Parse(lines[0]);
                for (int i = 1; i <= T; i++)
                {
                    string s = lines[i];
                    string[] scores = s.Split(' ');
                    string coder = "";
                    string jammer = "";
                    for(int j = 0; j < scores[0].Length; j++)
                    {
                        if (scores[0][j] != '?' && scores[1][j] != '?')
                        {
                            coder += scores[0][j];
                            jammer += scores[1][j];
                        }
                        else if (scores[0][j] == '?' && scores[1][j] != '?')
                        { 
                            jammer += scores[1][j];
                            int[] tests = new int[3];
                            tests[0] = int.Parse(coder + "0");
                            tests[1] = int.Parse(coder + scores[1][j]);
                            tests[2] = int.Parse(coder + "9");
                            int[] diffs = new int[3];
                            diffs[0] = Math.Abs(int.Parse(jammer) - tests[0]);
                            diffs[1] = Math.Abs(int.Parse(jammer) - tests[1]);
                            diffs[2] = Math.Abs(int.Parse(jammer) - tests[2]);
                            if (diffs[0] <= diffs[1] && diffs[0] <= diffs[2])
                                coder += '0';
                            else if (diffs[1] <= diffs[0] && diffs[1] <= diffs[2])
                                coder += scores[1][j];
                            else
                                coder += '9';
                        }
                        else if (scores[0][j] != '?' && scores[1][j] == '?')
                        {
                            coder += scores[0][j];
                            int[] tests = new int[3];
                            tests[0] = int.Parse(jammer + "0");
                            tests[1] = int.Parse(jammer + scores[0][j]);
                            tests[2] = int.Parse(jammer + "9");
                            int[] diffs = new int[3];
                            diffs[0] = Math.Abs(int.Parse(coder) - tests[0]);
                            diffs[1] = Math.Abs(int.Parse(coder) - tests[1]);
                            diffs[2] = Math.Abs(int.Parse(coder) - tests[2]);
                            if (diffs[0] <= diffs[1] && diffs[0] <= diffs[2])
                                jammer += '0';
                            else if (diffs[1] <= diffs[0] && diffs[1] <= diffs[2])
                                jammer += scores[0][j];
                            else
                                jammer += '9';
                        } else
                        {
                            if(coder.Length == 0 || int.Parse(coder) == int.Parse(jammer))
                            {
                                coder += '0';
                                jammer += '0';
                            } else
                            {
                                if(int.Parse(coder) < int.Parse(jammer))
                                {
                                    coder += '9';
                                    jammer += '0';
                                }
                                else
                                {
                                    coder += '0';
                                    jammer += '9';
                                }
                            }
                        }
                    }

                    file.WriteLine(String.Format("Case #{0}: {1} {2}", i, coder, jammer));
                }
            }
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
