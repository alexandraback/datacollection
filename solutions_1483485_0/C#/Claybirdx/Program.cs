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
        public static Dictionary<string, string> dicMapping = new Dictionary<string, string>()
        {
            {"a","y"},{"b","h"},{"c","e"},{"d","s"},{"e","o"},{"f","c"},{"g","v"},
            {"h","x"},{"i","d"},{"j","u"},{"k","i"},{"l","g"},{"m","l"},{"n","b"},
            {"o","k"},{"p","r"},{"q","z"},{"r","t"},{"s","n"},{"t","w"},
            {"u","j"},{"v","p"},{"w","f"},{"x","m"},{"y","a"},{"z","q"}
        };
        static void Main(string[] args)
        {
            List<Input> lstInput = Input<Input>();
            List<Input> lstOutput = new List<Input>();
            string strInput = "",strOutput = "";

            foreach (Input a in lstInput)
            {
                Input o = new Input();
                strInput = a.Line;
                strOutput = "";
                foreach (char c in strInput)
                {
                    if (dicMapping.ContainsKey(c.ToString()))
                    {
                        strOutput += dicMapping[c.ToString()];
                    }
                    else
                    {
                        strOutput += c.ToString();
                    }

                }
                o.Line = strOutput;
                lstOutput.Add(o);
            }
            Output<Input>(lstOutput, "Case #[0]: [1]");
            //Console.Write("Job Done.  Press Enter to Quit.");
            //Console.ReadLine();
        }
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

    }
    class Input
    {
        public string Line { get; set; }
    }
}
