using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Elf
{
    class Program {
        static void Main(string[] args) {
            int TCount = Int32.Parse(Console.In.ReadLine());
            for(int i = 0; i < TCount; i++) {
                Test test = new Test();
                test.Load();
                Console.Out.WriteLine("Case #" + (i + 1) + ": " + test.Solve());
            }
        }
    }
    class Test {
        long p;
        long q;
        public void Load() {
            var par = Console.ReadLine().Split('/').Select(it =>Int64.Parse(it));
            p = par.First();
            q = par.Last();
        }
        int calc()
        {
            int result = 0;
            long pp = p;
            for (int i = 0; i < 41; i++)
            {
                pp *= 2;
                if (pp >= q)
                {
                    pp -= q * (pp / q);
                    if (result == 0)
                    {
                        result = i+1;
                    }
                    if (pp == 0)
                    {
                        return result;
                    }
                }
            }
            return -1;
        }
        public string Solve() {
            int c = calc();
            if(c==-1)
            return "impossible";
            return c.ToString();
        }
    }
}

