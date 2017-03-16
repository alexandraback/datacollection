using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Numerics;

namespace Codejam_2013Round1A
{
    class Program
    {
        static void Main(string[] args)
        {

            FileStream fs = new FileStream("output.out", FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);

            StreamReader sr = new StreamReader("A-small-attempt0.in");

            String line;
            line = sr.ReadLine(); //Number of cases
            int case_num = int.Parse(line.Trim());

            for (int case_id = 0; case_id < case_num; case_id++)
            {
                line = sr.ReadLine(); //Case title information
                string[] strRT;
                strRT = line.Split(' ');
                //int R = int.Parse(strRT[0].ToString().Trim()), T = int.Parse(strRT[1].ToString().Trim());

                string caseResult=CaseSolver(strRT[0].ToString().Trim(),strRT[1].ToString().Trim());
                Console.WriteLine("Case #" + (case_id + 1).ToString() + ": "+caseResult);
                sw.WriteLine("Case #" + (case_id + 1).ToString() + ": "+caseResult);
            }//for case_id ...

            sw.Flush();
            sr.Close();
            sw.Close();
            fs.Close();
            Console.WriteLine("Done!");
        }// Main

        static string CaseSolver(string r, string t)
        {
            BigInteger R = BigInteger.Parse(r), T=BigInteger.Parse(t);
            BigInteger account = 0;
            //while (T>=0)
            //{
            //    if (T >= R * 2 + 1)
            //        account++;

            //    T -= R * 2 + 1;
            //    R += 2;
            //}

            BigInteger a = 2, b = 2 * R - 1, c = -T;
            account = (SqRtN(b * b - 4 * a * c) - b) / (a * 2);
            return account.ToString() ;
        }//CaseSolver

        static BigInteger SqRtN(BigInteger N)
        {
            if (0 == N)
                return 0;
            BigInteger n1= (N >> 1) + 1;
            BigInteger n2= (n1 + (N / n1)) >> 1;
            while (n2 < n1)
            {
                n1 = n2;
                n2 = (n1 + (N / n1)) >> 1;
            }
            return n1;
        }
    }
}
