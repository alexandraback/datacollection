using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamC
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Filename:");
            string filename = Console.ReadLine();
            string[] linesArray = File.ReadAllLines(@"F:\DL\" + filename);

            List<string> linesList = linesArray.ToList();

            int testCases = Int32.Parse(linesList[0]);
            using (StreamWriter file = new StreamWriter(@"F:\DL\SolveC.txt"))
            {
                for (int i = 1; i <= testCases; i++)
                {
                    string testCase = linesList[i];
                    List<string> numbers = testCase.Split(' ').ToList();
                    int R = Int32.Parse(numbers[0]);
                    int C = Int32.Parse(numbers[1]);
                    int M = Int32.Parse(numbers[2]);
                    file.WriteLine("Case #" + i.ToString() + ":\n" + SolveTest(R, C, M));
                }
            }
        }

        private static string SolveTest(int R, int C, int M, bool Recursived = false)
        {
            if (M == 0)
            {
                string Zero = "c";
                for (int i = 0; i < R; i++)
                {
                    int toC = i == 0 ? (C - 1) : C;
                    for (int j = 0; j < toC; j++)
                    {
                        Zero += ".";
                    }
                    Zero += "\n";
                }
                Zero = Zero.Substring(0, Zero.Length-1);
                return Zero;
            }
            if (R == 1)
            {
                string row = "c";
                for (int i = 0; i < (C - M - 1); i++)
                {
                    row += ".";
                }
                for (int i = 0; i < M; i++)
                {
                    row += "*";
                }
                return row;
            }
            if (C == 1)
            {
                string col = "c\n";
                for (int i = 0; i < (R - M - 1); i++)
                {
                    col += ".\n";
                }
                for (int i = 0; i < M; i++)
                {
                    col += "*\n";
                }
                col = col.Substring(0, col.Length - 1);
                return col;
            }
            if (R == 2)
            {
                int total = R * C;
                int remaining = total - M;
                if (remaining == 1)
                {
                    string ret = "c";
                    for (int i = 0; i < (C-1); i++)
                    {
                        ret += "*";
                    }
                    ret += "\n";
                    for (int i = 0; i < C; i++)
                    {
                        ret += "*";
                    }
                    return ret;
                }
                if (M % 2 == 1) return "Impossible";
                if (remaining < 4)
                {
                    return "Impossible";
                }
                int starred = M / 2;
                string complete = "c";
                for (int i = 0; i < (C - 1 - starred); i++)
                {
                    complete += ".";
                }
                for (int i = 0; i < starred; i++)
                {
                    complete += "*";
                }
                complete += "\n";
                for (int i = 0; i < (C-starred); i++)
                {
                    complete += ".";
                }
                for (int i = 0; i < starred; i++)
                {
                    complete += "*";
                }
                return complete;
            }
            if (C == 2)
            {
                
                int total = R * C;
                int remaining = total - M;
                if (remaining == 1)
                {
                    string ret = "c*\n";
                    for (int i = 0; i < (R-1); i++)
                    {
                        ret += "**";
                        if (i < (R - 2)) ret += "\n";
                    }
                    return ret;
                }
                if (M % 2 == 1) return "Impossible";
                if (remaining < 4)
                {
                    return "Impossible";
                }
                int starred = M / 2;
                string complete = "c.\n";
                for (int i = 0; i < (R-1-starred); i++)
                {
                    complete += "..\n";
                }
                for (int i = 0; i < starred; i++)
                {
                    complete += "**\n";
                }
                complete = complete.Substring(0, complete.Length - 1);
                return complete;
            }
            // R>2 C>2
            int totalcells = R * C;
            int remainingcells = totalcells - M;
            if (remainingcells == 1)
            {
                string retval = "c";
                for (int j = 0; j < (R); j++)
                {
                    int toC = j == 0 ? (C - 1) : C;
                    for (int i = 0; i < toC; i++)
                    {
                        retval += "*";
                    }
                    retval += "\n";
                }
                retval = retval.Substring(0, retval.Length - 1);
                return retval;
            }
            if (remainingcells < 4) return "Impossible";
            if (R < C)
            {
                int fullCols = M / R;
                int partialRow = M % R;
                if (fullCols >= 1)
                {
                    string toAdd = SolveTest(R, C - 1, M - R);
                    string temp = "";
                    if (toAdd == "Impossible") return toAdd;
                    for (int i = 0; i <= toAdd.Length; i++)
                    {
                        if (i % C == (C - 1)) temp += "*";
                        if (i < toAdd.Length) temp += toAdd[i];
                    }
                    return temp;
                }
                string toAddPartial = "";
                if ((R - partialRow) == 1)
                {
                    toAddPartial = SolveTest(R, C - 1, 1);
                    partialRow--;
                }
                else
                {
                    toAddPartial = SolveTest(R, C - 1, 0);
                }
                string tempPartial = "";
                int added = 0;
                if (toAddPartial == "Impossible") return toAddPartial;
                for (int i = 0; i <= toAddPartial.Length; i++)
                {
                    if (i % C == (C - 1))
                    {
                        if ((R-added) > partialRow)
                        {
                            tempPartial += ".";
                            added++;
                        }
                        else
                        {
                            tempPartial += "*";
                        }
                    }
                    if (i < toAddPartial.Length) tempPartial += toAddPartial[i];
                }
                return tempPartial;
            }
            else
            {
                int fullRows = M / C;
                int partalCol = M % C;
                if (fullRows >= 1)
                {
                    string toAdd = SolveTest(R - 1, C, M - C);
                    if (toAdd == "Impossible") return toAdd;
                    toAdd += "\n";
                    for (int i = 0; i < C; i++)
                    {
                        toAdd += "*";
                    }
                    return toAdd;
                }
                string toAddPartial = "";
                if ((C - partalCol) == 1)
                {
                    toAddPartial = SolveTest(R - 1, C, 1);
                    partalCol--;
                }
                else
                {
                    toAddPartial = SolveTest(R - 1, C, 0);
                }
                if (toAddPartial == "Impossible") return toAddPartial;
                toAddPartial += "\n";
                for (int i = 0; i < C; i++)
                {
                    if ((C-i) <= partalCol)
                    {
                        toAddPartial += "*";
                    }
                    else
                    {
                        toAddPartial += ".";
                    }
                }
                return toAddPartial;
            }
            return "";
        }
    }
}
