using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ_1C2013A_Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "A-small-attempt2";
            FileStream fs = new FileStream(@"C:\Users\Patrick\Desktop\" + filename + ".in", System.IO.FileMode.Open);

            StreamReader sr = new StreamReader(fs);

            int cases = int.Parse(sr.ReadLine());

            FileStream fw = new FileStream(@"C:\Users\Patrick\Desktop\out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fw);



            for (int c = 0; c < cases; c++)
            {
                string line = sr.ReadLine();

                string[] parts = line.Split(' ');
                string name = parts[0];
                int n = int.Parse(parts[1]);


                List<int> consonantIndexes = new List<int>();

                for (int i = 0; i < name.Length - n + 1; i++)
                {

                    if (IsConsonant(name[i]))
                    {
                        bool good = true;
                        for (int j = 1; j < n; j++)
                        {
                            if (isVowel(name[j + i]))
                            {
                                good = false;
                                break;
                            }
                        }
                        if (good)
                            consonantIndexes.Add(i);
                    }
                }

                int nval = 0;

                List<Tuple<int, int>> done = new List<Tuple<int, int>>();


                //done.Add(Tuple.Create<int, int>(1, 2));


                //if (done.Contains(t2))
                //    break;

                foreach (int i in consonantIndexes)
                {
                    int end = name.Length - i - n;

                    Tuple<int, int> t2 = Tuple.Create(i + 1, end + 1);

                    //for (int j = 0; j < i + 1; j++)
                    //{
                    //    for (int k = i + n - 1; k < name.Length; k++)
                    //    {
                    //        Tuple<int, int> t3 = Tuple.Create(j, k);
                    //        if (!done.Contains(t3))
                    //        {
                    //            //nval++;
                    //            done.Add(t3);
                    //        }
                    //    }
                    //}
                    int endi = i + n;
                    if (consonantIndexes.Count > 1)
                    {
                        if (i != 0 && endi != name.Length)
                            nval -= (consonantIndexes.Count -1);
                    }

                   

                    if (!done.Contains(t2))
                    {
                        // nval += end + 1;

                        nval += (i + 1) * (end + 1);

                    }
                }

                if (consonantIndexes.Count > 1)
                {
                    nval -= consonantIndexes.Count - 1;
                }


                int output = nval;





                sw.WriteLine(string.Format("Case #{0}: {1}", c + 1, output));
                Console.WriteLine(string.Format("Case #{0}: {1}", c + 1, output));
            }


            sw.Flush();
            sw.Close();
            fw.Close();
            fs.Close();
            Console.ReadKey();
        }

        public struct pairnum
        {
            public int start;
            public int end;
        }

        static bool isVowel(char c)
        {
            return isVowel(c.ToString());
        }
        static bool isVowel(string c)
        {
            return "aeiou".Contains(c);
        }

        static bool IsConsonant(char c)
        {
            return IsConsonant(c.ToString());
        }
        static bool IsConsonant(string c)
        {
            return !"aeiou".Contains(c);
        }
    }
}
