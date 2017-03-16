using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace ProblemB
{
    class ProblemB
    {
        class OtherPosition
        {
            public double t { get; set; }
            public double x { get; set; }
        }

        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en-US");
            System.Threading.Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("en-US");

            string inputFolder = @"c:\Devel\X\GoogleCodeJam2012_Round1C\Inputs";
            string inputFile = "B-small-attempt0.in";

            string outputFile = Path.GetFileNameWithoutExtension(inputFile) + ".out";

            using (StreamReader sr = new StreamReader(Path.Combine(inputFolder, inputFile)))
            using (StreamWriter sw = new StreamWriter(Path.Combine(inputFolder, outputFile)))
            {
                string line;

                line = sr.ReadLine();
                int T = int.Parse(line);

                for (int testcase = 0; testcase < T; testcase++)
                {
                    line = sr.ReadLine();
                    string[] parts = line.Split(' ');
                    double D = double.Parse(parts[0]);
                    int N = int.Parse(parts[1]);
                    int A = int.Parse(parts[2]);

                    OtherPosition[] other = new OtherPosition[N+1];

                    for (int i = 0; i < N; i++)
                    {
                        line = sr.ReadLine();
                        parts = line.Split(' ');
                        other[i] = new OtherPosition()
                        {
                            t = double.Parse(parts[0]),
                            x = double.Parse(parts[1]),
                        };
                    }
                    other[N] = new OtherPosition()
                    {
                        t = double.MaxValue,
                        x = other[N - 1].x,
                    };

                    line = sr.ReadLine();
                    parts = line.Split(' ');

                    double[] accelerations = new double[A];
                    for (int i = 0; i < A; i++)
                    {
                        accelerations[i] = double.Parse(parts[i]);
                    }

                    double[] solution = new double[A];

                   // Parallel.For(0, A, a =>
                    for(int a = 0; a < A; ++a )
                    {
                        double furthest = other[0].x;
                        double position = 0.0;
                        double speed = 0.0;
                        double elapsed = 0.0;

                        // initial timescale
                        elapsed += TimeToDestination(ref position, furthest, ref speed, accelerations[a]);

                        double otherPosition = WhereIsMyOpponent(D, N, other, elapsed);

                        while (position < D)
                        {
                            // if we are behind the other
                            if (Math.Abs(otherPosition - position) < 0.000001)
                            {
                                TrackOtherCar(D, N, other, accelerations[a], ref position, ref otherPosition, ref elapsed, ref speed);
                            }
                            // otherwise, catchup
                            else
                            {
                                elapsed += TimeToDestination(ref position, otherPosition, ref speed, accelerations[a]);
                                otherPosition = WhereIsMyOpponent(D, N, other, elapsed);
                            }
                        }

                        solution[a] = elapsed;
                    }
                    //);

                    // code thing here

                    // write solution here
                    sw.WriteLine("Case #{0}:", testcase + 1);
                    for (int i = 0; i < A; i++)
                    {
                        sw.WriteLine("{0:F6}", solution[i]);
                    }
                }
            }
        }

        private static void TrackOtherCar(
            double D, 
            int N, 
            OtherPosition[] other,
            double acceleration,
            ref double position, 
            ref double otherPosition, 
            ref double elapsed, 
            ref double speed)
        {
            for (int i = 0; i < N; i++)
            {
                if (other[i].t <= elapsed && other[i + 1].t > elapsed)
                {
                    double otherspeed = (other[i + 1].x - other[i].x) / (other[i + 1].t - other[i].t);
                        
                    double timeAtNext;
                    if (other[i + 1].x <= D)
                    {
                        timeAtNext = other[i + 1].t;
                    }
                    else
                    {
                        timeAtNext = other[i].t + (D - other[i].x) / otherspeed;
                    }

                    double timeToNextPoint = timeAtNext - elapsed;

                    // need to break
                    if (speed >= otherspeed)
                    {
                        speed = otherspeed;
                        elapsed += timeToNextPoint;
                        otherPosition = other[i + 1].x;
                        position += other[i + 1].x; // timeToNextPoint* speed;
                    }
                    // other is speeding away
                    else
                    {
                        double takeOnTime = (otherspeed - speed) / acceleration;

                        // if I can take on him before the next point
                        if (takeOnTime > timeToNextPoint)
                        {
                            // calculate to take on point
                            takeOnTime = timeToNextPoint;
                        }

                        position = speed * takeOnTime + 0.5 * acceleration * takeOnTime * takeOnTime;
                        otherPosition = WhereIsMyOpponent(D, N, other, elapsed + takeOnTime);
                        speed += acceleration * takeOnTime;
                        elapsed += takeOnTime;
                    }
                    return;
                }
            }

            throw new InvalidOperationException();
        }

        private static double WhereIsMyOpponent(
            double D, 
            int N, 
            OtherPosition[] other, 
            double elapsed)
        {
            bool foundPosition = false;
            double otherPosition = 0;
            for (int i = 0; i < N - 1; i++)
            {
                if (other[i].t <= elapsed && other[i + 1].t > elapsed)
                {
                    foundPosition = true;
                    double otherspeed = (other[i + 1].x - other[i].x) / (other[i + 1].t - other[i].t);
                    otherPosition = (elapsed - other[i].t) * otherspeed;
                    break;
                }
            }
            if (!foundPosition)
            {
                otherPosition = D;
            }
            return otherPosition;
        }

        private static double TimeToDestination(
            ref double position, 
            double furthest, 
            ref double speed, 
            double acceleration)
        {
            double distance = furthest - position;

            double D = speed * speed - 4 * acceleration / 2 * (-distance);
            double time = (-speed + Math.Sqrt(D)) / acceleration;

            speed += time * acceleration;
            position = furthest;

            return time;
        }

        //private static double DistanceWhileLinearAcceleration (
        //    ref double position,

    }
}
