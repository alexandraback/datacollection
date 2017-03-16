using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace NewLotteryGame
{
    class Calc
    {
        private int limitVal1;
        private int limitVal2;
        private int limitCatalina;

        public Calc(int limitVal1, int limitVal2, int limitCatalina)
        {
            // TODO: Complete member initialization
            this.limitVal1 = limitVal1;
            this.limitVal2 = limitVal2;
            this.limitCatalina = limitCatalina;
        }
        internal int Calculate()
        {
            //Dictionary<Tuple<int, int>, bool> vals = new Dictionary<Tuple<int, int>, bool>();
            //bool[] vals = new bool[1000];
            //Dictionary<Tuple<int, int>, bool> founds = new Dictionary<Tuple<int, int>, bool>();
            int resu = 0;
            for (int c1=0;c1<limitVal1;++c1)
            {
                for (int c2=0;c2<limitVal2;++c2)
                {
                    int val = c1 & c2;
                    if (val < limitCatalina)
                        ++resu;
                        //vals[new Tuple<int, int>(c1, c2)] = true;
                }
            }
            //int resu = 0;
            //int max = Math.Min(vals.Count(), limitCatalina);
            //for (int i = 0; i < max; ++i)
            //    if (vals[i])
            //        ++resu;
            return resu;
            //return vals.Count();
        }
    }
}
