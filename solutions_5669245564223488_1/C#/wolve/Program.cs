using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using Helper;

namespace ProblemB
{
    public class Car
    {
        public char First;
        public char Last;
        public string Letters;
        public int M;
    }

    public class Solver
    {
        public long Permutations(int k)
        {
            long p = 1;
            while (k > 0)
            {
                p = (p * k) % 1000000007;
                k--;
            }
            return p % 1000000007;
        }

        public string Simplify(string car)
        {
            char last = ' ';
            var sb = new StringBuilder();
            for (int i = 0; i < car.Length; i++)
            {
                char ch = car[i];
                if (last != ch)
                {
                    sb.Append(ch);
                }
                last = ch;
            }
            return sb.ToString();
        }

        public String Solve(String input)
        {
            var sb = new StringBuilder();
            var reader = new InputReader(input);
            var T = reader.NextInt();
            for (int i = 0; i < T; i++)
            {
                var N = reader.NextInt();
                var cars = new List<string>();
                for (int j = 0; j < N; j++)
                {
                    var str = Simplify(reader.NextString());
                    cars.Add(str);
                }

                cars.Sort();

                var train = new List<Car>();
                for (int k = 0; k < cars.Count; k++)
                {
                    var c = new Car() { First = cars[k].First(), Last = cars[k].Last(), M = 1, Letters = cars[k]};
                    train.Add(c);
                }


                // join aa and aa
                for (int j = 0; j < train.Count; j++)
                {
                    var a = train[j];
                    if (a.Letters.Length > 1) continue;
                    for (int m = 0; m < train.Count; m++)
                    {
                        if (j == m) continue;

                        var b = train[m];
                        if (b.Letters.Length > 1) continue;
                        
                        if (a.First == b.First)
                        {
                            a.M++;
                            train.RemoveAt(m);
                            j--;
                            break;
                        }
                    }
                }
                long totalM = 1;
                foreach (var t in train)
                {
                    totalM = (totalM * Permutations(t.M)) % 1000000007;
                }

                // join aa and ab
                for (int j = 0; j < train.Count; j++)
                {
                    var a = train[j];
                    for (int m = j + 1; m < train.Count; m++)
                    {
                        var b = train[m];

                        if (a.Last == b.First)
                        {
                            a.Last = b.Last;
                            a.Letters += b.Letters;
                            train.RemoveAt(m);
                            j--;
                            break;
                        }
                        if (b.Last == a.First)
                        {
                            a.First = b.First;
                            a.Letters = b.Letters + a.Letters;
                            train.RemoveAt(m);
                            j--;
                            break;
                        }
                    }
                }

                var compl = new StringBuilder();
                foreach (var t in train)
                {
                    compl.Append(t.Letters);
                }

                var complStr = compl.ToString();

                // validate seq
                bool isValid = true;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    int status = 0;
                    for (int j = 0; j < complStr.Length; j++)
                    {
                        if (complStr[j] == ch)
                        {
                            if (status == 0)
                            {
                                status = 1;
                            }

                            if (status == 2)
                            {
                                status = -1;
                            }
                        }
                        else
                        {
                            if (status == 1)
                            {
                                status = 2;
                            }
                        }
                    }
                    if (status == -1)
                    {
                        isValid = false;
                        break;
                    }
                }

                totalM = (totalM * Permutations(train.Count)) % 1000000007;


                sb.Append("Case #");
                sb.Append("" + (i + 1));
                sb.Append(": ");

                sb.Append(isValid ? totalM : 0);
                sb.AppendLine();
            }

            return sb.ToString();
        }
    }


    public class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = "example.in";
            const string filename = "B-large.in";
            string outFile = filename.Replace(".in", ".out");
            var result = new Solver().Solve(File.ReadAllText(filename));
            Console.Write(result);
            File.WriteAllText(outFile, result);
        }
    }
}
