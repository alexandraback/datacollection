using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamManager
{
    class R1C_1_2013 :SolutionBase
    {
        char[] samo = new char[5] {'a', 'e', 'i', 'o', 'u'};

        public override void ProcessOne(int processNumber, System.IO.StreamReader input, System.IO.StreamWriter output)
        {
            string[] data = ReadLineAsStringTable();
            string name = data[0];
            int n = int.Parse(data[1]);

            Int64 result = 0;
            for (int i = 0; i < name.Length-n+1; i++)
            {
                int start = i;
                int k = i;
                int count = 0;
                while (count < n && k < name.Length)
                {
                    if (name[k] == 'a' || name[k] == 'e' || name[k] == 'i' || name[k] == 'o' || name[k] == 'u')
                    {
                        count = 0; start = k + 1;
                    }
                    else
                    {
                        count++;
                    }
                    k++;
                }
                if (count == n)
                {
                    result += name.Length - start - n + 1;
                };
                
            }


            base.StoreResults(output, processNumber, result);
        }
    }
}
