using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016Q_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (var i = 0; i < T; i++)
            {
                var s = Console.ReadLine();
                var r = 0;
                for(var j=1;j<s.Length;j++)
                    if (s[j - 1] != s[j])
                        r++;
                if (s[s.Length - 1] == '-')
                    r++;
                Console.WriteLine("Case #{0}: {1}", i + 1, r);
            }
        }
    }
}
