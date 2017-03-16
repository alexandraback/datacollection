using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApplication18
{
    class Kvaternion
    {
        public bool minus;
        public char value;
        public Kvaternion()
        {
            this.minus = false;
            this.value = '1';
        } 
        public char suc(char a, char b, bool min)
        {
            if (min) minus = !minus;
            switch (a)
            {
                case '1':
                    switch (b)
	                {
                        case '1':
                            return '1';
                        case 'i':
                            return 'i';
                        case 'j':
                            return 'j';
                        case 'k':
                            return 'k';
                        default:
                            return a;
	                }
                case 'i':
                    switch (b)
                    {
                        case '1':
                            return 'i';
                        case 'i':
                            minus = !minus;
                            return '1';
                        case 'j':
                            return 'k';
                        case 'k':
                            minus = !minus;
                            return 'j';
                        default:
                            return a;
                    }
                case 'j':
                    switch (b)
                    {
                        case '1':
                            return 'j';
                        case 'i':
                            minus = !minus;
                            return 'k';
                        case 'j':
                            minus = !minus;
                            return '1';
                        case 'k':
                            return 'i';
                        default:
                            return a;
                    }
                case 'k':
                    switch (b)
                    {
                        case '1':
                            return 'k';
                        case 'i':
                            return 'j';
                        case 'j':
                            minus = !minus;
                            return 'i';
                        case 'k':
                            minus = !minus;
                            return '1';
                        default:
                            return a;
                    }
                default:
                    return a;
            }
        }
    }

    class Program
    {
        static long min(long a, long b)
        {
            if (a < b) return a;
            else return b;
        }
        
        static long SucinJednehoSubstringu(ref Kvaternion prvy, string S, long L)
        {
            Kvaternion pom = new Kvaternion();
            /*for (int i = 0; i < S.Length; i++)
            {
                pom.value = pom.suc(pom.value, S[i], false);
            }
            */
            for (long i = 0; i < L; i++)
            {
                prvy.value = prvy.suc(prvy.value, S[(int)i], false);
            }
            return prvy.value;
        }

        static void Main(string[] args)
        {
            //int T = Ctecka.ReadInt();
            long T = int.Parse(Console.ReadLine());
            long l;
            long x;
            string S;
            string P;
            bool ano;
            bool[] vystup = new bool[T];
            string[] Psplit = new string[5];
            
            for (long i = 0; i < T; i++)
            {
                //Console.WriteLine("#{0}", i);
                ano = false;
                P = Console.ReadLine();
                Psplit = P.Split(' ');
                l = long.Parse(Psplit[0]);
                x = long.Parse(Psplit[1]);
                //x = 16 + (x % 16);
                //l = Ctecka.ReadInt();
                //x = Ctecka.ReadInt();
                //Console.ReadLine();
                S = Console.ReadLine();

                Kvaternion prvy = new Kvaternion();
                Kvaternion cely = new Kvaternion();
                prvy.value = (char)SucinJednehoSubstringu(ref prvy, S, S.Length);
                //Console.WriteLine((char)prvy.value);
                //Console.WriteLine(prvy.minus);
                for (long j = 0; j < (x % 4); j++)
                {
                    cely.value = cely.suc(cely.value, prvy.value, prvy.minus);
                   
                }
                //Console.WriteLine((char)(cely.value));
                //Console.WriteLine((cely.minus));
                if ((cely.value != '1') || (!cely.minus))
                {
                    //NIC
                }
                else
                {
                    Kvaternion ickovy = new Kvaternion();
                    for (long j = 0; j < min(4 * S.Length, x * S.Length); j++)
                    {
                        //Console.WriteLine("#{0}", ickovy.value);
                        ickovy.value = ickovy.suc(ickovy.value, S[(int)j % S.Length], false);
                        if (ickovy.value == 'i')
                        {
                            Kvaternion druhy = new Kvaternion();
                            for (long k = j + 1; k < min(j + 1 + 4 * S.Length, x * S.Length); k++)
                            {
                                druhy.value = druhy.suc(druhy.value, S[(int)k % S.Length], false);
                                if (druhy.value == 'j')
                                {
                                    Kvaternion spolu = new Kvaternion();
                                    spolu.value = spolu.suc(ickovy.value, druhy.value, ickovy.minus);
                                    if (ickovy.minus) spolu.minus = !spolu.minus;
                                    spolu.value = spolu.suc(spolu.value, 'k', false);
                                    if ((spolu.value == '1') && (spolu.minus))
                                    {
                                        ano = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                vystup[i] = ano;

            }
            for (long i = 0; i < T; i++)
            {
                if (vystup[i])
                {
                    Console.WriteLine("Case #{0}: YES", i+1);
                }
                else
                    Console.WriteLine("Case #{0}: NO", i+1);
            }

            //Console.ReadLine();
        }
    }
}
