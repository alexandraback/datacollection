using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace Application1
{
    class Program
    {
        static void Main(string[] args)
        {
            if (File.Exists(@"C:\Anitha\Projects\CodeJam\output.txt"))
            {
                File.Delete(@"C:\Anitha\Projects\CodeJam\output.txt");
            }
            int counter = 0, linesUsed;
            string[] LinesToWrite;
            string line;

            using (System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Anitha\Projects\CodeJam\input.in"))
            {
                linesUsed = int.Parse(file.ReadLine());
                LinesToWrite = new string[linesUsed];

                while ((line = file.ReadLine()) != null)
                {
                    int strToComp = int.Parse(line);
                    string dist = "";
                    List<string> strList= new List<string>();
                    for (int i = 0; i < strToComp; i++)
                    {
                        strList.Add(file.ReadLine());
                    }
                    bool ispossible = FeglaWon(strList, out dist);
                    if (!ispossible)
                    {
                        LinesToWrite[counter] = "Case #" + (counter + 1) + ": " + "Fegla Won";
                        counter++;
                        continue;
                    }
                    int sum = 0;
                    for (int i = 0; i < dist.Length;i++ )
                    {
                        List<int> iList = new List<int>();
                        List<int> minList = new List<int>();
                        for (int s = 0; s < strList.Count();s++ )
                        {
                            int index = 0;
                            while (strList[s][index] == dist[i])
                            {
                                index++;
                                if (strList[s].Length <= index) break;
                            }
                            iList.Add(index);
                            if (strList[s].Length <= index)
                                strList[s] = "";
                            else
                                strList[s] = strList[s].Substring(index);
                        }
                        
                        for (int x = 1; x <= iList.Max(); x++)
                        {
                            int tmpMin = 0;
                            for (int y = 0; y < iList.Count(); y++)
                            {
                                tmpMin += (iList[y] - x) < 0 ? x - iList[y] : iList[y] - x;
                            }
                            minList.Add(tmpMin);
                        }

                        sum += minList.Min();
                    }
                    LinesToWrite[counter] = "Case #" + (counter + 1) + ": " + sum.ToString();
                    counter++;
                }

                file.Close();
            }

            File.WriteAllLines(@"C:\Anitha\Projects\CodeJam\output.txt", LinesToWrite);
        }

        private static bool FeglaWon(List<string> strList, out string dist)
        {
            List<string> newList = new List<string>();
            foreach(string str in strList)
            {
                string temp = str[0].ToString();
                for (int i = 1; i < str.Length; i++)
                {
                    if (str[i - 1] == str[i]) continue;
                    temp += str[i].ToString();
                }
                newList.Add(temp);
            }
            dist = newList.Distinct().First();
            return newList.Distinct().Count() == 1;
        }
    }
}
