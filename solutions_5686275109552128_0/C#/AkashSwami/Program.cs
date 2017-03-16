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
            using (StreamReader sr = new StreamReader(@"B-small-attempt2.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"B-small-attempt2-O.in", false))
                {
                    int Cases = Convert.ToInt32(sr.ReadLine());

                    for (int i = 0; i < Cases; i++)
                    {
                        int TotalCustomer = Convert.ToInt32(sr.ReadLine());
                        List<int> Value = Array.ConvertAll(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), v => int.Parse(v)).ToList();
                        int ans = Value.Max();
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


                List<int> myUnSortArray = new List<int>() { 1, 5, 8, 3, 10, 9, 19, 5, 19, 4 };
                myUnSortArray.Sort();



            }
        }
    }
}
