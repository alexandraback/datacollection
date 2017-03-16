using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static int m_NumberOfCases;
        static List<string> m_InputCases;
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
            System.IO.StreamReader r = new System.IO.StreamReader("C-large.in");
            string line = r.ReadLine();
            m_NumberOfCases = Convert.ToInt32(line.Trim());
            m_InputCases = new List<string>(m_NumberOfCases);
            while ((line = r.ReadLine()) != null)
                m_InputCases.Add(line);
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
            foreach (string item in m_InputCases)
            {
                string[] digits = item.Split(' ');
                int a = Convert.ToInt32(digits[0]);
                int b = Convert.ToInt32(digits[1]);
                int returnValue = 0;
                for (int n = a; n < b; ++n)
                {
                    int subCount = GetCount(n) - 1;
                    List<int> yetDigits = new List<int>(7);
                    int m = n;
                    for (int i = 0; i < subCount; ++i)
                    {
                        int fixedPart = m / 10;
                        int tail = m - fixedPart * 10;
                        m = tail * (int)Math.Pow(10, subCount) + fixedPart;
                        if (m > n && m <= b)
                        {
                            bool yetFlag = false;
                            for (int t = 0; t < yetDigits.Count; ++t)
                            {
                                if (yetDigits[t] == m)
                                {
                                    yetFlag = true;
                                    break;
                                }
                            }
                            if (!yetFlag)
                            {
                                returnValue++;
                                yetDigits.Add(m);
                            }
                        }
                    }
                    string nString = n.ToString();
                }
                m_OutputCases.Add(returnValue.ToString());
            }
        }
        private static int GetCount(int number)
        {
            if (number < 10)
                return 1;
            if (number < 100)
                return 2;
            if (number < 1000)
                return 3;
            if (number < 10000)
                return 4;
            if (number < 100000)
                return 5;
            if (number < 1000000)
                return 6;
            return 7;
        }
    }
}
