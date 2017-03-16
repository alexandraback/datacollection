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
        //static string inputFile = @"C:\Users\a.gilotte\Documents\jam\D-small-attempt0.in";
        static string inputFile = @"C:\Users\a.gilotte\Documents\jam\D-large.in";
        //static string inputFile = @"C:\Users\a.gilotte\Documents\jam\test.txt";


        public static void Main()
        {
            var lines = File.ReadAllLines(inputFile);
            var results = new Fract().Run(lines);
            //var formated = FormatResultOneLine(results).ToList();
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

        static IEnumerable<string> FormatResultOneLine(IEnumerable<string> rawResults)
        {
            yield return "Case #1:";
            int i = 1;
            foreach (var result in rawResults)
            {
                yield return result;
                i++;
            }
        }


    }


    class Fract
    {
        public Fract() { }

        public IEnumerable<string> Run(IList<string> lines)
        {
            foreach (var line in lines.Skip(1))
                yield return Solve(line);
        }
        string Solve(string line)
        {
            var tokens = line.Split(' ');
            var k = long.Parse(tokens[0]);
            var c = long.Parse(tokens[1]);
            int s = int.Parse(tokens[2]);

            if (s * c < k)
                return "IMPOSSIBLE";
            
            return string.Join( " ", GetPlaces(k,c,s));
        }

        List<long> GetPlaces(long k, long c, int s)
        {
            var places = new HashSet<long>();
            for (int i = 0; i * c < k; i++)
            {
                var listToTest = Enumerable.Range(i * (int)c, (int)c).Where(j => j < k).Select(j => (long)j).ToList();
                var index = GetIndex(listToTest, k, c);
                places.Add(index);
            }
            return places.ToList();
            //return Complete(k,c,s,places);
        }

        long GetIndex(List<long> listToTest , long k , long c)
        {
            long index = 0;
            long mult = 1;
            foreach( long i in listToTest)
            {
                index += mult * i;
                mult *= k;
            }
            index += 1;
            return index;
        }

        List<long> Complete(long k, long c, int s, HashSet<long> places)
        {
            long i = 1;
            while (places.Count() < s)
            {
                places.Add(i);
            }
            return places.ToList();
        }
    }


}
