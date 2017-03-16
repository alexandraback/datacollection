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
            StreamReader streamReader = new StreamReader("in.txt");
			
            StreamWriter streamWriter = new StreamWriter("out.txt");
            int causes = Convert.ToInt16(streamReader.ReadLine());
            double c, f, x;
            double minimo;
            double Factory;
            double velocityNow;
            bool stop;
            for (int i = 1; i <= causes;i++ )
            {
                string[] tmp=streamReader.ReadLine().Split(' ');
                c = double.Parse(tmp[0], System.Globalization.CultureInfo.InvariantCulture);
				
                f = double.Parse(tmp[1], System.Globalization.CultureInfo.InvariantCulture);
				
                x = double.Parse(tmp[2], System.Globalization.CultureInfo.InvariantCulture);
                
				velocityNow = 2.0;
                minimo = x / velocityNow;
                stop = false;
                Factory = 0;
				
                while (!stop)
                { 
                    Factory=Factory+c/velocityNow;
                    velocityNow = velocityNow + f;
                    if (minimo > x / velocityNow + Factory)
                        minimo = x / velocityNow + Factory;
                    if (minimo < Factory)
                        stop = true;
                }
                streamWriter.WriteLine("Case #" + i + ": " + minimo.ToString("0.00000000000",System.Globalization.CultureInfo.GetCultureInfo("en-GB")));
            }

            streamReader.Close();
            streamWriter.Close();
        }
    }
}
