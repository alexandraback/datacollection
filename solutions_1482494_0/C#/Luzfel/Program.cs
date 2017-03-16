using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Timers;
using System.Diagnostics;
using System.Numerics;
using System.IO;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

namespace CodeJam2012_1A
{
    class Program
    {
        static void Main(string[] args)
        {

            List<string> phrases = leer();

            List<int> niveles = new List<int>();
            List<List<int>> puntos1 = new List<List<int>>();
            List<List<int>> puntos2 = new List<List<int>>();



            phrases.Remove(phrases[0]);
            for (int i = 0; i < phrases.Count; i++)
            {
                niveles.Add(Int32.Parse(phrases[i]));
                List<int> dato1 = new List<int>();
                List<int> dato2 = new List<int>();
                for (int j = i + 1; j <= i + Int32.Parse(phrases[i]); j++)
                { 
                    dato1.Add(Int32.Parse((phrases[j]).Substring(0,phrases[j].IndexOf(" "))));
                    dato2.Add(Int32.Parse((phrases[j]).Substring(phrases[j].IndexOf(" ")+1)));
                }
                puntos1.Add(dato1);
                puntos2.Add(dato2);

                i += Int32.Parse(phrases[i]);
            }

            List<string> cases = new List<string>();

            for (int i = 0; i < niveles.Count; i++)
            {
                cases.Add("Case #" + (i + 1) + ": " + minimo(niveles[i], puntos1[i], puntos2[i]));
            }

            
            escribir(cases);

            Console.ReadKey(true);
        }

        public static string minimo(int niveles, List<int> puntos1, List<int> puntos2)
        {

            int estrellas = 0;
            List<bool> pasado2= new List<bool>();
            List <bool> pasado1 = new List<bool>();

            

            for(int i=0; i< puntos2.Count;i++)
            {
                pasado1.Add(false);
                pasado2.Add(false);
            }
            int cont = 0;

            bool simon = true;
            bool terminado = false;

            while (simon)
            {

                for (int i = 0; i < puntos2.Count; i++)
                {
                    if (puntos2[i] <= estrellas && pasado2[i] == false && pasado1[i] == false)
                    {
                        estrellas += 2;
                        pasado1[i] = true;
                        pasado2[i] = true;
                        cont++;
                        i = -1;
                    }
                    else if (puntos2[i] <= estrellas && pasado2[i] == false)
                    {
                        estrellas++;
                        pasado2[i] = true;
                        cont++;
                        i = -1;
                    }

                }
                int pos = -1;
                int mayor = 0;
                for (int i = 0; i < puntos1.Count; i++)
                {
                    if (puntos1[i] <= estrellas && pasado1[i]==false && puntos2[i] > mayor)
                    {
                        pos = i;
                        mayor = puntos2[i];
                    }
                }

                //revisar si pos es -1 y si ya están true todos los pasados2

                if (pos != -1)
                {
                    pasado1[pos] = true;
                    estrellas++;
                    cont++;
                }
                else
                {
                    simon = false;
                    terminado = true;
                    foreach (bool a in pasado2)
                    {
                        if (a == false)
                        {
                            terminado = false;
                            break;
                        }
                    }
                }
            }

            if (terminado == true)
            {
                return cont+"";
            }
            else
            {
                return "Too Bad";
            }
            
        }

        public static bool esPrimo(string num)
        {
            BigInteger numero = BigInteger.Parse(num);

            if (numero < 2)
                return false;

            BigInteger raiz = numero;
            bool primo = true;
            for (int i = 2; i * i <= raiz; i++)
            {
                if (numero % i == 0)
                {
                    primo = false;
                    break;
                }
            }
            return primo;
        }

        public static bool esPalindromo(string numero)
        {
            string palabra1 = numero + "";
            string palabra2 = "";
            for (int i = 0; i < palabra1.Length; i++)
            {
                palabra2 = (palabra2 + palabra1.ElementAt(palabra1.Length - i - 1));
            }
            return (palabra1.Equals(palabra2));
        }

        public static bool esTriPitagoras(int a, int b, int c)
        {
            return Math.Pow(a, 2) + Math.Pow(b, 2) == Math.Pow(c, 2);
        }

        public static int triCompletar(int a, int b)
        {
            double c = Math.Sqrt(Math.Pow(a, 2) + Math.Pow(b, 2));
            int d = (int)(c);
            if (c == d)
            {
                return d;
            }
            else
            {
                return -1;
            }
        }

        public static int triPerimetro(int a, int b)
        {
            int c = triCompletar(a, b);
            return a + b + c;
        }

        public static int cantDivisores(long numero)
        {
            int cantidad = 1;
            long dividido = numero;
            for (int i = 2; i < numero / 2; i++)
            {
                int potencia = 0;
                while (dividido % i == 0)
                {
                    dividido = dividido / i;
                    potencia++;
                }

                cantidad = cantidad * (potencia + 1);
                if (dividido == 1)
                    break;
            }
            return cantidad;

        }
        
        public static List<int> obtenerDivisores(int a)
        {
            List<int> lista = new List<int>();
            int raiz = (int)Math.Pow(a, 0.5);
            lista.Add(1);
            for (int i = 2; i <= raiz; i++)
            {
                if (a % i == 0)
                    if (i * i == a)
                        lista.Add(i);
                    else
                    {
                        lista.Add(i);
                        lista.Add(a / i);
                    }
            }
            
            return lista;
        }

        public static int valorDeLetra(char a)
        {
            char[] letras = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
            List<char> alfabeto = new List<char>(letras);
            int[] valor = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };

            return (valor[alfabeto.IndexOf(a)]);

        }

        public static long factorial(int a)
        {
            long factorial = 1;
            for (int i = 1; i <= a; i++)
                factorial *= i;
            return factorial;
        }
        
        public static void simplificar(ref int num, ref int den)
        {
            for (int i = 2; i <= den / 2; i++)
                while (den % i == 0 && num % i == 0)
                {
                    num = num / i;
                    den = den / i;
                }
        }

        public static List<string> leer()
        {
            List<string> phrases = new List<string>();
            using (StreamReader objReader = new StreamReader("c:\\test.in"))
            {
                string sLine = "";
                while (sLine != null)
                {
                    sLine = objReader.ReadLine();
                    if (sLine != null)
                        phrases.Add(sLine);
                }
            }
            return phrases;
        }

        public static void escribir(List<string> phrases)
        {
            using (StreamWriter sw = new StreamWriter("Output.txt"))
            {
                foreach(string a in phrases)
                {
                    Console.WriteLine(a);
                    sw.WriteLine(a);
                }

            }
        }
        
        
    }
}
