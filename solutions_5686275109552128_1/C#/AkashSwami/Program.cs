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
            using (StreamReader sr = new StreamReader(@"B-large.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"B-large-O.in", false))
                {
                    int Cases = Convert.ToInt32(sr.ReadLine());

                    for (int i = 0; i < Cases; i++)
                    {
                        int TotalCustomer = Convert.ToInt32(sr.ReadLine());
                        List<long> Value = Array.ConvertAll(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), v => long.Parse(v)).ToList();
                        long ans = Value.Max();
                        int Temp = 2;
                        while (Temp < ans)
                        {
                            ans = Math.Min(ans, Value.Sum(x => (x - 1) / Temp) + Temp);
                            Temp += 1;
                        }
                        Console.WriteLine("Case #" + (i + 1) + ": " + ans);
                        sw.WriteLine("Case #" + (i + 1) + ": " + ans);
                    }
                }
                Console.ReadLine();
            }
        }
    }
}
