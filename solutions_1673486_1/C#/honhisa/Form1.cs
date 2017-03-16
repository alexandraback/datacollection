using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace _1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            textBox1.Select(1024, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // Input
            FileStream infs = new FileStream(textBox1.Text, FileMode.Open);
            FileStream outfs = new FileStream(textBox1.Text + ".out", FileMode.Create);
            StreamReader sr = new StreamReader(infs, Encoding.GetEncoding(932));
            StreamWriter sw = new StreamWriter(outfs, Encoding.GetEncoding(932));
            String line;

            line = sr.ReadLine();
            int T = int.Parse(line);

            for (int i = 1; i <= T; i++)
            {
                line = sr.ReadLine();
                String[] Params = line.Split(' ');
                int nInput = int.Parse(Params[0]);
                int nPswd  = int.Parse(Params[1]);

                line = sr.ReadLine();
                Params = line.Split(' ');
                double[] percentages = new double[Params.Length];
                for ( int j=0; j<Params.Length; j++ )
                {
                    percentages[j] = double.Parse( Params[j] );
                }

                double result = nPswd + 2;
                for (int nBksp=0; nBksp<=nInput; nBksp++)
                {
                    int nStrOK = nPswd - nInput + 2 * nBksp + 1;
                    int nStrNG = nStrOK + nPswd + 1;

                    int nOK = nInput - nBksp;
                    double perOK = 1.0;
                    for ( int j=0; j<nOK; j++ ) perOK *= percentages[j];
                    double perNG = 1.0 - perOK;

                    double Expected = nStrOK * perOK + nStrNG * perNG;

                    if (Expected < result) result = Expected;
                }
                

                sw.WriteLine("Case #" + i.ToString() + ": " + result.ToString("F6"));
            }
            sw.Close(); outfs.Close();
            sr.Close(); infs.Close();

            MessageBox.Show( "Finished" );
        }
    }
}
