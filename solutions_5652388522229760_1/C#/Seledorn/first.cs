using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace googleshit {
    class Program {
        static void Main(string[] args) {
            List<int> output= new List<int>();
            bool first=true;
            foreach (String s in File.ReadLines(@"C:\Users\Daniel\Downloads\A-large.in")) {
                if(!first)
                    output.Add(process(Int32.Parse(s)));
                first = false;
            }

            for (int i = 0; i< output.Count;i++) {
                File.AppendAllText(@"C:\Users\Daniel\Downloads\A-large.out","Case #"+(i+1) + ": " + ((output[i] == -1)? "INSOMNIA" : output[i].ToString())+ "\n");
            }
        }
        
        static int process(int n) {
            int num = -1;
            if(n == 0) {
                return num;
            }

            bool[] numsTaken = new bool[10];
            for (int i = 1; numsTaken.Contains(false); i++) {
                num = i*n;
                foreach (char c in num.ToString()) {
                    for (int j = 0; j<numsTaken.Length; j++) {
                        if (c == j.ToString().First()) {
                            if (numsTaken[j]!=true)
                                Console.WriteLine(num +" "+ j);
                            numsTaken[j]=true;
                        }
                    }
                }
            }
            return num;
        }        
    }
}
