using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemD
{
    class funcs
    {
        public static int findch(string str, char ch, int pos)
        {
            for (int i = pos; i < str.Length; i++)
            {
                if (str[i].Equals(ch)) return i;
            }
            return 0;
        }

        public static int backfindch(string str, char ch, int pos)
        {
            for (int i = pos; i >= 0; i--)
                if (str[i].Equals(ch)) return i;
            return 0;
        }

        public static List<string> I_WashLine(string[] input_str)
        {
            List<string> ret_lines = new List<string>();
            for (int i = 0; i < input_str.Length; i++)
                if ((!input_str[i].StartsWith("I :")) && (!(input_str[i].Length == 0)))
                    ret_lines.Add(input_str[i]);
                else
                {
                    if (input_str[i].Length == 0)
                    {
                        Console.WriteLine("NONE");
                        //Console.Read();
                        //Console.Read();
                    }
                }
            return ret_lines;
        }

        public static void WriteLines(string filename, List<string> newlines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < newlines.Count; i++) sw.WriteLine(newlines[i]);
            sw.Close();
            fs.Close();
        }

        public static void WriteLines(string filename, List<double> newlines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < newlines.Count; i++) sw.WriteLine(newlines[i].ToString());
            sw.Close();
            fs.Close();
        }

        public static void WriteInts(string filename, int[] lines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < lines.Length; i++) sw.WriteLine(lines[i].ToString());
            sw.Close();
            fs.Close();
        }

        public static void WriteLongs(string filename, List<long> lines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < lines.Count; i++) sw.WriteLine(lines[i].ToString());
            sw.Close();
            fs.Close();
        }

        public static void WriteDoubles(string filename, double[] lines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < lines.Length; i++) sw.WriteLine(lines[i].ToString());
            sw.Close();
            fs.Close();
        }

        public static void WriteLines(string filename, string[] newlines)
        {
            FileStream fs = new FileStream(filename, FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs);
            for (int i = 0; i < newlines.Length; i++) sw.WriteLine(newlines[i]);
            sw.Close();
            fs.Close();
        }

        public static int[] getInts(string file)
        {
            List<int> ret = new List<int>();
            StreamReader sr = new StreamReader(file, Encoding.Default);
            string temp;
            while ((temp = sr.ReadLine()) != null)
            {
                ret.Add(int.Parse(temp));
            }
            sr.Close();
            return ret.ToArray();
        }

        public static double[] getDouble(string file)
        {
            List<double> ret = new List<double>();
            StreamReader sr = new StreamReader(file, Encoding.Default);
            string temp;
            while ((temp = sr.ReadLine()) != null)
            {
                ret.Add(double.Parse(temp));
            }
            sr.Close();
            return ret.ToArray();
        }

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

        public static List<string> getInputDocs2(string file)
        {
            List<string> ret = new List<string>();
            StreamReader sr = new StreamReader(file, Encoding.Default);
            string temp;
            while ((temp = sr.ReadLine()) != null)
            {
                ret.Add(temp);
            }
            sr.Close();
            return ret;
        }

        public static int maptype(string mytype)
        {
            if (mytype == "anger") return 1;
            if (mytype == "disgust") return 2;
            if (mytype == "fear") return 3;
            if (mytype == "happy") return 4;
            if (mytype == "sad") return 5;
            return 0;
        }
    }
}
