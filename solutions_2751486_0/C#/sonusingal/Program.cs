using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace googleContest2
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader(@"C:\Users\Sonu\Desktop\Contest\Google\1\A-small-attempt0.in");
            var sw = new StreamWriter(@"C:\Users\Sonu\Desktop\Contest\Google\1\A-small-attempt0_output.in", true);
            sw.AutoFlush = true;
            var count = int.Parse(sr.ReadLine());
            for (var i = 0; i < count; i++)
            {
                var line1 = sr.ReadLine().Split(' ');
                var word = line1[0];
                var n = int.Parse(line1[1]);
                sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, GetCount(word,n)));
            }
        }

        private static int GetCount(string word, int n)
        {
            var vowels = new[] { 97, 101, 105, 111, 117 };
            var count = 0;
            var charList = word.ToCharArray().ToList();
            var l = word.Length;
            var vc = charList.Count(c=>vowels.Contains((int)c));
            var cc = l - vc;
            if (cc < n) return 0;
            for (var i = n; i <= l; i++)
            {
                for (var j = 0; j <= l - i; j++)
                {
                    var ss = word.Substring(j, i).ToCharArray().ToList();
                    vc = charList.Count(c => vowels.Contains((int)c));
                    var b = true;
                    for(var k=0;k<=i-n;k++)
                    {
                        b = true;
                        for (var m = 0; m < n; m++)
                        {
                            if(vowels.Contains((int)ss[k+m]))
                            {
                                b = false;
                                break;
                            }
                        }
                        if (b) break;
                    }

                    if (b) count++;
                }
            }
            return count;
        }         
    }
}
