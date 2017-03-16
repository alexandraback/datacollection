using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamSolutions
{
    class Program
    {
        static void Main(string[] args)
        {
            //var c = new InfiniteHouseOfPanckacakes();
            //c.Solve("dijkstra.in");

            var c = new Dijkstra();
            c.Solve("C-large.in");
        }
    }
}
