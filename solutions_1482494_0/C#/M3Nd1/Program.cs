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

                result = Resolve(linea.Split(' '), fileInput);

                fileOutput.WriteLine("Case #{0}: " + result, i);
            }

            fileInput.Close();
            fileOutput.Close();
        }


        static string Resolve(string[] datos, StreamReader fileInput)
        {
            int resultado = 0;

            int n = int.Parse(datos[0]);
            int stars = 0;

            List<Level> lstar = new List<Level>(n);

            for (int i = 0; i < n; i++)
            {
                string[] linea = fileInput.ReadLine().Split(' ');

                lstar.Add(new Level(i, int.Parse(linea[0]), int.Parse(linea[1])));
            }

            List<Level> sStar = lstar.OrderBy(e => e.s).ToList();
            List<Level> fStar = lstar.OrderBy(e => e.f).ToList();

            Level l;
            while (sStar.Count > 0)
            {
                // segunda estrella
                if (sStar.First().s <= stars)
                {
                    l = sStar.First();

                    if (sStar.Where(e => e.s <= stars).Count() > 1)
                    {
                        int nuevoResultado = -1;
                        int aux;

                        foreach (Level l2 in sStar.Where(e => e.s <= stars))
                        {
                            aux = Resolve2(l2, new List<Level>(sStar), new List<Level>(fStar), stars);

                            if ((aux > 0 && aux < nuevoResultado) || nuevoResultado < 0)
                                nuevoResultado = aux;
                        }

                        if (nuevoResultado < 0)
                            return "Too Bad";

                        return (resultado + nuevoResultado).ToString();
                    }

                    sStar.Remove(l);
                    stars++;

                    if (fStar.Contains(l))
                    {
                        fStar.Remove(l);
                        stars++;
                    }
                }
                else if (fStar.Count>0 && fStar.First().f <= stars)
                {
                    l = fStar.First();

                    if (fStar.Where(e => e.f <= stars).Count() > 1)
                    {
                        int nuevoResultado = -1;
                        int aux;

                        foreach (Level l2 in fStar.Where(e => e.f <= stars))
                        {
                            aux = Resolve2(l2, new List<Level>(sStar), new List<Level>(fStar), stars);

                            if ((aux > 0 && aux < nuevoResultado) || nuevoResultado < 0)
                                nuevoResultado = aux;
                        }

                        if (nuevoResultado < 0)
                            return "Too Bad";

                        return (resultado + nuevoResultado).ToString();
                    }

                    fStar.Remove(l);
                    stars++;
                }
                else
                    return "Too Bad";

                resultado++;
            }

            return resultado.ToString();
        }

        static int Resolve2(Level lProximo, List<Level> sStar, List<Level> fStar, int stars)
        {
            int resultado = 1;

            if (lProximo.s <= stars)
            {
                sStar.Remove(lProximo);
                stars++;

                if (fStar.Contains(lProximo))
                {
                    fStar.Remove(lProximo);
                    stars++;
                }
            }
            else if (lProximo.f <= stars)
            {
                fStar.Remove(lProximo);
                stars++;
            }
            else
                return -1;

            Level l;
            while (sStar.Count > 0)
            {
                // segunda estrella
                if (sStar.First().s <= stars)
                {
                    l = sStar.First();

                    if (sStar.Where(e => e.s <= stars).Count() > 1)
                    {
                        int nuevoResultado = -1;
                        int aux;

                        foreach (Level l2 in sStar.Where(e => e.s <= stars))
                        {
                            aux = Resolve2(l2, new List<Level>(sStar), new List<Level>(fStar), stars);

                            if ((aux > 0 && aux < nuevoResultado) || nuevoResultado < 0)
                                nuevoResultado = aux;
                        }

                        if (nuevoResultado < 0)
                            return -1;

                        return resultado + nuevoResultado;
                    }

                    sStar.Remove(l);
                    stars++;

                    if (fStar.Contains(l))
                    {
                        fStar.Remove(l);
                        stars++;
                    }
                }
                else if (fStar.Count > 0 && fStar.First().f <= stars)
                {
                    l = fStar.First();

                    if (fStar.Where(e => e.f <= stars).Count() > 1)
                    {
                        int nuevoResultado = -1;
                        int aux;

                        foreach (Level l2 in fStar.Where(e => e.f <= stars))
                        {
                            aux = Resolve2(l2, new List<Level>(sStar), new List<Level>(fStar), stars);

                            if ((aux > 0 && aux < nuevoResultado) || nuevoResultado < 0)
                                nuevoResultado = aux;
                        }

                        if (nuevoResultado < 0)
                            return -1;

                        return resultado + nuevoResultado;
                    }

                    fStar.Remove(l);
                    stars++;
                }
                else
                    return -1;

                resultado++;
            }

            return resultado;
        }

    }



    public class Level
    {
        public int l;
        public int f;
        public int s;

        public Level(int xL, int xF, int xS)
        {
            l = xL;
            f = xF;
            s = xS;
        }
    }
}
