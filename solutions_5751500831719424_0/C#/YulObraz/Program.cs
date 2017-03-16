using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1B_First {
    class Program {
        static void Main(string[] args) {
            int testCount = Console.In.ReadLine().Split(' ').Select(it => Int32.Parse(it)).First();
            for(int i = 0; i < testCount; i++) {
                var test = new Test();
                test.Load();
                Console.Write("Case #{0}: ", i + 1);
                Console.Error.Write("Case #{0}: ", i + 1);
                Console.WriteLine(test.Solve());
                Console.Error.WriteLine(test.Solve());
            }
            //Console.ReadKey();
        }

    }
    public class Test {
        int count;
        string []lines;
        public void Load() {
            count = Console.In.ReadLine().Split(' ').Select(it => Int32.Parse(it)).First();
            lines = new string[count];
            for(int i = 0; i < count; i++) {
                lines[i] = Console.In.ReadLine();
            }
        }
        int[] linepos;
        int[] repeat;
        int calc() {
            if(lines[0].Length <= linepos[0]) {
                for(int i = 0; i < count; i++) {
                    if(lines[i].Length > linepos[i]) {
                        return -1;
                    }
                }
                return -2;
            }
            repeat = new int[count];
            char x = lines[0][linepos[0]];
            int min = Int32.MaxValue; int max = 1;
            for(int i = 0; i < count; i++) { 
                repeat[i] =0;
                while(linepos[i] < lines[i].Length && lines[i][linepos[i]] == x) {
                    repeat[i]++;
                    linepos[i]++;
                }
                if(repeat[i] < min) {
                    min = repeat[i];
                }
                if(repeat[i] > max) {
                    max = repeat[i];                
                }
            }
            if(min == 0) {
                return -1;
            }
            if(min == max) {
                return 0;
            }
            int result = Int32.MaxValue;
            for(int j = min; j <= max; j++) {
                int sum = 0;
                for(int i = 0; i < count; i++) {
                    sum += Math.Abs(j - repeat[i]);
                }
                if(result > sum) {
                    result = sum;
                }
            }
            return result;
        }
        public string Solve() {
            linepos = new int[count];
            int sum = 0;
            while(true) {
                int step = calc();
                if(step == -1) {
                    return "Fegla Won";
                } else if(step == -2) {
                    return sum.ToString();
                } else {
                    sum += step;
                }
            }
            
            return "Error";
        }
        
    }
}
