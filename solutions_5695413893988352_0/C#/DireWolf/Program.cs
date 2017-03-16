using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamCSharp
{
    class Program
    {
       
        static void Main(string[] args)
        {
            int t;
            using (StreamWriter sw = new StreamWriter(@"C:\Users\Vukasin\Desktop\Petnica\GoogleCodeJam\GoogleCodeJam\A-large.out"))
            {
                using (StreamReader sr = new StreamReader(@"C:\Users\Vukasin\Desktop\Petnica\GoogleCodeJam\GoogleCodeJam\A-Small.in"))
                {
                    t = int.Parse(sr.ReadLine());
                    for (int i = 1; i <= t; i++)
                    {
                        List<string> possibleS = new List<string>();
                        List<string> possibleJ = new List<string>();
                        sw.Write("Case #" + i  + ": ");
                        var line = sr.ReadLine();
                        var cols = line.Split(' ');
                        string s = cols[0];
                        string j = cols[1];
                        bool added = false;
                        for (int l = 0; l < s.Length; l++) 
                        {
                            if (s[l] == '?') 
                            {
                                if (added)
                                {
                                    List<string> possibleStmp = new List<string>();

                                    for(int z = 0 ; z < possibleS.Count ; z++)
                                    {
                                        for (int k = 0; k <= 9; k++)
                                        {
                                            char[] tmp = possibleS[z].ToCharArray();
                                            tmp[l] = char.Parse(k.ToString());
                                            possibleStmp.Add(new string(tmp));
                                        }
                                    }

                                    possibleS = possibleStmp;
                                }
                                else 
                                {
                                    for (int k = 0; k <= 9; k++) 
                                    {
                                        char[] tmp = s.ToCharArray();
                                        tmp[l] = char.Parse(k.ToString());
                                        possibleS.Add(new string(tmp));
                                    }
                                    added = true;
                                }
                            }
                        }
                        if (added == false) 
                        {
                            possibleS.Add(s);
                        }

                        added = false;
                        for (int l = 0; l < j.Length; l++)
                        {
                            if (j[l] == '?')
                            {
                                if (added)
                                {
                                    List<string> possibleJtmp = new List<string>();

                                    for (int z = 0; z < possibleJ.Count; z++)
                                    {
                                        for (int k = 0; k <= 9; k++)
                                        {
                                            char[] tmp = possibleJ[z].ToCharArray();
                                            tmp[l] = char.Parse(k.ToString());
                                            possibleJtmp.Add(new string(tmp));
                                        }
                                    }

                                    possibleJ = possibleJtmp;
                                }
                                else
                                {
                                    for (int k = 0; k <= 9; k++)
                                    {
                                        char[] tmp = j.ToCharArray();
                                        tmp[l] = char.Parse(k.ToString());
                                        possibleJ.Add(new string(tmp));
                                    }
                                    added = true;
                                }
                            }
                        }
                        if (added == false)
                        {
                            possibleJ.Add(j);
                        }

                        List<int> pobbislnumberS = possibleS.Select(x => int.Parse(x)).ToList();
                        List<int> pobbislnumberJ = possibleJ.Select(x => int.Parse(x)).ToList();

                        Dictionary<int, List<Tuple<string, string>>> possibleRes = new Dictionary<int, List<Tuple<string, string>>>();
                        foreach (var nb in possibleS) 
                        {
                            foreach (var nb1 in possibleJ) 
                            {
                                if (!possibleRes.ContainsKey((int)Math.Abs(int.Parse(nb1) - int.Parse(nb)))) 
                                {
                                    possibleRes.Add((int)Math.Abs(int.Parse(nb1) - int.Parse(nb)), new List<Tuple<string, string>>());
                                }
                                possibleRes[(int)Math.Abs(int.Parse(nb1) - int.Parse(nb))].Add(Tuple.Create(nb, nb1));
                            }
                        }
                        var res = possibleRes.OrderBy(x => x.Key).First().Value.OrderBy(x => x.Item1).ThenBy(x => x.Item2).First();
                        sw.WriteLine(res.Item1 + " " + res.Item2);

                    }
                }
	}
        }
    }
}


