using System.IO;
using System.Text;

namespace CodeJam2012
{
    class ProblemA
    {
        static void Main(string[] args)
        {
            StringBuilder output = new StringBuilder();
            
            string map = "ynficwlbkuomxsevzpdrjgthaq";

            string[] lines = File.ReadAllLines("A-small-attempt0.in");
            
            for (int i = 1; i < lines.Length; i++)
            {
                string result = "";

                foreach (char c in lines[i])
                {
                    if (c >= 'a' && c <= 'z')
                        result += (char)(map.IndexOf(c) + 97);
                    else
                        result += c;
                }

                output.AppendFormat("Case #{0}: {1}", i, result);
                output.AppendLine();
            }

            File.WriteAllText("A-small-attempt0.out", output.ToString());
        }
    }
}
