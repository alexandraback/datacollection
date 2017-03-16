using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace FairWarning {
    class Program {
        static void Main(string[] args) {
            StreamReader fileInput = new StreamReader("../../input.txt");
            StreamWriter fileOutput = new StreamWriter("../../output.txt");

            int cantidadCasos = Convert.ToInt32(fileInput.ReadLine());

            string result;
            for (int i = 1; i <= cantidadCasos; i++) {
                string linea = fileInput.ReadLine();
                string linea2 = fileInput.ReadLine();

                result = Resolve(linea.Split(' '), linea2.Split(' '));

                fileOutput.WriteLine("Case #{0}: " + result, i);
            }

            fileInput.Close();
            fileOutput.Close();
        }


        static string Resolve(string[] datos, string[] datos2)
        {
            double resultado;

            int a = int.Parse(datos[0]);
            int b = int.Parse(datos[1]);

            double[] p = new double[a];
            int i = 0;
            foreach (string dato in datos2)
            {
                p[i] = double.Parse(dato);
                i++;
            }

            for (int j = 0; j < Math.Pow(2, a); j++)
            {

            }


            //hit enter
            double enter = 2 + b;

            resultado = enter;

            //seguir tipeando
            double seguirOK = b - a + 1;
            double probSeguirOK = 1;
            foreach (double prob in p)
                probSeguirOK *= prob;

            double seguirMAL = b + b - a + 2;
            double probSeguirMAL = 1 - probSeguirOK;

            double seguir = seguirOK * probSeguirOK + seguirMAL * probSeguirMAL;

            if (seguir < resultado)
                resultado = seguir;

            //borrando x
            int x = 1;
            double borrarOK = 0.0;
            while (x < a && borrarOK <= resultado)
            {
                borrarOK = x + b - a + x + 1;
                double probBorrarOK = 1;
                for (int j = 0; j < a - x; j++)
                    probBorrarOK *= p[j];

                double borrarMAL = b + x + b - a + x + 2;
                double probBorrarMAL = 1 - probBorrarOK;

                double borrar = borrarOK * probBorrarOK + borrarMAL * probBorrarMAL;

                if (borrar < resultado)
                    resultado = borrar;

                x++;
            }

            return String.Format("{0:0.000000}", resultado);
        }

    }
}
