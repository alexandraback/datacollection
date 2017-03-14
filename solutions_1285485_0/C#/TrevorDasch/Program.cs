using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace CodeJamQualA
{
    class Program
    {
        private class Point
        {
            public int x, y;

            public Point(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
            public bool Equals(Point p2){
                return p2.x==x&&p2.y==y;
            }
        }

        private static bool ContainsPoint(Point s, Point e, Point p)
        {
            if ((p.y == s.y || p.y == e.y) && (e.y!=s.y))
                return false;
            if (p.y == s.y && p.y == e.y)
            {
                if (p.x <= e.x && p.x >= s.x)
                    return true;
                if (p.x >= e.x && p.x <= s.x)
                    return true;
                return false;
            }

            double rp = (double)(e.x - p.x) / (double)(e.y - p.y);
            double rs = (double)(e.x - s.x) / (double)(e.y - s.y);
            if (rp == rs)
            {
                if (p.y <= e.y && p.y >= s.y)
                    return true;
                if (p.y >= e.y && p.y <= s.y)
                    return true;
            }
            return false;
        }

        static double Magnitude(Point s, Point e){

            return (Math.Sqrt((double)((s.x - e.x) * (s.x - e.x) + (e.y - s.y) * (e.y - s.y))));
        }


        static void Main(string[] args)
        {
            string countstr = System.Console.ReadLine();
            int count = int.Parse(countstr);

            string outputstr = "";
            for (int i = 0; i < count; i++)
            {
                System.Console.Write("Case #" + (i + 1) + ": " + Process() + "\n");
            }

            //System.Console.WriteLine(outputstr);


        }

        static int H, W, D, x, y;
        static bool[,] grid;

        static string Process()
        {
            string instr = System.Console.ReadLine();
            string[] splstr = instr.Split(" ".ToCharArray());


            H = 2*int.Parse(splstr[0]);

            //Console.WriteLine("H: " + H);
            W = 2*int.Parse(splstr[1]);

            //Console.WriteLine("W: " + W);
            D = 2*int.Parse(splstr[2]);

            //Console.WriteLine("D: " + D);

            
            x = 0; y = 0;
            grid = new bool[W,H];

            for(int i = 0; i<H/2; i++){
                string s = System.Console.ReadLine();
                for(int j = 0; j<s.Length; j++){
                    if(s.Substring(j,1).Equals("#")){
                        grid[j * 2, i * 2] = grid[j * 2+1, i * 2] = grid[j * 2, i * 2+1] = grid[j * 2+1, i * 2+1] = true;
                        
                    }
                    else if (s.Substring(j,1).Equals("X")){
                        x = j*2+1;
                        y = i*2+1;
                    }
                }
            }


            bool[,] grid2 = new bool[D*2 + 2*W, D*2 + 2*H];

            int p = y -1;
            bool even = true;
            while (p < D * 2 + H*2)
            {

                int q = x - 1;
                bool odd = false;
                while(q < D*2 + W*2){

                    grid2[q, p] = true; 
                    if (odd)
                        q += (W  - x-2)*2;
                    else
                        q += (x - 2)*2 ;
                    odd = !odd;
                     
                }
                if (even)
                    p += (H - y-2)*2;
                else
                    p += (y - 2)*2 ;

                even = !even;
            }

            int mx, my;
            mx = my = 0;
            for (int i = D+1; i < D + 2*H; i++)
            {
                for (int j = D+1; j < D + 2*W; j++)
                {
                    if (grid2[j, i])
                    {
                        mx = j;
                        my = i;
                        break;
                    }

                }
                if (mx != 0)
                    break;

            }

            Point m = new Point(mx,my);
            grid2[mx, my] = false;
            int count = 0;

            List<Point> possibilites = new List<Point>();

            for (int i = 0; i < D * 2 + 2*H; i++)
            {
                for (int j = 0; j < D * 2 + 2*W; j++)
                {


                    if (grid2[j, i])
                    {
                        Point np = new Point(j, i);

                        if (Magnitude(m, np) <= D)
                        {
                            possibilites.Add(np);
                        }
                    }
                }


            }

            //Console.WriteLine("M: (" + m.x + "," + m.y + ")\n-----------------------");

            foreach (Point p1 in possibilites)
            {

                bool clear = true;
                foreach (Point p2 in possibilites)
                {
                    if (!p1.Equals(p2))
                    {
                        if (ContainsPoint(m, p1, p2))
                        {

                            clear = false;
                            break;
                        }
                    }
                }
                if (clear)
                {
                    //Console.WriteLine("(" + p1.x + "," + p1.y + ")");
                    count++;

                }
            }
            return count + "";

        }


        static bool RayCastTowardsPointBounce(double ox, double oy, double tx, double ty, bool[,] grid, double D)
        {
            
            double currentPosX = ox;
            double currentPosY = oy;
            double distance = 0;

            if(tx == ox && ty == oy)
                return false;

            if (tx == ox)
            {
                int direction = 1;
                if(ty < oy)
                    direction = -1;
                while (distance <= D)
                {
                    
                    currentPosY += direction;
                    distance += 1;
                    if (grid[(int)tx, (int)currentPosY - (direction<0?1:0)])
                    {
                        direction = -direction;
                    }
                    
                    if (currentPosY == oy && distance <= D)
                        return true;
                }
            }
            else if (ty == oy)
            {
                int direction = 1;
                if (tx < ox)
                    direction = -1;
                while (distance <= D)
                {
                    currentPosX += direction;
                    distance += 1;

                    if (grid[(int)currentPosX - (direction < 0 ? 1 : 0), (int)ty])
                    {
                        direction = -direction;
                    }
                    if (currentPosX == ox && distance <= D)
                        return true;
                }
            }
            else{
                double dirX, dirY;

                dirX = 1;
                dirY = 1;
                if(tx < ox)
                    dirX =-1;
                if(ty < oy)
                    dirY = -1;

                double ratio = Math.Abs((tx - ox) / (ty - oy));

                double deltaY, deltaX;


                while(distance <= D){
                    if (dirX == -1)
                    {
                        deltaX = (currentPosX - (int)currentPosX);
                    }
                    else
                    {
                        deltaX = 1-(currentPosX - (int)currentPosX);
                    }
                    if (deltaX == 0)
                        deltaX = 1;

                    if(dirY == -1)
                    {
                        deltaY = (currentPosY - (int)currentPosY);
                    }
                    else
                    {
                        deltaY = 1 - (currentPosY - (int)currentPosY);
                    }
                    if (deltaY == 0)
                        deltaY = 1;

                    if (ratio * deltaY < deltaX)
                    { // move delta Y;
                        currentPosY += deltaY * dirY;
                        currentPosX += ratio * deltaY * dirX;

                        distance += Math.Sqrt((deltaY*deltaY)*(1+ratio*ratio)); 

                        if (grid[(int)currentPosX,(int)currentPosY - (dirY < 0 ? 1 : 0)])
                        {
                            dirY = -dirY;
                        }

                    }
                    else if (ratio * deltaY > deltaX)
                    {
                        distance += Math.Sqrt((deltaX * deltaX) * (1 + 1 / (ratio * ratio)));

                        currentPosX += deltaX * dirX;
                        currentPosY += dirY * deltaX / ratio;

                        if (grid[(int)currentPosX - (dirX < 0 ? 1 : 0), (int)currentPosY])
                        {
                            dirX = -dirX;
                        }

                    }
                    else
                    {
                        currentPosX += deltaX * dirX;
                        currentPosY += deltaY * dirY;
                        distance += Math.Sqrt((deltaY * deltaY) + (deltaX * deltaX));

                       
                        if (grid[(int)currentPosX - (dirX < 0 ? 1 : 0), (int)currentPosY - (dirY < 0 ? 1 : 0)])
                        {
                            /*
                            Console.WriteLine("Coming into a corner. Directions: " + dirX + "," + dirY);
                            
                            Console.WriteLine("Wall looks like this:");
                            Console.WriteLine((grid[(int)currentPosX - 1, (int)currentPosY - 1] ? "#" : ".") + "" + (grid[(int)currentPosX, (int)currentPosY - 1] ? "#" : "."));
                            Console.WriteLine((grid[(int)currentPosX - 1, (int)currentPosY] ? "#" : ".") + "" + (grid[(int)currentPosX, (int)currentPosY] ? "#" : "."));
                            */


                            bool deadend = true;

                            double tmpdirX = dirX;
                            double tmpdirY = dirY;
                            if (grid[(int)currentPosX - (dirX < 0 ? 1 : 0), (int)currentPosY - (dirY < 0 ? 0 : 1)])
                            {
                                tmpdirX = -dirX;
                                deadend = false;
                            }
                            if (grid[(int)currentPosX - (dirX < 0 ? 0 : 1), (int)currentPosY - (dirY < 0 ? 1 : 0)])
                            {
                                tmpdirY = -dirY;
                                deadend = false;
                            }


                            dirX = tmpdirX;
                            dirY = tmpdirY;
                            /*
                            if (!deadend)
                                Console.WriteLine("Leaving Corner. Directions: " + dirX + "," + dirY);
                            else
                                Console.WriteLine("Died.");
                            */
                            if (deadend)
                                return false;



                        }

                    }

                    if (currentPosY == oy && currentPosX == ox && distance <= D)
                        return true;
                
                }

            }


            return false;
        }



        static double RayCastToPoint(double ox, double oy, double tx, double ty, bool[,] grid, double D)
        {
            if (Math.Sqrt((tx - ox) * (tx - ox) + (ty - oy) * (ty - oy)) > D)
                return -1;
            double currentPosX = ox;
            double currentPosY = oy;
            double distance = 0;

            if (tx == ox && ty == oy)
                return -1;

            if (tx == ox)
            {
                int direction = 1;
                if (ty < oy)
                    direction = -1;
                while (distance <= D)
                {

                    currentPosY += direction;
                    distance += 1;
                    if (grid[(int)tx, (int)currentPosY ])
                    {
                        if (currentPosY == (int)currentPosY)
                        {
                            if ((int)currentPosY == (int)ty)
                                return distance;
                            else
                                return -1;
                        }
                    }
                }
            }
            else if (ty == oy)
            {
                int direction = 1;
                if (tx < ox)
                    direction = -1;
                while (distance <= D)
                {
                    currentPosX += direction;
                    distance += 1;

                    if (grid[(int)currentPosX , (int)ty])
                    {

                        if (currentPosX == (int)currentPosX)
                        {
                            if ((int)currentPosX == tx)
                                return distance;
                            else
                                return -1;
                        }
                    }
                }
            }
            else
            {
                double dirX, dirY;

                dirX = 1;
                dirY = 1;
                if (tx < ox)
                    dirX = -1;
                if (ty < oy)
                    dirY = -1;

                double ratio = Math.Abs((tx - ox) / (ty - oy));

                double deltaY, deltaX;


                for (int i = 1; i <= Math.Abs(ty - oy); i++ )
                {
                    if (ratio * i == (int)(ratio * i))
                    {
                        if (grid[(int)(ox + (int)(ratio * i) * dirX), (int)(oy + i * dirY)])
                        {
                            if (ox + (int)(ratio * i) * dirX == tx && ty == oy + i * dirY)
                            {
                                return (Math.Sqrt((i * i) * (ratio * ratio + 1)));
                            }
                            else
                                return -1;
                        }
                    }
                }
                return -1;

                while (distance <= D)
                {
                    if (dirX == -1)
                    {
                        deltaX = (currentPosX - (int)currentPosX);
                    }
                    else
                    {
                        deltaX = 1 - (currentPosX - (int)currentPosX);
                    }
                    if (deltaX == 0)
                        deltaX = 1;

                    if (dirY == -1)
                    {
                        deltaY = (currentPosY - (int)currentPosY);
                    }
                    else
                    {
                        deltaY = 1 - (currentPosY - (int)currentPosY);
                    }
                    if (deltaY == 0)
                        deltaY = 1;

                    if (ratio * deltaY < deltaX)
                    { // move delta Y;
                        currentPosY += deltaY * dirY;
                        currentPosX += ratio * deltaY * dirX;

                        distance += Math.Sqrt((deltaY * deltaY) * (1 + ratio * ratio));
                        if (distance > D)
                            return -1;

                    }
                    else if (ratio * deltaY > deltaX)
                    {
                        distance += Math.Sqrt((deltaX * deltaX) * (1 + 1 / (ratio * ratio)));
                        if (distance > D)
                            return -1;
                        currentPosX += deltaX * dirX;
                        currentPosY += dirY * deltaX / ratio;

                    }
                    else
                    {
                        currentPosX += deltaX * dirX;
                        currentPosY += deltaY * dirY;
                        distance += Math.Sqrt((deltaY * deltaY) + (deltaX * deltaX));

                        if (distance > D)
                            return -1;

                    }

                    if (grid[(int)(currentPosX + 0.00000000000005), (int)(currentPosY + 0.00000000000005)] && 
                        Math.Abs(currentPosX - (int)(currentPosX + 0.00000000000005)) < 0.00000000000005 &&
                        Math.Abs(currentPosY - (int)(currentPosY + 0.00000000000005)) < 0.00000000000005)
                    {

                        if (Math.Abs(currentPosX - tx) < 0.00000000000005 && Math.Abs(ty - currentPosY) < 0.00000000000005)
                            return distance;
                        else
                            return -1;

                        /*
                        Console.WriteLine("Coming into a corner. Directions: " + dirX + "," + dirY);
                            
                        Console.WriteLine("Wall looks like this:");
                        Console.WriteLine((grid[(int)currentPosX - 1, (int)currentPosY - 1] ? "#" : ".") + "" + (grid[(int)currentPosX, (int)currentPosY - 1] ? "#" : "."));
                        Console.WriteLine((grid[(int)currentPosX - 1, (int)currentPosY] ? "#" : ".") + "" + (grid[(int)currentPosX, (int)currentPosY] ? "#" : "."));
                        */
                    }
                }

            }


            return -1;
        }
/*
        private class Ray2d{
            public double x, y;
            public double u, v;

            public Ray2d(double x, double y, double u, double v)
            {
                this.x = x;
                this.y = y;
                this.u = u;
                this.v = v;
            }

            public double Magnitude(){
                return Math.Sqrt((u - x) * (u - x) + (v - y) * (v - y));
            }

            public double Angle()
            {
                return (Math.Atan2(v - y, u - x) + (v-y<0&&u-x<0?Math.PI:0) + 2 * Math.PI)% (2*Math.PI);
            }

            public bool SameRay(Ray2d r2)
            {
                if (this.x == r2.x && this.y == r2.y)
                {
                    if (v == 0 && r2.v == 0)
                    {
                        if (u == 0 && r2.u == 0)
                            return true;
                        if (u / Math.Abs(u) == r2.u / Math.Abs(u))
                            return true;
                        return false;
                    }
                    if (u / v == r2.u / r2.v)
                    {
                        if (v / Math.Abs(v) == r2.v / Math.Abs(v))
                            return true;
                    }
                }

                return false;
            }

        

        }


        Ray2d GetReflectionSurface(int px, int py, int dirX, int dirY)
        {
            if (grid[(int)px - (dirX < 0 ? 1 : 0), (int)py - (dirY < 0 ? 1 : 0)])
            {


                bool a = false, b = false; ;

                if (grid[(int)px - (dirX < 0 ? 1 : 0), (int)py - (dirY < 0 ? 0 : 1)])
                {
                    a = true;
                }
                if (grid[(int)px- (dirX < 0 ? 0 : 1), (int)py - (dirY < 0 ? 1 : 0)])
                {
                    b = true;
                }


                if (a == b)
                {
                    return new Ray2d(px, py, 0, 0);
                }
                return new Ray2d(px, py, px + (a ? 1 : 0), py + (b ? 1 : 0));

            }
            return null;
        }

        bool RaysContain(Ray2d r1, Ray2d r2, Ray2d newRay)
        {

            double angle1, angle2, angle3;
            angle1 = r1.Angle();
            angle2 = newRay.Angle();
            angle3 = r2.Angle();
            if( angle1 > angle3)
                angle3+=Math.PI*2;
            if(angle1 > angle2)
                angle2+=Math.PI*2;
            return( angle1 <= angle2 && angle2 <= angle3 && newRay.Magnitude() <= D);

        }


        int ExpandVision(int cx, int cy, Ray2d r1, Ray2d r2, List<Ray2d> Illegals)
        {
            int count = 0;
            Ray2d originCast = new Ray2d(cx, cy, x, y);
            if(RaysContain(r1,r2,originCast)){
                bool good = true;
                foreach(Ray2d il in Illegals){
                    if(il.SameRay(originCast)){
                        good = false;
                        break;
                    }
                }
                if (good)
                {
                    count++;
                    Illegals.Add(originCast);
                }
            }

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Ray2d nr = new Ray2d(cx, cy, j, i);
                    if (RaysContain(r1, r2, nr))
                    {

                    }

                }

            }



return 0;

        }


        
*/

    }
}
