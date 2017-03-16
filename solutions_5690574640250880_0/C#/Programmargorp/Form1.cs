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
                string[] temp = read[x].Split(' ');
                int height = Convert.ToInt32(temp[0]);
                int width = Convert.ToInt32(temp[1]);
                int nummines = Convert.ToInt32(temp[2]);
                int numfree = (width * height) - nummines;
                bool[,] free = new bool[width,height];
                bool solvable = false;
                if (nummines == 1&& width>=3&&height>=3)
                {
                    solvable = false;
                }
                if (width == 1 || height == 1)
                {
                    solvable = true;
                }
                else if (width == 2 || height == 2)
                {
                    if (numfree == 1 || (numfree >= 4 && numfree%2==0))
                    {
                        solvable = true;
                    }
                }
                else
                {
                    if (width >= 3 && height >= 3 && (numfree==4||numfree==6||numfree==8||numfree>=9))
                    {
                        solvable = true;
                    }
                }
                if (width >= 3 && height >= 3 && numfree == 1)
                {
                    solvable = false;
                }
                if (nummines == 0)
                {
                    solvable = false;
                }
                if (solvable == true && (width>=3 && height>=3))
                {
                    if ((int)(numfree / 2) == (decimal)numfree/2)
                    {
                        int numpair = numfree / 2;
                        int startx = 0;
                        int starty = 0;
                        int count = 0;
                        while (numpair > 0)
                        {
                            if (starty + 1 < height)
                            {
                                for (int y = startx; y < width && numpair > 0; y++)
                                {
                                    free[y, starty] = true;
                                    free[y, starty + 1] = true;
                                    numpair--;
                                }
                                count++;
                                if (count >= 1)
                                    starty += 2;
                            }
                            for (int y = starty; y < height && numpair > 0; y++)
                            {
                                free[startx, y] = true;
                                free[startx + 1, y] = true;
                                numpair--;
                            }
                            startx += 2;
                        }
                    }
                    else
                    {
                        int numpair = (int)numfree / 2;
                        int numpairx=0;
                        if (numpair > width)
                        {
                            numpairx = width;
                        }
                        else
                        {
                            numpairx = numpair-1;
                        }
                        int numpairy = numpair - numpairx;
                        int startx = 0;
                        int starty = 0;
                        int incx = 0;
                        int incy1 = 0;
                        bool incy = false;
                        while (numpairx > 0 || numpairy>0)
                        {
                            
                            for (int y = startx; y < width && numpairx>0; y++)
                            {
                                free[y, starty] = true;
                                free[y, starty + 1] = true;
                                numpairx--;
                                //if (numpairx == 0)
                                //    incy = true;
                            }
                            for (int y = starty+2; y < height && numpairy>0; y++)
                            {
                                free[startx, y] = true;
                                free[startx + 1, y] = true;
                                numpairy--;
                                incy1 = y;
                                //if (numpairy == 0 && y == height - 1)
                                //{
                                //    incx = 2;
                                //}
                                //else if (numpairy == 0 && startx == 0)
                                //{
                                //    incx = 2;
                                //    incy1 = y - starty;
                                //}
                                //else
                                //{
                                //    incx = 0;
                                //    incy1 = y - starty;
                                //}
                            }
                            if (numpairy > 0)
                            {
                                startx += 2;
                            }
                            if (numpairx > 0)
                            {
                                starty += 2;
                            }
                        }
                        bool xinc = false;
                        if (startx + 2 < width)
                        {
                            startx += 2;
                            xinc = true;
                        }
                        if (incy1 + 1 < height&&xinc==false)
                        {
                            starty = incy1 + 1;
                        }
                        if (starty == 0)
                        {
                            starty += 2;
                        }
                        free[startx, starty] = true;
                    }
                }
                if ((height == 1 || width == 1) && solvable == true)
                {
                    if (height == 1)
                    {
                        for (int y = 0; y < numfree; y++)
                        {
                            free[y, 0] = true;
                        }
                    }
                    else
                    {
                        for (int y = 0; y < numfree; y++)
                        {
                            free[0, y] = true;
                        }
                    }
                }
                if (solvable == true && (height == 2 || width == 2))
                {
                    int numpair = numfree / 2;
                    if (height == 2)
                    {
                        for (int y = 0; y < numpair; y++)
                        {
                            free[y, 0] = true;
                            free[y, 1] = true;
                        }
                    }
                    else
                    {
                        for (int y = 0; y < numpair; y++)
                        {
                            free[0, y] = true;
                            free[1, y] = true;
                        }
                    }
                }
                if (nummines == 0)
                {
                    for (int y = 0; y < width; y++)
                    {
                        for (int z = 0; z < height; z++)
                        {
                            free[y, z] = true;
                        }
                    }
                    solvable = true;
                }
                if (width >= 3 && height >= 3 && numfree == 1)
                {
                    for (int y = 0; y < width; y++)
                    {
                        for (int z = 0; z < height; z++)
                        {
                            free[y, z] = false;
                        }
                    }
                    solvable = true;
                }
                if (nummines == 1 && width>=3 && height>=3)
                {
                    for (int y = 0; y < width; y++)
                    {
                        for (int z = 0; z < height; z++)
                        {
                            free[y, z] = true;
                        }
                    }
                    free[width - 1, height - 1] = false;
                    solvable = true;
                }
                richTextBox2.Text = richTextBox2.Text + "Case #" + Convert.ToString(x) + ":\n";
                if (solvable == false)
                {
                    richTextBox2.Text = richTextBox2.Text + "Impossible\n";
                }
                else
                {
                    richTextBox2.Text = richTextBox2.Text + "c";
                    for (int z = 1; z < width; z++)
                    {
                        if (free[z, 0] == true)
                        {
                            richTextBox2.Text = richTextBox2.Text + ".";
                        }
                        else
                        {
                            richTextBox2.Text = richTextBox2.Text + "*";
                        }
                    }
                    richTextBox2.Text = richTextBox2.Text + "\n";

                    for (int y = 1; y < height; y++)
                    {
                        for (int z = 0; z < width; z++)
                        {
                            if (free[z, y] == true)
                            {
                                richTextBox2.Text = richTextBox2.Text + ".";
                            }
                            else
                            {
                                richTextBox2.Text = richTextBox2.Text + "*";
                            }
                        }
                        richTextBox2.Text = richTextBox2.Text + "\n";
                    }
                }
            }
        }
    }
}
