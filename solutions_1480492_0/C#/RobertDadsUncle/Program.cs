using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round_1A_Problem_A
{
    public class CaseData
    {
        public enum LaneEnum
        {
            Left,
            Right
        }
        public class Car
        {
            private decimal m_Position;
            private int m_Speed;
            private LaneEnum m_CurrentLane;


            public Car(LaneEnum currentLane, int speed, int position)
            {
                m_Position = position;
                m_Speed = speed;
                m_CurrentLane = currentLane;
            }

            public decimal Position
            {
                get { return m_Position; }
                set { m_Position = value; }
            }

            public int Speed
            {
                get { return m_Speed; }
                set { m_Speed = value; }
            }

            public LaneEnum CurrentLane
            {
                get { return m_CurrentLane; }
                set { m_CurrentLane = value; }
            }


            public void SwitchLanes()
            {
                if(CurrentLane == LaneEnum.Left)
                {
                    CurrentLane = LaneEnum.Right;
                }
                else
                {
                    CurrentLane = LaneEnum.Left;
                }
            }
        }

        private List<Car> m_Cars = new List<Car>();

        public CaseData(List<Car> cars)
        {
            m_Cars = cars;
        }

        decimal DELTA = new decimal(0.01);
        decimal MAXTIME = new decimal(10000);

        public string Solve()
        {
            if (m_Cars.Count <= 2)
            {
                return "Possible";
            }
            decimal bestTime = decimal.MinValue;

            var carCopy = new Car[m_Cars.Count];
            m_Cars.CopyTo(carCopy);

            bestTime = Search(0, carCopy);

            if (bestTime == MAXTIME)
            {
                return "Possible";
            }
            return bestTime.ToString();
        }


        private decimal Search(decimal time, Car[] carCopy)
        {
            while (time < MAXTIME)
            {
                Advance(DELTA);
                time += DELTA;
                Car collidera;
                Car colliderb;
                if (Colliding(out collidera, out colliderb))
                {
                    collidera.SwitchLanes();
                    Car collidertest;
                    if (Colliding(out collidertest, out collidertest))
                    {
                        collidera.SwitchLanes();
                        colliderb.SwitchLanes();    
                        if (Colliding(out collidertest, out collidertest))
                        {
                            return time;
                        }
                    }
                }
            }
            return MAXTIME;
        }


        private bool Colliding(out Car collidera, out Car colliderb)
        {
            collidera = null;
            colliderb = null;
            for(int i=0;i<m_Cars.Count;i++)
            {
                for(int j=i+1;j<m_Cars.Count;j++)
                {
                    if(m_Cars[i].CurrentLane == m_Cars[j].CurrentLane)
                    {
                        if(Math.Abs(m_Cars[i].Position-m_Cars[j].Position) <= 5)
                        {
                            collidera = m_Cars[i];
                            colliderb = m_Cars[j];
                            return true;
                        }
                    }
                }
            }
            return false;
        }


        private void Advance(decimal d)
        {
            foreach(var car in m_Cars)
            {
                car.Position += car.Speed * d;
            }
        }
    }
    class Program
    {
        private const string INPUT_FILE = "C-small-attempt2.in";
        const string OUTPUT_FILE = "C-small-attempt2.out";

        static void Main(string[] args)
        {
            var lines = new List<string>();
            using (var sr = new StreamReader(INPUT_FILE))
            {
                while (!sr.EndOfStream)
                {
                    lines.Add(sr.ReadLine());
                }
            }

            var numTestCases = int.Parse(lines[0]);

            var outputLines = new List<string>();
            int currentLineNumber = 1;
            var cases = new List<CaseData>();
            for (int i = 0; i < numTestCases; i++)
            {
                var caseData = lines[currentLineNumber];
                currentLineNumber++;

                var ints = new List<int>();
                {
                    var tokens = caseData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count == 1);
                var numCars = ints[0];

                var cars = new List<CaseData.Car>();

                for (int carIndex = 0; carIndex < numCars; carIndex++)
                {
                    var carData = lines[currentLineNumber];
                    currentLineNumber++;
                    var tokens = carData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    var carInts = new List<int>();
                    cars.Add(new CaseData.Car(tokens[0] == "L" ? CaseData.LaneEnum.Left : CaseData.LaneEnum.Right, int.Parse(tokens[1]), int.Parse(tokens[2])));
                }
                cases.Add(new CaseData(cars));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + caseData.Solve();
                outputLines.Add(output);
            }

            using (var sw = new StreamWriter(OUTPUT_FILE))
            {
                foreach (var line in outputLines)
                {
                    sw.Write(line + "\n");
                }
            }
        }
    }
}
