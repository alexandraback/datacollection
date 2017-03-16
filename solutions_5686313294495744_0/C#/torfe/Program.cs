using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //var problem = new Question1();
            //problem.Solve(@"..\..\files\A-sample.in");
            //problem.Solve(@"..\..\files\A-small-attempt0.in");
            //problem.Solve(@"..\..\files\A-large.in");

            //var problem = new Question2();
            //problem.Solve(@"..\..\files\B-sample.in");
            //problem.Solve(@"..\..\files\B-small.in");
            //problem.Solve(@"..\..\files\B-large.in");

            var problem = new Question3();
            //problem.Solve(@"..\..\files\C-sample.in");
            problem.Solve(@"..\..\files\C-small-attempt0.in");
            //problem.Solve(@"..\..\files\C-large.in");

            //var problem = new Question4();
            //problem.Solve(@"..\..\files\D-sample.in");
            //problem.Solve(@"..\..\files\D-small.in");
            //problem.Solve(@"..\..\files\D-large.in");

            Console.ReadLine();
        }
    }
}
