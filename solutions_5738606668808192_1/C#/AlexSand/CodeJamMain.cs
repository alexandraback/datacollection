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
        //static string inputFile = @"C:\Users\a.gilotte\Documents\jam\C-small-attempt0.in";
        static string inputFile = @"C:\Users\a.gilotte\Documents\jam\C-large.in";


        public static void Main()
        {
            var lines = File.ReadAllLines(inputFile);
            var results = new JamCoin().Run(lines);
            var formated = FormatResultOneLine(results).ToList();
            //var formated = FormatResult(results).ToList();
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

    class JamCoin 
    {
        public JamCoin() {
            PreparePrimeList( (long) Math.Pow(2,32) );
        
        }

        public IEnumerable<string> Run(IList<string> lines)
        {

            var line = lines.ElementAt(1);
            var tokens = line.Split(' ');
            int n = int.Parse(tokens[0]);
            int j = int.Parse(tokens[1]);

            return Solve(n, j);

        }

        int _n;


        IEnumerable<string> Solve(int n, int j)
        {
            _n = n;

            HashSet<long> coins = new HashSet<long>();
            Random random = new Random(0);
            while (coins.Count() < j)
            {
                var bytes = new int[_n];
                for (int i = 1; i < _n - 1; i++)
                {
                    bytes[i] = random.Next(2);
                }
                bytes[0] = 1;
                bytes[_n - 1] = 1;

                long coin = GetInBase(bytes, 2);
                if (IsCoin(coin))
                    coins.Add(coin);
            }


            foreach (var coin in coins)
            {
                yield return Print(coin);
            }
        }

        bool IsCoin(long m)
        {
            if (m % 2 == 0)
                return false;
            var bytes = this.ToBytes(m);
            for (int d = 2; d <= 10; d++)
            {
                var div = GetDivisor(bytes, d);
                if (div == 0)
                    return false;
            }
            return true;
        }

        long GetDivisor(int[] bytes, int intBase)
        {
            long m = GetInBase(bytes, intBase);
            return GetDivisor(m);
        }

        List<long> _primeNumbers = new List<long>();

        void PreparePrimeList(long m)
        {
            long i = 2;
            while (i * i < m)
            {
                if (GetDivisor(i) == 0)
                {
                    _primeNumbers.Add(i);
                }
                i++;
            }
        }

        long GetDivisor(long m)
        {
            foreach (var p in _primeNumbers)
            {
                if (m % p == 0)
                {
                    if (m == p)
                        return 0;
                    return p;
                }
            }
            return 0;
        }

        long GetInBase(int[] bytes, int intBase)
        {
            long result = 0;
            long mult = 1;
            foreach (int b in bytes)
            {
                result += mult * b;
                mult *= intBase;
            }
            return result;
        }


        string Print(long coin)
        {
            var bytes = ToBytes(coin);
            var result = string.Join("", bytes.Reverse());
            for( int i = 2 ; i <=10; i++)
            {
                var divisor = GetDivisor(bytes, i);
                result += " " + divisor;
            }
            return result;
        }

        int[] ToBytes(long coin )
        {
            var bytes = new int[_n];
            for (int i = 0; i < _n; i++)
            {
                bytes[i] = (int)(coin % 2);
                coin /= 2; 
            }
            return bytes;
        }

    }


}
