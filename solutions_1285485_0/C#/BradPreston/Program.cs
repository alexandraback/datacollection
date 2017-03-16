using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CJ2012Round1Prob2
{
    public class Prob2
    {
        int n;
        int s;
        int p;
        List<int> t;

        

        public int solveLine(string _line)
        {
            int x = 0;
            string[] nums = _line.Split(' ');
            n = Int32.Parse(nums[0]);
            s = Int32.Parse(nums[1]);
            p = Int32.Parse(nums[2]);
            t = new List<int>();
            for (int i = 3; i < nums.Length; i++)
            {
                t.Add(Int32.Parse(nums[i]));
            }
            List<int> nonSuprising = new List<int>();
            List<int> suprising = new List<int>();
            int easy = 0;
            int needSuprise = 0; 
            foreach (int score in t)
            {
                if (score == 0)
                {
                    if (p == 0)
                    {
                        easy += 1;
                    }
                }
                else if (Math.Ceiling(score / 3.0) >= p)
                {
                    easy += 1;

                }
                else if (Math.Ceiling((score-1) / 3.0) >= p-1)
                {
                    needSuprise += 1;
                }

            }



            return easy + Math.Min(s,needSuprise);
        }


    }


    public class Prob3
    {

        public int getRecycles(int _num,int _lowerbound,int _upperbound)
        {
            List<int> recycles = new List<int>();
            string numString = _num.ToString();
            int newNum = 0;

            for (int i = 1; i <= numString.Length-1; i++)
            {
                newNum = Int32.Parse(numString.Substring(i) + numString.Substring(0, i));
                if ((_lowerbound < newNum )&&(newNum <= _upperbound))
                {
                    if (!recycles.Contains(newNum))
                    {
                        recycles.Add(newNum);
                    }

                }


            }

            return recycles.Count;
        }

        public int solveLine(string _line)
        {
            int x = 0;
            string[] nums = _line.Split(' ');
            int a = Int32.Parse(nums[0]);
            int b = Int32.Parse(nums[1]);
            
            

            for (int n = a; n <= b; n++)
            {
                x += getRecycles(n, n, b);


            }



            return x;
        }
    }

    public class Prob4
    {

        public double h;
        public double w;
        double x;
        double y;
        public double d;
        public void getXY(List<string> _lines)
        {
            int xCount = 0;
            int yCount = 0;
            foreach (string line in _lines)
            {
                xCount = 0;
                foreach (char c in line)
                {
                     
                    if (c == 'X')
                    {
                        x = xCount - 0.5;
                        y = yCount - 0.5;
                        return;
                    }
                    xCount++;
                }
                yCount++;

            }
            
        }



        public int solveLines(List<string> _lines)
        {
            int sum = 0;
            List<double> reflectX = new List<double>();
            List<double> reflectY = new List<double>();
            getXY(_lines);
            w -= 2.0;
            h -= 2.0;
            int numXreflect = (int)Math.Ceiling(d / w);
            int numYreflect = (int)Math.Ceiling(d / h);


            //create reflections
            reflectX.Add(x);
            reflectY.Add(y);
            double newX = x;
            double newY = y;
            bool odd = true;
            while ((newX - x) <= d)
            {
                if (odd)
                {
                    newX += 2.0*(w - x);
                   
                }
                else
                {
                    newX += 2.0 * x;
                }
                reflectX.Add(newX);
                odd = !odd;
            }
            newX = x;
            odd = true;
            while ((x - newX) <= d)
            {
                if (!odd)
                {
                    newX -= 2.0 * (w - x);

                }
                else
                {
                    newX -= 2.0 * x;
                }
                reflectX.Add(newX);
                odd = !odd;
            }

            odd = true;
            while ((newY - y) <= d)
            {
                if (odd)
                {
                    newY += 2.0 * (h - y);

                }
                else
                {
                    newY += 2.0 * y;
                }
                reflectY.Add(newY);
                odd = !odd;
            }
            newY = y;
            odd = true;
            while ((y - newY) <= d)
            {
                if (!odd)
                {
                    newY -= 2.0 * (h - y);

                }
                else
                {
                    newY -= 2.0 * y;
                }
                reflectY.Add(newY);
                odd = !odd;
            }

           
            

            List<double> angle = new List<double>();


            double currentAngle;
            

            foreach (double currentReflectX in reflectX)
            {
                foreach (double currentReflectY in reflectY)
                {

                    if (((x - currentReflectX)*(x - currentReflectX) + (y - currentReflectY)*(y - currentReflectY) <= d*d) &&((x - currentReflectX)*(x - currentReflectX) + (y - currentReflectY)*(y - currentReflectY) > 0 ) )
                    {
                        currentAngle = Math.Atan2((currentReflectY - y) , (currentReflectX - x));
                        if (!angle.Contains(currentAngle))
                        {
                            sum++;
                            angle.Add(currentAngle);

                        }
                    }

                }


            }
            return sum;
        }
    }
    class Program
    {
        public static void solve()
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");
            //Prob2 prob2 = new Prob2();
            Prob4 prob = new Prob4();
            int numCases = Int32.Parse(sr.ReadLine());
            string[] split;
            int lineNum = 0;
            string line;
            List<string> lines = new List<string>();
            while ((line = sr.ReadLine()) != null)
            {

                split = line.Split(' ');
                prob.h = double.Parse(split[0]);
                prob.w = double.Parse(split[1]);
                prob.d = double.Parse(split[2]);
                for (int i = 0; i < prob.h; i++)
                {
                    lines.Add(sr.ReadLine());
                }

                lineNum++;
                sw.Write("Case #" + lineNum.ToString() + ": ");
                sw.Write(prob.solveLines(lines));
                lines.Clear();
                sw.WriteLine();
            }

            sw.Close();
            sr.Close();
        }


        static void Main(string[] args)
        {
            solve();
        }
    }
}
