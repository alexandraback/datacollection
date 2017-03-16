using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Codejam
{
    class B
    {
        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine());
            Dictionary<int, int> colls;
            for (int current = 1; current <= t; current++)
            {
                colls = new Dictionary<int, int>();
                int lines = Convert.ToInt32(Console.ReadLine());
                for(int i = 1; i <= 2 * lines - 1; i++)
                {
                    foreach(string str in Console.ReadLine().Split(' '))
                    {
                        int temp = Convert.ToInt32(str);
                        if (colls.Keys.Contains(temp))
                        {
                            colls[temp]++;
                        }
                        else
                        {
                            colls.Add(temp,1);
                        }
                    }
                }

             Console.WriteLine("Case #{0}: {1}",current,string.Join(" ",colls.Where(x => x.Value % 2 == 1).Select(x=>x.Key).OrderBy(x=> x).ToArray()));

            }
        }
    }
}
