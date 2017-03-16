using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Mirror
{
    class program
    {
        public static int offset = 60;
        public static int[,] positions = new int[200, 200];
        public static char[,] map = new char[100, 100];
        public static int height = 0, width = 0, dist = 0;

        public static void Main()
        {

            string[] lines = funcs.getInputDocs(@"D-small-attempt1.in");
            List<string> newlines = new List<string>();
            int size = int.Parse(lines[0]);
            int num = 1, linenum = -1;
            int p_x = 0, p_y = 0;

            for (int i = 1; i < lines.Length; i++)
            {
                string thisline = lines[i];                               
                if (linenum == -1)
                {
                    string[] words = thisline.Split(' ');
                    height = int.Parse(words[0]); width = int.Parse(words[1]); dist = int.Parse(words[2]);
                    linenum++;
                }
                else
                {
                    for (int j = 0; j < width; j++)
                    {
                        map[linenum, j] = thisline[j];
                        if (thisline[j] == 'X')
                        {
                            p_x = linenum; p_y = j;
                        }
                    }
                    
                    linenum++;
                    if (linenum == height)
                    {
                        int value = judge(p_x, p_y);
                        newlines.Add("Case #" + num.ToString() + ": " + value.ToString());
                        num++;
                        linenum = -1;
                    }
                }                
            }
            funcs.WriteLines(@"D-small-attempt1.out", newlines);
        }



        public static int judge(int p_x, int p_y)
        {
            List<double> climb = new List<double>();
            List<int> posneg = new List<int>();
            

            for (int i = 0; i < 200; i++)
                for (int j = 0; j < 200; j++)
                    positions[i, j] = 0;

            positions[p_x + offset, p_y + offset] = 2;
            //Detection within distance.
            int countnum = 0;
            for (int x = p_x - dist; x <= p_x + dist; x++)
                for (int y = p_y - dist; y <= p_y + dist; y++)                
                    if ((cal_dist(p_x, p_y, x, y) != 0) && (cal_dist(p_x, p_y, x, y) <= dist))
                    {
                        if ((p_x == x) || (p_y == y))
                        {
                            if (!(((p_x == x) && (Math.Abs(p_y - y) > 1)) || ((Math.Abs(p_x - x) > 1) && (p_y == y))))
                            {
                                positions[x + offset, y + offset] = 1;
                                countnum++;
                            }
                        }
                        else
                        {
                            double value = ((double)y - (double)(p_y)) / ((double)x - (double)(p_x));
                            int ext = Math.Sign(y - p_y);
                            int flag = 0;

                            for (int i = 0; i < climb.Count; i++)
                                if ((Same(climb[i], value)) && (posneg[i] == ext))
                                {
                                    flag = 1; break;
                                }
                            if (flag == 0)
                            {
                                positions[x + offset, y + offset] = 1;
                                countnum++;
                                climb.Add(value); posneg.Add(ext);
                            }
                        }
                    }                          
            
            int counter = 0;
            for (int x = p_x - dist; x <= p_x + dist; x++)            
                for (int y = p_y - dist; y <= p_y + dist; y++)
                    if (positions[x + offset, y + offset] == 1)
                    {
                        double x2 = p_x + 0.5, y2 = p_y + 0.5;
                        double destx = x + 0.5, desty = y + 0.5;
                        if (Simulate(x2, y2, destx, desty))
                        {
                            counter++;                            
                        }
                        else { }                            
                    }  
            return counter;
        }

        public static bool Simulate(double x2, double y2, double destx, double desty)
        {
            double miles = 0;
            double xdire = destx - x2, ydire = desty - y2;
            double xnow = x2, ynow = y2;
            
            while (miles < dist)
            {
                //If Integer...
                double xtarget = XTarget(xnow, xdire);
                double ytarget = YTarget(ynow, ydire);

                double[] reaching = DecideReach(xnow, ynow, xtarget, ytarget, xdire, ydire);
                double xreach = reaching[0], yreach = reaching[1];                
                if ((JudgeDest(xnow, ynow, xreach, yreach, x2, y2)) && (miles != 0))
                {
                    miles = miles + cal_dist(xnow, ynow, x2, y2);
                    if (dist - miles >= -0.000001)
                        return true;
                    else
                        return false;
                }

                //Now Calculating the Direction according to xreach, yreach, xdire, ydire.
                double[] newdire = CalculateDirection(xreach, yreach, xdire, ydire);
                miles = miles + cal_dist(xnow, ynow, xreach, yreach);
                
                xnow = xreach; ynow = yreach;
                xdire = newdire[0]; ydire = newdire[1];
                //Console.WriteLine(xdire + " " + ydire);
                if ((xdire == 9999)&&(ydire == 9999)) return false; //DIE               
            }
            return false;
        }

        public static double[] CalculateDirection(double xnode, double ynode, double xdire, double ydire)
        {
            int xd = Math.Sign(xdire); int yd = Math.Sign(ydire);
            double[] dires = new double[2];
            dires[0] = xdire; dires[1] = ydire;
            int xm = (int)Math.Round(xnode), ym = (int)Math.Round(ynode);

            if ((Same(xnode, Math.Round(xnode))) && (Same(ynode, Math.Round(ynode))))
            {
                //OK. First Phase.                
                if ((xd == -1) && (yd == -1))
                {
                    if (map[xm - 1, ym - 1] != '#') return dires;  //Directly.
                    else
                    {
                        if (map[xm, ym - 1] == '#') dires[1] = -dires[1];
                        if (map[xm - 1, ym] == '#') dires[0] = -dires[0];
                        if ((map[xm, ym] != '#') && (map[xm, ym - 1] != '#')) { dires[0] = 9999; dires[1] = 9999; }
                        return dires;
                    }
                }

                if ((xd == -1) && (yd == 1))
                {
                    if (map[xm - 1, ym] != '#') return dires;  //Directly.
                    else
                    {
                        if (map[xm, ym] == '#') dires[1] = -dires[1];
                        if (map[xm - 1, ym - 1] == '#') dires[0] = -dires[0];
                        if ((map[xm, ym] != '#') && (map[xm - 1, ym - 1] != '#')) { dires[0] = 9999; dires[1] = 9999; }
                        return dires;
                    }
                }

                if ((xd == 1) && (yd == -1))  //right
                {
                    if (map[xm, ym - 1] != '#') return dires;  //Directly.
                    else
                    {
                        if (map[xm - 1, ym - 1] == '#') dires[1] = -dires[1];
                        if (map[xm, ym] == '#') dires[0] = -dires[0];
                        if ((map[xm, ym] != '#') && (map[xm - 1, ym - 1] != '#')) { dires[0] = 9999; dires[1] = 9999; }
                        return dires;
                    }
                }

                if ((xd == 1) && (yd == 1))
                {
                    if (map[xm, ym] != '#') return dires;  //Directly.
                    else
                    {
                        if (map[xm - 1, ym] == '#') dires[1] = -dires[1];
                        if (map[xm, ym - 1] == '#') dires[0] = -dires[0];
                        if ((map[xm - 1, ym] != '#') && (map[xm, ym - 1] != '#')) { dires[0] = 9999; dires[1] = 9999; }
                        return dires;
                    }
                }
            }
            else
            {
                if (Same(xnode, (double)Math.Round(xnode)))
                {
                    //X Direction reached, y doesn't.
                    if (xd == -1)
                    {
                        if (map[(int)Math.Round(xnode) - 1, (int)Math.Floor(ynode)] == '#')
                            dires[0] = -dires[0];
                    }
                    else
                    {
                        if (map[(int)Math.Round(xnode), (int)Math.Floor(ynode)] == '#')
                            dires[0] = -dires[0];
                    }
                }
                else
                {
                    if (yd == -1)
                    {
                        if (map[(int)Math.Floor(xnode), (int)Math.Round(ynode) - 1] == '#')
                            dires[1] = -dires[1];
                    }
                    else
                    {
                        if (map[(int)Math.Floor(xnode), (int)Math.Round(ynode)] == '#')
                            dires[1] = -dires[1];
                    }
                }
                    
            }
            return dires;
        }

        public static bool JudgeDest(double xt, double yt, double xr, double yr, double xfin, double yfin)
        {
            if (((xfin >= xt) && (xfin <= xr) || (xfin >= xr) && (xfin <= xt)) && 
                ((yfin >= yt) && (yfin <= yr) || (yfin >= yr) && (yfin <= yt)))
            {
                if (Same(xt, xr))
                    return true;
                if (Same(yt, yr)) 
                    return true;
                double slope1 = (xr - xt) / (yr - yt);
                double slope2 = (xfin - xt) / (yfin - yt);
                if (Same(slope1, slope2)) return true;
            }
            return false;
        }

        public static double[] DecideReach(double xnow, double ynow, double xtarget, double ytarget, double xdire, double ydire)
        {
            double[] pair = new double[2];

            if ((Same(xnow, xtarget)) || (Same(ynow, ytarget)))
            {
                pair[0] = xtarget; pair[1] = ytarget;
            }
            else
            {
                double prx = Math.Abs(xtarget - xnow) / Math.Abs(xdire);
                double pry = Math.Abs(ytarget - ynow) / Math.Abs(ydire);

                if (prx < pry)
                {
                    pair[0] = xtarget; pair[1] = ynow + ydire * prx;
                }
                else
                {
                    pair[0] = xnow + xdire * pry; pair[1] = ytarget;
                }
            }           

            return pair;
        }

        public static double XTarget(double xnow, double xdire)
        {
            if (Math.Sign(xdire) == 0) return xnow;
            if (Same(xnow, (double)(int)Math.Round(xnow)))
                return xnow + Math.Sign(xdire);
            else
                if (Math.Sign(xdire) == 1) return Math.Ceiling(xnow); else return Math.Floor(xnow);
        }

        public static double YTarget(double ynow, double ydire)
        {
            if (Math.Sign(ydire) == 0) return ynow;
            if (Same(ynow, (double)(int)Math.Round(ynow)))
                return ynow + Math.Sign(ydire);
            else
                if (Math.Sign(ydire) == 1) return Math.Ceiling(ynow); else return Math.Floor(ynow);
                
        }

        public static double cal_dist(int x1, int y1, int x2, int y2)
        {
            return Math.Sqrt(Math.Pow((double)x1 - (double)x2, 2) + Math.Pow((double)y1 - (double)y2, 2));        
        }

        public static double cal_dist(double x1, double y1, double x2, double y2)
        {
            return Math.Sqrt(Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y2, 2));
        }

        public static bool Same(double x1, double x2)
        {
            if ((x1 - x2 >= -0.00001) && (x1 - x2 <= 0.00001)) return true;
            if ((x2 - x1 >= -0.00001) && (x2 - x1 <= 0.00001)) return true;
            return false;
        }

    }
}
