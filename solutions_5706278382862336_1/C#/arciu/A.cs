using System;
using System.Globalization;
using System.Linq;
using System.Threading;

namespace GCJ2014
{

    class A
    {

        static long Nwd(long a, long b)
        {
            long w;
            while (b != 0)
            {
                w = a % b;
                a = b;
                b = w;
            }
            return a;
        }


        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
            var T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                var c = Console.ReadLine().Split('/').Select(x=> long.Parse(x)).ToArray();
                long nwd = Nwd(c[0], c[1]);
                c[0] /= nwd;
                c[1] /= nwd;
                int? cond = null;
                for (int i = 1; i <= 41; i++)
                {
                    if(((1L)<<i) ==c [1]){
                        cond = i;
                    }
                }
                if(!cond.HasValue){
                    Console.WriteLine("Case #{0}: impossible", t);
                    continue;
                }
                 
                for (int i = 1; i <= cond; i++)
                {
                    if((((1L)<<(cond - i)) &c [0] )!= 0){
                        Console.WriteLine("Case #{0}: {1}", t, i);
                        break;
                    }
                }                                    
            }
        }
    }
}
