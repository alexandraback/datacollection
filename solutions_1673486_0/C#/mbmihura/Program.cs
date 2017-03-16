using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace cjf
{
    class Program
    {
        static void Main(string[] args)
        {
            new Algoritmo().Run();
        }
    }

    partial class Algoritmo
    {
        StreamReader entrada = new StreamReader("C://Users//Martin//Desktop//ino//input.in");
        StreamWriter salida = new StreamWriter("C://Users//Martin//Desktop//ino//output " + ".in");

        public void Run() 
        {
            Main();
            entrada.Close();
            salida.Close();
        }
        public string readLine()
        {
            return entrada.ReadLine();
        }
        public int readIntLine()
        {
            string s = entrada.ReadLine();
            return Convert.ToInt32(s);
        }
        public int readIntSpace()
        {
            StringBuilder n = new StringBuilder();
            int carac;
            carac = entrada.Read();
            while ((carac != ' ') && (carac != 10) && (carac != -1))
            {
                n.Append(Convert.ToChar(carac));
                carac = entrada.Read();
            }
            return Convert.ToInt32(n.ToString());
        }
        public double readDoubleSpace()
        {
            StringBuilder n = new StringBuilder();
            int carac;
            carac = entrada.Read();
            while ((carac != ' ') && (carac != 10) && (carac != -1) && (carac != '\r'))
            {
                if (carac == '.')
                    carac = ',';
                n.Append(Convert.ToChar(carac));
                carac = entrada.Read();
            }
            return Convert.ToDouble(n.ToString());
        }
        public void Case(int t, string resultado)
        {
            salida.WriteLine("Case #{0}: {1}", t, resultado); 
        }
        public void Case(int t, int resultado)
        {
            Case(t, resultado.ToString());
        }
        public void Case(int t, double resultado)
        {
            Case(t, resultado.ToString("F6", System.Globalization.CultureInfo.InvariantCulture));
        }
    }
}
