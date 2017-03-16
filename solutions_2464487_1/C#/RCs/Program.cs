using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.IO;

namespace FairAndSquare2
{
    class Solver
    {
        public void Run()
        {
            int cases, numCase;
            long r, t, result;
            BigInteger br, bt, lower, upper, mid, total, answer;

            StreamReader sr = new StreamReader("input.txt");
            StreamWriter sw = new StreamWriter("output.txt");

            string input;
            string[] values;

            input = sr.ReadLine();
            cases = Int32.Parse(input);

            for (numCase = 1; numCase <= cases; numCase++)
            {
                input = sr.ReadLine();
                values = input.Split(' ');

                r = long.Parse(values[0]);
                t = long.Parse(values[1]);
                br = new BigInteger(r);
                bt = new BigInteger(t);

                lower = new BigInteger(1);
                upper = new BigInteger(t);
                mid = new BigInteger();
                answer = new BigInteger();
                while(lower <= upper)
		        {
			        mid = (lower + upper) / 2;

			        total = mid * (2 * r + 2 * mid - 1);
			        if(total == t)
			        {
				        answer = mid;
				        break;
			        }
			        else if(total < t)
			        {
				        answer = mid;
				        lower = mid + 1;
			        }
			        else
			        {
				        upper = mid - 1;
			        }
		        }

                sw.WriteLine("Case #{0}: {1}", numCase, answer.ToString());
            }

            sr.Close();
            sw.Close();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Solver solver = new Solver();
            solver.Run();
        }
    }
}
