using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace CodeJam_1C_2012
{
    class Problem_C
    {

        public static void Prob_C(string[] args)
        {
            string inputFile = "B-small-attempt1.in";
            // string inputFile = "C-small-attempt0.in";
            string outputFile = "B-small-result1.out";

            TextReader reader = new StreamReader(inputFile);
            TextWriter writer = new StreamWriter(outputFile);

            int TestCases = int.Parse(reader.ReadLine());

            for (int caseCount = 0; caseCount < TestCases; caseCount++)
            {
                string line = reader.ReadLine();
                string[] words = line.Split(' ');

                //output:
                string sout = "Case #" + (caseCount + 1) + ": ";
                writer.WriteLine(sout);
                Console.WriteLine(sout);
                writer.Flush();

                double D = double.Parse(words[0], CultureInfo.InvariantCulture);
                int N = int.Parse(words[1]);
                int A = int.Parse(words[2]);

                List<Pair> otherCar = new List<Pair>();
                for (int i = 0; i < N; i++)
                {
                    line = reader.ReadLine();
                    words = line.Split(' ');

                    otherCar.Add(new Pair()
                    {
                        Time = double.Parse(words[0], CultureInfo.InvariantCulture),
                        Position = double.Parse(words[1], CultureInfo.InvariantCulture)
                    });   
                }
                List<double> Accelerations = new List<double>();
                line = reader.ReadLine();
                    words = line.Split(' ');
                for (int i = 0; i < A; i++)
                {
                    Accelerations.Add(double.Parse(words[i], CultureInfo.InvariantCulture));
                }

                foreach(var acc in Accelerations)
                {
                    double wait = 0;
                    for (int i = 0; i < otherCar.Count; i++)
                    {
                        Pair othercar = otherCar[i];
                        double othercartime = othercar.Time;
                        if (othercar.Position > D)
                        {
                            double timeoc = 0;
                            double posoc = 0;
                            if(i > 0)
                            {
                                timeoc = otherCar[i-1].Time;
                                posoc = otherCar[i-1].Position;
                            }
                            if (posoc > D)
                            {
                                continue;
                            }
                            double frac = (othercar.Position - D) / (othercar.Position - posoc);
                            othercartime = timeoc + frac * (othercar.Time - timeoc);
                        }
                        
                        double time = Math.Sqrt(2 * Math.Min(othercar.Position, D) / acc);                            
                        time = othercartime - time;
                        wait = Math.Max(wait, time);
                    }

                    double timeNeeded = wait + Math.Sqrt(2 * D / acc);

                    writer.WriteLine(timeNeeded.ToString(CultureInfo.InvariantCulture));
                    Console.WriteLine(timeNeeded.ToString(CultureInfo.InvariantCulture));
                    writer.Flush();
                }


            }



            Console.ReadLine();
        }

        public class Pair
        {
            public double Time { get; set; }
            public double Position { get; set; }
        }
    }
}
