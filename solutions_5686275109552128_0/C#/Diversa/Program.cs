using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Linq;
using System.IO;
using System.Collections;

namespace Infinite
{
    class Program
    {
        public static bool unc = false;

        static void Main(string[] args)
        {
            FileStream fs = new FileStream("E:\\B-small.in", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs);
            int count = int.Parse(sr.ReadLine());

            FileStream fs2 = new FileStream("E:\\b-smalll.out", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs2);


            string line = string.Empty;
            string row = string.Empty;

            int answer =0;



            int j = 0;
            int Z = 2;


            if (!sr.EndOfStream)
            {
                while (count > 0)
                {

                    sr.ReadLine();
                    row = sr.ReadLine();

                    List<string> result = row.Split(' ').ToList();
                    List<int> pancakes = result.ConvertAll(s => Int32.Parse(s));

                    answer = pancakes.Max();

                    Z = 2;
                    while (Z < answer)
                    
                    {
                        int sp=0;
                        for(int i=0;i<pancakes.Count();i++)
                        {
                           sp+= ((pancakes[i]-1)/Z);
                        }
                        answer = Math.Min(answer, sp + Z);
                                Z++;
                    }


                    j++;
                    line += "Case #" + j + ": ";
                    line += answer;
                    sw.WriteLine(line);

                    count--;
                    line = string.Empty;
                    ////
                     answer = 0;

 

                }
            }
            sw.Close();
            //sr.Close();
            fs.Close();
            fs2.Close();
        }


    }

}