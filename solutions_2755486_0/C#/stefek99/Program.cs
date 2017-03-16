using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace App1Express
{


    class Case
    {
        private int successfulAttacks = 0;
        IDictionary<int, int> wall = new Dictionary<int, int>();
        IDictionary<int, int> addStack;

        IDictionary<int, List<Attack>> dicAttacks = new Dictionary<int, List<Attack>>(); 

        public void solve()
        {
            List<int> listIndices = dicAttacks.Keys.ToList();
            listIndices.Sort();
            foreach (int index in listIndices)
            {
                List<Attack> attacksThatDay = dicAttacks[index];
                addStack = new Dictionary<int, int>(); // resetting stack to add
                foreach (Attack a in attacksThatDay)
                {
                    bool isThisAttackSuccessful = false;
                    //iterate from left to right
                    for (int i = a._w; i < a._e; i++)
                    {
                        if (wall.ContainsKey(i))
                        {
                            if (a._s > wall[i])
                            {
                                isThisAttackSuccessful = true;
                                _AddToStack(i, a._s);
                            }
                        }
                        else
                        {
                            // attack hist cause there is no wall there yet
                            isThisAttackSuccessful = true;
                            _AddToStack(i, a._s);

                        }
                    }

                    if (isThisAttackSuccessful)
                    {
                        successfulAttacks++;
                    }
                }

                //At the end of day we raise wall
                foreach (KeyValuePair<int, int> positionStrenght in addStack)
                {
                    wall[positionStrenght.Key] = positionStrenght.Value;
                }

            }


        }

        private void _AddToStack(int position, int strenght)
        {
            if (addStack.ContainsKey(position))
            {
                if (addStack[position] < strenght) addStack[position] = strenght;
            }
            else
            {
                addStack.Add(position, strenght);
            }
        }

        public double Result { get { return successfulAttacks; } }

        public void AddTribe(int d, int n, int w, int e, int s, int deltaD, int deltaP, int deltaS)
        {
            // Here will attacks
            for (int i = 0; i < n; i++)
            {
                int currentD = d + (i*deltaD);
                int currentE = e + (i*deltaP);
                int currentW = w + (i*deltaP);
                int currentS = s + (i*deltaS);

                if (dicAttacks.ContainsKey(currentD))
                {
                    dicAttacks[currentD].Add(new Attack(currentW, currentE, currentS));
                }
                else
                {
                    dicAttacks[currentD] = new List<Attack>{new Attack(currentW, currentE, currentS)};
                }
            }
        }
    }

    class Attack
    {
        public readonly int _w;
        public readonly int _e;
        public readonly int _s;

        public Attack(int w, int e, int s)
        {
            _w = w;
            _e = e;
            _s = s;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            string sLine = Console.ReadLine();
            int nCases = int.Parse(sLine);
            List<Case> listCases = new List<Case>();

            for (int i = 0; i < nCases; i++)
            {
                sLine = Console.ReadLine();
                int nTribes = int.Parse(sLine);
                Case c = new Case();

                for (int j = 0; j < nTribes; j++)
                {
                    sLine = Console.ReadLine();
                    string[] arrStrings = sLine.Split(new char[] {' '});

                    int d = int.Parse(arrStrings[0]);
                    int n = int.Parse(arrStrings[1]);
                    int w = int.Parse(arrStrings[2]);
                    int e = int.Parse(arrStrings[3]);
                    int s = int.Parse(arrStrings[4]);
                    int delta_d = int.Parse(arrStrings[5]);
                    int delta_p = int.Parse(arrStrings[6]);
                    int delta_s = int.Parse(arrStrings[7]);
                    c.AddTribe(d,n,w,e,s,delta_d,delta_p, delta_s);
                }

                listCases.Add(c);

            }

            CultureInfo oColture = CultureInfo.CreateSpecificCulture("en-US");
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\Michal\result.txt"))
            {
                for (int i = 0; i < nCases; i++)
                {
                    Case c = listCases[i];
                    c.solve();
                    Console.WriteLine("Case #" + (i + 1) + ": " + c.Result); 
                    //Console.WriteLine("Case #" + (i + 1) + ": " + c.Result.ToString("N6", oColture)); 
                    //file.WriteLine("Case #" + (i + 1) + ": " + c.Result.ToString("N6", oColture)); 

                }
                Console.ReadLine();
            }

        }
    }
}
