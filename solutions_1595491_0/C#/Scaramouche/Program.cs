using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication2
{
    class Program
    {
        static Dictionary<char, char> m_Dictionary;
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
            System.IO.StreamReader r = new System.IO.StreamReader("B-small-attempt0.in");
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
                int numberOfGooglers = Convert.ToInt32(digits[0]);
                if(numberOfGooglers != digits.Length - 3)
                    throw new Exception("Small problem caught!");
                int numberOfSurprises = Convert.ToInt32(digits[1]);
                int p = Convert.ToInt32(digits[2]);
                int returnValue = 0;
                for (int i = 0; i < numberOfGooglers; ++i)
                {
                    int score = Convert.ToInt32(digits[i + 3]);
                    int medium = score / 3;
                    int tail = score - medium * 3;
                    if (medium >= p)
                    {
                        returnValue++;
                        continue;
                    }
                    if (tail != 0 && (medium + 1) >= p)
                    {
                        returnValue++;
                        continue;
                    }
                    if (numberOfSurprises != 0)
                    {
                        if (tail == 2 && (medium + 2) >= p)
                        {
                            returnValue++;
                            numberOfSurprises--;
                            continue;
                        }
                        if ((medium > 0 ) && (medium + 1) >= p)
                        {
                            returnValue++;
                            numberOfSurprises--;
                            continue;
                        }
                    }
                }
                m_OutputCases.Add(returnValue.ToString());
            }
        }

    }
}
