using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            Exercise1();

            Console.WriteLine("Press any key to continue...");
            Console.ReadKey();
        }

        static void Exercise1()
        {
            List<string> lines = Utils.GetStringList("input.txt");
            int numofCases = Convert.ToInt32(lines[0]);

            List<string> outputs = new List<string>();

            for (int i = 1; i <= numofCases; i++)
            {
                string[] arr = lines[i].Split(null);
                int maxShynessLevel = Convert.ToInt32(arr[0]);
                string last = arr[1];

                bool flag = false;
                int totalAudience = 0;
                int added = 0;
                for (int j = 0; j < maxShynessLevel + 1; j++)
                {
                    char cNumofAudience = last[j];
                    int numofAudiene = Int32.Parse(cNumofAudience.ToString());
                    if (numofAudiene == 0)
                    {
                        flag = true;
                    }
                    else
                    {
                        if (flag == true)
                        {
                            added += Math.Max(0, j - totalAudience);
                            totalAudience += added;
                        }
                        totalAudience += numofAudiene;
                        flag = false;
                    }
                }

                outputs.Add("Case #"+ i +": " + added);
            }

            Utils.WriteFile(outputs, "output.txt");
        }
    }
}
