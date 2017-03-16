using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace Cookie {
    class Program {
        static void Main(string[] args) {
            int testCount = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First();
            for(int i = 1; i <= testCount; i++) {
                Test test = new Test();
                test.Load();
                Console.WriteLine("Case #{0}: {1}", i, test.Solve());
            }
        }
    }

    public class Test {
        double C, F, X;//C - price, F-productivity, X-target
        public void Load() {
            var pars = Console.ReadLine().Split().Select(it => Double.Parse(it, CultureInfo.InvariantCulture));
            C = pars.First();
            F = pars.Skip(1).First();
            X = pars.Last();
        }
        double calc() {
            double lastTime = X;// /2
            double timesum = 0;
            for(int n=0; ;n++) {
                double time_last = X / (2 + n * F);//время для cookie
                if(lastTime > timesum + time_last) {
                    lastTime = timesum + time_last;
                } else {
                    break;
                }
                double timen = C / (2 + n * F);//время для покупки следующей фабрики
                timesum += timen;
            }
            return lastTime;
        }
        public string Solve() {
            return calc().ToString("#0.0000000", CultureInfo.InvariantCulture);
        }
    }
}
