using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam._2013
{
    public class Round1A : Exercicio
    {
        public string resolveLinhas(string[] linhas)
        {
            var sep = linhas[0].Split(' ');
            var r = Convert.ToInt64(sep[0]);
            var militers = Convert.ToInt64(sep[1]);
            long areaAtual = 0;
            var i = 1;

            militers -= calcArea(i, r);

            while (militers >= (areaAtual = calcArea(2 * (i+1), r)))
            {
                militers -= areaAtual;
                i++;
            }

            return i.ToString();
        }

        private long calcArea(long i, long r)
        {
            return (long)(2 * (r + i) - 2);
        }
    }
}
