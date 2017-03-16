/* C# Program
 * Google Code Jam 2012
 * Qualification Round
 * Problem D. Hall of Mirrors
 * 
 * Copyright Craig Maher - 2012
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Diagnostics;

namespace CodeJamQR12PD {
    class Program {
        static void Main(string[] args) {
            //files
            StreamReader input;
            StreamWriter output;
            input = new StreamReader("D-small-attempt0.in");
            output = new StreamWriter("D-small-attempt0.out");

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string outString;
            for (int i = 1; i <= TestCases; ++i) {
                outString = Process(input);
                output.WriteLine("Case #{0}: {1}", i, outString);
                Console.WriteLine("Case #{0}: {1}", i, outString);
            }

            input.Close();
            output.Close();


            Console.ReadLine();
        }

        private static string Process(StreamReader input) {
            string info = input.ReadLine();
            string[] numbers = info.Split(' ');
            int H = int.Parse(numbers[0]);
            int W = int.Parse(numbers[1]);
            int D = int.Parse(numbers[2]);
            char[][] hallOfMirrors = new char[H][];
            int count = 0;

            //'#', '.', or 'X'
            for (int i = 0; i < H; ++i) {
                
                hallOfMirrors[i] = input.ReadLine().ToCharArray();
                
            }
            //find position of x
            int posX = -1;
            int posY = -1;
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    if (hallOfMirrors[i][j] == 'X') {
                        posX = j;
                        posY = i;
                        break;
                    }
                }
            }
            //loop through angles
            //using gradiant
            //theory is that the gradient should be able to hit a spot that is a round number before fog is to heavy, a round number in this case I believe is half a unit.
            //I was thinking this means D*2 but I realised D as half the distance is spent returning
            //since I want half a unit accuracy I have scaled everything
            double distanceTraveled = 0;
            
            
            int TargetPosX;
            int TargetPosY;
            double lightPosX, lightPosY;
            int startX, startY;

            //double newLisgtPosX, newLisgtPosY;
            double oldLightPosX, oldLightPosY;

            int iterations;

            int momentumX, momentumY;

            bool cont = true;

            double DirectionX = 0;
            double DirectionY = 0;
            for (int i = -D; i <= D; ++i) {
                for (int j = -D; j <= D; ++j) {
                    //if angle is able to be simplified it should be skipped
                    if (!CanSimplify(i, j) && (j != 0 || i != 0))
                    {

                        //TestCode
                        if (info == "11 24 36" && j == 1 && i == 2)
                        {
                            int sdjka = 234;
                        }
                        
                        lightPosX = posX * 2 + 1;
                        lightPosY = posY * 2 + 1;
                        momentumX = i;
                        momentumY = j;
                        distanceTraveled = 0;
                        if (Math.Abs(i) >= Math.Abs(j))
                        {
                            DirectionX = i / Math.Abs(i);
                            DirectionY = (double)j / Math.Abs(i);
                            iterations = Math.Abs(i);
                        }
                        else
                        {
                            DirectionY = j / Math.Abs(j);
                            DirectionX = (double)i / Math.Abs(j);
                            iterations = Math.Abs(j);
                        }
                        cont = true;
                        do
                        {
                            TargetPosX = (int)lightPosX + momentumX;
                            TargetPosY = (int)lightPosY + momentumY;
                            //travel to target and detect mirrors and change target if nessesarry
                            //startX = (int)lightPosX;
                            //startY = (int)lightPosY;
                            //double traveledX = Math.Abs(momentumX);
                            //double traveledY = Math.Abs(momentumY);
                            for (int k = 0; k < iterations && cont; k++)
                            {
                                oldLightPosX = lightPosX;
                                oldLightPosY = lightPosY;
                                lightPosX += DirectionX;
                                lightPosY += DirectionY;

                                if (k == iterations - 1)
                                {
                                    lightPosX = TargetPosX;
                                    lightPosY = TargetPosY;
                                }
                                //traveledX -= Math.Abs(DirectionX);
                                //traveledY -= Math.Abs(DirectionY);
                                //check for collision on 
                                if (hallOfMirrors[(int)lightPosY / 2][(int)lightPosX / 2] == '#')
                                {
                                    bool conti = true;

                                    //check if collision on y or x
                                    if (hallOfMirrors[(int)oldLightPosY / 2][(int)lightPosX / 2] == '#')
                                    {
                                    
                                        //what to do
                                        DirectionX *= -1;//change direction
                                        momentumX *= -1; //change momentum

                                        int wall = InBetween(lightPosX, oldLightPosX);
                                        //change target
                                        TargetPosX = wall - (TargetPosX - wall);
                                        
                                        //change position
                                        //lightPosX = wall + Math.Abs(lightPosX - wall) * momentumX / Math.Abs(momentumX);
                                        lightPosX = wall - (lightPosX - wall);
                                        
                                    }
                                    else if (hallOfMirrors[(int)lightPosY / 2][(int)oldLightPosX / 2] != '#')
                                    {
                                        if (lightPosY % 2 == 0 && lightPosX % 2 == 0)
                                        {
                                            cont = false;
                                        }
                                        else
                                        {
                                            conti = false;
                                            //check if x or y intersects their wall first
                                            int wallX = InBetween(lightPosX, oldLightPosX);
                                            int wally = InBetween(lightPosY, oldLightPosY);
                                            //check if x or y intersects first
                                            if ((wallX - oldLightPosX) / DirectionX < (wally - oldLightPosY) / DirectionY)
                                            {
                                                DirectionX *= -1;//change direction
                                                momentumX *= -1; //change momentum

                                                int wall = InBetween(lightPosX, oldLightPosX);
                                                //change target
                                                TargetPosX = wall - (TargetPosX - wall);

                                                //change position
                                                //lightPosX = wall + Math.Abs(lightPosX - wall) * momentumX / Math.Abs(momentumX);
                                                lightPosX = wall - (lightPosX - wall);
                                            }
                                            else
                                            {
                                                int wall = InBetween(lightPosY, oldLightPosY);

                                                DirectionY *= -1;//change direction
                                                momentumY *= -1; //change momentum


                                                //change target
                                                TargetPosY = wall - (TargetPosY - wall);

                                                //change position
                                                //lightPosX = wall + Math.Abs(lightPosX - wall) * momentumX / Math.Abs(momentumX);
                                                lightPosY = wall - (lightPosY - wall);
                                                
                                            }
                                            
                                            
                                            
                                        }
                                    }

                                    if (conti && hallOfMirrors[(int)lightPosY / 2][(int)oldLightPosX / 2] == '#')
                                    {
                                    
                                        int wall = InBetween(lightPosY, oldLightPosY);

                                        //if (hallOfMirrors[(int)wall / 2][(int)oldLightPosX / 2] == '#' || hallOfMirrors[(wall-1) / 2][(int)oldLightPosX / 2] == '#')

                                        DirectionY *= -1;//change direction
                                        momentumY *= -1; //change momentum

                                        
                                        //change target
                                        TargetPosY = wall - (TargetPosY - wall);

                                        //change position
                                        //lightPosX = wall + Math.Abs(lightPosX - wall) * momentumX / Math.Abs(momentumX);
                                        lightPosY = wall - (lightPosY - wall);
                                        
                                        
                                    }
                                    
                                    
                                }
                            }
                            distanceTraveled++;
                            lightPosX = TargetPosX;//update to make sure accurate
                            lightPosY = TargetPosY;//update to make sure accurate
                            //check if reflection has reached user
                            if (TargetPosX == posX * 2 + 1 && TargetPosY == posY * 2 + 1)
                            {
                                if (Math.Sqrt(Math.Pow(distanceTraveled, 2) * (Math.Pow(i, 2) + Math.Pow(j, 2))) <= D * 2)
                                {
                                    count++;
                                }
                                break;
                            }

                            //once at target destination check mirrors corner, mirrors edge
                            //trace path of light and go to next if light path is too long.
                            //once at target destination check if distance Traveled is too long
                        } while (Math.Sqrt(Math.Pow(distanceTraveled, 2) * (Math.Pow(i, 2) + Math.Pow(j, 2))) < D * 2 && cont);//keeps a very accurate record of distance travelled, but could be slightly more efficient if I checked that there was enough distance left to get home
                        
                    }
                }
            }

            return count.ToString();
        }

        static bool CanSimplify(int numberA, int numberB)
        {
            int gcd = GCD(Math.Abs(numberA), Math.Abs(numberB));
            return gcd != 1;
        }
        static void Simplify(ref int numberA, ref int numberB)
        {
            int gcd = GCD(Math.Abs(numberA),Math.Abs(numberB));
            numberA /= gcd;
            numberB /= gcd;
        }
        static int GCD(int a, int b)
        {
            while (b > 0)
            {
                int rem = a % b;
                a = b;
                b = rem;
            }
            return a;
        }

        static int InBetween(double A, double B)
        {
            if (B > A)
            {
                return (int)B;
            }
            return (int)A;
            
        }

    }
}
