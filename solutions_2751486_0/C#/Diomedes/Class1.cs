using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace ConsoleApplication1
{
    class Class1
    {
        StreamReader sr;
        StreamWriter sw;

        public Class1(string infile, string outfile)
        {
            sr = new StreamReader(infile);
            sw = new StreamWriter(outfile);
        }
        /*
         Sample Input:
         * 
            4
            quartz 3
            straight 3
            gcj 2
            tsetse 2
         */
        public bool isConsonant(char c)
        {
            return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }
        public void Execute()
        {
            int NumCases = int.Parse(sr.ReadLine());
            for (int k = 0; k < NumCases; k++)
            {
                int successCount = 0;
                string line = sr.ReadLine();

                string name = line.Split(' ')[0];
                int nameLength = name.Length;
                int n = int.Parse(line.Split(' ')[1]);
                List<int> nStringIndexes = new List<int>();
                
                Console.WriteLine(String.Format("Name = {0}, Length = {1}, n = {2}", name, nameLength, n));

                //first, find all substrings with at least n consecutive consonants. 
                int currentConsLength = 0;
                for (int i = 0; i < nameLength; i++)
                {
                    if (isConsonant(name[i]))
                    {
                        currentConsLength++;
                    }
                    else
                    {
                        currentConsLength = 0;
                    }
                    if (currentConsLength >= n)
                    {
                        nStringIndexes.Add(i + 1 - n);    
                    }
                }
                foreach (int index in nStringIndexes)
                {
                    Console.WriteLine(String.Format("Found Index = {0}", index));
                }

                for (int i = 0; i < nStringIndexes.Count; i++)
                { 
                    //only count if this is a duplicate string, only count it for the first index
                    int index = nStringIndexes.ElementAt(i);
                    int prevIndex = -1;
                    if(i > 0)
                    {
                        prevIndex = nStringIndexes.ElementAt(i - 1);
                    }
                    int val1 = index - prevIndex;
                    int val2 = nameLength - index - n + 1;
                    Console.WriteLine(String.Format("adding {0} * {1} to success count", val1, val2));
                    successCount += val1 * val2;
                }

                sw.WriteLine(String.Format("Case #{0}: {1}", k + 1, successCount));
            }


            sw.Close();
            sr.Close();
        }
    }
}
