using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace CodeJamContest
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream("S:\\B-small-attempt3.in", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs);
            int count = int.Parse(sr.ReadLine());

            FileStream fs2 = new FileStream("S:\\B-small-attempt3.out", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fs2);

            string line = string.Empty;
            string xline = string.Empty;
            string yline = string.Empty;

            int j = 0;

            int x = 0;
            int y = 0;

            if (!sr.EndOfStream)
            {
                while (count > 0)
                {
                    string[] st = sr.ReadLine().Split(' ');
                    x = int.Parse(st[0]);
                    y = int.Parse(st[1]);

                    if (x > 0)
                    {
                        while (x > 0)
                        {
                            xline += "EW";
                            x--;
                        }
                        xline = xline.Remove(xline.Length - 1, 1);
                    }
                    else if(x<0)
                    {
                        while (x < 0)
                        {
                            xline += "WE";
                                x++;
                        }
                        xline = xline.Remove(xline.Length - 1, 1);
                    }



                    if (y > 0)
                    {
                        while (y > 0)
                        {
                            yline += "SN";
                            y--;
                        }
                        
                    }
                    else if(y<0)
                    {
                        while (y < 0)
                        {
                            yline += "NS";
                            y++;
                        }
                       
                    }

                    



                    j++;
                    line = string.Empty;
                    line += "Case #" + j + ": " + xline + yline;

                    sw.WriteLine(line);
                    xline = string.Empty;
                    yline = string.Empty;
    
                    //line2 = sr.ReadLine();


                    count--;
                }
            }
            sw.Close();
            //sr.Close();
            fs.Close();
            fs2.Close();
        }
    }
}
