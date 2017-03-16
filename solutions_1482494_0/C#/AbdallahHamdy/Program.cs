using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
namespace lang
{
    class Levels
    {
        public int oneStar;
        public int twoStar;
        public bool oneStare=false;
        public bool TwoStare=false;
        public Levels(int o, int t)
        {
            oneStar = o;
            twoStar = t;
        }
    }
    class Program
    {
        static StreamReader read;
        static StreamWriter write;

        static void Main(string[] args)
        {
            read = new StreamReader("input.txt");
            write = new StreamWriter("output.txt");
            int T = Convert.ToInt32(read.ReadLine());
            Dictionary<string, char> hist = new Dictionary<string, char>();
            for (int i = 0; i < T; i++)
            {
                string code = read.ReadLine();
                int n = Convert.ToInt16(code);
                List<Levels> levels = new List<Levels>();
                for (int j = 0; j < n; j++)
                {
                    code = read.ReadLine();
                    string []c=code.Split(' ');
                    levels.Add(new Levels( Convert.ToInt32(c[0]),Convert.ToInt32(c[1])));
                }
                int Score = 0;
                int itr = 0;
                bool imp = false;
               
                while (levels.Count > 0&&!imp)
                {
                    int re=-1;
                    bool two = false;
                    int max = -1;
                    for (int j = 0; j < levels.Count; j++)
                    {
                        if (levels[j].twoStar <= Score)
                        {
                            if (levels[j].oneStare)
                                Score += 1;
                            else
                                Score += 2;
                            levels.RemoveAt(j);
                            two = true;
                            break;
                        }
                        else if (levels[j].oneStar <= Score && !levels[j].oneStare && levels[j].twoStar > max)
                        {
                            re = j;
                            max = levels[j].twoStar;
                        }
                    }
                    if (!two)
                    {
                        if (re != -1)
                        {
                            levels[re].oneStare = true;
                            Score++;
                        }
                        else
                            imp = true;
                    }
                    itr++;
                }
                if (imp)
                {
                    write.WriteLine("Case #" + (i + 1) + ": " + "Too Bad");
                    Console.WriteLine("Case #" + (i + 1) + ": " + "Too Bad");
                }
                else
                {
                    write.WriteLine("Case #" + (i + 1) + ": " + itr);
                    Console.WriteLine("Case #" + (i + 1) + ": " + itr);
                }
            }
            write.Close();
        }
        static string Rotate(string A)
        {
            return A.Substring(A.Length - 1, 1) + A.Substring(0, A.Length - 1);
            
        }
    }
}
/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up
*/