using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
    class FileProcessing
    {
        int m_Int_CaseAmount;

        string m_String_ResultFilename = "";

        int m_Int_Generation = 40;

        public void readFile(string fileName)
        {
            this.SetResultPath(fileName);

            StreamReader sr = new StreamReader(fileName);

            string line = sr.ReadLine();

            this.m_Int_CaseAmount = int.Parse(line);
            line = sr.ReadLine();

            int currentCase = 0;

            while (line != null)
            {
                List<long> data = new List<long>();

                foreach(string i in line.Split('/'))
                {
                    data.Add(long.Parse(i));
                }

                this.SolveProblemA(currentCase, data);
                currentCase++;
                line = sr.ReadLine();
            }

            sr.Close();
        }

        void SetResultPath(String filename)
        {
            string path = "";

            for (int i = 0; i < filename.Split('/').Length - 1; i++)
            {
                path += filename.Split('/')[i];
                path += "/";
            }

            path += "Results.txt";

            this.m_String_ResultFilename = path;

            StreamWriter sw = new StreamWriter(path);
            sw.Close();
        }

        void SolveProblemA(int caseNumber, List<long> data)
        {
            int solution = this.function1(data[0], data[1]);

            string result = "impossible";

            if (solution > 0)
            {
                result = solution.ToString();
            }

            this.ResultWritter(caseNumber, result);

        }

        int function1(long numerator, long denominator)
        {
            int result = 0;
            bool possible = true;

		    if (numerator == 0)
            {
			    possible = false;
		    }

            if (possible)
            {
                int i = 1;
                long left = 0;
                bool found = false;


                while (i < m_Int_Generation && !found)
                {
                    numerator *= 2;

                    if (numerator >= denominator)
                    {
                        result = i;
                        found = true;
                        left = numerator - denominator;
                    }

                    i ++;
                }

                while (i < m_Int_Generation && left != 0)
                {
                    left *= 2;

                    if (left >= denominator)
                    {
                        left = left - denominator;
                    }

                    i++;
                }

                if (i > m_Int_Generation || left != 0)
                {
                    result = 0;
                }
            }

		    return result;
        }

        void ResultWritter(int caseNumber, string result)
        {
            String finalAnswer = "Case #" + (caseNumber + 1).ToString() + ": " + result;

            StreamWriter sw = new StreamWriter(this.m_String_ResultFilename, true);

            sw.WriteLine(finalAnswer);
            sw.Close();
        }
    }
}
