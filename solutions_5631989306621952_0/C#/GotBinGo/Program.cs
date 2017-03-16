using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejama
{
    class Program
    {
        static void Main(string[] args)
        {
            var g = File.ReadAllLines("a.txt").Skip(1);
            var f = new List<string>();
            foreach (string s in g)
            {
                List<char> e = new List<char>();
                foreach (char c in s)
                {
                    if (e.Count() == 0)
                        e.Add(c);
                    else
                    {
                        
                        if ((int)c >= (int)e[0])
                            e.Insert(0, c);
                        else
                            e.Add(c);
                    }
                }
                f.Add(String.Join("", e));
            
            }
            //var g = File.ReadAllLines("a.txt").Skip(1).Select((x, i) => "Case #"+i+": "+String.Join("", x.ToCharArray().ToList().OrderBy(y => y).Reverse())).ToList();
            
            File.WriteAllLines("a_ki.txt", f.Select((x, i) => "Case #"+(i+1)+": " + x).ToArray());

        }
    }
}
