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
            for (int i = 3; i < nums.Length; i++)
            {
                t.Add(Int32.Parse(nums[i]));
            }


            for (int dancers = 0; dancers < n; dancers++)
            {



            }



            return x;
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

    
    class Program
    {
        public static void solve()
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");
            //Prob2 prob2 = new Prob2();
            Prob3 prob = new Prob3();
            int numCases = Int32.Parse(sr.ReadLine());

            int lineNum = 0;
            string line;
            while ((line = sr.ReadLine()) != null)
            {
                lineNum++;
                sw.Write("Case #" + lineNum.ToString() + ": ");
                sw.Write(prob.solveLine(line));
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
