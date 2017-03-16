using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cj12a
{
    class Program
    {

        static void Main(string[] args)
        {
            StringBuilder sb;
            using (StreamWriter outfile = new StreamWriter("a.small.out"))
            {
                using (StreamReader sr = File.OpenText("A-small-attempt0.in"))
                {
                    String AandB;
                    int T = int.Parse(sr.ReadLine());
                    int c = 1;
                    while ((AandB = sr.ReadLine()) != null)
                    {
                        int a,b = 0;
                        double output = 1.0;
                        string[] sa = AandB.Split(' ');
                        a = int.Parse(sa[0]);
                        b = int.Parse(sa[1]);
                        double[] probabilities = new double[a];
                        string[] prob_input = sr.ReadLine().Split(' ');
                        for (int i = 0; i < prob_input.Length; i++)
                        {
                            probabilities[i] = double.Parse(prob_input[i]);
                        }
                        
                        //parsed input at this point

                        int char_left_to_type = b - a;
                        //worst case press enter; retype everything; press enter;
                        double case3 = b+2;
                        //check for likelihood of correctness
                        double[] correct_through_i = new double[a+1];
                        correct_through_i[0] = 1;
                        for (int i = 1; i < prob_input.Length+1; i++)
                        {
                            correct_through_i[i] = probabilities[i-1]*correct_through_i[i-1];
                        }
                        double case1 = (b - a)+1 + (1-correct_through_i[a]) * (b+1);
                        double case2 = case1;
                        for (int i = a-1; i >0 ; i--)
                        {
                            case2 = Math.Min((b - a+(a-i)*2) + 1 + (1 - correct_through_i[i]) * (b + 1), case2);
                        }
                        output = Math.Min(case3, case2);

                        Console.WriteLine("Case #{0}: {1:F6}", c, output);
                        outfile.WriteLine("Case #{0}: {1:F6}", c, output);
                        c++;
                    }
                }

            }
            Console.ReadLine();
        }
    }
}
