using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Repeater {
    class Program {
        static void Main(string[] args) {
            using (var reader = new StreamReader("A-small-attempt0.in"))
            using (var writer = new StreamWriter("A-small-attempt0.out")) {
                int tests = int.Parse(reader.ReadLine());
                for (int test = 1; test <= tests; test++) {
                    SolveTest(reader, writer, test);
                }
            }
        }

        private static void SolveTest(StreamReader reader, StreamWriter writer, int test) {
            int stringCount = int.Parse(reader.ReadLine());
            var strings = new string[stringCount];
            for (int i = 0; i < stringCount; i++) {
                strings[i] = reader.ReadLine();
            }

            var orders = new List<Tuple<char, int>[]>();
            orders.Add(StringToOrder(strings[0]));
            for (int i = 1; i < stringCount; ++i) {
                orders.Add(StringToOrder(strings[i]));
                if (new String(orders[0].Select(x => x.Item1).ToArray()) != new string(orders[i].Select(x => x.Item1).ToArray())) {
                    writer.WriteLine("Case #{0}: Fegla Won", test);
                    return;
                }
            }
            /*foreach (var o in orders) {
                foreach (var t in o)
                    Console.Write("({0}, {1}) ", t.Item1, t.Item2);
                Console.WriteLine();
            }*/

            var ans = 0;
            for (int l = 0; l < orders[0].Length; ++l) {
                var minCount = orders.Min(o => o[l].Item2);
                var maxCount = orders.Max(o => o[l].Item2);
                int minActions = int.MaxValue;
                for (int des = minCount; des <= maxCount; ++des) {
                    var actions = orders.Sum(o => Math.Abs(des - o[l].Item2));
                    minActions = Math.Min(actions, minActions);
                }
                ans += minActions;
            }

            writer.WriteLine("Case #{0}: {1}", test, ans);
        }

        private static Tuple<char, int>[] StringToOrder(string s) {
            var order = new List<Tuple<char, int>>();
            char previous = s[0];
            order.Add(Tuple.Create(s[0], 0));
            for (int i = 1; i < s.Length; i++) {
                if (s[i] != previous) {
                    order[order.Count - 1] = Tuple.Create(order.Last().Item1, i - order.Last().Item2);
                    previous = s[i];
                    order.Add(Tuple.Create(previous, i));
                }
            }
            order[order.Count - 1] = Tuple.Create(order.Last().Item1, s.Length - order.Last().Item2);
            return order.ToArray();
        }
    }
}
