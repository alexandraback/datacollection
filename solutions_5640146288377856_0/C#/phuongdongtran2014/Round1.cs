using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Round1
    {
        static void Main(string[] args)
        {
            Round1C_A();
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }

        static void Round1C_A()
        {
            //List<string> lines = Utils.GetStringList("input.txt");
            List<string> lines = Utils.GetStringList("A-small-attempt0.in");
            int numofCases = Convert.ToInt32(lines[0]);
            List<string> outputs = new List<string>();

            for (int indx = 0; indx < numofCases; indx++)
            {
                string line = lines[indx + 1];
                string[] arr = line.Split(null);
                int R = Int32.Parse(arr[0]);
                int C = Int32.Parse(arr[1]);
                int W = Int32.Parse(arr[2]);

                int numofFirstGuess = C / W;
                int space = C - W * numofFirstGuess;

                int numofGuess = numofFirstGuess + W;
                if (space == 0)
                    numofGuess--;

                outputs.Add("Case #" + (indx + 1) + ": " + numofGuess * R);
                Console.WriteLine("Case #" + (indx + 1) + ": ");
            }
            Utils.WriteFile(outputs, "round1c-a.txt");
        }

        static void Round11B()
        {
            List<string> lines = Utils.GetStringList("input.txt");
            //List<string> lines = Utils.GetStringList("A-small-attempt2.in");
            int numofCases = Convert.ToInt32(lines[0]);
            List<string> outputs = new List<string>();

            for (int indx = 0; indx < numofCases; indx++)
            {
                string number = lines[indx + 1];
                Int64 n = Int64.Parse(number);
                Int64 result = 0;
                Int64 i = 1;
                int len = n.ToString().Length;
                while (i <= n)
                {
                    Console.WriteLine(i);
                    int lengthi = i.ToString().Length;
                    if (lengthi < len)
                    {
                        if (i % 10 == 9)
                        {
                            Int64 reverse = ReverseInt(i);
                            if (reverse - i >= 2 && reverse <= n)
                            {
                                i = reverse;
                                result++;
                                continue;
                            }
                        }
                    }
                    else
                    {
                        if ((i % 10).ToString()[0] == n.ToString()[0])
                        {
                            Int64 reverse = ReverseInt(i);
                            if (reverse - i >= 2 && reverse <= n)
                            {
                                i = reverse;
                                result++;
                                continue;
                            }
                        }
                    }

                    i++;
                    result++;
                }

                outputs.Add("Case #" + (indx + 1) + ": " + result);
                Console.WriteLine("Case #" + (indx + 1) + ": ");
            }
            Utils.WriteFile(outputs, "round1b-a.txt");
        }

        public static Int64 ReverseInt(Int64 num)
        {
            Int64 result = 0;
            while (num > 0)
            {
                result = result * 10 + num % 10;
                num /= 10;
            }
            return result;
        }

        static void Quiz()
        {
            int N = 15;
            int[] A = { 2, 3, 1, 15, 5, 6, 7, 8, 9, 10, 11, 16, 12, 13, 14};
            for (int i = 0; i < N; i++)
            {
                if (Math.Abs(A[i]) > N) continue;
                A[Math.Abs(A[i]) - 1] = -A[Math.Abs(A[i]) - 1];
            }

            for (int i = 0; i < N; i++)
            {
                if (A[i] >= 0)
                {
                    Console.WriteLine("number:" + (i + 1));
                }
            }
        }

        static void Round1A()
        {
            //List<string> lines = Utils.GetStringList("input.txt");
            List<string> lines = Utils.GetStringList("A-large-practice.in");
            int numofCases = Convert.ToInt32(lines[0]);
            List<string> outputs = new List<string>();

            for (int indx = 0; indx < numofCases; indx++)
            {
                string NL = lines[indx * 3 + 1];

                int N = Int32.Parse(NL.Split(null)[0]);
                int L = Int32.Parse(NL.Split(null)[1]);

                List<string> outlets = lines[indx * 3 + 2].Split(null).ToList();
                List<string> devices = lines[indx * 3 + 3].Split(null).ToList();
                devices.Sort();

                int numofSwitches = 0;
                int min = Int32.MaxValue;

                for (int i = 0; i < N; i++)
                {
                    numofSwitches = 0;
                    List<string> tempOutlets = new List<string>(outlets);
                    //tempOutlets = outlets;
                    for (int j = 0; j < L; j++)
                    {
                        char element = tempOutlets[0][j];
                        char elementDevice = devices[i][j];
                        if (element != elementDevice)
                        {
                            for (int k = 0; k < N; k++)
                            {
                                char[] o = tempOutlets[k].ToCharArray();
                                o[j] = tempOutlets[k][j] == '0' ? '1' : '0';
                                tempOutlets[k] = new string(o);
                            }
                            numofSwitches++;
                        }
                    }

                    tempOutlets.Sort();
                    if (Utils.Compare(tempOutlets, devices))
                    {
                        if (min > numofSwitches) min = numofSwitches;
                        Console.WriteLine(numofSwitches);
                    }
                }

                string output = min == Int32.MaxValue ? "NOT POSSIBLE" : min.ToString();
                outputs.Add("Case #" + (indx + 1) + ": " + output);
                Console.WriteLine("Case #" + (indx + 1) + ": ");
            }
            Utils.WriteFile(outputs, "round1a.txt");
        }

        static void Round11A()
        {
            //List<string> lines = Utils.GetStringList("input.txt");
            List<string> lines = Utils.GetStringList("A-small-attempt2.in");
            int numofCases = Convert.ToInt32(lines[0]);
            List<string> outputs = new List<string>();

            for (int indx = 0; indx < numofCases; indx++)
            {
                int intervals = Int32.Parse(lines[indx * 2 + 1]);
                string numberofMushroom = lines[indx * 2 + 2];
                List<string> a = numberofMushroom.Split(null).ToList();
                List<int> mushrooms = a.Select(int.Parse).ToList();

                int medthod1 = 0;
                for (int i = 0; i < mushrooms.Count; i++)
                {
                    if (i + 1 < mushrooms.Count && mushrooms[i + 1] < mushrooms[i])
                    {
                        medthod1 += mushrooms[i] - mushrooms[i + 1];
                    }
                }

                int eaten = 0;
                int constantRate;
                for (constantRate = 0; constantRate <= 1000; constantRate++)
                {
                    eaten = 0;
                    bool shouldStop = false;
                    for (int i = 0; i < mushrooms.Count - 1; i++)
                    {
                        int e = Math.Min(mushrooms[i], constantRate * 10);
                        
                        int mushEat = Math.Max(mushrooms[i] - mushrooms[i + 1], 0);
                        if (constantRate * 10 < mushEat)
                        {
                            break;
                        }
                        if (i == mushrooms.Count - 2 && mushEat > 0)
                            e = Math.Min(e, mushEat);
                        eaten += e;

                        if (i == mushrooms.Count - 2 && constantRate * 10 >= mushEat)
                        {
                            shouldStop = true;
                        }
                    }

                    if (shouldStop) break;
                }


                outputs.Add("Case #" + (indx + 1) + ": " + medthod1.ToString() + " " + eaten.ToString());
                Console.WriteLine("Case #" + (indx + 1) + ": " + constantRate.ToString());
            }
            Utils.WriteFile(outputs, "round11a.txt");
        }
    }
}
