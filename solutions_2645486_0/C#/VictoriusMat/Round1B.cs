using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam._2013
{
    public class Round1B : Exercicio
    {
        public string resolveLinhas(string[] linhas)
        {
            var valores = linhas[0].Split(' ');
            var energia = Convert.ToInt32(valores[0]);
            var regain = Convert.ToInt32(valores[1]);
            var numAtividades = Convert.ToInt32(valores[2]);
            var atividades = new List<int>();
            foreach (var atividade in linhas[1].Split(' '))
                atividades.Add(Convert.ToInt32(atividade));

            var max = getMax(energia, energia, regain, atividades);

            return max.ToString();
        }

        private int getMax(int energia, int max, int regain, IEnumerable<int> atividades)
        {
            if (regain >= max)
                return atividades.Sum(e => max * e);

            int[] ganho = new int[energia+1];
            for (int i = 0; i <= energia; i++)
                if (atividades.Count() > 1){
                    var enresult = energia - i + regain;
                    if (enresult > max)
                        enresult = max;
                    ganho[i] = i * atividades.First() + getMax(enresult, max, regain,
                        atividades.Skip(1));
                }
                else{
                    ganho[i] = i * atividades.First();
                }

            return ganho.Max();
        }
    }
}
