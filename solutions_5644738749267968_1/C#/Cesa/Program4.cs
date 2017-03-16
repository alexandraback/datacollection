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
            StreamReader Sr = new StreamReader("in.txt");
            StreamWriter Sw = new StreamWriter("out.txt");
			
            List<double>naomi;
            List<double>ken;
			
            List<double> naomidifferent;
            List<double> kendifferent;
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
                string[] rmp = Sr.ReadLine().Split(' ');
                foreach (string x in rmp)
                    naomi.Add(double.Parse(x, System.Globalization.CultureInfo.InvariantCulture));
                
                rmp = Sr.ReadLine().Split(' ');
                foreach (string x in rmp)
                    ken.Add(double.Parse(x, System.Globalization.CultureInfo.InvariantCulture));
                ken.Sort();
                ken.Reverse();
				naomi.Sort();
                naomi.Reverse();
				
				
                kendifferent = ken.ToList();

                naomidifferent = naomi.ToList();
				
				
                
                while(naomidifferent.Count>0)
                {
                    if (kendifferent[0] > naomidifferent[0])
                    {
                        kendifferent.RemoveAt(0);

                        naomidifferent.RemoveAt(naomidifferent.Count - 1);
                    }
                    else
                    {
                        DifferentVictory++;
                        kendifferent.RemoveAt(0);
                        naomidifferent.RemoveAt(0);
                    }

                }
				
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
				
				
                Sw.WriteLine("Case #" + i + ": " + DifferentVictory + " " + NormalVictory);
              }

            Sr.Close();
            Sw.Close();
        }
    }
}
