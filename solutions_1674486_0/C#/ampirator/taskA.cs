using System.Collections.Generic;
using System.IO;

namespace GCJPractice
{
    public class taskA
    {
        private const string inFile = @"D:\MyDocuments\Visual Studio 2010\Projects\GCJPractice\GCJPractice\in.txt";
        private const string outFile = @"D:\MyDocuments\Visual Studio 2010\Projects\GCJPractice\GCJPractice\out.txt";
        private int n;
        private int[][] pt;

        public void SolveTask()
        {
            Prepare();
        }

       

        void Prepare()
        {
            StreamReader r = new StreamReader(inFile);
            StreamWriter w = new StreamWriter(outFile);
            
            n = int.Parse(r.ReadLine());
        
            for (int i = 0; i < n; i++)
            {
                var nn = int.Parse(r.ReadLine());
                pt = new int[nn][];
                
//                var pt = new List<int>();
                for (int j = 0; j < nn; j++)
                {
                    var s = r.ReadLine();
                    var strs = s.Split();
                    int k = int.Parse(strs[0]);
                    pt[j] = new int[nn];

                    for (int jj = 0; jj < k; jj++)
                    {
                        var v = int.Parse(strs[jj + 1]);
                        pt[j][v-1] = 1;
                    }
                }

                string result = Solve(pt, nn);

                w.WriteLine(string.Format("Case #{0}: {1}", i + 1, result));
            }
            r.Close();
            w.Close();
        }

        private int counter;
        string Solve(int [][] pt, int n)
        {
            const string resYes = "Yes";
            const string resNo = "No";

            for (int i = 0; i < n; i++ )
            {
                 for(int j= 0; j <n; j++)
                 {
                     if(i != j)
                     {
                         counter = 0;
                        deikstra(i, j, n);
                        if (counter > 1)
                            return resYes;
                     }
                 }
            }

            return resNo;
        }

        private void deikstra(int a, int b, int n)
        {
            
            for (int ii = 0; ii < n; ii++)
            {
                if(pt[a][ii] == 1)
                {
                    if(ii == b)
                    {
                        counter ++;
                    }
                    else
                    {
                        deikstra(ii, b, n);
                    }

                }
            }
        }


    }
}