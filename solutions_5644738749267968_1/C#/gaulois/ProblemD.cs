
#define TRACE

using System;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Problem
    {
        public List<float> nao = new List<float>();
        public List<float> ken = new List<float>();
    }

    class MainClass
    {
        static float KenPlay(List<float> ken, float nao)
        {
            float def = ken[0];

            foreach(float play in ken)
            {
                if(play > nao)
                {
                    def = play;
                    break;
                }
            }

            return def;
        }

        static int War(Problem m)
        {
            List<float> ken = new List<float>(m.ken);
            List<float> nao = new List<float>(m.nao);

            int scoreNao = 0;
            while (ken.Count != 0)
            {
                float pNao = nao[0];
                nao.Remove(pNao);

                float kP = KenPlay(ken, pNao);
                ken.Remove(kP);

                if (pNao > kP)
                {
                    scoreNao++;
                }
            }

            return scoreNao;
        }

        static int DeceitfulWar(Problem m)
        {
            List<float> ken = new List<float>(m.ken);
            List<float> nao = new List<float>(m.nao);

            int pts = 0;
            while(nao.Count != 0)
            {
                if (nao[nao.Count-1] > ken[ken.Count-1])
                {
                    pts++;

                    nao.Remove(nao[nao.Count - 1]);
                    ken.Remove(ken[ken.Count - 1]);
                }
                else if (nao[0] < ken[ken.Count - 1])
                {
                    nao.Remove(nao[0]);
                    ken.Remove(ken[ken.Count - 1]);
                }
            }

            return pts;
        }

        static List<int> Solve(Problem m)
        {
            int warScoreNao = War(m);
            int dwarScoreNao = DeceitfulWar(m);

            List<int> s = new List<int>();
            s.Add(dwarScoreNao);
            s.Add(warScoreNao);
            return s;
        }

        static List<Problem> ReadProblems(string file)
        {
            List<Problem> problems = new List<Problem>();

            string[] lines = System.IO.File.ReadAllLines(file);

            int nProbs = int.Parse(lines[0]);
            for (int i = 1; i < lines.Length; ++i)
            {
                Problem problem = new Problem();

                // Flush the number of items.
                ++i;

                string[] sViews = lines[i].Split(' ');
                foreach (string sView in sViews)
                {
                    problem.nao.Add(float.Parse(sView));
                }

                ++i;
                sViews = lines[i].Split(' ');
                foreach (string sView in sViews)
                {
                    problem.ken.Add(float.Parse(sView));
                }

                problem.ken.Sort();
                problem.nao.Sort();

                problems.Add(problem);
            }

            return problems;
        }

        public static void Main(string[] args)
        {
            Trace.Listeners.Add(new ConsoleTraceListener());

            //string filename = "../../tiny.in";
            string filename = "../../D-large.in";
            //string filename = "../../C-large-practice.in";

            List<Problem> problems = ReadProblems(filename);

            int i = 0;
            StringBuilder sb = new StringBuilder();
            foreach (var problem in problems)
            {
                //List<int> res = Solve (j);
                List<int> res = Solve(problem);

                string s = string.Format("Case #{0}: {1}", i + 1, res.Count == 0 ? "Impossible" : string.Join(" ", res));

                Console.WriteLine(s);
                sb.Append(s);
                sb.Append("\n");

                ++i;
            }

            System.IO.File.WriteAllText(filename.Replace(".in", ".out"), sb.ToString());
        }
    }
}
