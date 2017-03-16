using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ex4
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream filestream = new FileStream(@"C:\Users\Guillame Leclerc\Documents\codeJam2k14\ex4\output.txt", FileMode.Truncate);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);
            Console.SetError(streamwriter);
            System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Users\Guillame Leclerc\Documents\codeJam2k14\ex4\file.txt");
            int nbTestCases = Int32.Parse(file.ReadLine());
            for (int T = 1; T <= nbTestCases; T++)
            {
                file.ReadLine();
                List<Double> girl = new List<double>();
                List<Double> boy = new List<double>();
                List<Double> girl2;
                List<Double> boy2;
                foreach (String e in file.ReadLine().Split(' '))
                {
                    girl.Add(Double.Parse(e, System.Globalization.NumberStyles.Any));
                }
                foreach (String e in file.ReadLine().Split(' '))
                {
                    boy.Add(Double.Parse(e, System.Globalization.NumberStyles.Any));
                }
                girl.Sort();
                boy.Sort();
                girl2 = new List<double>(girl);
                boy2 = new List<double>(boy);
                int scoreWar = 0;
                while(girl.Count >0)
                {
                    if (girl[girl.Count - 1] > boy[boy.Count - 1])
                    {
                        boy.RemoveAt(0);
                        scoreWar++;
                    }
                    else
                    {
                        boy.RemoveAt(boy.Count - 1);
                    }
                    girl.RemoveAt(girl.Count - 1);
                }
                girl = girl2;
                boy = boy2;
                int scoreDWar = 0;
                while (girl.Count > 0)
                {

                    int index = girl.FindIndex(x => x > boy[0]);
                    if(index != -1)
                    {
                        scoreDWar++;
                        girl.RemoveAt(index);
                        boy.RemoveAt(0);
                    }
                    else
                    {
                        boy.RemoveAt(boy.Count - 1);
                        girl.RemoveAt(0);
                    }

                    
                }

                Console.WriteLine("Case #" + T + ": "+ scoreDWar + " " +scoreWar);

            }
            Console.ReadKey();
            filestream.Close();
        }
    }
}
