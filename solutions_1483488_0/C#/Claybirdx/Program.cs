using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace Google.CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Input> lstInput = Input<Input>();
            List<Input> lstOutput = new List<Input>();

            foreach (Input a in lstInput)
            {
                Input o = new Input();
                int intOutput = Compute(a.Line);
                o.Line = intOutput.ToString();
                lstOutput.Add(o);
            }
            Output<Input>(lstOutput, "Case #[0]: [1]");
        }

        public static int Compute(string strInput)
        {
            string[] aryLine = strInput.Split(' ');
            double A = int.Parse(aryLine[0]);
            double B = int.Parse(aryLine[1]);
            int intOutput = 0;

            for (double n = A; n <= B; n++)
            {
                Dictionary<double, double> dicOutput = new Dictionary<double, double>();
                int intDigit = A.ToString().Length;
                for (int i = 1; i < intDigit; i++)
                {
                    double h = int.Parse(n.ToString().Substring(0, intDigit - i));
                    double t = int.Parse(n.ToString().Substring(intDigit - i));

                    double m = t * (Math.Pow(10, intDigit - i)) + h;

                    if (n < m && m <= B) 
                    {
                        if (!dicOutput.ContainsKey(n*Math.Pow(10,intDigit)+m))
                        {
                            dicOutput[n * Math.Pow(10, intDigit) + m] = 1;
                            intOutput++;
                        }
                    }
                }
            }
            return intOutput;
        }
        #region Utility/IO
        public static List<T> Input<T>()
        {
            string strFileName = "input.txt";
            List<T> lstInput = new List<T>();
            int intInputCount = 0;
            PropertyInfo[] pi = typeof(T).GetProperties();
            T InputItem = (T)Activator.CreateInstance(typeof(T));
            try
            {
                using (StreamReader sr = new StreamReader(strFileName, System.Text.Encoding.ASCII))
                {
                    string strLine = "";
                    int intCurLine = 0;
                    int intCurProperty = 0;

                    while ((strLine = sr.ReadLine()) != null)
                    {
                        intCurLine++;
                        if (intCurLine == 1)
                        {
                            if (!int.TryParse(strLine, out intInputCount))
                            { Console.Write("Invalid Input in Line 1"); }
                            continue;
                        }
                        pi[intCurProperty].SetValue(InputItem, strLine, null);
                        if (intCurProperty == (pi.Count() - 1))
                        {
                            lstInput.Add(InputItem);
                            InputItem = (T)Activator.CreateInstance(typeof(T));
                            intCurProperty = 0;
                        }
                        else
                        {
                            intCurProperty++;
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            if (lstInput.Count() != intInputCount)
            { Console.WriteLine("Invalid Input of Lines."); }
            return lstInput;
        }

        public static void Output<T>(List<T> lstOutput, string strFormatter)
        {
            string strFileName = "output.txt";
            PropertyInfo[] pi = typeof(T).GetProperties();
            try
            {
                using (StreamWriter sw = new StreamWriter(strFileName, false, System.Text.Encoding.ASCII))
                {
                    string strLine = "";
                    for (int i = 0; i < lstOutput.Count(); i++)
                    {
                        strLine = strFormatter;
                        strLine = strLine.Replace("[0]", (i + 1).ToString());
                        for (int j = 0; j < pi.Count(); j++)
                        {
                            strLine = strLine.Replace(string.Format("[{0}]", j + 1), pi[j].GetValue(lstOutput[i], null).ToString());
                        }
                        sw.WriteLine(strLine);
                    }
                }
            }
            catch (Exception e)
            {
                Console.Write(e.Message);
            }
        }
        #endregion
    }
    class Input
    {
        public string Line { get; set; }
    }
}
