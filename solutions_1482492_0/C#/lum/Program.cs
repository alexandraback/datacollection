using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace R1Q2
{
    

    class Program
    {
        
        /*static Tuple<double, double> worst(List<Tuple<double, double>> l)
        {
            double dist_worst = 0;
            double t_worst = 0;
            double quot_worst = 0;
            foreach (var dt in l)
            {
                var time = dt.Item1;
                var dist = dt.Item2;
                
                if (dist == 0.0) continue;
                var quot = time / dist;
            }
            if (t_worst == 0 && dist_worst == 0)
            {
                Console.WriteLine("foo");
            }
            return new Tuple<double, double>(t_worst, dist_worst);
        }
         * */
        static void Main(string[] args)
        {
            var instream = File.OpenRead("foo.in");
            var outstream = File.OpenWrite("foo.out");

            var reader = new StreamReader(instream);
            var writer = new StreamWriter(outstream);

            var num = int.Parse(reader.ReadLine());
            System.Console.WriteLine("Num of Cases {0}", num);
            var i = 1;

            while (!reader.EndOfStream)
            {
                var three_val = reader.ReadLine().Split(' ');
                var t_case = new { d_house = double.Parse(three_val[0]),
                                    num_car_data = int.Parse(three_val[1]),
                                    num_accel_data = int.Parse(three_val[2])};

                List<Tuple<double, double>> timeDist = new List<Tuple<double, double>>();
                for (int j = 0; j < t_case.num_car_data; j++)
                {
                    var timedate = reader.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
                    timeDist.Add(new Tuple<double, double>(timedate[0], timedate[1]));
                }
                //timeDist = timeDist.Sort((t1, t2) => t1.Item1 < t2.Item1);

                for (int k = 0; k < timeDist.Count; k++)
                {
                    double last_dist;
                    double last_time;
                    double now_dist = timeDist[k].Item2;
                    double now_time = timeDist[k].Item1;
                    if(timeDist[k].Item2 > t_case.d_house)
                    {
                        if (k == 0)
                        {
                            last_dist = 0;
                            last_time = 0;
                        }
                        else
                        {
                            last_dist = timeDist[k - 1].Item2;
                            last_time = timeDist[k - 1].Item1;
                            while(timeDist.Count > k) timeDist.RemoveAt(k);
                        }

                        var dist_per_time = (now_dist - last_dist) / (now_time - last_time);
                        var dist_to_goal = t_case.d_house - last_dist;
                        var time_to_go = dist_to_goal / dist_per_time;
                        timeDist.Add(new Tuple<double, double>(last_time + time_to_go, t_case.d_house));
                        break;
                    }
                }
                timeDist.RemoveAll(t => t.Item2 > t_case.d_house);

                var accelerations = reader.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
                writer.WriteLine("Case #{0}:", i);
                Console.WriteLine("Case #{0}:", i);

                //Tuple<double, double> worstProgress = worst(timeDist);
                // TODO: limit worst time distance of goal.
                
                
                foreach(var accel in accelerations)
                {
                    double min_startTime = 0;

                    foreach (var td in timeDist)
                    {
                        var time = td.Item1;
                        var dist = td.Item2;
                        

                        double startTime = time - Math.Sqrt((dist * 2) / accel);
                        if (startTime > min_startTime)
                        {
                            min_startTime = startTime;
                        }
                    }
                    double min_endTime = min_startTime + Math.Sqrt((t_case.d_house * 2) / accel);
                    writer.WriteLine("{0}", min_endTime);
                    Console.WriteLine("{0}", min_endTime);
                }
                
                i++;
            }
            writer.Close();
            reader.Close();
            System.Console.ReadKey();
        }
    }
}
