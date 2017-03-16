using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Slides_
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader("input.in"))
            using (var sw = new StreamWriter("output.out"))
            {
                string line = sr.ReadLine();
                string[] words = line.Split(' ');
                int t = int.Parse(words[0]);
                int b;
                long m;
                long max;
                string res;
                for (int i = 0; i < t; i++)
                {
                    res = "";
                    line = sr.ReadLine();
                    words = line.Split(' ');
                    b = int.Parse(words[0]);
                    m = long.Parse(words[1]);

                    max = 1;
                    for (int j = 1; j < b - 1; j++)
                        max *= 2;


                    if (m > max)
                        sw.WriteLine(string.Format("Case #{0}: IMPOSSIBLE", i + 1));
                    else
                    {
                        List<List<char>> stringList = new List<List<char>>();
                        long current;
                        if (max == 1)
                            current = max;
                        else
                            current = max / 2;

                        for (int j = 0; j < b; j++)
                        {
                            List<char> tmp = new List<char>();

                            for (int k = 0; k < b; k++)
                            {
                                tmp.Add('0');
                            }

                            stringList.Add(tmp);
                        }

                        for (int j = 0; j < b - 1; j++)
                        {
                            for (int k = j+1; k < b - 1; k++)
                            {
                                stringList[j][k] = '1';
                            }
                        }

                        for (int j = 0; j < b - 1; j++)
                        {
                            if (m - current >= 0)
                            {
                                m = m - current;
                                stringList[b-2-j][b-1] = '1';
                            }

                            if (current >= 2)
                                current = current / 2;

                            if (m == 0)
                                break;
                        }

                        for (int j = 0; j < stringList.Count; j++)
                        {
                            res += string.Join("", stringList[j]) + "\n";
                        }

                        sw.WriteLine(string.Format("Case #{0}: POSSIBLE", i + 1));
                        sw.Write(string.Format("{0}", res));
                    }
                }
            }
        }
    }
}
