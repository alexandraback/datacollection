using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Lawnmower
{
    class Program
    {
        static void Main(string[] args)
        {
            string file = args[0];
            //string file = "1.in";
            if (!File.Exists(file))
                Console.WriteLine(String.Format("File {0} doesn't exist", file));
            StreamReader reader = new StreamReader(file);
            StreamWriter writer = new StreamWriter(file + ".out");

            int tests = int.Parse(reader.ReadLine());
            for (int i = 0; i < tests; ++i)
            {
                bool horizontalError = false, verticalError = false;
                string[] values = reader.ReadLine().Split(' ');
                int n = int.Parse(values[0]);
                int m = int.Parse(values[1]);
                int[,] lawn = new int[n, m];
                for (int j = 0; j < n; ++j)
                {
                    values = reader.ReadLine().Split(' ');
                    for (int k = 0; k < m; ++k)
                        lawn[j, k] = int.Parse(values[k]);
                }
                for (int j = 0; j < n; ++j)
                {
                    for (int k = 0; k < m; ++k)
                    {
                        horizontalError = false;
                        verticalError = false;
                        for (int l = 0; l < n; ++l)
                            if (lawn[l, k] > lawn[j, k])
                            {
                                horizontalError = true;
                                break;
                            }
                        for (int l = 0; l < m; ++l)
                            if (lawn[j, l] > lawn[j, k])
                            {
                                verticalError = true;
                                break;
                            }
                        if (horizontalError && verticalError) break;
                    }
                    if (horizontalError && verticalError) break;
                }
                if (horizontalError && verticalError)
                    writer.WriteLine(String.Format("Case #{0}: NO", i + 1));
                else
                    writer.WriteLine(String.Format("Case #{0}: YES", i + 1));
            }
            writer.Flush();
            writer.Close();
            reader.Close();
        }
    }
}
