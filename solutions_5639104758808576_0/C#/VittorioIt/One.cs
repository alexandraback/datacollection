using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam2015Qualification
{
    class One
    {
        static void Main(string[] args)
        {
            TextReader text = File.OpenText("../../input.txt");
            TextWriter outtext = File.CreateText("../../output.txt");
            int T = int.Parse(text.ReadLine());
            for (int n_case = 1; n_case <= T; n_case++)
            {
                String line = text.ReadLine();
                String[] infos = line.Split(' ');
                int smax = int.Parse(infos[0]);
                int count = 0;
                int res = 0;
                for (int j = 0; j < smax + 1; j++)
                {
                    int n = int.Parse(infos[1].Substring(j, 1));
                    if (count >= j)
                    {
                        count += n;
                    }
                    else 
                    {
                        res += (j - count);
                        count = j + n;
                    }
                }
                outtext.WriteLine("Case #" + n_case + ": " + res);
            }
            outtext.Flush();
        }
    }
}
