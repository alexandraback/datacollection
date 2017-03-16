using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Studio.Algorithm.GoogleCodeJamTemplate
{
    public class Program
    {

        public static string FILE_PERFIX = "A-";
        // public static string FILE_PERFIX = "B-";
        public static bool IS_FILE_OUT = true;
        public static bool IS_FILE_IN = true;
        public static bool IS_SMALL = false;

        public static char[] SPLITERS = new char[] { ' ', '\t' };


        public static void Main(string[] args)
        {
            GoogleCodeJam();
            Console.ReadKey();
        }

        /// <summary>
        /// Algorithm should be writen here for each test case
        /// </summary>
        public static void TestCase(int Index, TextReader reader)
        {
            string CaseNo = string.Format("Case #{0}: ", Index);
            string Result = CaseNo;

            string[] splits = reader.ReadLine().Split(SPLITERS);

            int N = int.Parse(splits[0]);
            int[] s = new int[N];
            double sum = 0.0d;
            for (int i = 0; i < N; i++)
            {
                s[i] = int.Parse(splits[i + 1]);
                sum += s[i];
            }

            double[] m = new double[N];
            double target = sum * 2.0d/N;
            int x = 0;
            for (int i = 0; i < N; i++)
            {
                double p = s[i] * 1.0d / sum;
                double needed = target - s[i];
                m[i] = needed * 100.0d / sum;
                if (m[i] > 0)
                    x++;
            }

            for (int i = 0; i < N; i++)
            {
                double mi = m[i];
                if(mi < 0)
                {
                    m[i] = 0;
                    double avg = mi/x;
                    for (int j = 0; j < N; j++)
                    {
                        if (m[j] > 0)
                            m[j] += avg;
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                if (false == Result.EndsWith(" "))
                    Result += " ";
                Result += m[i].ToString();
            }

            O(Result);
        }



        public static void GoogleCodeJam()
        {
            FileStream fs = null;
            TextReader sr = null;
            if (true == Program.IS_FILE_IN)
            {
                // open file
                string fn = FILE_PERFIX + "large.in";
                if (IS_SMALL) fn = FILE_PERFIX + "small.in";
                fs = File.Open(fn, FileMode.Open);
                sr = new StreamReader(fs);
            }
            else
            {
                sr = Console.In;
            }
            // read test case count
            string line = sr.ReadLine();
            int n = int.Parse(line);
            // for each test case
            for (int cs = 1; cs <= n; cs++)
            {
                TestCase(cs, sr);
            }
            if (true == IS_FILE_IN)
            {
                // close file
                if (null != sr) sr.Close();
                if (null != fs) fs.Close();
            }
        }

        /// <summary>
        /// Short for OutputLine
        /// </summary>
        /// <param name="s"></param>
        public static void O(string format, params object[] args)
        {
            Program.OutputLine(string.Format(format, args));
        }

        public static void O(string s)
        {
            Program.OutputLine(s);
        }

        static bool IS_FIRST_RUN = true;

        public static void OutputLine(string s)
        {
            System.Console.WriteLine(s);
            // write to file ?
            if (true == IS_FILE_OUT)
            {
                string fn = FILE_PERFIX + "large.out";
                if (IS_SMALL) fn = FILE_PERFIX + "small.out";
                FileStream fs = null;
                StreamWriter sw = null;
                try
                {
                    if (true == IS_FIRST_RUN)
                    {
                        IS_FIRST_RUN = false;
                        fs = File.Open(fn, FileMode.Create);
                    }
                    else
                    {
                        fs = File.Open(fn, FileMode.Append);
                    }
                    sw = new StreamWriter(fs);
                    sw.WriteLine(s);
                }
                catch (Exception e)
                {
                    System.Console.WriteLine(e.StackTrace);
                }
                finally
                {
                    // close file
                    if (null != sw) sw.Close();
                    if (null != fs) fs.Close();
                }
            }
        }

    }
}
