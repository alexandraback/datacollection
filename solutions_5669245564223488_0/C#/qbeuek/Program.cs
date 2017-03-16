using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace second
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    inputStream.ReadLine();

                    var strings = inputStream.ReadLine().Split().ToList();

                    var result = 0L;
                    foreach (var permutation in Permutate(strings, strings.Count))
                    {
                        char? previous = null;
                        var seen = new HashSet<char>();
                        var valid = true;
                        foreach (var car in permutation)
                        {
                            foreach (var wagon in car)
                            {
                                if (previous.HasValue && previous != wagon && seen.Contains(wagon))
                                {
                                    valid = false;
                                    break;
                                }

                                seen.Add(wagon);
                                previous = wagon;
                            }
                            if (!valid)
                                break;
                        }
                        if (valid)
                        {
                            result++;
                            result = result % 1000000007;
                        }
                    }

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, result);
                }
            }
        }

        static void RotateRight<T>(List<T> sequence, int count)
        {
            T tmp = sequence[count - 1];
            sequence.RemoveAt(count - 1);
            sequence.Insert(0, tmp);
        }

        static IEnumerable<List<T>> Permutate<T>(List<T> sequence, int count)
        {
            if (count == 1) yield return sequence;
            else
            {
                for (int i = 0; i < count; i++)
                {
                    foreach (var perm in Permutate(sequence, count - 1))
                        yield return perm;
                    RotateRight(sequence, count);
                }
            }
        }
    }
}
