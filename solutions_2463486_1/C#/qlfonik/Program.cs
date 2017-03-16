using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace GoogleCodeJam2012
{
    class Program
    {
        static void Main(string[] args)
        {
            var candidates = GetAllPalindromes(8, false);
            List<BigInteger> prePalindromes = new List<BigInteger>();
            //List<BigInteger> passedCandidates = new List<BigInteger>();
            foreach (var c in candidates)
            {
                var bi = BigInteger.Parse(c);
                if (!bi.IsZero)
                {
                    var bi2 = bi * bi;
                    if (bi2 == BigInteger.Parse(string.Join("", bi2.ToString().Reverse())))
                    {
                        prePalindromes.Add(bi2);
                        //passedCandidates.Add(bi);
                    }
                }
            }


            string fileName = "input.in";
            using (var reader = new StreamReader(fileName))
            {
                int cases = int.Parse(reader.ReadLine().Trim());
                using (var writer = new StreamWriter("output.out"))
                {
                    for (int i = 0; i < cases; i++)
                    {
                        var line = reader.ReadLine();
                        var lineValues = line.Split(' ');

                        BigInteger min = BigInteger.Parse(lineValues[0]);
                        BigInteger max = BigInteger.Parse(lineValues[1]);

                        writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, prePalindromes.Where(pp => pp >= min && pp <= max).Count()));
                    }
                }
            }
        }

        static List<string> GetAllPalindromes(int digits, bool useOptimizedSource)
        {
            List<string> result = new List<string>();
            for (int i = 0; i < digits; i++)
                result.AddRange((useOptimizedSource && i > 0) ? GetNarrowedPalindromes(i + 1) : GetPalindromes(i + 1));
            return result;
        }

        static List<string> GetPalindromes(int digits)
        {
            if (digits == 1)
                return (new string[] { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" }).ToList();
            if (digits == 2)
                return (new string[] { "00", "11", "22", "33", "44", "55", "66", "77", "88", "99" }).ToList();
            else
            {
                var inner = GetPalindromes(digits - 2);
                List<string> result = new List<string>();
                for (int d = 0; d < 10; d++)
                {
                    foreach (var i in inner)
                    {
                        result.Add(string.Join("", d, i, d));
                    }
                }
                return result;
            }
        }

        static List<string> GetNarrowedPalindromes(int digits)
        {
            if (digits == 1)
                return (new string[] { "0", "1", "2" }).ToList();
            if (digits == 2)
                return (new string[] { "00", "11", "22" }).ToList();
            else
            {
                var inner = GetNarrowedPalindromes(digits - 2);
                List<string> result = new List<string>();
                for (int d = 0; d < 3; d++)
                {
                    foreach (var i in inner)
                    {
                        result.Add(string.Join("", d, i, d));
                    }
                }
                return result;
            }
        }

    }
}
