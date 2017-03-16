using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012_B
{
    class Program
    {
        static void Main(string[] args)
        {
            string line = string.Empty;
            System.IO.StreamReader file = new System.IO.StreamReader("C:\\googleCodeJam\\B\\test.in");
            System.IO.StreamWriter resultFile = new StreamWriter("C:\\googleCodeJam\\B\\result.txt");
            line = file.ReadLine();
            int T = int.Parse(line);

            for (int i = 0; i < T; i++)
            {
                string resultLine = "Case #" + (i + 1).ToString() + ": ";
                line = file.ReadLine();
                string[] inputs = line.Split(' ');

                int N = int.Parse(inputs[0]);
                int S = int.Parse(inputs[1]);
                int p = int.Parse(inputs[2]);

                int result = 0;

                for (int j = 0; j < N; j++)
                {
                    int score = int.Parse(inputs[j + 3]);
                    int med = score/3;
                    int mod = score%3;

                    if (med>=p)
                    {
                        result++;
                    }
                    else
                    {
                        switch (mod)
                        {
                            case 0:
                                if (p-med==1 && S>0 && med!=0)
                                {
                                    result++;
                                    S--;
                                }
                                break;
                            case 1:
                                if (p-med==1 && med!=0)
                                {
                                    result++;
                                }
                                break;
                            case 2:
                                if (p-med==2 && S>0 && med!=0)
                                {
                                    result++;
                                    S--;
                                }
                                if (p-med==1 && med!=0)
                                {
                                    result++;
                                }
                                break;
                            default:
                                throw  new Exception("Greska");                                
                        }
                    }
                }
                resultLine = resultLine + result.ToString();
                resultFile.WriteLine(resultLine);
            }
            Console.ReadLine();
            file.Close();
            resultFile.Close();
        }
    }
}
