using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_MagicTrick
{
    class Program
    {
        static TextReader input = Console.In;
        static TextWriter output = Console.Out;
        static void Main(string[] args)
        {
            if (args.Any())
            {
                var path = args[0];
                if (File.Exists(path))
                {
                    input = File.OpenText(path);
                }
                path = path.Remove(path.LastIndexOf('.'));
                path += ".out";
                output = File.CreateText(path);
            }

            int totalCases = int.Parse(input.ReadLine());
            for (int currentCase = 1; currentCase <= totalCases; currentCase++)
            {
                string caseOutput = HandleCase(input);
                output.WriteLine(string.Format("Case #{0}: {1}", currentCase, caseOutput));
            }
            output.Flush();
        }

        private static string HandleCase(TextReader input)
        {
            string line = input.ReadLine();
            int blockAmount = int.Parse(line);
            var NaomiBlocksWar = input.ReadLine().Split(' ').Select(double.Parse).OrderBy(weight => weight).ToList();
            var NaomiBlocksDeceitful = NaomiBlocksWar.ToList();
            var KenBlocksWar = input.ReadLine().Split(' ').Select(double.Parse).OrderBy(weight => weight).ToList();
            var KenBlocksDeceitful = KenBlocksWar.ToList();

            // play war first
            int warWins = 0;
            for (int i = 0; i < blockAmount; i++)
            {
                // naomi ai for war: take alternating lowest and highest
                // ken ai for war: take lowest above naomi block, or give up with lowest block
                var naomiBlock = i % 2 == 0 ? NaomiBlocksWar.TakeFirst() : NaomiBlocksWar.TakeLast();

                var kenBlock = KenBlocksWar.TakeFirstHigher(naomiBlock);
                // there is no higher, ken gives up this round with his lowest block
                if (kenBlock == default(double))
                {
                    kenBlock = KenBlocksWar.TakeFirst();
                }

                if (naomiBlock > kenBlock)
                {
                    warWins++;
                }
            }

            // play deceitful war
            int deceitfulWarWins = 0;
            for (int i = 0; i < blockAmount; i++)
            {
                // naomi ai for deceitful war: look at ken's lowest block, take her first higher block and lie about it being ken's highest + i * E-8
                // ken ai for deceitful war: same as above: take lowest block above naomi block, or give up with lowest block
                // since naomi is cheating, ken's block is ALWAYS the lowest
                var kenBlock = KenBlocksDeceitful.TakeFirst();

                var naomiBlock = NaomiBlocksDeceitful.TakeFirstHigher(kenBlock);
                if (naomiBlock == default(double))
                {
                    naomiBlock = NaomiBlocksDeceitful.TakeFirst();
                }

                if (naomiBlock > kenBlock)
                {
                    deceitfulWarWins++;
                }
            }

            return deceitfulWarWins + " " + warWins;
        }
    }

    public static class ListExtensions
    {
        public static T TakeFirst<T>(this List<T> list)
        {
            T value = list[0];
            list.RemoveAt(0);
            return value;
        }

        public static T TakeLast<T>(this List<T> list)
        {
            T value = list[list.Count - 1];
            list.RemoveAt(list.Count - 1);
            return value;
        }

        /// <summary>
        /// Assumes sorted
        /// </summary>
        public static T TakeFirstHigher<T>(this List<T> list, T value) where T:IComparable
        {
            T firstHigher = list.FirstOrDefault(val => val.CompareTo(value) > 0);
            if (firstHigher.CompareTo(default(T)) != 0)
            {
                list.Remove(firstHigher);
            }
            return firstHigher;
        }
    }
}
