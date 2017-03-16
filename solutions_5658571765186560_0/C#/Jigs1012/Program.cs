using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuaternionTemp
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"D-small-attempt0.in"))
            {
                int Cases = Convert.ToInt32(sr.ReadLine());

                for (int i = 0; i < Cases; i++)
                {
                    using (StreamWriter sw = new StreamWriter(@"D-small-attempt0-O.in", true))
                    {
                        List<int> Val = Array.ConvertAll(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), v => int.Parse(v)).ToList();

                        bool ans = true;

                        if (Val[0] >= 7) ans = false;
                        else if (Val[0] > Val[1] && Val[0] > Val[2]) ans = false;
                        else if (Val[1] * Val[2] % Val[0] != 0) ans = false;
                        else if ((Val[0] + 1) / 2 > Math.Min(Val[1], Val[2])) ans = false;
                        else if (Val[0] > 0 && Val[0] < 4) ans = true;
                        else if (Val[0] == 4) ans = Math.Min(Val[1], Val[2]) > 2;
                        else if (Val[0] == 5) ans = !(Math.Min(Val[1], Val[2]) == 3 && Math.Max(Val[1], Val[2]) == 5);
                        else if (Val[0] == 6) ans = Math.Min(Val[1], Val[2]) > 3;

                        string Person = ans ? "GABRIEL" : "RICHARD";

                        sw.WriteLine("Case #" + (i + 1) + ": " + Person);
                        // Console.WriteLine("Case #" + (i + 1) + ": " + Person);
                    }
                }
                //Console.ReadLine();

            }
        }
    }
}

