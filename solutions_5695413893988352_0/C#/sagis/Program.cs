using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Q2
{
    class Program
    {
        static string INPUT = "input.txt";
        static string OUTPUT = "output.txt";

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(INPUT))
            using (StreamWriter sw = new StreamWriter(OUTPUT))
            {
                int numberOfCases = int.Parse(sr.ReadLine());
                for (int i = 0; i < numberOfCases; i++)
                {
                    string line = sr.ReadLine();
                    string[] parts = line.Split(' ');
                    string[] builder = new string[2];
                    builder[0] = "";
                    builder[1] = "";

                    bool firstBigger = false;
                    bool secondBigger = false;

                    int firstDigitPos = -1;
                    int lastTwoQMarks = -1;

                    bool foundBigger = false;
                    for (int pos = 0; pos < parts[0].Length; pos++)
                    {
                        if ((firstDigitPos == -1) &&
                            (((parts[0][pos] == '?') && (parts[1][pos] != '?')) ||
                             ((parts[0][pos] != '?') && (parts[1][pos] == '?')))
                            )
                            firstDigitPos = pos;
                        else if ((parts[0][pos] == '?') && (parts[1][pos] == '?'))
                        {
                            lastTwoQMarks = pos;
                            firstDigitPos = -1;
                        }

                        if (((parts[0][pos] != '?') && (parts[1][pos] != '?'))&&
                            (parts[0][pos] != parts[1][pos]))
                        {
                            int d1 = int.Parse(parts[0][pos].ToString());
                            int d2 = int.Parse(parts[1][pos].ToString());

                            if (firstDigitPos == -1)
                                firstDigitPos = lastTwoQMarks;

                            if (d1 + 6 <= d2)
                            {
                                MakeFirstBigger(firstDigitPos, ref parts[0], ref parts[1]);
                            }
                            else if (d1 >= d2 + 6)
                            {
                                MakeFirstBigger(firstDigitPos, ref parts[1], ref parts[0]);
                            }

                            foundBigger = true;
                        }

                        if (foundBigger == true)
                            break;
                    }

                    for (int pos = 0; pos < parts[0].Length; pos++)
                    {
                        if ((parts[0][pos] == '?') && (parts[1][pos] == '?'))
                        {
                            if ((firstBigger == false) && (secondBigger == false))
                            {
                                builder[0] += "0";
                                builder[1] += "0";
                            }
                            else if (firstBigger == true)
                            {
                                builder[0] += "0";
                                builder[1] += "9";
                            }
                            else if (secondBigger == true)
                            {
                                builder[0] += "9";
                                builder[1] += "0";
                            }
                        }
                        else if ((parts[0][pos] != '?') && (parts[1][pos] == '?'))
                        {
                            builder[0] += parts[0][pos];
                            if ((firstBigger == false) && (secondBigger == false))
                                builder[1] += parts[0][pos];
                            else if (firstBigger == true)
                                builder[1] += "9";
                            else if (secondBigger == true)
                                builder[1] += "0";
                        }
                        else if ((parts[0][pos] == '?') && (parts[1][pos] != '?'))
                        {
                            builder[1] += parts[1][pos];
                            if ((firstBigger == false) && (secondBigger == false))
                                builder[0] += parts[1][pos];
                            else if (firstBigger == true)
                                builder[0] += "0";
                            else if (secondBigger == true)
                                builder[0] += "9";
                        }
                        else // Both digits
                        {
                            builder[0] += parts[0][pos];
                            builder[1] += parts[1][pos];

                            if ((firstBigger == false) && (secondBigger == false))
                            {
                                int d1 = int.Parse(parts[0][pos].ToString());
                                int d2 = int.Parse(parts[1][pos].ToString());

                                if (d1 > d2)
                                    firstBigger = true;
                                else if (d1 < d2)
                                    secondBigger = true;
                            }
                        }
                    }

                    if (builder[0].Length != builder[1].Length)
                        throw new Exception("(builder[0].Length != builder[1].Length)");

                    string output = String.Format("Case #{0}: {1} {2}", i + 1, builder[0], builder[1]);
                    sw.WriteLine(output);
                    Console.WriteLine(output);
                }
            }
        }

        private static void MakeFirstBigger(int firstDigitPos, ref string s1, ref string s2)
        {
            if (firstDigitPos == -1)
                return;

            if ((s1[firstDigitPos] == '?')&&(s2[firstDigitPos] == '?'))
            {
                s1 = s1.Substring(0, firstDigitPos) + "1" + s1.Substring(firstDigitPos + 1);
                s2 = s2.Substring(0, firstDigitPos) + "0" + s2.Substring(firstDigitPos + 1);
            }
            else if (s1[firstDigitPos] == '?')
            {
                int d2 = int.Parse(s2[firstDigitPos].ToString());
                if (d2 < 9)
                {
                    s1 = s1.Substring(0, firstDigitPos) + (d2 + 1).ToString() + s1.Substring(firstDigitPos + 1);
                }
                else if (firstDigitPos > 0)
                {
                    s1 = s1.Substring(0, firstDigitPos - 1) + "1" + s1.Substring(firstDigitPos);
                    s2 = s2.Substring(0, firstDigitPos - 1) + "0" + s2.Substring(firstDigitPos);
                }
            }
            else if (s2[firstDigitPos] == '?')
            {
                int d1 = int.Parse(s1[firstDigitPos].ToString());
                if (d1 > 0)
                {
                    s2 = s2.Substring(0, firstDigitPos) + (d1 - 1).ToString() + s2.Substring(firstDigitPos + 1);
                }
                else if (firstDigitPos > 0)
                {
                    s1 = s1.Substring(0, firstDigitPos - 1) + "1" + s1.Substring(firstDigitPos);
                    s2 = s2.Substring(0, firstDigitPos - 1) + "0" + s2.Substring(firstDigitPos);
                }
            }
        }
    }

    /*
    class Program
    {
        static string INPUT = "input.txt";
        static string OUTPUT = "output.txt";

        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(INPUT))
            using (StreamWriter sw = new StreamWriter(OUTPUT))
            {
                int numberOfCases = int.Parse(sr.ReadLine());
                for (int i = 0; i < numberOfCases; i++)
                {
                    string line = sr.ReadLine();
                    string[] parts = line.Split(' ');
                    string[] builder = new string[2];
                    builder[0] = "";
                    builder[1] = "";

                    bool firstBigger = false;
                    bool secondBigger = false;

                    for (int pos = 0; pos < parts[0].Length; pos++)
                    {
                        if ((parts[0][pos] == '?') && (parts[1][pos] == '?'))
                        {
                            if ((firstBigger == false) && (secondBigger == false))
                            {
                                if ((pos + 1 < parts[0].Length) &&
                                    ((parts[0][pos+1] != '?') && (parts[1][pos+1] != '?')))
                                {
                                    int d1 = int.Parse(parts[0][pos+1].ToString());
                                    int d2 = int.Parse(parts[1][pos+1].ToString());
                                    if (d1 + 6 <= d2)
                                    {
                                        firstBigger = true;
                                        builder[0] += "1";
                                        builder[1] += "0";
                                    }
                                    else if (d1 >= d2 + 6)
                                    {
                                        secondBigger = true;
                                        builder[0] += "0";
                                        builder[1] += "1";
                                    }
                                    else
                                    {
                                        builder[0] += "0";
                                        builder[1] += "0";
                                    }
                                }
                                else
                                {
                                    builder[0] += "0";
                                    builder[1] += "0";
                                }
                            }
                            else if (firstBigger == true)
                            {
                                builder[0] += "0";
                                builder[1] += "9";
                            }
                            else if (secondBigger == true)
                            {
                                builder[0] += "9";
                                builder[1] += "0";
                            }
                        }
                        else if ((parts[0][pos] != '?') && (parts[1][pos] == '?'))
                        {
                            builder[0] += parts[0][pos];
                            if ((firstBigger == false) && (secondBigger == false))
                            {
                                if ((pos + 1 < parts[0].Length) &&
                                    ((parts[0][pos + 1] != '?') && (parts[1][pos + 1] != '?')))
                                {
                                    int d = int.Parse(parts[0][pos].ToString());
                                    int d1 = int.Parse(parts[0][pos + 1].ToString());
                                    int d2 = int.Parse(parts[1][pos + 1].ToString());
                                    if ((d1 + 6 <= d2)&&(d > 0))
                                    {
                                        firstBigger = true;
                                        builder[1] += (d - 1).ToString();
                                    }
                                    else if ((d1 >= d2 + 6)&&(d < 9))
                                    {
                                        secondBigger = true;
                                        builder[1] += (d + 1).ToString();
                                    }
                                    else
                                    {
                                        builder[1] += parts[0][pos];
                                    }
                                }
                                else
                                    builder[1] += parts[0][pos];
                            }
                            else if (firstBigger == true)
                                builder[1] += "9";
                            else if (secondBigger == true)
                                builder[1] += "0";
                        }
                        else if ((parts[0][pos] == '?') && (parts[1][pos] != '?'))
                        {
                            builder[1] += parts[1][pos];
                            if ((firstBigger == false) && (secondBigger == false))
                            {
                                if ((pos + 1 < parts[0].Length) &&
                                    ((parts[0][pos + 1] != '?') && (parts[1][pos + 1] != '?')))
                                {
                                    int d = int.Parse(parts[1][pos].ToString());
                                    int d1 = int.Parse(parts[0][pos + 1].ToString());
                                    int d2 = int.Parse(parts[1][pos + 1].ToString());
                                    if ((d1 + 6 <= d2) && (d < 9))
                                    {
                                        firstBigger = true;
                                        builder[0] += (d + 1).ToString();
                                    }
                                    else if ((d1 >= d2 + 6) && (d > 0))
                                    {
                                        secondBigger = true;
                                        builder[0] += (d - 1).ToString();
                                    }
                                    else
                                    {
                                        builder[0] += parts[1][pos];
                                    }
                                }
                                else
                                    builder[0] += parts[1][pos];
                            }
                            else if (firstBigger == true)
                                builder[0] += "0";
                            else if (secondBigger == true)
                                builder[0] += "9";
                        }
                        else // Both digits
                        {
                            builder[0] += parts[0][pos];
                            builder[1] += parts[1][pos];

                            if ((firstBigger == false) && (secondBigger == false))
                            {
                                int d1 = int.Parse(parts[0][pos].ToString());
                                int d2 = int.Parse(parts[1][pos].ToString());

                                if (d1 > d2)
                                    firstBigger = true;
                                else if (d1 < d2)
                                    secondBigger = true;
                            }
                        }
                    }

                    if (builder[0].Length != builder[1].Length)
                        throw new Exception("(builder[0].Length != builder[1].Length)");

                    string output = String.Format("Case #{0}: {1} {2}", i + 1, builder[0], builder[1]);
                    sw.WriteLine(output);
                    Console.WriteLine(output);
                }
            }
        }
    }
    */
}
