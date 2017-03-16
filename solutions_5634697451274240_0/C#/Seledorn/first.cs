using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace googlestuff {
    class Program {
        static void Main(string[] args) {
            List<int> output= new List<int>();
            bool first=true;
            foreach (String s in File.ReadLines(@"C:\Users\Daniel\Downloads\B-small-attempt0.in")) {
                if(!first) {
                    bool[] arr = new bool[s.Length];
                    int i = 0;
                    foreach (char c in s) {
                        arr[i] = (c=='+');
                        ++i;
                    }
                    output.Add(process(arr));
                }
                first = false;
            }

            for (int i = 0; i< output.Count;i++) {
                File.AppendAllText(@"C:\Users\Daniel\Downloads\B-small-attempt0.out", "Case #"+(i+1) + ": " + output[i].ToString() + "\n");
            }
        }
        
        static int process(bool[] input) {
            int ack = 0;
            bool last = true;
            for(int i = input.Length-1; i>=0; i--) {
                if (last != input[i]) ack++;
                last = input[i];
            }
            if ((ack%2 == 0) != input[0])
                ++ack;

            return ack;
        }        
    }
}
