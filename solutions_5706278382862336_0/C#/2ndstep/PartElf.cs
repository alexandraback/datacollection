using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B3
{
    public class PartElf
    {
        static void Main(string[] args)
        {
            PartElf.Go();
            Console.ReadLine();

        }
        private ulong P;
        private ulong Q;
        private int t;

        public PartElf(ulong P, ulong Q,int t)
        {            
            this.P = P;
            this.Q = Q;
            this.t = t;
        }
        public static void Go()
        {
            List<Task<string>> tasks = new List<Task<string>>();
            int tests = int.Parse(Console.ReadLine());
            for (int t = 0; t < tests; t++)
            {
                ulong[] input = ReadArray();
                ulong P = input[0];
                ulong Q = input[1];
                PartElf e = new PartElf(P, Q,t);
                tasks.Add(e.Count());
            }

            //Task.WaitAll(tasks.ToArray());
            foreach (var item in tasks)
            {
                Console.WriteLine(item.Result);
            }
        }        
        private static ulong[] ReadArray()
        {
            return Console.ReadLine().Split(new char[] { '/' }).Select(s => ulong.Parse(s)).ToArray();
        }
        public async Task<string> Count()
        {
            while(gen <= 40 && P > 0)
            {
                ulong p = P * Row;
                ulong q = Q * Row;
                ulong minus = (ulong)Math.Floor((decimal)p / Q);
                if (minus > 0 && result == 0)
                    result = gen+1;
                p -= Q * minus;
                if (p % Row != 0)
                    return GetResponse();
                P = p / Row;                
                NextGen();
            }
            return GetResponse(result);

        }
        private void NextGen()
        {
            gen++;
            Row*=2;
        }
        int result = 0;
        int gen = 0;
        private ulong Row = 2;
        public ulong getResult(ulong input)
        {
            ulong result = 1;
            ulong dec = 2;
            while(dec <input)
            {
                result++;
                dec *= 2;
            }
            return result;

        }
        public string GetResponse(int? result=null)
        {
            return string.Format("Case #{0}: {1}",this.t +1,result == null ? "impossible" : result.ToString());
        }
    }
}
