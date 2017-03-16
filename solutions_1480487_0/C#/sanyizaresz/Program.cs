//DOUBLE FORMATTING: HUNGARIAN OS!!!
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Diagnostics;

namespace TaskSolution
{
    class Program
    {
        static void Main(string[] args)
        {
            char[] sep = { ' ' };
            
            TextReader tr = new StreamReader(Path.Combine(Path.GetDirectoryName(Application.ExecutablePath), "input.txt"));
            DateTime now = DateTime.Now;
            TextWriter tw = new StreamWriter(@"output.txt");

            int caseMax = Convert.ToInt32(tr.ReadLine());
            for (int caseIndex = 0; caseIndex < caseMax; caseIndex++)
            {
                string solution = string.Empty;
                string[] ps = tr.ReadLine().Split(sep);
                int n = int.Parse(ps[0]);
                List<double> p = new List<double>();
                for (int i = 0; i < n; i++)
                {
                    p.Add(double.Parse(ps[i + 1]));
                }

                
                solution = Solve(p);
                Console.WriteLine(String.Format("Case #{0}: {1}", caseIndex + 1, solution));
                tw.WriteLine(String.Format("Case #{0}: {1}", caseIndex + 1, solution));
            }
            tw.Close();
            Console.WriteLine("Ready:)");
            Console.ReadLine();
        }

      

        private static string Solve(List<double> p)
        {
            double sum = p.Sum();
            double n = p.Count;
            p.Add(double.MaxValue);
            List<double>  ps= p.ToList();
            ps.Sort();
            Dictionary<int, int> map = new Dictionary<int, int>();
            
            for (int i = 0; i < n; i++)
            {
                map.Add(i, ps.IndexOf(p[i]));
            }
            
            
            
            List<double> res = new List<double>();
            for (int i = 0; i < n; i++)
            {
                res.Add(0);
            }
            double used = sum;
            for (int i = 1; i < n+1 && used > 0; i++)
            {
               
                double d = ps[i ] - ps[i-1];
                if (d*(i)> used)
                {
                    d = used / (double)(i);
                }

                for (int j = 0; j < i; j++)
                {
                    res[j] += d;
                    used -=  d;
                }
                if (used < -0.0000001) throw new Exception();
            }
           

            if (used > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    double d = used / (double)n;
                    res[i] += d;
                }
            }
            if (Math.Abs(res.Sum() - sum)>0.000001)
            {
                throw new Exception();
            }

          

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++)
            {
                
                //sb.Append(res[i] );
                double r = res[map[i]] / sum * 100.0;
                sb.Append(r.ToString("0.00000000").Replace(',','.'));
                if (i + 1 < n) sb.Append(" ");

               

            }
            return sb.ToString();
        }


    }
}
