using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace FairAndSquare2
{
    class Program
    {
        static void Main(string[] args)
        {
            string file = args[0];
            //string file = "1.txt";
            if (!File.Exists(file))
                Console.WriteLine(String.Format("File {0} doesn't exist", file));
            StreamReader reader = new StreamReader(file);
            StreamWriter writer = new StreamWriter(file + ".out");
            int tests = int.Parse(reader.ReadLine());
            double[] leftValues = new double[tests];
            double[] rightValues = new double[tests];
            double minLeftValue = double.MaxValue, maxRightValue = double.MinValue;
            for (int i = 0; i < tests; ++i)
            {
                int result = 0;
                string[] values = reader.ReadLine().Split(' ');
                leftValues[i] = double.Parse(values[0]);
                rightValues[i] = double.Parse(values[1]);
                if (minLeftValue > leftValues[i]) minLeftValue = leftValues[i];
                if (maxRightValue < rightValues[i]) maxRightValue = rightValues[i];
            }
            List<double> results = new List<double>();
            double value = Math.Ceiling(Math.Sqrt(minLeftValue));
            double endValue = maxRightValue;
            double count = Math.Pow(value, 2);
            while (count <= endValue)
            {
                if (IsPalindrom(value.ToString()))
                    if (IsPalindrom(count.ToString()))
                        results.Add(count);
                ++value;
                count += value * 2 - 1;
            }
            for (int i = 0; i < tests; ++i)
            {
                int result = 0;
                for (int j = 0; j < results.Count; ++j)
                    if (results[j] >= leftValues[i]
                        && results[j] <= rightValues[i])
                        ++result;
                writer.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));                
            }
            writer.Flush();
            writer.Close();
            reader.Close();
        }

        static bool IsPalindrom(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            string s1 = new string(charArray);
            return s == s1;
        }
    }
}
