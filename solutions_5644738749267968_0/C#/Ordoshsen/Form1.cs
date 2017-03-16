using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (StreamReader sr = new StreamReader(@"D-small-attempt0.in", true))
            {
                int T = Convert.ToInt32(sr.ReadLine());
                for (int i = 1; i <= T; i++)
                {
                    int N = Convert.ToInt32(sr.ReadLine());
                    double[] n = new double[N];
                    double[] k = new double[N];

                    string s = sr.ReadLine();
                    s = s.Replace(".", ",");
                    string[] nums = s.Split(' ');
                    for (int j=0;j<N;j++)
                        n[j] = Convert.ToDouble(nums[j]);
                    Array.Sort(n);

                    s = sr.ReadLine();
                    s = s.Replace(".", ",");
                    string[] nums2 = s.Split(' ');
                    for (int j = 0; j < N; j++)
                        k[j] = Convert.ToDouble(nums2[j]);
                    Array.Sort(k);

                    int y = 0;
                    int z = 0;
                    int hn = N-1;
                    int hk = N - 1;

                    for (int j = 0; j < N; j++)
                    {
                        if (n[hn] < k[hk])
                        {
                            hn--;
                            hk--;
                        }
                        else
                        {
                            hn--;
                            y++;
                        }
                    }

                    hn = N - 1;
                    hk = N - 1;
                    int dn = 0;
                    int dk = 0;

                    for (int j = 0; j < N; j++)
                    {
                        if (n[dn] > k[dk])
                        {
                            dn++;
                            dk++;
                            z++;
                        }
                        else
                        {
                            dn++;
                        }
                    }

                    using (StreamWriter sw = new StreamWriter(@"D-small-attempt0.out", true))
                    {
                        sw.WriteLine("Case #" + i + ": " + z + " " + y);
                    }
                }
            }
        }
    }
}
