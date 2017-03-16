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
                using (StreamReader sr = new StreamReader(@"C:\Users\Vukasin\Desktop\Petnica\GoogleCodeJam\GoogleCodeJam\A-large.in"))
                {
                    t = int.Parse(sr.ReadLine());
                    for (int i = 1; i <= t; i++)
                    {
                        sw.Write("Case #" + i  + ": ");
                        string s = sr.ReadLine();
                        var dic = new Dictionary<char, int>();
                        var res = new List<int>();
                        for (int j = 0; j < 30; j++) 
                        {
                            dic.Add((char)('A' + j), 0);
                        }
                        foreach (var c in s) 
                        {
                            if (!dic.ContainsKey(c)) 
                            {
                                dic.Add(c, 0);
                            }
                            dic[c]++;
                        }
                        // case 0
                        if (dic['Z'] != 0) 
                        {
                            for (int j = 0; j < dic['Z']; j++) 
                            {
                                res.Add(0);
                                dic['E']--;
                                dic['R']--;
                                dic['O']--;
                            }
                        }
                        dic['Z'] = 0;

                        // case 2
                        if (dic['W'] != 0)
                        {
                            for (int j = 0; j < dic['W']; j++)
                            {
                                res.Add(2);
                                dic['T']--;
                                dic['O']--;
                            }
                        }
                        dic['W'] = 0;

                        // case 4
                        if (dic['U'] != 0)
                        {
                            for (int j = 0; j < dic['U']; j++)
                            {
                                res.Add(4);
                                dic['F']--;
                                dic['O']--;
                                dic['R']--;
                            }
                        }
                        dic['U'] = 0;

                        // case 6
                        if (dic['X'] != 0)
                        {
                            for (int j = 0; j < dic['X']; j++)
                            {
                                res.Add(6);
                                dic['S']--;
                                dic['I']--;
                            }
                        }
                        dic['X'] = 0;

                        // case 8
                        if (dic['G'] != 0)
                        {
                            for (int j = 0; j < dic['G']; j++)
                            {
                                res.Add(8);
                                dic['E']--;
                                dic['I']--;
                                dic['H']--;
                                dic['T']--;

                            }
                        }
                        dic['G'] = 0;

                        // case 3
                        if (dic['T'] != 0)
                        {
                            for (int j = 0; j < dic['T']; j++)
                            {
                                res.Add(3);
                                dic['H']--;
                                dic['R']--;
                                dic['E']--;
                                dic['E']--;
                            }
                        }
                        dic['T'] = 0;

                        // case 1
                        if (dic['O'] != 0)
                        {
                            for (int j = 0; j < dic['O']; j++)
                            {
                                res.Add(1);
                                dic['N']--;
                                dic['E']--;
                            }
                        }
                        dic['O'] = 0;

                        // case 5
                        if (dic['F'] != 0)
                        {
                            for (int j = 0; j < dic['F']; j++)
                            {
                                res.Add(5);
                                dic['I']--;
                                dic['V']--;
                                dic['E']--;
                            }
                        }
                        dic['F'] = 0;

                        // case 7
                        if (dic['S'] != 0)
                        {
                            for (int j = 0; j < dic['S']; j++)
                            {
                                res.Add(7);
                                dic['E']--;
                                dic['V']--;
                                dic['E']--;
                                dic['N']--;
                            }
                        }
                        dic['S'] = 0;

                        // case 9
                        if (dic['E'] != 0)
                        {
                            for (int j = 0; j < dic['E']; j++)
                            {
                                res.Add(9);
                                dic['N']--;
                                dic['I']--;
                                dic['N']--;
                            }
                        }
                        dic['E'] = 0;

                        sw.WriteLine(string.Join("", res.OrderBy(x => x)));
                    }
                }
	}
        }
    }
}


