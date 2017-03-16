using System.Collections.Generic;
using System.IO;

namespace ProjectB
{
    class Program
    {


        const string Small = "B-small-attempt0.in";
        const string Large = "B-large.in";

        static void Main(string[] args)
        {
            string inFile = Small;
            //string inFile = Large;
            StreamReader readStream = new StreamReader(inFile);
            string outFile = inFile + ".out.txt";
            StreamWriter writer = new StreamWriter(outFile);

            string firstLine = readStream.ReadLine();

            int T = int.Parse(firstLine);
            for (int i = 1; i <= T; i++)
            {
                string line = readStream.ReadLine();
                string[] lines = line.Split(' ');
                long x = long.Parse(lines[0]);
                long y = long.Parse(lines[1]);
                string result = solve(x, y);
                writer.WriteLine("Case #" + i + ": " + result);
            }

            readStream.Close();
            writer.Close();
        }

        private static string solve(long x, long y)
        {
            return DoSolve(0, 0, x, y, 1, string.Empty);
        }

        private static string DoSolve(long currentx, long currenty, long x, long y, int step, string path)
        {
            if (currentx == x && currenty == y)
                return path;
            if (currentx < x)
            {
                if (currentx + step <= x)
                {
                    path += "E";
                    currentx += step;
                }
                else
                {
                    path += "W";
                    currentx -= step;
                }
            }
            else if (currentx > x)
            {
                if (currentx - step >= x)
                {
                    path += "W";
                    currentx -= step;
                }
                else
                {
                    path += "E";
                    currentx += step;
                }
            }
            else
            {

                if (currenty < y)
                {
                    if (currenty + step <= y)
                    {
                        path += "N";
                        currenty += step;
                    }
                    else
                    {
                        path += "S";
                        currenty -= step;
                    }
                }
                else if (currenty > y)
                {
                    if (currenty - step >= y)
                    {
                        path += "S";
                        currenty -= step;
                    }
                    else
                    {
                        path += "N";
                        currenty += step;
                    }
                }
            }
            step++;
            return DoSolve(currentx, currenty, x, y, step, path);
        }
    }
}
