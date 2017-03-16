using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleContest1
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader(@"C:\Users\Sonu\Desktop\Contest\Google\1\B-small-attempt1.in");
            var sw = new StreamWriter(@"C:\Users\Sonu\Desktop\Contest\Google\1\B-small-attempt1_output.in", true);
            sw.AutoFlush = true;
            var count = int.Parse(sr.ReadLine());
            for (var i = 0; i < count; i++)
            {
                var line1 = sr.ReadLine().Split(' ');
                var x = int.Parse(line1[0]);
                var y = int.Parse(line1[1]);
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, GetMoves(x, y)));
            }
        }

        private static string GetMoves(int x, int y)
        {
            var moves = "";
            var px = 0;
            var py = 0;
            var n = 0;
            while (x != px || y != py)
            {
                n++;
                var xd = x - px;
                var yd = y - py;
                var xa = Math.Abs(xd);
                var ya = Math.Abs(yd);
                if (xd == 0 || ya==n)
                {
                    var north = false;
                    if (yd == n) north= true;
                    else if (yd == -n) north = false;
                    else{
                        if (yd > n || (yd <0 && yd > -n)) north = true;
                        else north = false;
                    }
                    if(north){ moves += "N"; py += n; }
                    else{ moves += "S"; py -= n; }
                }
                else if (yd == 0 || xa ==n)
                {
                    var east = false;
                    if (xd == n) east = true;
                    else if (xd == -n) east = false;
                    else
                    {
                        if (xd > n || (xd < 0 && xd > -n)) east = true;
                        else east = false;
                    }
                    if (east)
                    { moves += "E"; px += n; }
                    else { moves += "W"; px -= n; }
                }
                else
                {
                    if (xa <= ya)
                    {
                        if (xd > 0)
                        { moves += "E"; px += n; }
                        else { moves += "W"; px -= n; }
                    }
                    else
                    {
                        if (yd > 0)
                        { moves += "N"; py += n; }
                        else { moves += "S"; py -= n; }
                    }
                }
            }
            return moves;
        }

       
    }
}
