using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            var problem = new Round1BProblemA();
            problem.Solve(@"..\..\files\A-small-attempt1.in");
            //problem.Solve(@"..\..\files\A-examples.in");
            Console.ReadLine();
        }
    }
}
