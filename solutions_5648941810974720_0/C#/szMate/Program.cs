using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static bool FullZero(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] != 0) return false;
            }
            return true;
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt0(6).in");
            StreamWriter sw = new StreamWriter("outs.txt");
            long T = Int64.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string S = sr.ReadLine();

                int[] counts = new int[30];
                for (int j = 0; j < S.Length; j++)
			    {
                    counts[S[j] - 'A']++;
		        }

                string ret = "";
                while (!FullZero(counts))
                {
                    if (counts['Z' - 'A'] > 0)
                    {
                        int z = counts['Z' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '0';
                            counts['Z' - 'A']--;
                            counts['E' - 'A']--;
                            counts['R' - 'A']--;
                            counts['O' - 'A']--;
                        }
                    }
                    if (counts['W' - 'A'] > 0)
                    {
                        int z = counts['W' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '2';
                            counts['T' - 'A']--;
                            counts['W' - 'A']--;
                            counts['O' - 'A']--;
                        }
                    }
                    if (counts['U' - 'A'] > 0)
                    {
                        int z = counts['U' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '4';
                            counts['F' - 'A']--;
                            counts['O' - 'A']--;
                            counts['U' - 'A']--;
                            counts['R' - 'A']--;
                        }
                    }
                    if (counts['X' - 'A'] > 0)
                    {
                        int z = counts['X' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '6';
                            counts['S' - 'A']--;
                            counts['I' - 'A']--;
                            counts['X' - 'A']--;
                        }
                    }
                    if (counts['G' - 'A'] > 0)
                    {
                        int z = counts['G' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '8';
                            counts['E' - 'A']--;
                            counts['I' - 'A']--;
                            counts['G' - 'A']--;
                            counts['H' - 'A']--;
                            counts['T' - 'A']--;
                        }
                    }
                    if (counts['R' - 'A'] > 0)
                    {
                        int z = counts['R' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '3';
                            counts['E' - 'A']--;
                            counts['E' - 'A']--;
                            counts['R' - 'A']--;
                            counts['H' - 'A']--;
                            counts['T' - 'A']--;
                        }
                    }
                    if (counts['F' - 'A'] > 0)
                    {
                        int z = counts['F' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '5';
                            counts['E' - 'A']--;
                            counts['F' - 'A']--;
                            counts['I' - 'A']--;
                            counts['V' - 'A']--;
                        }
                    }
                    if (counts['S' - 'A'] > 0)
                    {
                        int z = counts['S' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '7';
                            counts['E' - 'A']--;
                            counts['S' - 'A']--;
                            counts['E' - 'A']--;
                            counts['V' - 'A']--;
                            counts['N' - 'A']--;
                        }
                    }
                    if (counts['I' - 'A'] > 0)
                    {
                        int z = counts['I' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '9';
                            counts['N' - 'A']--;
                            counts['E' - 'A']--;
                            counts['I' - 'A']--;
                            counts['N' - 'A']--;
                        }
                    }
                    if (counts['O' - 'A'] > 0)
                    {
                        int z = counts['O' - 'A'];
                        for (int j = 0; j < z; j++)
                        {
                            ret += '1';
                            counts['E' - 'A']--;
                            counts['O' - 'A']--;
                            counts['N' - 'A']--;
                        }
                    }
                }

                sw.WriteLine("Case #{0}: {1}", i + 1, String.Concat(ret.OrderBy(c => c)));
            }
            sw.Close();
            sr.Close();
        }
    }
}
