using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamR1A2012
{
    class Program
    {
        private class Car
        {
            public Car(double s, double p)
            {
                Speed = s;
                Pos = p;
            }

            public readonly double Speed;
            public double Pos;
        }

        static private int CarSorter(Car x, Car y)
        {
            if (x.Pos == y.Pos)
            {
                if (x.Speed == y.Speed)
                {
                    return 0;
                }
                else if (x.Speed < y.Speed)
                {
                    return -1;
                }
                else
                {
                    return 1;
                }
            }
            else if (x.Pos < y.Pos)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        static private double GetMinCollTime(List<Car> cars)
        {
            double minCollTime = Double.PositiveInfinity;

            for (int i = 0; i < (cars.Count - 1); i++)
            {
                Car a = cars[i];
                Car b = cars[i + 1];
                if (a.Speed > b.Speed)
                {
                    double ct = (b.Pos - (5.0 + a.Pos)) / (a.Speed - b.Speed);
                    minCollTime = Math.Min(minCollTime, ct);
                }
            }

            return minCollTime;
        }

        static private void AdvanceCars(List<Car> cars, double t)
        {
            foreach (Car c in cars)
            {
                c.Pos += t * c.Speed;
            }
        }

        static private bool SplitCars(List<Car> combined, List<Car> carsInLeftLane, List<Car> carsInRightLane)
        {
            double lastL = -100;
            double lastR = -100;
            double lastLspeed = -100;
            double lastRspeed = -100;

            foreach (Car c in combined)
            {
                bool fitsInRight = ((c.Pos - 5.0) >= lastR);
                bool fitsInLeft = ((c.Pos - 5.0) >= lastL);

                bool rightHasGap = ((c.Pos - 5.00001) >= lastR);
                bool leftHasGap = ((c.Pos - 5.00001) >= lastL);

                if (!(fitsInLeft || fitsInRight))
                {
                    // no room
                    return false;
                }
                else if (fitsInLeft && !fitsInRight)
                {
                    carsInLeftLane.Add(c);
                    lastL = c.Pos;
                    lastLspeed = c.Speed;
                }
                else if (fitsInRight && !fitsInLeft)
                {
                    carsInRightLane.Add(c);
                    lastR = c.Pos;
                    lastRspeed = c.Speed;
                }
                else
                {
                    bool goLeft;

                    if (leftHasGap && !rightHasGap)
                    {
                        // go with a gap
                        goLeft = true;
                    }
                    else if (rightHasGap && !leftHasGap)
                    {
                        // go with a gap
                        goLeft = false;
                    }
                    else
                    {
                        // go where it's slower
                        goLeft = (lastLspeed < lastRspeed);
                    }

                    // fits in both - go wherever the last traffic is slowest
                    if (goLeft)
                    {
                        carsInLeftLane.Add(c);
                        lastL = c.Pos;
                        lastLspeed = c.Speed;
                    }
                    else
                    {
                        carsInRightLane.Add(c);
                        lastR = c.Pos;
                        lastRspeed = c.Speed;
                    }
                }
            }

            return true;
        }

        static private void R1A_C()
        {
            int numTestCases = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numTestCases; zz++)
            {
                int numCars = Int32.Parse(Console.ReadLine());

                List<Car> carsInLeftLane = new List<Car>();
                List<Car> carsInRightLane = new List<Car>();

                for (int carLoop = 0; carLoop < numCars; ++carLoop)
                {
                    string carDef = Console.ReadLine();
                    string[] splits = carDef.Split(' ');

                    bool isRight = splits[0] == "R";
                    double speed = Int32.Parse(splits[1]);
                    double start = Int32.Parse(splits[2]);

                    if (isRight)
                    {
                        carsInRightLane.Add(new Car(speed, start));
                    }
                    else
                    {
                        carsInLeftLane.Add(new Car(speed, start));
                    }
                }

                string result = "???";
                double timeElapsed = 0.0;

                bool done = false;
                while (!done)
                {
                    // sort the cars by position
                    carsInLeftLane.Sort(CarSorter);
                    carsInRightLane.Sort(CarSorter);

                    // find min time for any would-be collisions
                    double minCollTime = Math.Min(GetMinCollTime(carsInLeftLane), GetMinCollTime(carsInRightLane));

                    if (minCollTime == 0.0)
                    {
                        result = timeElapsed.ToString();
                        break;
                    }

                    if (Double.IsPositiveInfinity(minCollTime))
                    {
                        result = "Possible";
                        break;
                    }

                    // should be safe to advance that far
                    AdvanceCars(carsInLeftLane, minCollTime);
                    AdvanceCars(carsInRightLane, minCollTime);
                    timeElapsed += minCollTime;

                    // pile cars into one lane, whatever
                    List<Car> combined = carsInLeftLane;
                    combined.AddRange(carsInRightLane);
                    combined.Sort(CarSorter);

                    carsInLeftLane = new List<Car>();
                    carsInRightLane = new List<Car>();

                    if (!SplitCars(combined, carsInLeftLane, carsInRightLane))
                    {
                        result = timeElapsed.ToString();
                        break;
                    }
                }

                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, result));
            }
        }

        static void Main(string[] args)
        {
            R1A_C();
        }
    }
}
