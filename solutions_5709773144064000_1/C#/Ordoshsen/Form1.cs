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
            

            using (StreamReader sr = new StreamReader(@"B-large.in", true))
            {
                int T = Convert.ToInt32(sr.ReadLine());
                for (int i = 1; i < T+1; i++)
                {
                    double y = 0;
                    double s = 2;
                    string line = sr.ReadLine();
                    line = line.Replace(".",",");
                    string[] lines = line.Split(' ');
                    double c = Convert.ToDouble(lines[0]);
                    double f = Convert.ToDouble(lines[1]);
                    double x = Convert.ToDouble(lines[2]);

                    while (x / s > c / s + x / (s + f))
                    {
                        y += (c / s);
                        s += f;
                    }
                    y += x / s;
                    string magic = Convert.ToString(y);
                    magic = magic.Replace(",", ".");
                    
                    using (StreamWriter sw = new StreamWriter(@"B-large.out", true))
                    {
                        sw.WriteLine("Case #" + i + ": " + magic);
                    }
                }
            }
        }
    }
}
