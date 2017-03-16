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
            MakeDictionary();
            GetInput();
            Solve();
            WriteOutput();

            Console.WriteLine("Done!");
            Console.ReadKey();
        }

        private static void MakeDictionary()
        {
            m_Dictionary = new Dictionary<char, char>();

            string inputDataBase = @"ejp mysljylc kd kxveddknmc re jsicpdrysi" +
                                @"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" +
                                @"de kr kd eoya kw aej tysr re ujdr lkgc jv";
            string outputDataBase = @"our language is impossible to understand" +
                                @"there are twenty six factorial possibilities" +
                                @"so it is okay if you want to just give up";
            for (int i = 0; i < inputDataBase.Length; ++i)
            {
                char inpupChar = inputDataBase[i];
                char outputChar = outputDataBase[i];
                char oldChar;
                if (m_Dictionary.TryGetValue(inpupChar, out oldChar) && oldChar != outputChar)
                    throw new Exception("Small problem caught!");
                m_Dictionary[inpupChar] = outputChar;
            }
            m_Dictionary.Add('z', 'q');
            m_Dictionary.Add('q', 'z');
        }
        private static void GetInput()
        {
            System.IO.StreamReader r = new System.IO.StreamReader("A-small-attempt0.in");
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
                char[] tempOutput = new char[item.Length];
                for (int i = 0; i < item.Length; ++i)
                {
                    char inpupChar = item[i];
                    bool toUpper = false;
                    if (char.IsUpper(inpupChar))
                    {
                        inpupChar = char.ToLower(inpupChar);
                        toUpper = true;
                    }
                    char outputChar;
                    if (!m_Dictionary.TryGetValue(inpupChar, out outputChar))
                        throw new Exception("Small problem caught!");
                    if(toUpper)
                        tempOutput[i] = char.ToUpper(outputChar);
                    else
                        tempOutput[i] = outputChar;
                }
                m_OutputCases.Add(new string(tempOutput));
            }
        }

    }
}
