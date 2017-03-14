using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Round1D_Mirrors
    {
        char WALL = '#';
        char[][] grid = new char[30][];
        int startx = 0, starty = 0;
        int h, w, maxdist;
        

        public Round1D_Mirrors(){

            StreamReader reader = new StreamReader("D-small-attempt1.in");
            StreamWriter writer = File.CreateText("D-small-attempt1.out");

            string s = reader.ReadLine();
            int t = Int32.Parse(s);
            int i,j,k;
            char[] delim = { ' ' };
            string[] tokens;
            for (i = 1; i <= t; i++)
            {
                tokens = reader.ReadLine().Split(delim);
                h = Int32.Parse(tokens[0]);
                w = Int32.Parse(tokens[1]);
                maxdist = Int32.Parse(tokens[2]);
                for (j = 0; j < h; j++)
                {
                    grid[j] = reader.ReadLine().ToCharArray();
                    for (k = 0; k < w; k++)
                    {
                        if (grid[j][k] == 'X')
                        {
                            startx = k;
                            starty = j;
                            grid[j][k] = '.';
                            break;
                        }
                    }
                }
                writer.WriteLine("Case #" + i + ": " + Solve());
                //writer.WriteLine("Case #" + i + ": " + SolveBasic());
            }
            reader.Close();
            writer.Close();
        }

        private int SolveBasic()
        {
            int stepx = w * 2, stepy = h * 2;
            int result = 0;
            if ((startx) * 2 - 1 <= maxdist) result++;
            if ((starty) * 2 - 1 <= maxdist) result++;
            if ((w - startx) * 2 - 3 <= maxdist) result++;
            if ((h - starty) * 2 - 3 <= maxdist) result++;
            result += SolveBasic2((startx) * 2 - 1, (h - starty) * 2 - 3, stepx, stepy);
            result += SolveBasic2((startx) * 2 - 1, (starty) * 2 - 1, stepx, stepy);
            result += SolveBasic2((w - startx) * 2 - 3, (starty), stepx, stepy);
            result += SolveBasic2((w - startx) * 2 - 3, (h - starty) * 2 - 3, stepx, stepy);
            result += 2 * SolveBasic2((startx) * 2 - 1, stepy, stepx, stepy);
            result += 2 * SolveBasic2(stepx, (starty) * 2 - 1, stepx, stepy);
            result += 2 * SolveBasic2((w - startx) * 2 - 3, stepy, stepx, stepy);
            result += 2 * SolveBasic2(stepx, (h - starty) * 2 - 3, stepx, stepy);
            result += 4 * SolveBasic2(stepx, stepy, stepx, stepy);
            return result;
        }

        private int SolveBasic2(int basex, int basey, int stepx, int stepy)
        {
            int count = 0;
            for (int i = basex; i <= maxdist; i+=stepx)
            {
                for (int j = basey; j <= maxdist; j += stepy)
                {
                    if (PythagoreanGreater(i, j, maxdist)) break;
                    else count++;
                }
            }
            return count;
        }

        private int Solve()
        {
            int stepx, stepy;
            int count = 0;
            // horizontal and vertical
            count += WalkHV();
            // 45deg diagonals
            count += Walk4(1, 1);
            for (stepx = 1; stepx < maxdist; stepx++)
            {
                for (stepy = stepx+1; stepy < maxdist; stepy++)
                {
                    if (PythagoreanGreater(stepx, stepy, maxdist)) break;
                    else if (Gcd(stepx, stepy) > 1) continue;
                    else
                    {
                        count += Walk4(stepx, stepy);
                        count += Walk4(stepy, stepx);
                    }
                }
            }
            return count;
        }

        private int WalkHV()
        {
            int count = 0;
            int d, p;
            for (p = startx + 1, d = 1; p < w; p++, d += 2)
            {
                if (grid[starty][p] == WALL) break;
            }
            if (d <= maxdist) count++;
            for (p = startx - 1, d = 1; p > 0; p--, d += 2)
            {
                if (grid[starty][p] == WALL) break;
            }
            if (d <= maxdist) count++;
            for (p = starty + 1, d = 1; p < h; p++, d += 2)
            {
                if (grid[p][startx] == WALL) break;
            }
            if (d <= maxdist) count++;
            for (p = starty - 1, d = 1; p > 0; p--, d += 2)
            {
                if (grid[p][startx] == WALL) break;
            }
            if (d <= maxdist) count++;

            return count;
        }

        private int Walk4(int stepx, int stepy)
        {
            int count = 0;
            if (Walk(1, 1, stepy, stepx)) count++;
            if (Walk(1, -1, stepy, stepx)) count++;
            if (Walk(-1, 1, stepy, stepx)) count++;
            if (Walk(-1, -1, stepy, stepx)) count++;
            return count;
        }

        private bool Walk(int directionx, int directiony, int denomx, int denomy)
        {
            int posx = startx;
            int posy = starty;
            int dirx = directionx;
            int diry = directiony;
            int subx = 0;
            int suby = 0;
            int subdist = 0;
            int toedgex, toedgey;
            int jump;
            while (true)
            {
                // back to starting cell
                if ((posx == startx) && (posy == starty) && (subdist > 0))
                {
                    if (subx * dirx == suby * diry)
                    {
                        subdist += Math.Abs(subx);
                        return !(PythagoreanGreater(subdist * denomx, subdist * denomy, maxdist * denomx * denomy * 2));
                    }
                }

                // move across cell
                toedgex = denomx - (subx * dirx);
                toedgey = denomy - (suby * diry);
                jump = (toedgex < toedgey) ? toedgex : toedgey;
                subx += (dirx * jump);
                suby += (diry * jump);
                subdist += jump;

                // determine next cell and direction

                // running into corner of cell
                if ((Math.Abs(subx) == denomx) && (Math.Abs(suby) == denomy))
                {
                    // running into an opposing corner
                    if (grid[posy + diry][posx + dirx] == WALL)
                    {
                        if (grid[posy][posx + dirx] == WALL)
                        {
                            // 180 Reflecting corner
                            if (grid[posy + diry][posx] == WALL)
                            {
                                subdist *= 2;
                                return !(PythagoreanGreater(subdist * denomx, subdist * denomy, maxdist * denomx * denomy * 2));
                            }
                            // X-reflect
                            else
                            {
                                //posx = posx;
                                posy = posy + diry;
                                //subx = subx;
                                suby = -suby;
                                dirx = -dirx;
                                //diry = diry;
                            }
                        }
                        // Y-reflect
                        else if (grid[posy + diry][posx] == WALL)
                        {
                            posx = posx + dirx;
                            //posy = posy;
                            subx = -subx;
                            //suby = suby;
                            //dirx = dirx;
                            diry = -diry;
                        }
                        // Destruction
                        else
                        {
                            return false;
                        }
                    }
                    // Pass through corner
                    else
                    {
                        posx = posx + dirx;
                        posy = posy + diry;
                        subx = -subx;
                        suby = -suby;
                        //dirx = dirx;
                        //diry = diry;
                    }
                }
                else if (Math.Abs(subx) == denomx)
                {
                    // X-reflect
                    if (grid[posy][posx + dirx] == WALL)
                    {
                        //posx = posx;
                        //posy = posy;
                        //subx = subx;
                        //suby = suby;
                        dirx = -dirx;
                        //diry = diry;
                    }
                    // Moving along
                    else
                    {
                        posx = posx + dirx;
                        //posy = posy;
                        subx = -subx;
                        //suby = suby;
                        //dirx = dirx;
                        //diry = diry;
                    }
                }
                else if (Math.Abs(suby) == denomy)
                {
                    // Y-reflect
                    if (grid[posy + diry][posx] == WALL)
                    {
                        //posx = posx;
                        //posy = posy;
                        //subx = subx;
                        //suby = suby;
                        //dirx = dirx;
                        diry = -diry;
                    }
                    // Moving along
                    else
                    {
                        //posx = posx;
                        posy = posy + diry;
                        //subx = -subx;
                        suby = -suby;
                        //dirx = dirx;
                        //diry = diry;
                    }
                }
                if (PythagoreanGreater(subdist * denomx, subdist * denomy, maxdist * denomx * denomy * 2)) break;
            }
            return false;
        }

        private bool PythagoreanGreater(int x, int y, int z)
        {
            long a = x, b = y, c = z;
            return ((a * a) + (b * b) > (c * c));
        }

        private int Gcd(int x, int y)
        {
            int a, b, c;
            if ((x <= 0) || (y <= 0)) return 0;
            a = x;
            b = y;
            c = a % b;
            while (c > 0)
            {
                a = b;
                b = c;
                c = a % b;
            }
            return b;
        }
    }
}
