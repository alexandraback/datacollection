using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Kingdom_Rush
{
    class funcs
    {
        public static string[] getInputDocs(string file)
        {
            List<string> ret = new List<string>();
            StreamReader sr = new StreamReader(file, Encoding.Default);
            string temp;
            while ((temp = sr.ReadLine()) != null)
            {
                ret.Add(temp);
            }
            sr.Close();
            return ret.ToArray();
        }

        public static void WriteLines(string filename, List<string> newlines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < newlines.Count; i++) sw.WriteLine(newlines[i]);
            sw.Close();
            fs.Close();
        }
    }
}
