using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\Zlatko\Desktop\DSmall.in");

            int T = int.Parse(lines[0]);
            for (int i = 0; i < T; i++)
            {

                int N = int.Parse(lines[3 * i + 1]),
                    dwins = 0,
                    wins = 0;

                List<double> naomi = new List<double>();
                List<double> ken = new List<double>();

                string[] naomis = lines[3 * i + 2].Split();
                string[] kens = lines[3 * i + 3].Split();

                for (int j = 0; j < N; j++)
                {
                    naomi.Add(double.Parse(naomis[j]));
                    ken.Add(double.Parse(kens[j]));                
                }

                naomi.Sort();
                ken.Sort();

                int n = N;

                while (n > 0)
                    for (int k = 0; k < n; k++)
                        if (ken[k] > naomi[n - 1])
                        {
                            naomi.RemoveAt(n - 1);
                            ken.RemoveAt(k);
                            n--;
                            break;
                        }

                        else if (k == n - 1 && ken[k] < naomi[n - 1])
                        {
                            wins++;
                            naomi.RemoveAt(n - 1);
                            ken.RemoveAt(0);
                            n--;
                            break;
                        }

                n = N;
                for (int j = 0; j < n; j++)
                {
                    naomi.Add(double.Parse(naomis[j]));
                    ken.Add(double.Parse(kens[j]));
                }

                naomi.Sort(); 
                naomi.Reverse();
                ken.Sort();
                ken.Reverse();
                
                for (int k = 0; k < n; k++)
                    if (naomi[0] > ken[k])
                    {
                        dwins++;
                        naomi.RemoveAt(0);
                        ken.RemoveAt(k);
                        n--;
                        k = 0;
                    }


                using (StreamWriter file = new StreamWriter(@"C:\Users\Zlatko\Desktop\OutputDSmall.txt", true))
                {
                    file.WriteLine("Case #" + (i + 1) + ": " + dwins + " " + wins + "\n");
                }


            }

        }
    }
}
