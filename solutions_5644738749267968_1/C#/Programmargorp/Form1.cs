using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Magic_Trick
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string input = richTextBox1.Text;
            string [] read = input.Split('\n');
            int length = Convert.ToInt32(read[0]);
            int counter = 0;
            for (int x = 1; x < read.Length ; x+=3)
            {
                counter++;
                int numblock = Convert.ToInt32(read[x]);
                string[] temp = read[x + 1].Split(' ');
                decimal[] naomi = new decimal[numblock];
                for (int y = 0; y < numblock; y++)
                {
                    naomi[y] = Convert.ToDecimal(temp[y]);
                }
                temp = read[x + 2].Split(' ');
                decimal[] ken = new decimal[numblock];
                for (int y = 0; y < numblock; y++)
                {
                    ken[y] = Convert.ToDecimal(temp[y]);
                }
                Array.Sort(naomi);
                Array.Sort(ken);

                temp = read[x + 1].Split(' ');
                decimal[] naomi1 = new decimal[numblock];
                for (int y = 0; y < numblock; y++)
                {
                    naomi1[y] = Convert.ToDecimal(temp[y]);
                }
                temp = read[x + 2].Split(' ');
                decimal[] ken1 = new decimal[numblock];
                for (int y = 0; y < numblock; y++)
                {
                    ken1[y] = Convert.ToDecimal(temp[y]);
                }
                Array.Sort(naomi1);
                Array.Sort(ken1);

                int warscore = 0;
                for (int y = numblock-1; y >= 0; y--)
                {
                    if (naomi[y] > ken[y])
                    {
                        naomi[y] = 0;
                        ken[0] = 0;
                        for (int z = 0; z < ken.Length - 1; z++)
                        {
                            ken[z] = ken[z + 1];
                        }
                        warscore++;
                    }
                    else if (naomi[y] < ken[y])
                    {
                        int z = 0;
                        while (naomi[y] > ken[z])
                        {
                            z++;
                        }
                        naomi[y] = 0;
                        ken[z] = 0;
                        for (int a = z; a < ken.Length - 1; a++)
                        {
                            ken[a] = ken[a + 1];
                        }
                    }
                }
                bool satasfied = true;
                for (int y = 0; y < naomi1.Length; y++)
                {
                    if (naomi1[y] < ken1[y])
                    {
                        satasfied = false;
                    }
                }
                bool scorezero = false;
                while (satasfied == false)
                {
                    satasfied = true;
                    for (int y = 0; y < naomi1.Length; y++)
                    {
                        if (naomi1[y] < ken1[y])
                        {
                            satasfied = false;
                        }
                    }
                    if (satasfied == false)
                    {
                        naomi1[0] = 0;
                        ken1[ken1.Length-1] = 0;
                        for (int z = 0; z < naomi1.Length - 1; z++)
                        {
                            naomi1[z] = naomi1[z + 1];
                        }
                        if (naomi1.Length > 1)
                        {
                            Array.Resize(ref naomi1, naomi1.Length - 1);
                            Array.Resize(ref ken1, ken1.Length - 1);
                        }
                        else
                        {
                            scorezero = true;
                            satasfied = true;
                        }
                    }
                }
                int deceitscore = 0;
                if (scorezero == false)
                {
                    deceitscore = naomi1.Length;
                }
                richTextBox2.Text = richTextBox2.Text + "Case #" + Convert.ToString(counter) + ": " + deceitscore + " " + warscore + "\n";
            }
        }
    }
}
