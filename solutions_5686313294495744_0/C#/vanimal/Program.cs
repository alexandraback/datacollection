using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jam
{
    class Program
    {
        static void Main(string[] args)
        {
            int cases = ReadInt();

            for (int i = 0; i < cases; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, Solve());
            }
        }
        
        static string Solve()
        {
            int signups = ReadInt();

            List<Tuple<string, string>> topics = Enumerable.Range(0, signups).Select(i => ReadString().Split(' ')).Select(p => Tuple.Create(p[0], p[1])).ToList();

            int distinctFirsts = topics.Select(t => t.Item1).Distinct().Count();
            int distinctSeconds = topics.Select(t => t.Item2).Distinct().Count();

            return Math.Min(signups - distinctFirsts, signups - distinctSeconds).ToString();
        }

        static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        static string ReadString()
        {
            return Console.ReadLine();
        }

        static List<T> ReadList<T>()
        {
            return Console.ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToList();
        }
    }
}
