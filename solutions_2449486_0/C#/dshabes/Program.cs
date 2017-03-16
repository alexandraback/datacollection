using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJQB
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testNumber = 1; testNumber <= testCount; testNumber++)
            {
                var parts = Console.ReadLine().Split();
                var n = int.Parse(parts[0]);
                var m = int.Parse(parts[1]);
                var grid = new int[n, m];
                for (int i = 0; i < n; i++)
                {
                    var cells = Console.ReadLine().Split();
                    for (int j = 0; j < m; j++)
                        grid[i, j] = int.Parse(cells[j]);
                }

                bool success = true;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (grid[k, j] > grid[i, j])
                            {
                                success = false;
                                break;
                            }
                        }
                        if (success)
                            continue;
                        success = true;
                        for (int k = 0; k < m; k++)
                        {
                            if (grid[i, k] > grid[i, j])
                            {
                                success = false;
                                break;
                            }
                        }
                        if (!success)
                            break;
                    }
                    if (!success)
                        break;
                }

                Console.WriteLine("Case #{0}: {1}", testNumber, success ? "YES" : "NO");
            }
        }
    }
}
