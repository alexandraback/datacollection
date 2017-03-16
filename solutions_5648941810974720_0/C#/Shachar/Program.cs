using Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2016_round_1B
{
    class Program
    {
        static void Main(string[] args)
        {
            MainProgram program = new MainProgram(@"D:\Google Code Jam\GoogleCodeJamFiles\20161B\A-small-attempt0.in");
            program.Work(CreateCase);
        }

        public static ICase CreateCase()
        {
            return new Getting_the_Digits();
        }
    }
}
