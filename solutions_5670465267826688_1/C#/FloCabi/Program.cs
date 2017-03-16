using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dijkstra
{
    class Program
    {
        static Dictionary<string, string> lookup = new Dictionary<string, string>();

        static Tuple<char, int> returnValue(char a, int sign, char b)
        {
            if (a == '1')
		        return Tuple.Create<char,int>(b, sign);
	        if( b == '1')
                return Tuple.Create<char, int>(a, sign);
	        if( a == 'i' && b == 'j')
                return Tuple.Create<char, int>('k', sign);
	        if( a == 'j' && b == 'i')
                return Tuple.Create<char, int>('k', -1 * sign);
	        if( a == 'k' && b == 'i')
                return Tuple.Create<char, int>('j', sign);
	        if( a == 'i' && b == 'k')
                return Tuple.Create<char, int>('j', -1 * sign);
	        if( a == 'j' && b =='k')
                return Tuple.Create<char, int>('i', sign);
	        if( a == 'k' && b =='j')
                return Tuple.Create<char, int>('i', -1 * sign);
	        if( a == 'i' && b == 'i')
                return Tuple.Create<char, int>('1', -1 * sign);
	        if( a =='j' && b =='j')
                return Tuple.Create<char, int>('1', -1 * sign);
            if (a == 'k' && b == 'k')
                return Tuple.Create<char, int>('1', -1 * sign);
            return null;
        }
        static void Main(string[] args)
        {
            string path = @"./input.txt";
            Boolean first = false;
            int textCase = 1;
            Dictionary<string, Dictionary<string, string>> transitiveMap = new Dictionary<string, Dictionary<string, string>>();
            using (StreamWriter sw = new StreamWriter(@"./output.out"))
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    while (sr.Peek() > 0)
                    {
                        if (!first)
                        {
                            string data = sr.ReadLine();
                            first = true;
                            continue;
                        }
                        else
                        {
                            string data = sr.ReadLine();
                            string[] splitted = data.Split(' ');
                            int numberCharacter = int.Parse(splitted[0]);
                            Int64 numberRepeated = Int64.Parse(splitted[1]);
                            string dataToAnalyze = sr.ReadLine();

                            string result = getNumber(numberCharacter,numberRepeated, dataToAnalyze);
                            sw.WriteLine("Case #" + textCase++ + ": " + result);
                            //Console.WriteLine("Case #" + textCase + ": " + result);
                        }
                    }
                }
                sw.Flush();
                sw.Close();
            }
            Console.WriteLine("END");
            Console.Read();
        }

        static string getNumber(Int64 numberCharacter, Int64 numberRepeated, string dataToAnalyze)
        {
            Int64 numberPeriod = numberRepeated;
            char tempoRes = '1';
            int sign = 1;
            char[] data = dataToAnalyze.ToArray();
            for (int i = 0; i < numberRepeated; i++)
            {
                for (int j = 0; j < data.Length; j++)
                {
                    Tuple<char, int> tuple = returnValue(tempoRes, sign, data[j]);
                    tempoRes = tuple.Item1;
                    sign = tuple.Item2;
                }
                if (tempoRes == '1' && sign == 1)
                {
                    numberPeriod = i + 1;
                    break;
                }
            }

            Int64 limit = numberRepeated % numberPeriod;
            bool first = false;
            bool second = false;

            char m = '1';
            int n = 1;
            for (int i = 0; i < numberPeriod * 2; i++)
            {
                for (int j = 0; j < data.Length; j++)
                {
                    Tuple<char, int> tuple = returnValue(m, n, data[j]);
                    m = tuple.Item1;
                    n = tuple.Item2;
                    if (m == 'i' && n == 1)
                    {
                        first = true;
                    }
                    if (first == true && m == 'k' && n == 1)
                    {
                        second = true;
                    }
                }
            }
            //Console.WriteLine(" L " + limit);
            if (limit > 0)
            {
                tempoRes = '1';
                sign = 1;
                for (int i = 0; i < limit; i++)
                {
                    for (int j = 0; j < data.Length; j++)
                    {
                        Tuple<char, int> tuple = returnValue(tempoRes, sign, data[j]);
                        tempoRes = tuple.Item1;
                        sign = tuple.Item2;
                    }
                }
            }
            //Console.WriteLine(" first " + first + " second " + second + " tempoRes " + tempoRes + " sign " + sign);
            if (first == true && second == true && tempoRes == '1' && sign == -1)
            {
                return "YES";
            }
            else
            {
                return "NO";
            }
        }

        static string getTransitivite(List<string> final, Dictionary<string, Dictionary<string, string>> transitiveMap)
        {
            string total = final[0];
            for (int i = 1; i < final.Count(); i++)
            {
                total = transitiveMap[total][final[i]];
            }
            return total;
        }
    }
}
