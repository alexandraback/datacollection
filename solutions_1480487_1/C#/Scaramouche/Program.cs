using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static int m_NumberOfCases;
        static List<int[]> m_InputCases;
        static List<string> m_OutputCases;

        static void Main(string[] args)
        {
            GetInput();
            Solve();
            WriteOutput();

            Console.WriteLine("Done!");
            Console.ReadKey();
        }

        private static void GetInput()
        {
            System.IO.StreamReader r = new System.IO.StreamReader("A-large.in");
            string line = r.ReadLine();
            m_NumberOfCases = Convert.ToInt32(line.Trim());
            m_InputCases = new List<int[]>(m_NumberOfCases);
            while ((line = r.ReadLine()) != null)
            {
                string[] items = line.Split(' ');
                int h = Convert.ToInt32(items[0]);
                int[] points = new int[h];
                for (int i = 0; i < h; ++i)
                    points[i] = Convert.ToInt32(items[i+1]);
                m_InputCases.Add(points);
            }
            r.Close();
            if(m_NumberOfCases != m_InputCases.Count)
                throw new Exception("Aaaa!");
        }
        private static void WriteOutput()
        {
            System.IO.StreamWriter w = new System.IO.StreamWriter("Output.txt");
            int i = 1;
            foreach(string item in m_OutputCases)
                w.WriteLine(string.Format("Case #{0}: {1}", i++, item));
            w.Flush();
            w.Close();
        }

        private static void Solve()
        {
            m_OutputCases = new List<string>(m_NumberOfCases);
            foreach (int[] item in m_InputCases)
            {
                double x = 0;
                for (int i = 0; i < item.Length; ++i)
                    x += item[i];
                double x1 = (2 * x) / item.Length;
                double extra = x;
                int count = 0;
                for (int i = 0; i < item.Length; ++i)
                {
                    if (item[i] < x1)
                    {
                        extra += item[i];
                        count++;
                    }
                }
                double x2 = extra / count;
                //double[] percent = new double[item.Length];
                string output = string.Empty;
                for (int i = 0; i < item.Length; ++i)
                {
                    if (item[i] < x1)
                    {
                        double z = x2 - item[i];
                        double z1 = (z * 100) / x;
                        output += z1.ToString("0.000000") + " ";
                    }
                    else
                        output += "0.000000 ";
                }
                m_OutputCases.Add(output.TrimEnd().Replace(',','.'));
            }
        }
 
    }

}
