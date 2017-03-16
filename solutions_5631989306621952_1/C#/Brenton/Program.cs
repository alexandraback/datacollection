using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = new StreamReader("C:\\Users\\Brenton\\Desktop\\cj\\A-large(1).in"))
            using (var sw = new StreamWriter("C:\\Users\\Brenton\\Desktop\\cj\\A-large(1).out"))
            {
                var lines = Int32.Parse(sr.ReadLine());
                for (int i = 1; i <= lines; i++)
                {
                    var word = new Queue<char>(sr.ReadLine().ToCharArray());
                    var output = new List<char>(word.Count);

                    while(word.Any())
                    {
                        if (!output.Any())
                        {
                            output.Add(word.Dequeue());
                        }
                        else
                        {
                            var next = word.Dequeue();
                            if (next >= output.First())
                            {
                                output.Insert(0, next);
                            }
                            else
                            {
                                output.Add(next);
                            }
                        }
                    }

                    sw.WriteLine("Case #" + i + ": " + string.Join("", output));
                }
            }
        }
    }
}
