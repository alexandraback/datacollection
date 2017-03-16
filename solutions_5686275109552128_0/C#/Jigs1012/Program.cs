using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace infinitehouseofpancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"B-small-attempt0.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"B-small-attempt0-O.in", false))
                {
                    int Cases = Convert.ToInt32(sr.ReadLine());

                    for (int i = 0; i < Cases; i++)
                    {
                        sr.ReadLine();
                        List<long> Value = Array.ConvertAll(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), v => long.Parse(v)).ToList();
                        long Result = Value.Max();
                        int MinValue = 2;
                        while (MinValue < Result)
                        {
                            Result = Math.Min(Result, Value.Sum(v => (v - 1) / MinValue) + MinValue);
                            MinValue += 1;
                        }
                        //Console.WriteLine("Case #" + (i + 1) + ": " + Result);
                        sw.WriteLine("Case #" + (i + 1) + ": " + Result);
                    }
                }
            }
        }
    }
}
