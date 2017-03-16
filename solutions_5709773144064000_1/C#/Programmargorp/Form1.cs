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
            for (int x = 1; x <= length; x++)
            {
                string[] data = read[x].Split(' ');
                decimal cost=Convert.ToDecimal( data[0]);
                decimal perfarm=Convert.ToDecimal( data[1]);
                decimal win=Convert.ToDecimal( data[2]);
                decimal current = 2;
                
                decimal timetotal = 0;
                decimal t1 = time1(win, current);
                decimal t2 = time2(cost, perfarm, win, current);
                while (t2 < t1)
                {
                    timetotal += (cost / current);
                    current = current + perfarm;
                    t1 = time1(win, current);
                    t2 = time2(cost, perfarm, win, current);
                }
                timetotal = timetotal + t1;
                if (Convert.ToInt32(timetotal) != timetotal)
                {
                    richTextBox2.Text = richTextBox2.Text + "Case #" + Convert.ToString(x) + ": " + Convert.ToString(timetotal) + "\n";
                }
                else
                {
                    richTextBox2.Text = richTextBox2.Text + "Case #" + Convert.ToString(x) + ": " + Convert.ToString(timetotal) + "000000\n";
                }
            }
        }
        public decimal time1(decimal x, decimal current)
        {
            decimal time=0;
            time = x / current;
            return time;
        }
        public decimal time2(decimal cost, decimal perfarm, decimal x, decimal current)
        {
            decimal time = 0;
            time = (cost / current) + (x / (current + perfarm));
            return time;
        }
    }
}
