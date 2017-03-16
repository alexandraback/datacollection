using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Studio.Algorithm.GoogleCodeJamTemplate
{
    public class Program
    {

        public static string FILE_PERFIX = "B-";
        // public static string FILE_PERFIX = "B-";
        public static bool IS_FILE_OUT = true;
        public static bool IS_FILE_IN = true;
        public static bool IS_SMALL = true;

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
            int E = int.Parse(splits[0]);
            int R = int.Parse(splits[1]);
            int N = int.Parse(splits[2]);
            splits = reader.ReadLine().Split(SPLITERS);
            IList<int> values = new List<int>();
            for (int i = 0; i < N; i++ )
            {
                var x = int.Parse(splits[i]);
                values.Add(x);
            }

            long[] prev = new long[E + 1];
            long[] next = new long[E + 1];
            
            for(int e = 0; e <= E; e++)
            {
                prev[e] = values[0]*(E - e);
            }


            long max = 0;
            for (int i = 1; i < N; i++)
            {
                var vi = values[i];
                for(int en = 0; en <= E; en++)
                {
                    max = 0;
                    for(int ep = en - R; ep <= E; ep++)
                    {
                        if(ep < 0) continue;
                        var current = ep + R;
                        if (current > E) current = E;
                        var spend = current - en;
                        var gain = spend*vi + prev[ep];
                        if (gain > max)
                            max = gain;
                    }
                    next[en] = max;
                }
                prev = next;
                next = new long[E + 1];
            }

            max = prev.Max(); 

            O(Result + max);
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
