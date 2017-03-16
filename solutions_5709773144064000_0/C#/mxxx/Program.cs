using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_QualB
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
                        string result = "Case #" + (i + 1) + ": " + RunCase(cases[i]);
                        Console.WriteLine(result);
                        sw.WriteLine(result);
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

        private const string InputFileName = @"C:\Users\mihai_000\Downloads\" + "B-small-attempt1";

        /// <summary>
        /// Gives the type of the test case parameters
        /// </summary>
        private const ParameterType parameterType = ParameterType.Double;

        /// <summary>
        /// How many rows follow each test case
        /// </summary>
        private const int linesPerCase = 1;

        public static string RunCase(TestCase testCase)
        {
            double farmCosts = (double)testCase[0][0];
            double farmPerSecond = (double)testCase[0][1];
            double goal = (double)testCase[0][2];

            double bestTime = double.MaxValue;
            int farms = 0;
            while (true)
            {
                double cookiesPerSecond = 2;
                double time = 0;
                for (int i = 0; i < farms; i++)
                {
                    time += farmCosts / cookiesPerSecond;
                    cookiesPerSecond += farmPerSecond;
                }
                 time += goal / cookiesPerSecond;
                 farms++;

                 if (time < bestTime)
                     bestTime = time;
                 else
                     break;
            }

            return bestTime.ToString("0.0000000", CultureInfo.InvariantCulture);
        }
    }
}