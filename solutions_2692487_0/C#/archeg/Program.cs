using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam
{
    class Task
    {
        public int PlayersMote { get; set; }

        public List<int> AvailableMotes { get; set; }

        public int Result { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string[] inputLines = File.ReadAllLines("file.in");

            int t = int.Parse(inputLines[0]);

            int currentLine = 1;
            List<Task> tasks = new List<Task>();
            for (int i = 0; i<t; i++)
            {
                var task = new Task();
                task.PlayersMote = int.Parse(inputLines[currentLine].Split()[0]);
                currentLine++;
                task.AvailableMotes = inputLines[currentLine].Split().Select(x => int.Parse(x)).ToList();
                tasks.Add(task);
                currentLine++;
            }

            foreach (var task in tasks)
            {
                Solve(task);
            }

            StringBuilder builder = new StringBuilder();
            int caseN = 1;
            foreach (var task in tasks)
            {
                builder.Append(string.Format("Case #{0}: {1}\n", caseN, task.Result));
                caseN++;
            }

            File.WriteAllText("file.out", builder.ToString());
        }

        private static void Solve(Task task)
        {
            int solution = int.MaxValue;
            int currentMoleSize = task.PlayersMote;
            int addedMoles = 0;

            List<int> availableMotes = task.AvailableMotes;
            availableMotes.Sort();
            for (int i = 0; i < availableMotes.Count; i++)
            {
                var enemyMole = availableMotes[i];
                if (enemyMole < currentMoleSize)
                {
                    currentMoleSize += enemyMole;
                }
                else
                {
                    int solutionRemovingAllNextMoles = availableMotes.Count - i + addedMoles;
                    solution = Math.Min(solution, solutionRemovingAllNextMoles);

                    if (currentMoleSize != 1)
                    {
                        addedMoles++;
                        currentMoleSize += (currentMoleSize - 1);
                        i -= 1;
                    }
                    else
                    {
                        task.Result = availableMotes.Count;
                        return;
                    }
                }
            }

            solution = Math.Min(solution, addedMoles);
            if (solution == int.MaxValue)
            {
                solution = 0;
            }

            task.Result = solution;
        }
    }
}
