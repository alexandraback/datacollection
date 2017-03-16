using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ2012.Round1A
{
    public class QRA
    {
        public void Solve(string type)
        {
            string inputFile = GetType().Name + "-" + type + ".in";
            string outputFile = GetType().Name + "-" + type + ".out";

            var reader = new Reader(inputFile);
            TextWriter tw = new StreamWriter(outputFile);

            //start

            int T = reader.GetInt();

            for (int i = 0; i < T; i++)
            {
                reader.NewLine();
                int A = reader.GetInt();
                int B = reader.GetInt();

                

                reader.NewLine();
                var lst = reader.GetDoubleArray(A);

                if (A == 3 && B == 4)
                {
                }

                var eENTER = B + 2;
                double res = eENTER;

                var exp = new double[A + 1];
                double prob = 1;
                for (int x = A; x >=0; x--)
                {
                    int ok = B - A + 1 + 2*x;
                    int ko = ok+B+1;

                    if (A - x >= 1) prob *= lst[A - x - 1];
                    /*
                    for (int j = 0; j < A-x; j++)
                    {
                        prob *= lst[j];
                    }
                    */
                    exp[x] = prob * ok + (1 - prob) * ko;
                    if (res > exp[x]) res = exp[x];
                }
                res = Math.Round(res, 6);
                


                // write result
                String Case = "Case #" + (i + 1).ToString() + ": " + string.Format("{0:0.000000}",res).Replace(",",".");
                tw.WriteLine(Case);

            }

            tw.Close();
            reader.Close();
        }



        #region reader
        private class Reader
        {
            private readonly StreamReader reader;
            private String[] valori;
            private int seek = 0;

            public Reader(string inputFile)
            {
                reader = new StreamReader(inputFile);
                NewLine();
            }

            public void NewLine()
            {
                string line = reader.ReadLine();
                valori = line.Split(' ');
                seek = 0;
            }

            public void Close()
            {
                reader.Close();
            }

            public int GetInt()
            {
                return int.Parse(valori[seek++]);
            }

            public long GetLong()
            {
                return long.Parse(valori[seek++]);
            }

            public float GetFloat()
            {
                return float.Parse(valori[seek++].Replace(".",","));
            }

            public double GetDouble()
            {
                return double.Parse(valori[seek++].Replace(".", ","));
            }

            public string GetString()
            {
                return valori[seek++];
            }

            public string[] GetStringArray(int count)
            {
                var array = new string[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetString();
                }
                return array;
            }

            public int[] GetIntArray(int count)
            {
                var array = new int[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetInt();
                }
                return array;
            }

            public long[] GetLongArray(int count)
            {
                var array = new long[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetLong();
                }
                return array;
            }

            public float[] GetFloatArray(int count)
            {
                var array = new float[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetFloat();
                }
                return array;
            }

            public double[] GetDoubleArray(int count)
            {
                var array = new double[count];
                for (int j = 0; j < count; j++)
                {
                    array[j] = GetDouble();
                }
                return array;
            }

            public int[,] GetIntMatrix(int h, int w)
            {
                var array = new int[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetInt();
                    }
                }

                return array;
            }

            public long[,] GetLongMatrix(int h, int w)
            {
                var array = new long[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetLong();
                    }
                }

                return array;
            }

            public string[,] GetStringMatrix(int h, int w)
            {
                var array = new string[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetString();
                    }
                }

                return array;
            }

            public float[,] GetFloatMatrix(int h, int w)
            {
                var array = new float[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetFloat();
                    }
                }

                return array;
            }

            public double[,] GetDoubleMatrix(int h, int w)
            {
                var array = new double[h, w];
                for (int i = 0; i < h; i++)
                {
                    NewLine();
                    for (int j = 0; j < w; j++)
                    {
                        array[i, j] = GetDouble();
                    }
                }

                return array;
            }

        }
        #endregion




    }


}
