using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace QRProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().
                GetModules()[0].FullyQualifiedName);

            String inputPath = path + Path.DirectorySeparatorChar + "D-small-attempt0.in";
            String outputPath = path + Path.DirectorySeparatorChar + "D-small-attempt0.in.txt";

            StreamReader reader = new StreamReader(inputPath);
            StreamWriter writer = new StreamWriter(outputPath);

            int caseNumber = 0;
            string line = reader.ReadLine();
            caseNumber = Convert.ToInt32(line);

            for (int i = 0; i < caseNumber; ++i)
            {
                DoOneCase(i + 1, reader, writer);
            }
            reader.Close();
            writer.Close();
        }

        public static void DoOneCase(int caseNumber, StreamReader reader, StreamWriter writer)
        {
            // read block number 
            string line = reader.ReadLine();
            int blockNum = Convert.ToInt32(line);

            // read Naomi block
            line = reader.ReadLine();
            string[] word = line.Split(new char[] { ' ' });
            List<double> Naomi = new List<double>();
            List<double> NaomiD = new List<double>();
            for (int i = 0; i < word.Length; ++i)
            {
                Naomi.Add(Convert.ToDouble(word[i]));
                NaomiD.Add(Convert.ToDouble(word[i]));
            }

            // read Ken block
            line = reader.ReadLine();
            word = line.Split(new char[] { ' ' });
            List<double> Ken = new List<double>();
            List<double> KenD = new List<double>();
            for (int i = 0; i < word.Length; ++i)
            {
                Ken.Add(Convert.ToDouble(word[i]));
                KenD.Add(Convert.ToDouble(word[i]));
            }

            // sort blocks  default increase
            Naomi.Sort();
            Ken.Sort();
            NaomiD.Sort();
            KenD.Sort();

            // calculate 
            int NaomiPoint = 0;
            int Ni = 0;
            int Ki = 0;
            while(Naomi.Count > 0)
            {
                Ni = Naomi.Count - 1;
                Ki = KenFindIndex(Naomi[Ni], Ken);
                if (Ki == -1) // use min
                {
                    Ki = 0;
                    NaomiPoint++;
                }

                // remove
                Naomi.RemoveAt(Ni);
                Ken.RemoveAt(Ki);
            }

            // calculate in D
            int NaomiPointD = 0;
            while (NaomiD.Count > 0)
            {
                Ni = 0;
                Ki = 0;
                if (NaomiD[Ni] > KenD[Ki]) // use min
                {
                    NaomiPointD++;
                }
                else 
                {
                    Ki = KenD.Count - 1;
                }

                // remove
                NaomiD.RemoveAt(Ni);
                KenD.RemoveAt(Ki);
            }



            string result = "" + NaomiPointD + " " + NaomiPoint;
            writer.WriteLine("Case #" + caseNumber + ": " + result);
        }

        public static int KenFindIndex(double toldMass, List<double> Ken)
        {
            for (int i = 0; i < Ken.Count; ++i)
            {
                if (toldMass < Ken[i])
                {
                    return i;
                }
            }
            return -1;
        }
    }
}
