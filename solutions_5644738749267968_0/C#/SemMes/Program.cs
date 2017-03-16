using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Deceitful_War
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader Sr = new StreamReader("input.txt");
            StreamWriter Sw = new StreamWriter("output.txt");
            List<double>naomi;
            List<double>ken;
            List<double> naomid;
            List<double> kend;
            int causes = Convert.ToInt16(Sr.ReadLine());
            int Nblocks = 0;
            int NormalVictory;
            int DifferentVictory;
            for (int i = 1; i <= causes; i++)
            {
                NormalVictory=0;
                DifferentVictory=0;
                Nblocks = Convert.ToInt16(Sr.ReadLine());
                naomi=new List<double>();
                ken=new List<double>();
                string[] temp = Sr.ReadLine().Split(' ');
                foreach (string x in temp)
                    naomi.Add(double.Parse(x, System.Globalization.CultureInfo.InvariantCulture));
                naomi.Sort();
                naomi.Reverse();
                temp = Sr.ReadLine().Split(' ');
                foreach (string x in temp)
                    ken.Add(double.Parse(x, System.Globalization.CultureInfo.InvariantCulture));
                ken.Sort();
                ken.Reverse();
                naomid = naomi.ToList();
                kend = ken.ToList();
                while(naomi.Count>0)
                {
                    if (naomi[0] > ken[0])
                    {
                        NormalVictory++;
                        
                        ken.RemoveAt(ken.Count - 1);
                    }
                    else
                        ken.RemoveAt(0);
                    naomi.RemoveAt(0);
                }
                while(naomid.Count>0)
                {
                    if (kend[0] > naomid[0])
                    {
                        kend.RemoveAt(0);

                        naomid.RemoveAt(naomid.Count - 1);
                    }
                    else
                    {
                        DifferentVictory++;
                        kend.RemoveAt(0);
                        naomid.RemoveAt(0);
                    }

                }
                Sw.WriteLine("Case #" + i + ": " + DifferentVictory + " " + NormalVictory);
              }

            Sr.Close();
            Sw.Close();
        }
    }
}
