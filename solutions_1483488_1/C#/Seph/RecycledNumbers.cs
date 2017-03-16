using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public class RecycledNumbers
    {
        public static void Main()
        {
            
            string InputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\RecycledNumbers\\in.txt";
            string OutputPath = "C:\\Users\\Seph\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam\\GoogleCodeJam\\RecycledNumbers\\out.txt";

            string FileOutput = "";
            string FileInput = System.IO.File.ReadAllText(InputPath);

            string[] InputLines = FileInput.Split(new string[] { "\r", "\n", "\r\n" }, StringSplitOptions.RemoveEmptyEntries);

            int Cases = Int32.Parse(InputLines[0]);
            for (int x = 1; x <= Cases; x++)
            {
                if (x != 1)
                    FileOutput += "\n";

                string[] Params = InputLines[x].Split(' ');
                FileOutput += "Case #" + x + ": " + GetCount(Int32.Parse(Params[0]),Int32.Parse(Params[1]));
            }


            System.IO.File.WriteAllText(OutputPath, FileOutput);
        }


        public static int GetCount(int a, int b)
        {
            int count = 0;
            HashSet<string> RecycledPairs = new HashSet<string>();
            while (a < b)
            {
                foreach (int r in RecycledNums(a))
                {
                    if (a<=r && a<r && r<=b && r!=a && !RecycledPairs.Contains(a+" "+r))
                    {
                        RecycledPairs.Add(a + " " + r);
                        count++;
                    }
                }
                a++;
            }

            return count;
        }

        public static List<int> RecycledNums(int x)
        {
            List<int> Results = new List<int>();
            string num = x.ToString();

            for (int y = 1; y < num.Length; y++)
            {
                char end = num[num.Length - 1];
                num = num.Remove(num.Length - 1);
                num = end + num;
                Results.Add(Int32.Parse(num));
            }

            return Results;
        }

    }
}
