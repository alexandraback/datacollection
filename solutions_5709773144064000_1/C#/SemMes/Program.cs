using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Cookie_Clicker_alpha
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader Sr = new StreamReader("input.txt");
            StreamWriter Sw = new StreamWriter("output.txt");
            int causes = Convert.ToInt16(Sr.ReadLine());
            double c, f, x;
            double minimo;
            double oldFac;
            double velocityNow;
            bool exit;
            for (int i = 1; i <= causes;i++ )
            {
                string[] temp=Sr.ReadLine().Split(' ');
                c = double.Parse(temp[0], System.Globalization.CultureInfo.InvariantCulture);
                f = double.Parse(temp[1], System.Globalization.CultureInfo.InvariantCulture);
                x = double.Parse(temp[2], System.Globalization.CultureInfo.InvariantCulture);
                velocityNow = 2.0;
                minimo = x / velocityNow;
                exit = false;
                oldFac = 0;
                while (!exit)
                { 
                    oldFac=oldFac+c/velocityNow;
                    velocityNow = velocityNow + f;
                    if (minimo > x / velocityNow + oldFac)
                        minimo = x / velocityNow + oldFac;
                    if (minimo < oldFac)
                        exit = true;
                }
                Sw.WriteLine("Case #" + i + ": " + minimo.ToString("0.00000000000",System.Globalization.CultureInfo.GetCultureInfo("en-GB")));
            }

            Sr.Close();
            Sw.Close();
        }
    }
}
