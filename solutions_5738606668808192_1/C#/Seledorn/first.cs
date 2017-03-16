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
            generatePrimes(1<<10);
            bool first = true;
            foreach (String s in File.ReadLines(@"C:\Users\Daniel\Downloads\C-large.in")) {
                if (!first) {
                    String old="";
                    String current="";
                    foreach (char c in s) {
                        if(Char.IsDigit(c)) {
                            current = current + c;
                        } else {
                            old = current;
                            current = "";
                        }
                    }
                    String outPath = @"C:\Users\Daniel\Downloads\C-large.out";
                    int keyLen = Int32.Parse(old);
                    int amount = Int32.Parse(current);
                    Result[] res = process(keyLen,amount);
                    File.WriteAllText(outPath, "Case #"+1 + ":\n");
                    for (int i = 0; i<res.Length;i++) {
                        File.AppendAllText(outPath, BitArrayToString(res[i].key,keyLen));
                        for (int j = 2; j<= 10; j++) {
                            File.AppendAllText(outPath, " "+res[i].divisors[j-2]);
                        }
                        File.AppendAllText(outPath, "\n");
                    }
                }
                first = false;
            }

        }        

        struct Result{
            public Result(BitArray key, UInt64[] divisors) {
                this.divisors = divisors;
                this.key = key;
            }
            public BitArray key;
            public UInt64[] divisors;
        }

        static Result[] process(int keyLength, int amount) {
            Result[] ret = new Result[amount];
            int current_index = 0;
            for (int i = 0; (current_index < amount);i++) {
                BitArray key = new BitArray(new int[] { (1<<keyLength-1) | 1 | (i<<1)});
                Console.WriteLine(BitArrayToString(key, keyLength));
                UInt64[] divisors = new UInt64[9];
                bool isPrime = false;
                for (int j = 2; j<=10;j++) {
                    bool success;
                    UInt64 divisor= getADivisor(keyToBase(key, (UInt64)j),out success);
                    if (!success) {
                        isPrime = true;
                        break;
                    } else divisors[j-2] = divisor;
                }
                if (!isPrime) {
                    Console.WriteLine(current_index);
                    ret[current_index++] = new Result(key, divisors);
                }
            }
            return ret;
        }
        
        static List<UInt64> knownPrimes= new List<UInt64>();

        static UInt64 getADivisor(UInt64 num, out bool success) {
            success = true;
            UInt64 maxCheck = (UInt64)Math.Ceiling(Math.Sqrt(num));
            for (int i = 0;i<knownPrimes.Count;i++) {
                if (knownPrimes[i]>maxCheck) break;
                if (num % knownPrimes[i] == 0) {
                    return knownPrimes[i];
                }
            }
            success = false;
            return 0;
        } 

        static void generatePrimes(UInt64 upto) {
            for (UInt64 i = 2; i<upto;i++) {
                bool success;
                getADivisor(i, out success);
                if (!success) knownPrimes.Add(i);
            }
        }

        static UInt64 keyToBase(BitArray key, UInt64 newBase) {
            UInt64 ack =0;
            UInt64 currentPower = 1;
            for (int i = 0; i<key.Length;i++) {
                ack += key[i] ? currentPower : 0;
                currentPower*= newBase;
            }
            return ack;
        }

        static String BitArrayToString(BitArray b, int len) {
            String s = "";
            for(int i = 0; i< len;i++) {
                s+=b[len-i-1] ? "1" : "0";
            }
            return s;
        }
    }
}
