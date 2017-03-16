using Combinatorics.Collections;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Code_Jam_2014
{
    class Ex2
    {
        static void Main(string[] args)
        {
            

            using (StreamWriter writer = new StreamWriter("B-small-attempt0.out"))
            {
                using (StreamReader sw = new StreamReader("B-small-attempt0.in"))
                {
                    int num = int.Parse(sw.ReadLine());

                    for (int i = 1; i <= num; i++)
                    {
                        string trash = sw.ReadLine();
                        List<string> trains = sw.ReadLine().Split(' ').ToList();

                        writer.WriteLine("Case #" + i + ": " + Solve(trains));
                    }
                }
            }
        }

        public static bool CheckStr(string str)
        {
            if (str.Length == 1)
                return true;

            HashSet<char> wasLetters = new HashSet<char>();
            for(int i = 0; i < str.Length - 1; i++)
            {
                if (wasLetters.Contains(str[i]))
                    return false;

                while (i < str.Length - 1 && str[i] == str[i + 1])
                    i++;

                wasLetters.Add(str[i]);
            }
            if (str.Last() != str[str.Length - 2] && wasLetters.Contains(str.Last()))
                return false;

            return true;
        }

        public static BigInteger Solve(List<string> pociagi)
        {
            BigInteger result = 0;
            object locker = new object();
            var p = new Permutations<string>(pociagi, GenerateOption.WithRepetition);
            Parallel.ForEach(p, new ParallelOptions { MaxDegreeOfParallelism = 30 }, str =>
            {
                bool isValid = CheckStr(string.Join("", str));
                if (isValid)
                    lock (locker)
                        result += 1;
            });

            return result;
        }

        public static IEnumerable<IEnumerable<T>> Permutation<T>(IEnumerable<T> input)
        {
            if (input == null || !input.Any()) yield break;
            if (input.Count() == 1) yield return input;

            foreach (var item in input)
            {
                var next = input;
                foreach (var perm in Permutation(next))
                {
                    yield return (new List<T> { item }).Concat(perm);
                }
            }
        }
    }
}
