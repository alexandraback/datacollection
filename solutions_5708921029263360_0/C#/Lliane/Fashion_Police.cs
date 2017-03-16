using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.R1C2016
{
    class Fashion_Police
    {
        public static void Run(System.Windows.Forms.TextBox inputTB, System.Windows.Forms.TextBox outputTB, System.Windows.Forms.TextBox debugTB)
        {

            int nbCases = int.Parse(inputTB.Lines.First());

            for (int i = 0; i < nbCases; i++)
            {
                var Nb = inputTB.Lines[i + 1].Split(' ');
                var dico = 
                FashionPoliceJPS(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]), Int32.Parse(Nb[2]), Int32.Parse(Nb[3]));
                /*var dicoJSP =
                FashionPoliceJSP(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]), Int32.Parse(Nb[2]), Int32.Parse(Nb[3]));
                var dicoPSJ =
                FashionPolicePSJ(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]), Int32.Parse(Nb[2]), Int32.Parse(Nb[3]));
                var dicoPJS =
                FashionPolicePJS(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]), Int32.Parse(Nb[2]), Int32.Parse(Nb[3]));
                var dicoSPJ =
                FashionPoliceSPJ(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]), Int32.Parse(Nb[2]), Int32.Parse(Nb[3]));
                var dicoSJP =
                FashionPoliceSJP(Int32.Parse(Nb[0]), Int32.Parse(Nb[1]), Int32.Parse(Nb[2]), Int32.Parse(Nb[3]));
                var mc =
                    Math.Max(Math.Max(Math.Max(dicoJPS.Count, dicoJSP.Count), Math.Max(dicoPSJ.Count, dicoPJS.Count)),
                    Math.Max(dicoSJP.Count, dicoSPJ.Count));
                var dico = mc == dicoJPS.Count ? dicoJPS :
                        mc == dicoJSP.Count ? dicoJSP :
                        mc == dicoPSJ.Count ? dicoPSJ :
                        mc == dicoPJS.Count ? dicoPJS :
                           mc == dicoSJP.Count ? dicoSJP : dicoSPJ;*/
                    
                outputTB.Text += "Case #" + (i + 1) + ": " +dico.Count()  + "\r\n";

                foreach (var l in dico)
                {
                    outputTB.Text += l + "\r\n";
                }
            
                continue;
            }
        }

        private static List<string> FashionPoliceJPS(Int32 J, Int32 P, Int32 S, Int32 K)
        {
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJP = new Dictionary<KeyValuePair<int,int>,int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiPS = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJS = new Dictionary<KeyValuePair<int, int>, int>();
            var l = new List<String>();

            for (int j = 1; j <= J; j++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int s = 1; s <= S; s++)
                    {
                        combiJP[new KeyValuePair<int, int>(j, p)] = 0;
                        combiPS[new KeyValuePair<int, int>(p, s)] = 0;
                        combiJS[new KeyValuePair<int, int>(j, s)] = 0;                        
                    }
                }
            }
            String pvrs = String.Empty;
        hereWeGoAgain:
            
            bool couldDoSthg = false;
            for (int j = 1; j <= J; j++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int s = 1; s <= S; s++)
                    {
                        String ss = j + " " + p + " " + s;
                        if (combiJP[new KeyValuePair<int,int>(j, p)] < K && 
                            combiPS[new KeyValuePair<int,int>(p, s)] < K &&
                            combiJS[new KeyValuePair<int,int>(j, s)] < K)
                        {
                            if (ss != pvrs)
                            { 
                                pvrs = ss;
                                l.Add(ss);
                                combiJP[new KeyValuePair<int,int>(j, p)]++;
                                combiPS[new KeyValuePair<int,int>(p, s)]++;
                                combiJS[new KeyValuePair<int, int>(j, s)]++;
                                couldDoSthg = true;
                                goto hereWeGoAgain;
                            }
                            else if (P > 1)
                            {
                                pvrs = ss;
                                bool canInsert = false;
                                for (int i = 0; i < l.Count - 1; i++)
                                {
                                    if (l[i] != ss && l[i + 1] != ss)
                                    {
                                        l.Insert(i+1, ss);
                                        canInsert = true;
                                        break;
                                    }
                                }
                                if (canInsert)
                                {
                                    combiJP[new KeyValuePair<int, int>(j, p)]++;
                                    combiPS[new KeyValuePair<int, int>(p, s)]++;
                                    combiJS[new KeyValuePair<int, int>(j, s)]++;
                                    couldDoSthg = true;
                                    goto hereWeGoAgain;
                                }
                            }
                            
                        }
                    }
                }
            }
            if (couldDoSthg)
                goto hereWeGoAgain;
            return l;
        }

        private static List<string> FashionPoliceSJP(Int32 J, Int32 P, Int32 S, Int32 K)
        {
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJP = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiPS = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJS = new Dictionary<KeyValuePair<int, int>, int>();
            var l = new List<String>();

            for (int j = 1; j <= J; j++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int s = 1; s <= S; s++)
                    {
                        combiJP[new KeyValuePair<int, int>(j, p)] = 0;
                        combiPS[new KeyValuePair<int, int>(p, s)] = 0;
                        combiJS[new KeyValuePair<int, int>(j, s)] = 0;
                    }
                }
            }
            String pvrs = String.Empty;
        hereWeGoAgain:

            bool couldDoSthg = false;
            for (int s = 1; s <= S; s++)
            {
                for (int j = 1; j <= J; j++) 
                {
                    for (int p = 1; p <= P; p++)
                    {
                        String ss = j + " " + p + " " + s;
                        if (combiJP[new KeyValuePair<int, int>(j, p)] < K &&
                            combiPS[new KeyValuePair<int, int>(p, s)] < K &&
                            combiJS[new KeyValuePair<int, int>(j, s)] < K)
                        {
                            if (ss != pvrs)
                            {
                                pvrs = ss;
                                l.Add(ss);
                                combiJP[new KeyValuePair<int, int>(j, p)]++;
                                combiPS[new KeyValuePair<int, int>(p, s)]++;
                                combiJS[new KeyValuePair<int, int>(j, s)]++;
                                couldDoSthg = true;
                            }
                            else if (P > 1)
                            {
                                pvrs = ss;
                                bool canInsert = false;
                                for (int i = 0; i < l.Count - 1; i++)
                                {
                                    if (l[i] != ss && l[i] + 1 != ss)
                                    {
                                        l.Insert(i + 1, ss);
                                        canInsert = true;
                                        break;
                                    }
                                }
                                if (canInsert)
                                {
                                    combiJP[new KeyValuePair<int, int>(j, p)]++;
                                    combiPS[new KeyValuePair<int, int>(p, s)]++;
                                    combiJS[new KeyValuePair<int, int>(j, s)]++;
                                    couldDoSthg = true;
                                }
                            }
                            //goto hereWeGoAgain;
                        }
                    }
                }
            }
            if (couldDoSthg)
                goto hereWeGoAgain;
            return l;
        }

        private static List<string> FashionPoliceJSP(Int32 J, Int32 P, Int32 S, Int32 K)
        {
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJP = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiPS = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJS = new Dictionary<KeyValuePair<int, int>, int>();
            var l = new List<String>();

            for (int j = 1; j <= J; j++)
            {
                for (int s = 1; s <= S; s++)
                {
                    for (int p = 1; p <= P; p++)
                    {
                        combiJP[new KeyValuePair<int, int>(j, p)] = 0;
                        combiPS[new KeyValuePair<int, int>(p, s)] = 0;
                        combiJS[new KeyValuePair<int, int>(j, s)] = 0;
                    }
                }
            }
            String pvrs = String.Empty;
        hereWeGoAgain:

            bool couldDoSthg = false;
            for (int j = 1; j <= J; j++)
            {
                for (int s = 1; s <= S; s++)
                {
                    for (int p = 1; p <= P; p++)
                    {
                        String ss = j + " " + p + " " + s;
                        if (combiJP[new KeyValuePair<int, int>(j, p)] < K &&
                            combiPS[new KeyValuePair<int, int>(p, s)] < K &&
                            combiJS[new KeyValuePair<int, int>(j, s)] < K)
                        {
                            if (ss != pvrs)
                            {
                                pvrs = ss;
                                l.Add(ss);
                                combiJP[new KeyValuePair<int, int>(j, p)]++;
                                combiPS[new KeyValuePair<int, int>(p, s)]++;
                                combiJS[new KeyValuePair<int, int>(j, s)]++;
                                couldDoSthg = true;
                            }
                            else if (P > 1)
                            {
                                pvrs = ss;
                                bool canInsert = false;
                                for (int i = 0; i < l.Count - 1; i++)
                                {
                                    if (l[i] != ss && l[i] + 1 != ss)
                                    {
                                        l.Insert(i + 1, ss);
                                        canInsert = true;
                                        break;
                                    }
                                }
                                if (canInsert)
                                {
                                    combiJP[new KeyValuePair<int, int>(j, p)]++;
                                    combiPS[new KeyValuePair<int, int>(p, s)]++;
                                    combiJS[new KeyValuePair<int, int>(j, s)]++;
                                    couldDoSthg = true;
                                }
                            }
                            //goto hereWeGoAgain;
                        }
                    }
                }
            }
            if (couldDoSthg)
                goto hereWeGoAgain;
            return l;
        }

        private static List<string> FashionPoliceSPJ(Int32 J, Int32 P, Int32 S, Int32 K)
        {
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJP = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiPS = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJS = new Dictionary<KeyValuePair<int, int>, int>();
            var l = new List<String>();

            for (int s = 1; s <= S; s++) 
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int j = 1; j <= J; j++)
                    {
                        combiJP[new KeyValuePair<int, int>(j, p)] = 0;
                        combiPS[new KeyValuePair<int, int>(p, s)] = 0;
                        combiJS[new KeyValuePair<int, int>(j, s)] = 0;
                    }
                }
            }
            String pvrs = String.Empty;
        hereWeGoAgain:

            bool couldDoSthg = false;
            for (int s = 1; s <= S; s++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int j = 1; j <= J; j++)
                    {
                        String ss = j + " " + p + " " + s;
                        if (combiJP[new KeyValuePair<int, int>(j, p)] < K &&
                            combiPS[new KeyValuePair<int, int>(p, s)] < K &&
                            combiJS[new KeyValuePair<int, int>(j, s)] < K)
                        {
                            if (ss != pvrs)
                            {
                                pvrs = ss;
                                l.Add(ss);
                                combiJP[new KeyValuePair<int, int>(j, p)]++;
                                combiPS[new KeyValuePair<int, int>(p, s)]++;
                                combiJS[new KeyValuePair<int, int>(j, s)]++;
                                couldDoSthg = true;
                            }
                            else if (P > 1)
                            {
                                pvrs = ss;
                                bool canInsert = false;
                                for (int i = 0; i < l.Count - 1; i++)
                                {
                                    if (l[i] != ss && l[i] + 1 != ss)
                                    {
                                        l.Insert(i + 1, ss);
                                        canInsert = true;
                                        break;
                                    }
                                }
                                if (canInsert)
                                {
                                    combiJP[new KeyValuePair<int, int>(j, p)]++;
                                    combiPS[new KeyValuePair<int, int>(p, s)]++;
                                    combiJS[new KeyValuePair<int, int>(j, s)]++;
                                    couldDoSthg = true;
                                }
                            }
                            //goto hereWeGoAgain;
                        }
                    }
                }
            }
            if (couldDoSthg)
                goto hereWeGoAgain;
            return l;
        }

        private static List<string> FashionPolicePJS(Int32 J, Int32 P, Int32 S, Int32 K)
        {
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJP = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiPS = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJS = new Dictionary<KeyValuePair<int, int>, int>();
            var l = new List<String>();

            for (int s = 1; s <= S; s++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int j = 1; j <= J; j++)
                    {
                        combiJP[new KeyValuePair<int, int>(j, p)] = 0;
                        combiPS[new KeyValuePair<int, int>(p, s)] = 0;
                        combiJS[new KeyValuePair<int, int>(j, s)] = 0;
                    }
                }
            }
            String pvrs = String.Empty;
        hereWeGoAgain:

            bool couldDoSthg = false;
            for (int p = 1; p <= P; p++)
            {
                for (int j = 1; j <= J; j++)
                {
                    for (int s = 1; s <= S; s++)
                    {
                        String ss = j + " " + p + " " + s;
                        if (combiJP[new KeyValuePair<int, int>(j, p)] < K &&
                            combiPS[new KeyValuePair<int, int>(p, s)] < K &&
                            combiJS[new KeyValuePair<int, int>(j, s)] < K)
                        {
                            if (ss != pvrs)
                            {
                                pvrs = ss;
                                l.Add(ss);
                                combiJP[new KeyValuePair<int, int>(j, p)]++;
                                combiPS[new KeyValuePair<int, int>(p, s)]++;
                                combiJS[new KeyValuePair<int, int>(j, s)]++;
                                couldDoSthg = true;
                            }
                            else if (P > 1)
                            {
                                pvrs = ss;
                                bool canInsert = false;
                                for (int i = 0; i < l.Count - 1; i++)
                                {
                                    if (l[i] != ss && l[i] + 1 != ss)
                                    {
                                        l.Insert(i + 1, ss);
                                        canInsert = true;
                                        break;
                                    }
                                }
                                if (canInsert)
                                {
                                    combiJP[new KeyValuePair<int, int>(j, p)]++;
                                    combiPS[new KeyValuePair<int, int>(p, s)]++;
                                    combiJS[new KeyValuePair<int, int>(j, s)]++;
                                    couldDoSthg = true;
                                }
                            }
                            //goto hereWeGoAgain;
                        }
                    }
                }
            }
            if (couldDoSthg)
                goto hereWeGoAgain;
            return l;
        }
        private static List<string> FashionPolicePSJ(Int32 J, Int32 P, Int32 S, Int32 K)
        {
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJP = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiPS = new Dictionary<KeyValuePair<int, int>, int>();
            Dictionary<KeyValuePair<Int32, Int32>, Int32> combiJS = new Dictionary<KeyValuePair<int, int>, int>();
            var l = new List<String>();

            for (int s = 1; s <= S; s++)
            {
                for (int p = 1; p <= P; p++)
                {
                    for (int j = 1; j <= J; j++)
                    {
                        combiJP[new KeyValuePair<int, int>(j, p)] = 0;
                        combiPS[new KeyValuePair<int, int>(p, s)] = 0;
                        combiJS[new KeyValuePair<int, int>(j, s)] = 0;
                    }
                }
            }
            String pvrs = String.Empty;
        hereWeGoAgain:

            bool couldDoSthg = false;
            for (int p = 1; p <= P; p++) 
            {
                for (int s = 1; s <= S; s++)    
                {
                    for (int j = 1; j <= J; j++)
                    {
                        String ss = j + " " + p + " " + s;
                        if (combiJP[new KeyValuePair<int, int>(j, p)] < K &&
                            combiPS[new KeyValuePair<int, int>(p, s)] < K &&
                            combiJS[new KeyValuePair<int, int>(j, s)] < K)
                        {
                            if (ss != pvrs)
                            {
                                pvrs = ss;
                                l.Add(ss);
                                combiJP[new KeyValuePair<int, int>(j, p)]++;
                                combiPS[new KeyValuePair<int, int>(p, s)]++;
                                combiJS[new KeyValuePair<int, int>(j, s)]++;
                                couldDoSthg = true;
                            }
                            else if (P > 1)
                            {
                                pvrs = ss;
                                bool canInsert = false;
                                for (int i = 0; i < l.Count - 1; i++)
                                {
                                    if (l[i] != ss && l[i] + 1 != ss)
                                    {
                                        l.Insert(i + 1, ss);
                                        canInsert = true;
                                        break;
                                    }
                                }
                                if (canInsert)
                                {
                                    combiJP[new KeyValuePair<int, int>(j, p)]++;
                                    combiPS[new KeyValuePair<int, int>(p, s)]++;
                                    combiJS[new KeyValuePair<int, int>(j, s)]++;
                                    couldDoSthg = true;
                                }
                            }
                            //goto hereWeGoAgain;
                        }
                    }
                }
            }
            if (couldDoSthg)
                goto hereWeGoAgain;
            return l;
        }
    }
}

