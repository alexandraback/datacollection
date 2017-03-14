using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012_D
{
    class Program
    {



        static void Main(string[] args)
        {            
            
            
            string line = string.Empty;
            System.IO.StreamReader file = new System.IO.StreamReader("C:\\googleCodeJam\\D\\test.in");
            System.IO.StreamWriter resultFile = new StreamWriter("C:\\googleCodeJam\\D\\result.txt");
            line = file.ReadLine();
            int T = int.Parse(line);
            

            for (int i = 0; i < T; i++)
            {
                List<CoordinatePair> points = new List<CoordinatePair>();
                line = file.ReadLine();
                string[] inputs = line.Split(' ');
                int H = int.Parse(inputs[0]);
                int W = int.Parse(inputs[1]);
                int D = int.Parse(inputs[2]);

                int position = 0;             
                int counter = 0;


                for (int j = 0; j < H; j++)
                {
                    line = file.ReadLine();
                    if (line.Contains("X"))
                    {
                        position = line.IndexOf('X');
                        counter = j;
                    }
                }

                
                double left = position - 0.5;
                double right = W - position - 1.5;
                double up = counter - 0.5;
                double down = H - counter - 1.5;

                int boxWidth = W - 2;
                int boxHeight = H - 2;

                int counterVertical = (int)Math.Ceiling((decimal) D/(decimal) boxHeight);
                int counterHorizontal = (int) Math.Ceiling((decimal) D/(decimal) boxWidth);

                double tempX1 = 0;
                double tempX2 = 0;
                
                double tempAdd = right;
                double tempSub = left;

                points.Add(new CoordinatePair(0,0));

                for (int j = 0; j < counterHorizontal; j++)
                {
                    if (Math.Abs(tempX1-2*tempSub)<=D)
                    {
                        points.Add(new CoordinatePair(tempX1 - 2*tempSub, 0));
                        tempX1 = tempX1 - 2*tempSub;
                        tempSub = boxWidth - tempSub;
                    }

                    if (Math.Abs(tempX2+2*tempAdd)<=D)
                    {
                        points.Add(new CoordinatePair(tempX2+2*tempAdd,0));
                        tempX2 = tempX2 + 2*tempAdd;
                        tempAdd = boxWidth - tempAdd;
                    }
                }

                List<CoordinatePair> tempList = new List<CoordinatePair>();
                foreach (var point in points)
                {
                    double tempY1 = 0;
                    double tempY2 = 0;
                    tempAdd = up;
                    tempSub = down;
                    for (int j = 0; j < counterVertical; j++)
                    {
                        CoordinatePair tempPair = new CoordinatePair(point.X,tempY1-2*tempSub);
                        if (CoordinatePair.Distance(tempPair,new CoordinatePair(0,0))<=D)
                        {
                            tempList.Add(tempPair);
                            tempY1 = tempY1 - 2*tempSub;
                            tempSub = boxHeight - tempSub;
                        }


                        tempPair = new CoordinatePair(point.X,tempY2+2*tempAdd);
                        if (CoordinatePair.Distance(tempPair,new CoordinatePair(0,0))<=D)
                        {
                            tempList.Add(tempPair);
                            tempY2 = tempY2 + 2*tempAdd;
                            tempAdd = boxHeight - tempAdd;
                        }
                    }
                }

                points.AddRange(tempList);
                points.Remove(new CoordinatePair(0, 0));

                List<CoordinatePair> resultList = new List<CoordinatePair>();
                List<CoordinatePair> pointsWithoutZero = new List<CoordinatePair>();

                foreach (var point in points)
                {
                    if (!(point.X==0 && point.Y==0))
                    {
                        resultList.Add(new CoordinatePair(point.X, point.Y));
                    }
                    
                }

                foreach (var point in points)
                {
                    if (point.X != 0 && point.Y != 0)
                    {
                        pointsWithoutZero.Add(new CoordinatePair(point.X, point.Y));
                    }
                }

                int resultCount = resultList.Count;

                foreach (var item in resultList)
                {
                    if ((item.X==0 && (item.Y>2*up || item.Y<-2*down)) || (item.Y == 0 &&(item.X>2*right || item.X<-2*left)))
                    {
                        resultCount--;
                    }

                    if (item.X!=0 && item.Y!=0)
                    {
                        foreach (var point in pointsWithoutZero)
                        {
                            if (item.X/point.X == item.Y/point.Y && item.X/point.X>1)
                            {
                                resultCount--;
                                break;
                            }
                        }
                    }
                }
                Console.WriteLine(resultCount);
            }
            file.Close();
            resultFile.Close();
            Console.WriteLine("Done");
            Console.ReadLine();
        }
    }


    class CoordinatePair
    {
        private double _x;
        private double _y;

        public double Y
        {
            get { return _y; }
            set { _y = value; }
        }

        public double X
        {
            get { return _x; }
            set { _x = value; }
        }

        public CoordinatePair(double x,double y)
        {
            this.X = x;
            this.Y = y;
        }


        public static double Distance(CoordinatePair firstPoint, CoordinatePair secondPoint)
        {
            return
                Math.Sqrt((secondPoint.X - firstPoint.X) * (secondPoint.X - firstPoint.X) +
                          (secondPoint.Y - firstPoint.Y) * (secondPoint.Y - firstPoint.Y));
        }
    }
}
