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

            int N = int.Parse(reader.ReadLine());

            Game[] gs = new Game[N];

            for (int i = 0; i < N; i++)
            {
                string[] splits = reader.ReadLine().Split(SPLITERS);
                gs[i] = new Game();
                gs[i].a = int.Parse(splits[0]);
                gs[i].b = int.Parse(splits[1]);
            }

            int acc = int.MaxValue;
            int total = 0;
            int stars = 0;
            while(acc > 0)
            {
                acc = 0;
                // find a way to complete
                Game mb = null;
                for (int i = 0; i < N; i++)
                {
                    Game g = gs[i];
                    if (false == g.bc && g.b <= stars)
                    {
                        if (null == mb || mb.b > g.b)
                            mb = g;
                    }
                }

                if (null != mb)
                {
                    acc++;
                    total++;
                    mb.bc = true;
                    stars++;
                    if (mb.ac == false)
                    {
                        mb.ac = true;
                        stars++;
                    }
                    continue;
                }

                // no b found.
                var gas = (from g in gs where g.ac == false && g.a <= stars select g).ToArray();
                Game ma = null;
                for (int i = 0; i < gas.Count(); i++)
                {
                    Game g = gas[i];
                    if (false == g.ac)
                    {
                        if (null == ma || ma.b < g.b)
                        {
                            ma = g;
                        }
                    }
                }

                if (null != ma)
                {
                    acc++;
                    total++;
                    ma.ac = true;
                    stars++;
                }
            }

            bool bc = true;
            for (int i = 0; i < gs.Count(); i++)
                bc &= gs[i].bc;

            if(false == bc)
                O(Result + "Too Bad");
            else
                O(Result + total);
        }

        public class Game
        {
            public int a;
            public int b;
            public bool ac = false;
            public bool bc = false;
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
