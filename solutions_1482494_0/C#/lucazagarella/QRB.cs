using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ2012.Round1A
{
    public class QRB
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
                int N = reader.GetInt();
                var mat = reader.GetIntMatrix(N,2);
                var mypoint = 0;
                var play = 0;
                var L = new List<Eleme>();
                for (int j = 0; j < N; j++)
                {
                    var x1 = mat[j, 0];
                    var x2 = mat[j, 1];
                    L.Add(new Eleme() { required = x1, stars = 1 });
                    L.Add(new Eleme() { required = x2, stars = 2,remove = x1});
                }

                string res = null;
                while (L.Any(x=>x.stars==2))
                {
                    var found=L.Where(x => x.required <= mypoint).OrderByDescending(x => x.stars).ThenByDescending(x=>x.remove).FirstOrDefault();
                    if (found==null)
                    {
                        res = "Too Bad";
                        break;
                    }
                    L.Remove(found);
                    if (found.remove>-1) //2 stars completo
                    {
                        var xx = L.Where(x => x.stars == 1 && x.required == found.remove).OrderByDescending(x=>x.required).First();
                        L.Remove(xx);
                        mypoint++;
                    }
                    else if (found.stars==1)
                    {
                        var xx = L.Where(x => x.stars == 2 && x.remove == found.required).OrderBy(x=>x.required).First();
                        xx.remove = -1;
                    }

                    play++;
                    mypoint++;
                }
                if (res==null)
                {
                    res = play.ToString();
                }

               


                // write result
                String Case = "Case #" + (i + 1).ToString() + ": " + res;
                tw.WriteLine(Case);

            }

            tw.Close();
            reader.Close();
        }

        private class Eleme
        {
            public int required;
            public int stars;
            public int remove = -1;

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
                return float.Parse(valori[seek++]);
            }

            public double GetDouble()
            {
                return double.Parse(valori[seek++]);
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
