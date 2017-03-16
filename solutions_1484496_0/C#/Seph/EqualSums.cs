using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace GoogleCodeJam
{
    class EqualSums
    {
        public static void Main()
        {
            string InputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\EqualSums\\in.txt";
            string OutputPath ="C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\EqualSums\\out.txt";

            string FileOutput = "";
            string FileInput = System.IO.File.ReadAllText(InputPath);

            string[] InputLines = FileInput.Split(new string[] { "\r", "\n", "\r\n" }, StringSplitOptions.RemoveEmptyEntries);

            int Cases = Int32.Parse(InputLines[0]);
            for (int cas = 1; cas <= Cases; cas++)
            {
                FileOutput += "Case #" + cas + ":\n";
                Dictionary<long, List<long>> sumMap = new Dictionary<long, List<long>>();
                
                List<long> FullSet = InputLines[cas].Split(' ').Select(c => long.Parse(c)).ToList();
                FullSet.RemoveAt(0);
                bool found = false;

                BitArray b = new BitArray(FullSet.Count(),false);

                while (!AllOnes(b) && !found)
                {
                    List<long> thisSubSet = new List<long>();

                    for (int i = 0; i < b.Length; i++)
                    {
                        if (b[i])
                        {
                            thisSubSet.Add(FullSet.ElementAt(i));
                        }
                    }

                    long thisSum = thisSubSet.Sum();
                    if (sumMap.ContainsKey(thisSum))
                    {
                        List<long> otherSubSet = sumMap[thisSum];

                        for (int s = 0; s < otherSubSet.Count; s++)
                        {
                            FileOutput += otherSubSet[s];
                            if (s != otherSubSet.Count - 1)
                                FileOutput += " ";
                        }
                        FileOutput += "\n";

                        for (int s = 0; s < thisSubSet.Count; s++)
                        {
                            FileOutput += thisSubSet[s];
                            if (s != thisSubSet.Count - 1)
                                FileOutput += " ";
                        }

                        found = true;
                    }
                    else
                    {
                        sumMap.Add(thisSum, thisSubSet);
                    }
                    

                    Increment(b);
                }



                if (!found)
                {
                    FileOutput += "Impossible";
                }

                if (cas != Cases)
                {
                    FileOutput += "\n";
                }
            }
            
            System.IO.File.WriteAllText(OutputPath, FileOutput);
        }


        public static void Increment(BitArray bArray)
        {
            for (int i = 0; i < bArray.Length; i++)
            {
                bool previous = bArray[i];
                bArray[i] = !previous;
                if (!previous)
                {
                    return;
                }
            }
        }

        public static bool AllOnes(BitArray bArray)
        {
            bool foundZero = false;
            for (int i = 0; i < bArray.Length; i++)
            {
                if (!bArray[i])
                {
                    foundZero = true;
                    break;
                }
            }

            return !foundZero;
        }
    }
}
