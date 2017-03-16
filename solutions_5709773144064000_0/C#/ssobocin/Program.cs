using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Mail;
using System.IO;

namespace Code
{
    class Code
    {

        static void Main(string[] args)
        {
            using (System.IO.StreamWriter file = new System.IO.StreamWriter("C:\\out.out"))
            {
                FileStream filestream = new FileStream("c:\\in.in", FileMode.Open);
                StreamReader streamreader = new StreamReader(filestream);

                string firstLine = streamreader.ReadLine();

                int caseID = 0;
                while (!streamreader.EndOfStream)
                {
                    caseID++;
                    string line = streamreader.ReadLine();
                    string[] data = line.Split(' ');
                    double C, F, X, Y, N;

                    C = Convert.ToDouble(data[0]);
                    F = Convert.ToDouble(data[1]);
                    X = Convert.ToDouble(data[2]);

                    N = (X * F - C * F - 2 * C) / (F * C);
                    if (N < 0)
                    {
                        N = 0;
                    }
                    Y = 0;
                    int A = (int)Math.Ceiling(N);
                    for (int i = 0; i < A; i++)
                    {
                        Y = Y + C / (2 + F *(i));
                    }

                    Y = Y + X / (2 + F * A);
                    file.WriteLine("Case #{0}: {1:F7}", caseID, Y);
                    


                }
            }
        }
    }
}
