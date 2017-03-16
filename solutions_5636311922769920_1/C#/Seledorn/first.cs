using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace googlestuff {
    class Program {
        static void Main(string[] args) {

            bool first = true;
            List<List<Int64>> results = new List<List<Int64>>();
            foreach (String s in File.ReadLines(@"C:\Users\Daniel\Downloads\D-Large.in")) {
                if (!first) {
                    var input = s.Split(' ').Select(i=>Int32.Parse(i));
                    int length = input.ElementAt(0);
                    int complexity = input.ElementAt(1);
                    int students = input.ElementAt(2);
                    results.Add(process(students, complexity, length));         
                }
                first = false;
            }
            String outPath = @"C:\Users\Daniel\Downloads\D-Large.out";
            File.WriteAllText(outPath, "");
            for(int i = 0; i<results.Count;i++) {
                File.AppendAllText(outPath,"Case #"+(i+1)+": "+((results[i] == null) ? "IMPOSSIBLE" : String.Join(" ", results[i]))+"\n");
            }
            Console.ReadLine();
        }


        static List<Int64> process(int students, int complexity, int length) {
            Console.WriteLine(students + "" + complexity + "" + length);
            if (students*complexity<length) return null;
            List<Int64> ret = new List<Int64>();

            int leastNumberOfSquares = (int)Math.Ceiling(length/(float)complexity);

            
            for (int i = 0; i<leastNumberOfSquares; i++) {
                Int64 answer = singleOut(Enumerable.Range(i*complexity, complexity).Select(n => n%length).ToArray(), length)+1;
                ret.Add(answer);
            }

            bool success = verify(students, complexity, length, ret);

            return ret; 
        }

        static int verifications = 0;
        public static bool verify(int students, int complexity,int length, List<Int64> answers) {
            ++verifications;
            bool[] tiles = new bool[length];
            int overlapp=0;
            foreach(Int64 a in answers) {
                Int64 answer = a-1;
                for (int i = 0; i<complexity;i++)
                {
                    Int64 tile = answer%length;
                    if (tiles[tile]==true) ++overlapp;
                    Console.WriteLine(tile);
                    tiles[tile] = true;
                    answer-=tile;
                    answer/=length;
                }
            }

            if(tiles.All(e => e))
                Console.WriteLine("passed test # "+verifications+": " + overlapp);
            else {
                Console.WriteLine("failed test # "+verifications);
                Console.WriteLine("students:"+students+" complexity:"+complexity+" length:"+length);
                Console.WriteLine("answer was: " + String.Join(" ", answers));
                int i = 0;
                foreach (bool b in tiles) {
                    if(!b)
                    Console.WriteLine("\t "+i);
                    ++i;
                }
                Console.Read();
            }
            return tiles.All(e => e);
        }

        static Int64 singleOut(int[] poses, int length) {
            //Console.WriteLine(String.Join(" ", poses));
            Int64 ret=poses[0];
            for(int i = 1; i<poses.Length;i++) {
                ret= ret*length;
                ret += poses[i];
            }
            return ret;
        }
    }
}
