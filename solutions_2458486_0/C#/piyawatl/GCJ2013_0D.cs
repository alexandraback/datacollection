using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2013_0
{
    class GCJ2013_0D
    {
        const string fileName = "D-small-attempt0";
        const string inputFile = fileName + ".in";
        const string outputFile = fileName + ".out";
        StreamReader reader = new StreamReader(inputFile);
        StreamWriter writer = new StreamWriter(outputFile);

        int[][] chestKeys = new int[202][];
        int[] chestTypes = new int[202];
        int[] keys = new int[202];
        int[] locks = new int[202];
        int K, N;

        public void Init()
        {
            for (int i = 0; i < chestKeys.Length; i++) chestKeys[i] = new int[202];
        }


        public void Clear()
        {
            for (int i = 0; i < chestKeys.Length; i++)
            {
                keys[i] = 0;
                locks[i] = 0;
                for (int j = 0; j < chestKeys[i].Length; j++)
                    chestKeys[i][j] = 0;
            }
        }

        public bool CanRemove(int chest)
        {
            for (int i = 0; i < keys.Length; i++)
            {
                if (keys[i]-chestKeys[chest][i] < locks[i])
                {
                    return false;
                }
            }
            return true;
        }

        public void RemoveChest(int chest)
        {
            for (int i = 0; i < keys.Length; i++)
            {
                keys[i] -= chestKeys[chest][i];
            }
            locks[chestTypes[chest]]--;
            chestTypes[chest] = 0;
        }

        public string Solve()
        {
            for (int i = 0; i < keys.Length; i++)
            {
                if (keys[i] < locks[i])
                {
                    return "IMPOSSIBLE";
                }
            }

            List<string> answer = new List<string>();
            for (int i = 0; i < N; i++)
            {
                for (int j = N; j >= 1; j--)
                {
                    if ((chestTypes[j] > 0) && CanRemove(j))
                    {
                        answer.Add(j.ToString() + " ");
                        RemoveChest(j);
                        break;
                    }
                    else if (j == 1)
                    {
                        return "IMPOSSIBLE";
                    }
                }
            }
            StringBuilder result = new StringBuilder(String.Empty);
            for (int i = answer.Count - 1; i >= 0; i--)
            {
                result.Append(answer[i]);
            }
            return result.ToString().Trim();
        }

        public GCJ2013_0D()
        {
            char[] sep = { ' ' };
            Init();
            int T = Int32.Parse(reader.ReadLine());
            for (int i = 0; i < T; i++)
            {
                Clear();
                string[] s = reader.ReadLine().Split(sep);
                K = Int32.Parse(s[0]);
                N = Int32.Parse(s[1]);
                s = reader.ReadLine().Split(sep);
                for (int j = 0; j < K; j++) keys[Int32.Parse(s[j])]++;
                for (int j = 1; j <= N; j++)
                {
                    s = reader.ReadLine().Split(sep);
                    chestTypes[j] = Int32.Parse(s[0]);
                    locks[chestTypes[j]]++;
                    K = Int32.Parse(s[1]);
                    for (int k = 0; k < K; k++)
                    {
                        int keyType = Int32.Parse(s[k + 2]);
                        chestKeys[j][keyType]++;
                        keys[keyType]++;
                    }
                }
                string result = Solve();
                writer.WriteLine(String.Format("Case #{0}: {1}", (i + 1), result));
            }

            reader.Close();
            writer.Close();
        }

        static void Main(string[] args)
        {
            new GCJ2013_0D();
        }
    }
}
