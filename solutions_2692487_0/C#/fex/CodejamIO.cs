using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dynamic
{
    public static class CodejamIO
    {
       public static void WriteToFile(int[] wyniki, string filepath)
        {
            using (StreamWriter sr = new StreamWriter(filepath))
            {
                int counter = 1;
                while (counter-1 < wyniki.Length)
                {
                    sr.WriteLine("Case #{0}: " + wyniki[counter - 1].ToString(), counter);
                    counter++;
                }
            }
        }

        
    }
}
