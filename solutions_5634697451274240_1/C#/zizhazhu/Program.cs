using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RevengePancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            System.IO.StreamReader input = new System.IO.StreamReader(@"D:\codejam\RevengePancakes\B-large.in");
            System.IO.StreamWriter output = new System.IO.StreamWriter(@"D:\codejam\RevengePancakes\B-large.out");

            int count = 0;
            string[] data = new string[1];
            string line;
            bool first = true;
            int idx = 0;
            while ((line = input.ReadLine()) != null)
            {
                if (first)
                {
                    count = int.Parse(line);
                    data = new string[count];
                    first = false;
                }
                else
                {
                    data[idx++] = line;
                }
            }
            input.Close();

            for (int i = 0; i < count; i++)
            {
                int res = 0;
                string cur = data[i];
                int signChange = 0;
                char pre = cur[0];
                for (int j = 0; j < cur.Length; j++)
                {
                    if (pre != cur[j])
                    {
                        signChange++;
                    }
                    pre = cur[j];
                }
                if(cur[0]=='-')
                {
                    if(signChange%2==0)
                    {
                        res = signChange + 1;
                    }
                    else
                    {
                        res = signChange;
                    }
                }
                else
                {
                    if (signChange % 2 == 0)
                    {
                        res = signChange;
                    }
                    else
                    {
                        res = signChange + 1;
                    }
                }
                output.WriteLine(@"Case #{0}: {1}",i+1,res);
            }
            output.Close();
        }
    }
}
