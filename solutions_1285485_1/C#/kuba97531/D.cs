using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Solvers
{
    class D : AbstractSolver
    {
        protected override object Solve(System.IO.StreamReader input)
        {
            int h = NextInt();
            int w = NextInt();

            int d = NextInt();

            RP start = null;

            char[,] map = new char[h, w];
            for (int i = 0; i < h; i++)
            {
                String line = NextLine();
                for (int j = 0; j < w; j++)
                {
                    map[i, j] = line[j];
                    if (line[j] == 'X')
                    {
                        start = new RP() { x = new R(2 * i + 1, 2), y = new R(2 * j + 1, 2) };
                    }
                }
            }

            int successes = 0;

            if (playRay(1, 0, start, d, map)) successes++;
            if (playRay(-1, 0, start, d, map)) successes++;
            if (playRay(0, 1, start, d, map)) successes++;
            if (playRay(0, -1, start, d, map)) successes++;

            for (int x = -50; x <= 50; x++)
            {
                for (int y = -50; y <= 50; y++)
                {
                    if (x * y != 0 && GCD(x, y) == 1)
                    {
                      if (playRay(x, y, start, d, map)) successes++;
                    }
                }
            }

                return successes;
        }

        bool playRay(int xs, int ys, RP start, int d, char[,] map)
        {
            R speed_x = (xs == 0) ? new R(0) : new R(1, xs);
            R speed_y = (ys == 0) ? new R(0) : new R(1, ys);

            RP speed = new RP() { x = speed_x, y =speed_y };

            Ray r = new Ray() { position = new RP(start), speed = speed, distanceToLive = d };

            while (true)
            {
                r.ping(map);
                r.moveInTime(r.timeToTheNextIntegerPosition());
                if (!r.stillAlive())
                {
                    //Console.WriteLine("failure!");
                    return false;
                }
                if (r.arrivedHome(start))
                {
                    //Console.WriteLine("success!");
                    return true;
                }
            }
        }

        class Ray
        {
            public RP position;
            public RP speed;
            public R timeFromHome = new R(0);

            public int distanceToLive;

            public void ping(char[,] map)
            {
                int nextX = (position.x + speed.x / 100).ToInt();
                int nextY = (position.y + speed.y / 100).ToInt();
                int prevX = (position.x - speed.x / 100).ToInt();
                int prevY = (position.y - speed.y / 100).ToInt();

                Func<int, int, bool> isBlocked = (x, y) => map[x, y] == '#';
                
                if (isBlocked(nextX, nextY))
                {
                    //jesli oba ukosy zablokowane
                    if (!isBlocked(nextX, prevY) && !isBlocked(prevX, nextY))
                    {
                        //Console.WriteLine("Die");
                        distanceToLive = 0; //die
                    }
                    else if (isBlocked(nextX, prevY) && isBlocked(prevX, nextY))
                    {
                        ///Console.WriteLine("Ping total");
                        speed.x = -speed.x;
                        speed.y = -speed.y;
                    }
                    else if (isBlocked(nextX, prevY) && !isBlocked(prevX, nextY))
                    {
                       // Console.WriteLine("Ping x");
                        speed.x = -speed.x;
                    }
                    else if (!isBlocked(nextX, prevY) && isBlocked(prevX, nextY))
                    {
                       // Console.WriteLine("Ping y");
                        speed.y = -speed.y;
                    }
                    else
                    {
                        throw new Exception("Impossibru!");
                    }
                }
            }

            public bool stillAlive()
            {
                R x = speed.x * timeFromHome;
                R y = speed.y * timeFromHome;
                //Console.WriteLine("speed " + speed.x + "," +speed.y+ " time " + timeFromHome);
                return x * x + y * y <= new R(distanceToLive * distanceToLive); //daj tu mniejsze rowne
            }

            public void moveInTime(R time)
            {
                position.x = position.x + speed.x * time;
                position.y = position.y + speed.y * time;
                timeFromHome = timeFromHome + time;
            }

            public bool arrivedHome(RP start)
            {
                return position == start;
            }

            public R timeToTheNextIntegerPosition()
            {
                R xd = position.x.DistanceToNextHalf(speed.x);
                R yd = position.y.DistanceToNextHalf(speed.y);
                return xd < yd ? xd : yd;

            }

            public override string ToString()
            {
                return string.Format("at ({0},{1}) with ({2}, {3})", position.x, position.y, speed.x, speed.y);
            }
        }

        //rational point
        class RP
        {
            public RP() { }
            public RP(RP other) { this.x = other.x; this.y = other.y; }
            public R x;
            public R y;
            public static bool operator ==(RP first, RP other)
            {
                return first.x == other.x && first.y == other.y;
            }

            public static bool operator !=(RP first, RP other)
            {
                return !(first == other);
            }

        }

        //rational
        class R
        {
            public int Up;
            public int Down;
            public R(int i)
            {
                Up = i; Down = 1;
            }
            public R(int up, int down)
            {
                if (down < 0)
                {
                    up = -up;
                    down = -down;
                }
                Up = up;
                Down = down;
                fix();
            }

            public R DistanceToNextInt(R speed)
            {
                if (speed.Up == 0) return new R(1000000000);

                if (Up % Down == 0) return new R(1) / speed.Abs();

                if (speed.Up > 0)
                {
                    return new R((Down - Up % Down) % Down, Down) / speed;
                }
                else
                {
                    return new R((Down + Up % Down) % Down, Down) / -speed;
                }
            }

            public bool isInteger
            {
                get { return Down == 1; }
            }

            public R DistanceToNextHalf(R speed)
            {
                return new R(Up * 2, Down).DistanceToNextInt(speed * new R(2));
            }

            public R Abs()
            {
                return new R(Math.Abs(this.Up), this.Down);
            }

            public static bool operator ==(R first, R other)
            {
                return first.Up == other.Up && first.Down == other.Down;
            }

            public static bool operator !=(R first, R other)
            {
                return !(first == other);
            }

            public static R operator +(R first, R second)
            {
                return new R(first.Up * second.Down + first.Down * second.Up, first.Down * second.Down);
            }

            public static R operator *(R first, R second)
            {
                return new R(first.Up * second.Up, first.Down * second.Down);
            }

            public static R operator *(R first, int x)
            {
                return new R(first.Up * x, first.Down);
            }

            public static R operator /(R first, int x)
            {
                return new R(first.Up, first.Down * x);
            }

            public static R operator /(R first, R second)
            {
                return new R(first.Up * second.Down, first.Down * second.Up);
            }

            public static R operator -(R first, R second)
            {
                return new R(first.Up * second.Down - first.Down * second.Up, first.Down * second.Down);
            }

            public static bool operator <(R first, R second)
            {
                return first.Up * second.Down < first.Down * second.Up;
            }

            public static bool operator >(R first, R second)
            {
                return first.Up * second.Down > first.Down * second.Up;
            }

            public static bool operator <=(R first, R second)
            {
                return first.Up * second.Down <= first.Down * second.Up;
            }

            public static bool operator >=(R first, R second)
            {
                return first.Up * second.Down >= first.Down * second.Up;
            }

            public static R operator -(R first)
            {
                return new R(-first.Up, first.Down);
            }

            private void fix()
            {
                if (Up == 0) Down = 1;
                if (Down == 0) throw new Exception("Divide by zero!");
                int g = GCD(Up, Down);
                Up /= g;
                Down /= g;
            }

            public int ToInt()
            {
                return Up / Down;
            }

            public bool IsPositive
            {
                get { return Up > 0; }
            }

            public override string ToString()
            {
                if (Down == 1) return Up.ToString();
                return string.Format("{0}/{1}", Up, Down);
            }


        }

        private static int GCD(int a, int b)
        {
            if (a < 0) a = -a;
            if (b < 0) b = -b;
            if (b == 0) return a;
            return GCD(b, a % b);
        }
    }

}
