using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HallOfMirrors
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\HallOfMirrors\D-small-attempt3.in.txt");
            int caseNum = int.Parse(lines[0]);
            int curLine = 1;
            for (int cn = 1; cn < caseNum+1; cn++)
            {
                int result = 0;
                List<double> dic = new List<double>();
                List<Angle> angleDic = new List<Angle>();
                var temp = lines[curLine].Split(' ');
                int H = int.Parse(temp[0]);
                int W = int.Parse(temp[1]);
                int D = int.Parse(temp[2]);
                curLine++;
                int h = 0;
                for (int cl = curLine; cl < curLine + H; cl++)
                {
                    //Console.WriteLine(lines[cl]);
                    for (int w = 0; w < W; w++)
                    {
                        if (lines[cl][w] == 'X')
                        {
                            int left = w * 2 - 1;
                            int right = (W - w) * 2 - 3;
                            int top = h * 2 - 1;
                            int bottom = (H - h) * 2 - 3;
                            Console.WriteLine(left + "," + right + "," + top + "," + bottom);
                            //prepare values
                            List<int> xvalues = new List<int>();
                            List<int> yvalues = new List<int>();
                            int le = left, ri = right, to = top, bo = bottom;
                            bool step=true;
                            while (true)
                            {
                                if (left < D)
                                {
                                    xvalues.Add(left);
                                }
                                if (right < D)
                                {
                                    xvalues.Add(-1*right);
                                }
                                if (top < D)
                                {
                                    yvalues.Add(top);
                                }
                                if (bottom < D)
                                {
                                    yvalues.Add(-1*bottom);
                                }
                                if (left >= D && right >= D && top >= D && bottom >= D)
                                {
                                    break;
                                }
                                if (step)
                                {
                                    left += ri;
                                    right += le;
                                    top += bo;
                                    bottom += to;
                                }
                                else
                                {
                                    left += le;
                                    right += ri;
                                    top += to;
                                    bottom += bo;
                                }
                                step = !step;
                            }
                            //Console.WriteLine("xvalues");
                            //foreach (var item in xvalues)
                            //{
                            //    Console.WriteLine(item);
                            //}
                            //Console.WriteLine("yvalues");
                            //foreach (var item in yvalues)
                            //{
                            //    Console.WriteLine(item);
                            //}
                            result = (le <= D ? 1 : 0) + (ri <= D ? 1 : 0) + (to <= D ? 1 : 0) + (bo <= D ? 1 : 0);
                            foreach (var x in xvalues)
                            {
                                foreach (var y in yvalues)
                                {
                                    //double key = Math.Atan2(y, x);
                                    //if (!dic.Contains(key))
                                    //{
                                    //    dic.Add(key);
                                    Angle angle = new Angle()
                                    {
                                        x = x,
                                        y = y,
                                        signx = x > 0,
                                        signy = y > 0
                                    };
                                    if(!angleDic.Contains(angle))
                                    {
                                        angleDic.Add(angle);
                                        var dis = Math.Sqrt(x * x + y * y);
                                        if (dis < D)
                                        {
                                            //Console.WriteLine(x + "," + y + "," + dis);
                                            result++;
                                        }
                                    }
                                }
                            }
                            //Console.WriteLine(result);
                        }
                        //Console.WriteLine(lines[cl][w]);
                    }
                    h++;
                }
                curLine += H;
                var resultLine = string.Format("Case #{0}: {1}\n", cn, result);
                Console.Write(resultLine);
                File.AppendAllText(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\HallOfMirrors\D-small-attempt3.out.txt", resultLine);
            }

        }
    }

    class Angle
    {
        public int x;
        public int y;
        public bool signx;
        public bool signy;
        public override bool Equals(object obj)
        {
            Angle a = obj as Angle;
            return Math.Abs(.1 * x / a.x - .1 * y / a.y) < 0.00000000001 && signx == a.signx && signy == a.signy;
        }
    }
}
