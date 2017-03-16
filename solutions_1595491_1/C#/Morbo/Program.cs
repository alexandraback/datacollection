using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    class Program
    {
        const string ConstFileNewlineFormat = "\n";
        const string ConstFilename = "B-large";

        /// <summary>
        /// Main entry point. 
        /// </summary>
        /// <param name="args">The args.</param>
        static void Main(string[] args)
        {
            SolveB();
        }

        /// <summary>
        /// Solves the B chalange.
        /// </summary>
        public static void SolveB()
        {
            var dataStringInput = ReadFile("c:\\temp\\" + ConstFilename + ".in");
            StringBuilder dataStringOutput = new StringBuilder();

            var data = dataStringInput.Split(new string[] { ConstFileNewlineFormat }, System.StringSplitOptions.None);

            // variable declaration
            int casesT = 0;

            int googlersN = 0;
            int surprisingS = 0;
            int bestRezP = 0;
            int[] scores;

            // data reading into variables and solving cases
            int elem = 0;
            casesT = Convert.ToInt32(data[elem]);
            elem++;

            for (int n = 0; n < casesT; n++)
            {
                int itemsI = 0;
                var items = data[elem].Split(new char[] { ' ' }).ToList();


                googlersN = Convert.ToInt32(items[itemsI]);
                itemsI++;

                surprisingS = Convert.ToInt32(items[itemsI]);
                itemsI++;

                bestRezP = Convert.ToInt32(items[itemsI]);
                itemsI++;

                scores = new int[googlersN];
                for (int k = 0; k < googlersN; k++)
                {
                    scores[k] = Convert.ToInt32(items[itemsI]);
                    itemsI++;
                }
                elem++;

                // reading done, solving current case

                // finding distribution, without 'surprises'
                List<Triplet> listTrip = new List<Triplet>();
                for (int i = 0; i < googlersN; i++)
                {
                    listTrip.Add(new Triplet(scores[i]));
                }

                // adding surprises
                int insertedSurprises = 0;
                int coolScore = 0;
                for (int i = 0; i < listTrip.Count; i++)
                {
                    if (listTrip[i].t3 >= bestRezP)
                    {
                        // no need to specialize
                        coolScore++;
                        continue;
                    }

                    // if there are no surprises left, we cannot upgrade the score for this poor thing...
                    if (insertedSurprises >= surprisingS)
                        continue;

                    if (listTrip[i].t3 == bestRezP - 1)
                    {
                        // see if we can specialize (w/o pointless spec)
                        if (listTrip[i].t2 == listTrip[i].t3 && listTrip[i].t2 > 0)
                        {
                            // available to specialization
                            coolScore++;
                            insertedSurprises++;
                        }
                    }
                }

                // formatting output
                dataStringOutput.Append("Case #");
                dataStringOutput.Append(n + 1);
                dataStringOutput.Append(": ");
                dataStringOutput.AppendLine(coolScore.ToString());
            }

            // -------------------------------------
            // all cases solved, writing output file
            WriteFile("C:\\temp\\" + ConstFilename + ".out", dataStringOutput.ToString());
        }

        /// <summary>
        /// Reads the file.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        /// <returns>Contents of the file.</returns>
        public static string ReadFile(string filePath)
        {
            string rez = string.Empty;

            using (StreamReader sr = new StreamReader(filePath))
            {
                rez = sr.ReadToEnd();
            }

            return rez;
        }

        /// <summary>
        /// Writes the content to the file.
        /// </summary>
        /// <param name="filePath">The file path.</param>
        /// <param name="content">The content.</param>
        public static void WriteFile(string filePath, string content)
        {
            using (StreamWriter sr = new StreamWriter(filePath))
            {
                sr.Write(content);
            }
        }

        /// <summary>
        /// Triplet class. Last socre will be always the gratest.
        /// </summary>
        public class Triplet
        {
            public int t1 { get; set; }
            public int t2 { get; set; }
            public int t3 { get; set; }

            public Triplet(int sum)
            {
                int initial = sum / 3;
                this.t1 = initial;
                this.t2 = (sum - initial) / 2;
                this.t3 = sum - this.t1 - this.t2;
            }
        }
    }
}
