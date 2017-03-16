using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GCJ
{
    class Box
    {
        public long type;
        public long quant;

        public Box(long type, long quant)
        {
            this.type = type;
            this.quant = quant;
        }
    }

    class Toy
    {
        public long type;
        public long quant;

        public Toy(long type, long quant)
        {
            this.type = type;
            this.quant = quant;
        }
    }

    class Result
    {
        public long boxesquant;
        public long toysquant;
        public long result;

        public Result(long boxesquant, long toysquant, long result)
        {
            this.boxesquant = boxesquant;
            this.toysquant = toysquant;
            this.result = result;
        }
    }

    class C
    {
        public static bool isValid(int n, int m, ref Box[] boxes, ref Toy[] toys)
        {
            return ((0 <= n) && (n < boxes.Length) && (0 <= m) && (m < toys.Length));
        }

        public static Result maxResult(ref Result a, ref Result b)
        {
            if (a.result > b.result)
            {
                return a;
            }
            else
            {
                return b;
            }
        }

        public static void fillTable(int n, int m, ref Result[,] result, ref Box[] boxes, ref Toy[] toys)
        {
            if (result[n, m].result != -1)
            {
                return;
            }
            else
            {
                Result nowResult = result[n, m];
                Result prevResult;
                long nboxquant, ntoyquant;

                if (n > 0)
                {
                    fillTable(n - 1, m, ref result, ref boxes, ref toys);
                    prevResult = result[n - 1, m];

                    if (nowResult.result < prevResult.result)
                    {
                        if (n < boxes.Length)
                        {
                            nboxquant = boxes[n].quant;
                        }
                        else
                        {
                            nboxquant = 0;
                        }

                        nowResult = new Result(nboxquant, prevResult.toysquant, prevResult.result);    
                    }
                    

                    if ((m < toys.Length) && (boxes[n - 1].type == toys[m].type) && (prevResult.boxesquant < prevResult.toysquant) && (nowResult.result < (prevResult.result + prevResult.boxesquant)))
                    {
                        if (n < boxes.Length)
                        {
                            nboxquant = boxes[n].quant;
                        }
                        else
                        {
                            nboxquant = 0;
                        }

                        nowResult = new Result(nboxquant, prevResult.toysquant - prevResult.boxesquant, prevResult.result + prevResult.boxesquant);
                    }
                }

                if (m > 0)
                {
                    fillTable(n, m - 1, ref result, ref boxes, ref toys);
                    prevResult = result[n, m - 1];

                    if (nowResult.result < prevResult.result)
                    {
                        if (m < toys.Length)
                        {
                            ntoyquant = toys[m].quant;
                        }
                        else
                        {
                            ntoyquant = 0;
                        }

                        nowResult = new Result(prevResult.boxesquant, ntoyquant, prevResult.result);
                    }

                    if ((n < boxes.Length) && (boxes[n].type == toys[m - 1].type) && (prevResult.boxesquant > prevResult.toysquant) && (nowResult.result < (prevResult.result + prevResult.toysquant)))
                    {
                        if (m < toys.Length)
                        {
                            ntoyquant = toys[m].quant;
                        }
                        else
                        {
                            ntoyquant = 0;
                        }

                        nowResult = new Result(prevResult.boxesquant - prevResult.toysquant, ntoyquant, prevResult.result + prevResult.toysquant);
                    }
                }

                if ((n > 0) && (m > 0))
                {
                    fillTable(n - 1, m - 1, ref result, ref boxes, ref toys);
                    prevResult = result[n - 1, m - 1];
                    nowResult = maxResult(ref nowResult, ref prevResult);

                    if ((boxes[n - 1].type == toys[m - 1].type) && (prevResult.boxesquant == prevResult.toysquant) && (nowResult.result < (prevResult.result + prevResult.boxesquant)))
                    {
                        if (n < boxes.Length)
                        {
                            nboxquant = boxes[n].quant;
                        }
                        else
                        {
                            nboxquant = 0;
                        }
                        if (m < toys.Length)
                        {
                            ntoyquant = toys[m].quant;
                        }
                        else
                        {
                            ntoyquant = 0;
                        }
                        nowResult = new Result(nboxquant, ntoyquant, prevResult.result + prevResult.boxesquant);
                    }
                }

                result[n, m] = nowResult;
                return;
            }
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"D:\input.txt");
            StreamWriter sw = new StreamWriter(@"D:\output.txt");

            int t = int.Parse(sr.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int n, m;
                string[] inputs;
                Box[] boxes;
                Toy[] toys;
                Result[,] result;

                inputs = sr.ReadLine().Split(' ');
                n = int.Parse(inputs[0]);
                m = int.Parse(inputs[1]);
                boxes = new Box[n];
                toys = new Toy[m];
                result = new Result[n + 1, m + 1];

                for (int j = 0; j < n + 1; j++)
                {
                    for (int k = 0; k < m + 1; k++)
                    {
                        result[j, k] = new Result(-1, -1, -1);
                    }
                }

                inputs = sr.ReadLine().Split(' ');

                for (int j = 0; j < n; j++)
                {
                    boxes[j] = new Box(long.Parse(inputs[j * 2 + 1]), long.Parse(inputs[j * 2]));
                }

                inputs = sr.ReadLine().Split(' ');

                for (int j = 0; j < m; j++)
                {
                    toys[j] = new Toy(long.Parse(inputs[j * 2 + 1]), long.Parse(inputs[j * 2]));
                }

                result[0, 0] = new Result(boxes[0].quant, toys[0].quant, 0);

                fillTable(n, m, ref result, ref boxes, ref toys);

                sw.WriteLine("Case #{0}: {1}", i + 1, result[n, m].result);
            }

            sr.Close();
            sw.Close();
        }
    }
}
