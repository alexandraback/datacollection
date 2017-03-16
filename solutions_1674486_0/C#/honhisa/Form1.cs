using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;

namespace _1
{
    public partial class Form1 : Form
    {
        private const int nThreads = 2;

        private event EventHandler ThreadFinish;
        List<Thread> threads = new List<Thread>();

        private int T;
        private int curr;

        private String[][] param;

        public Form1()
        {
            InitializeComponent();

            textBox1.Select(1024, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ThreadFinish += new EventHandler(ThreadFinished);

            // Input
            FileStream infs = new FileStream(textBox1.Text, FileMode.Open);
            FileStream outfs = new FileStream(textBox1.Text + ".out", FileMode.Create);
            StreamReader sr = new StreamReader(infs, Encoding.GetEncoding(932));
            StreamWriter sw = new StreamWriter(outfs, Encoding.GetEncoding(932));
            String line;

            line = sr.ReadLine();
            T = int.Parse(line);
            curr = 0;

            param = new String[T][];
            for (int i = 0; i<T; i++)
            {
                String N = sr.ReadLine();
                int nN = int.Parse( N );
                param[i] = new String[nN + 1];
                for (int j = 0; j < nN; j++) param[i][j] = sr.ReadLine();
            }

            // スレッド発動
            for (int i = 0; i < nThreads; i++ )
            {
                ThreadFinish(null, null);
                Thread.Sleep(500);
            }

            // 終了判定
            while (true)
            {
                bool bFinished = true;
                foreach (Thread th in threads)
                {
                    if ( th.IsAlive ) bFinished = false;
                }
                if (bFinished) break;
                Thread.Sleep(500);
            }

            for (int i=0; i<T; i++)
            {
                int iResult = param[i].Length - 1;
                sw.WriteLine("Case #" + (i + 1).ToString() + ": " + param[i][iResult]);
            }

            sw.Close(); outfs.Close();
            sr.Close(); infs.Close();

            MessageBox.Show( "Finished" );
        }

        private void ThreadFinished(object sender, EventArgs e)
        {
            int iNext = curr++;
            if (T <= iNext) return;

            ParameterizedThreadStart ts = new ParameterizedThreadStart(Work);
            Thread th = new Thread(ts);
            th.Start(param[iNext]);
            threads.Add( th );
        }

        private void Work(Object obj)
        {
            String[] param = (String[])obj;
            String[] line; // 各行のパラメータ分離用

            int nClasses = param.Length - 1;
            int[][] cls = new int[nClasses][];

            for (int i = 0; i < nClasses; i++ )
            {
                line = param[i].Split(' ');
                int nSub = int.Parse(line[0]);

                cls[i] = new int[nSub];
                for (int j = 0; j < nSub; j++ )
                {
                    cls[i][j] = int.Parse(line[j+1]) - 1;
                }
            }

            bool bFound = false;
            for (int i = 0; i < nClasses; i++ )
            {
                if ( 1 < cls[i].Length )
                {
                    int[] counter = new int[nClasses];
                    for (int j=0; j<nClasses; j++) counter[j] = 0;

                    for (int j = 0; j < cls[i].Length; j++)
                    {
                        count_path( cls, cls[i][j], counter );
                    }

                    for (int j = 0; j < nClasses; j++)
                    {
                        if (1 < counter[j])
                        {
                            bFound = true;
                            break;
                        }
                    }

                    if ( bFound ) break;
                }
            }

            // 解
            param[nClasses] = (bFound) ? "Yes" : "No";

            ThreadFinish(this, null);
        }

        private void count_path(int[][] cls, int from, int[] counter)
        {
            counter[from]++;
            for (int i = 0; i < cls[from].Length; i++ )
            {
                count_path( cls, cls[from][i], counter );
            }
        }
    }
}
