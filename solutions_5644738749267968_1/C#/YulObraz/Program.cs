using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace War
{
    class Program {
        static void Main(string[] args) {
            if(args.Length>0 &&args[0] == "test") {
                Console.WriteLine("1");
                int n = 1000;
                Console.WriteLine(n.ToString());
                for(int i = 0; i < n-1; i++) {
                    Console.Write(string.Format(CultureInfo.InvariantCulture, "{0:N6} ", i));
                }
                Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "{0:N6}", n));
                for(int i = n-1; i >0; i--) {
                    Console.Write(string.Format(CultureInfo.InvariantCulture, "{0:N6} ", i+0.5));
                }
                Console.WriteLine(string.Format(CultureInfo.InvariantCulture, "{0:N6}", -0.5));
                return;
            }
            int testCount = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First();
            for(int i = 1; i <= testCount; i++) {
                Test test = new Test();
                test.Load();
                Console.WriteLine("Case #{0}: {1}", i, test.Solve());
            }
        }
    }
    public class Test {
        List<float> linesN;
        List<float> linesK;
        int count;
        public void Load() {
            count = Console.ReadLine().Split().Select(it => Int32.Parse(it)).First();
            linesN = Console.ReadLine().Split().Select(it => Single.Parse(it, CultureInfo.InvariantCulture)).ToList();
            linesN.Sort();
            linesK = Console.ReadLine().Split().Select(it => Single.Parse(it, CultureInfo.InvariantCulture)).ToList();
            linesK.Sort();
        }
        public int calcDeceit() {
            int result = 0;
            List<float> source = new List<float>(linesN);
            source.Sort();
            List<float> line = new List<float>(linesK);
            line.Sort();
            while(source.Any()) {
                if(source.Last() < line.Last()) {//k wins
                    source.RemoveAt(0);
                    line.RemoveAt(line.Count - 1);
                } else { //n wins
                    result++;
                    source.RemoveAt(source.Count - 1);
                    line.RemoveAt(line.Count - 1);
                }
            }
            return result;
        }
        public int calcOptim() {
            int result = 0;
            List<float> line = new List<float>(linesK);
            line.Sort();
            foreach(float val in linesN) {
                int index = line.BinarySearch(val);
                index = ~index;
                if(index == line.Count) { //N wins
                    line.RemoveAt(0);
                    result++;
                } else { //K wins
                    line.RemoveAt(index);
                }
            }
            return result;
        }
        public string Solve() {
            return calcDeceit().ToString() + " " + calcOptim().ToString();
        }
    }
}
