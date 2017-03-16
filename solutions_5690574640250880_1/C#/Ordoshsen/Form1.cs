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
            using (StreamReader sr = new StreamReader(@"C-large.in", true))
            {
                int T = Convert.ToInt32(sr.ReadLine());
                for (int i = 1; i < T + 1; i++)
                {
                    string line = sr.ReadLine();
                    string[] lines = line.Split(' ');
                    int r = Convert.ToInt32(lines[0]);
                    int c = Convert.ToInt32(lines[1]);
                    int m = Convert.ToInt32(lines[2]);

                    if(r==1 && c ==1)
                            using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                            {
                                sw.WriteLine("Case #" + i + ":");
                                sw.WriteLine("c");
                            }
                    else if(r==1)
                            using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                            {
                                sw.WriteLine("Case #" + i + ":");
                                string magic = "";
                                for (int j = 0; j < m; j++)
                                    magic += "*";
                                for (int j = m; j < c-1; j++)
                                    magic += ".";
                                magic += "c";
                                sw.WriteLine(magic);
                            }
                    else if (c == 1)
                            using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                            {
                                sw.WriteLine("Case #" + i + ":");
                                for (int j = 0; j < m; j++)
                                    sw.WriteLine("*");
                                for (int j = m; j < r-1; j++)
                                    sw.WriteLine(".");
                                sw.WriteLine("c");
                            }
                    else if(c*r-m==1)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                            for(int j=0;j<r;j++)
                            {
                                for(int k=0;k<c-1;k++)
                                    sw.Write("*");
                            if(j!=r-1)
                                sw.WriteLine("*");
                            else
                                sw.WriteLine("c");
                            }
                        }
                    else if (c * r - m < 4)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                            sw.WriteLine("Impossible");
                        }
                    else if(c*r -5 == m)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                            sw.WriteLine("Impossible");
                        }
                    else if(c*r -7 == m)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                            sw.WriteLine("Impossible");
                        }
                    else if ((c == 2 || r == 2) && m % 2 == 1)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                            sw.WriteLine("Impossible");
                        }
                    else if(c==2)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                                for (int j = 0; j < m; j+=2)
                                    sw.WriteLine("**");
                                for (int j = m; j < 2*r-2; j+=2)
                                    sw.WriteLine("..");
                                sw.WriteLine(".c");
                        }
                    else if(r==2)
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            sw.WriteLine("Case #" + i + ":");
                            string magic1 = "";
                            string magic2 = "";
                                for (int j = 0; j < m; j+=2)
                                {
                                    magic1 += "*";
                                    magic2 += "*";
                                }
                                for (int j = m; j < c*2-2; j+=2)
                                {
                                    magic1 += ".";
                                    magic2 += ".";
                                }
                            magic1 += ".";
                            magic2 += "c";
                            sw.WriteLine(magic1);
                            sw.WriteLine(magic2);
                        }
                    else
                        using (StreamWriter sw = new StreamWriter(@"C-large.out", true))
                        {
                            char[,] pole = new char [r,c];
                            for (int j = 0; j < r; j++)
                                for (int k = 0; k < c; k++)
                                    pole[j, k] = '*';

                            pole[0, 0] = 'c';
                            pole[1, 0] = '.';
                            pole[1, 1] = '.';
                            pole[0, 1] = '.';
                            m += 4;

                            if(m!=r*c)
                            {
                                pole[2, 1] = '.';
                                pole[2, 0] = '.';
                                m+=2;
                            }
                            if(m!=r*c)
                            {
                                pole[1, 2] = '.';
                                pole[0, 2] = '.';
                                m+=2;
                            }

                            int R = 3;
                            int C = 3;
                            while(m<=r*c-2 && r!=R)
                            {
                                pole[R, 0] = '.';
                                pole[R, 1] = '.';
                                m += 2;
                                R++;
                            }
                            while (m <= r * c - 2 && c != C)
                            {
                                pole[0, C] = '.';
                                pole[1, C] = '.';
                                m += 2;
                                C++;
                            }
                            C=2;
                            R=2;
                            while (m != c * r)
                            {
                                while (m != c * r && R < r)
                                {
                                    pole[R, C] = '.';
                                    R++;
                                    m++;
                                }
                                C++;
                                R = 2;
                            }
                            sw.WriteLine("Case #" + i + ":");
                            for (int j = 0; j < r; j++)
                            {
                                for (int k = 0; k < c; k++)
                                    sw.Write(pole[j, k]);
                                sw.WriteLine();
                            }
                            

                        }
                }
            }
            MessageBox.Show("Done");
        }
    }
}
