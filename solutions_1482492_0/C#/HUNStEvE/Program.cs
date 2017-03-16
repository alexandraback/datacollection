using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace _2
{
    public struct PointTime
    {
        public double point;
        public double time;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;            

            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                string line = Console.ReadLine();
                string[] s = line.Split(new char[] { ' ' });
                double D = Double.Parse(s[0]);
                int N = Int32.Parse(s[1]);
                int A = Int32.Parse(s[2]);

                PointTime[] othercar = new PointTime[N];

                for (int j = 0; j < N; ++j)
                {
                    string line2 = Console.ReadLine();
                    string[] s2 = line2.Split(new char[] { ' ' });

                    PointTime pt = new PointTime();                    
                    pt.time = Double.Parse(s2[0]);
                    pt.point = Double.Parse(s2[1]);

                    if ((pt.point > D) && (j > 0) && (othercar[0].point < D))
                    {
                        pt.time = othercar[j-1].time + (pt.time - othercar[j-1].time) * (pt.point - D) / (pt.point - othercar[j-1].point);
                        pt.point = D;
                        othercar[j] = pt;
                        break;
                    }

                    othercar[j] = pt;
                }

                string line3 = Console.ReadLine();
                string[] s3 = line3.Split(new char[] { ' ' });

                Console.Out.WriteLine("Case #" + (i + 1) + ":");
                for (int j = 0; j < A; ++j)
                {
                    double acc = Single.Parse(s3[j]);

                    //othercar[0].myBestTime = Math.Max(Math.Sqrt(2*othercar[0].point*acc), othercar[0].time);
                    //othercar[0].myBestSpeed = Math.Sqrt(2 * acc * othercar[0].point);
                    //othercar[0].myBestSpeedTime = 
                    //for (int k = 1; k < othercar.Length; ++k)
                    //{
                        
                    //    //float mytime = 
                    //}


                    //N == 2  !!!!!
                    double mybesttime;

                    if (N == 1)
                    {
                        mybesttime = Math.Sqrt(2 * D / acc);
                    }
                    else
                    {
                        if (othercar[0].point <= D)
                        {
                            mybesttime = Math.Max(Math.Sqrt(2 * D / acc), othercar[1].time);
                        }
                        else
                        {
                            mybesttime = Math.Sqrt(2 * D / acc);
                        }
                    }



                    Console.Out.WriteLine(mybesttime);



                }

            }
        }
    }
}
