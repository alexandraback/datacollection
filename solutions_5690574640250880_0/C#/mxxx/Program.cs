using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_QualC
{
    #region TestCase
    struct TestCaseMember
    {
        private object[] values;
        public object this[int index]
        {
            get { return values[index]; }
        }

        public int Count { get { return values.Length; } }

        public TestCaseMember(params object[] values)
        {
            this.values = values;
        }
    }

    struct TestCase
    {
        private TestCaseMember[] member;
        public TestCaseMember this[int index] { get { return member[index]; } }

        public int Count { get { return member.Length; } }

        public TestCase(TestCaseMember[] member)
        {
            this.member = member;
        }
    }
    #endregion

    class Program
    {
        #region Constant

        enum ParameterType
        {
            String,
            Int,
            Double
        }

        public static void PrintFile(TestCase[] cases)
        {
            using (Stream s = File.Create("Output.out"))
            {
                using (StreamWriter sw = new StreamWriter(s))
                {
                    for (int i = 0; i < cases.Length; i++)
                    {
                        string r = RunCase(cases[i]);
                        string result = "Case #" + (i + 1) + ": " + r;

                        Console.WriteLine(result);
                        sw.WriteLine(result);
                        //if (r == Environment.NewLine + "Impossible")
                        //    sw.WriteLine(cases[i][0][0] + " " + cases[i][0][1] + " " + cases[i][0][2]);
                    }

                    sw.Flush();
                }
            }
        }

        public static TestCase[] ReadFile()
        {
            TestCase[] result;
            using (Stream s = File.OpenRead(InputFileName + ".in"))
            {
                using (StreamReader sr = new StreamReader(s))
                {
                    int numTestCases = int.Parse(sr.ReadLine());
                    result = new TestCase[numTestCases];

                    for (int currCase = 0; currCase < numTestCases; currCase++)
                    {
                        int caseLength = (linesPerCase != -1) ? linesPerCase : int.Parse(sr.ReadLine());

                        CreateCase(result, sr, currCase, caseLength);
                    }
                }
            }

            return result;
        }

        static void Main(string[] args)
        {
            TestCase[] cases = ReadFile();

            PrintFile(cases);

            Console.WriteLine("Done!");
            Console.ReadLine();
        }

        public static void CreateCase(TestCase[] result, StreamReader sr, int currCase, int caseLength)
        {
            TestCaseMember[] member = new TestCaseMember[caseLength];
            for (int i = 0; i < caseLength; i++)
            {
                string[] line = sr.ReadLine().Split(' ');
                object[] parameter = new object[line.Length];
                for (int j = 0; j < line.Length; j++)
                {
                    if (parameterType == ParameterType.String)
                        parameter[j] = line[j];
                    else if (parameterType == ParameterType.Int)
                        parameter[j] = int.Parse(line[j], CultureInfo.InvariantCulture);
                    else if (parameterType == ParameterType.Double)
                        parameter[j] = double.Parse(line[j], CultureInfo.InvariantCulture);
                }

                member[i] = new TestCaseMember(parameter);
            }

            result[currCase] = new TestCase(member);
        }
        #endregion

        private const string InputFileName = @"C:\Users\mihai_000\Downloads\" + "C-small-attempt11";

        /// <summary>
        /// Gives the type of the test case parameters
        /// </summary>
        private const ParameterType parameterType = ParameterType.Int;

        /// <summary>
        /// How many rows follow each test case
        /// </summary>
        private const int linesPerCase = 1;

        public static string RunCase(TestCase testCase)
        {
            int height = (int)testCase[0][0];
            int width = (int)testCase[0][1];
            int mines = (int)testCase[0][2];

            int[] map = new int[width * height];

            if (width == 1 || height == 1)
            {
                for (int i = 0; i < map.Length; i++)
                {
                    if (mines == 0)
                        break;

                    if (i == map.Length - 1)
                        return Environment.NewLine + "Impossible";

                    map[i] = 1;
                    mines--;
                }
            }
            else if (width == 2)
            {
                if ((mines % 2 != 0 || width * height - mines < 4) && width * height - mines != 1)
                    return Environment.NewLine + "Impossible";

                for (int y = 0; y < height; y++)
                {
                    if (mines == 0)
                        break;

                    for (int x = 0; x < width; x++)
                    {
                        if (mines == 0)
                            break;

                        map[x + y * width] = 1;
                        mines--;
                    }
                }
            }
            else if (height == 2)
            {
                if ((mines % 2 != 0 || width * height - mines < 4) && width * height - mines != 1)
                    return Environment.NewLine + "Impossible";

                for (int x = 0; x < width; x++)
                {
                    if (mines == 0)
                        break;

                    for (int y = 0; y < height; y++)
                    {
                        if (mines == 0)
                            break;

                        map[x + y * width] = 1;
                        mines--;
                    }
                }
            }
            else
            {
                for (int x = 0; x < width - 2; x++)
                {
                    if (mines == 0)
                        break;

                    for (int y = 0; y < height - 2; y++)
                    {
                        if (mines == 0)
                            break;

                        if (x == width - 3 && y == height - 3)
                            break;

                        map[x + y * width] = 1;
                        mines--;
                    }
                }

                if (mines % 2 != 0)
                {
                    map[width - 3 + (height - 3) * width] = 1;
                    mines--;
                }

                for (int x = 0; x < width - 3; x++)
                {
                    if (mines == 0)
                        break;

                    for (int y = height - 2; y < height; y++)
                    {
                        if (mines == 0)
                            break;

                        map[x + y * width] = 1;
                        mines--;
                    }
                }

                for (int y = 0; y < height - 3; y++)
                {
                    if (mines == 0)
                        break;

                    for (int x = width - 2; x < width; x++)
                    {
                        if (mines == 0)
                            break;

                        map[x + y * width] = 1;
                        mines--;
                    }
                }

                if (mines > 0 && map[width - 3 + (height - 3) * width] == 0)
                {
                    map[width - 3 + (height - 3) * width] = 1;
                    mines--;
                }

                if ((mines > 4 || mines % 2 != 0) && mines != 7)
                    return Environment.NewLine + "Impossible";
                else
                {
                    for (int i = 0; i < mines; i++)
                    {
                        if (i == 0)
                            map[width - 2 + (height - 3) * width] = 1;
                        else if (i == 1)
                            map[width - 1 + (height - 3) * width] = 1;
                        else if (i == 2)
                            map[width - 3 + (height - 2) * width] = 1;
                        else if (i == 3)
                            map[width - 3 + (height - 1) * width] = 1;
                        else if (i == 4)
                            map[width - 2 + (height - 1) * width] = 1;
                        else if (i == 5)
                            map[width - 2 + (height - 2) * width] = 1;
                        else if (i == 6)
                            map[width - 1 + (height - 2) * width] = 1;
                    }
                }
            }

            string result = "";
            for (int i = 0; i < map.Length; i++)
            {
                if (i % width == 0)
                    result += Environment.NewLine;

                if (i == map.Length - 1)
                    result += "c";
                else if (map[i] == 1)
                    result += "*";
                else
                    result += ".";
            }
            return result;
        }
    }
}
