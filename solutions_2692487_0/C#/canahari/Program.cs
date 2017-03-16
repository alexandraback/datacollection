using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1stRound1
{
    class EasyMoteSolver
    {
        public int Operations
        {
            get { return currentOpMin; }
        }

        int armin;
        List<int> enemies;
        int currentOpMin = int.MaxValue;

        public EasyMoteSolver(int armin, List<int> enemies)
        {
            this.armin = armin;
            this.enemies = enemies;
        }

        public void Solve()
        {
            enemies.Sort();
            SolveCase(0, armin, 0);
        }

        private void SolveCase(int currentOperations, int currentArmin, int currentEnemyIndex)
        {
            if (currentEnemyIndex == enemies.Count)
            {
                if (currentOperations < currentOpMin)
                    currentOpMin = currentOperations;
            }
            else
            {
                if (currentOperations > currentOpMin)
                    return;

                if (enemies[currentEnemyIndex] < currentArmin)
                {
                    //ha meg tudod enni, tutira edd meg. 
                    SolveCase(currentOperations, currentArmin + enemies[currentEnemyIndex], currentEnemyIndex + 1);
                }
                else
                {
                    //oldd meg úgy, hogy teremtesz egyet és megeszed... de csak ha armin nem 0 
                    if (currentArmin > 1)
                    {
                        SolveCase(currentOperations + 1, (currentArmin + (currentArmin - 1)), currentEnemyIndex);
                    }
                    
                    //oldd meg úgy, hogy eltünteted 
                    SolveCase(currentOperations + 1, currentArmin, currentEnemyIndex + 1);
                }

            }
        }
    }

    class Program
    {
        const string outFileName = "out.txt";

        [STAThread]
        static void Main(string[] args)
        {
            string inFileName = null;
            using (OpenFileDialog dlg = new OpenFileDialog())
            {
                if (dlg.ShowDialog() == DialogResult.OK)
                {
                    inFileName = dlg.FileName;
                }
            }
            if (inFileName == null)
                return;

            using (StreamWriter sw = new StreamWriter(outFileName))
            {
                using (StreamReader sr = new StreamReader(inFileName))
                {
                    int testCaseCount = int.Parse(sr.ReadLine());
                    for (int testCase = 1; testCase <= testCaseCount; testCase++)
                    {
                        string[] line = sr.ReadLine().Split(' ');
                        int armin = int.Parse(line[0]);
                        string[] line2 = sr.ReadLine().Split(' ');
                        List<int> moteSizes = new List<int>();
                        for (int m = 0; m < line2.Length; m++)
                            moteSizes.Add(int.Parse(line2[m]));
                        EasyMoteSolver solver = new EasyMoteSolver(armin, moteSizes);
                        solver.Solve();
                        sw.WriteLine("Case #{0}: {1}", testCase, solver.Operations);
                    }
                }
            }
        }
    }
}
