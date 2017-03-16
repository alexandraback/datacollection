using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace jam
{

    class CodeJamMain
    {
        static string inputFile = @"C:\Users\a.gilotte\Documents\jam\A-large.in";

        public static void Main()
        {
            var lines = File.ReadAllLines(inputFile);
            var results = new Insomnia().Run(lines);
            var formated = FormatResult(results).ToList();
            var outpFile = inputFile.Replace(".txt", "") + "_output.txt";
            File.WriteAllLines(outpFile, formated);
        }

        static IEnumerable<string> FormatResult(IEnumerable<string> rawResults)
        {
            int i = 1;
            foreach (var result in rawResults)
            {
                yield return "Case #" + i + ": " + result;
                i++;
            }
        }

    }

    class Insomnia
    {
        public Insomnia() { }

        public IEnumerable<string> Run(IList<string> lines)
        {
            Console.WriteLine("nbCases=" + lines.First());
            foreach (var line in lines.Skip(1))
            {
                yield return Solve(line);
            }
        }

        public string Solve(string line)
        {
            long n = int.Parse(line);

            if( n == 0)
                return "INSOMNIA";
            HashSet<int> digits = new HashSet<int>();
            for(int k =0; k > -1; k++)
            {
                long nk = n * k;
                foreach (var d in Digits(nk))
                    digits.Add(d);
                if (digits.Count() == 10)
                    return "" + nk;
            }
            return "INSOMNIA";
            
        }

        IEnumerable<int> Digits(long n)
        {
            while (n > 0)
            {
                yield return(int)(n % 10);
                n = n / 10;
            }
        }



    }


}
