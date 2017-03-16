using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D_War
{
    public class Jogo
    {

        private Int32 _id;

        private Double[]  _naomi;

        private Double[] _ken;

        private static CultureInfo _cultura = CultureInfo.GetCultureInfo("en-US");

        public Jogo(Int32 pId, String[] pDados)
        {
            _id = pId;
            _naomi = pDados[1].Split().Select(pX => Convert.ToDouble(pX, _cultura)).OrderByDescending(pX => pX).ToArray();
            _ken = pDados[2].Split().Select(pX => Convert.ToDouble(pX, _cultura)).OrderByDescending(pX => pX).ToArray();
        }

        public void Processar()
        {
            Resultado = ProcessarInterno();
        }

        private String ProcessarInterno()
        {
            var p1 = PontuacaoDeceitful();
            var p2 = PontuacaoNormal();

            return Resultado = String.Format("Case #{0}: {1} {2}", _id, p1, p2);
        }

        private Int32 PontuacaoDeceitful()
        {
            var naomi = new LinkedList<Double>(_naomi);
            var ken = new LinkedList<Double>(_ken);
            Int32 pontuacao = 0;
            var atual = naomi.First;
            var atualKen = ken.First;

            while (atual != null && atualKen != null)
            {
                if (atual.Value > atualKen.Value)
                {
                    atual = atual.Next;
                    atualKen = atualKen.Next;
                    pontuacao++;
                }
                else
                {
                    atualKen = atualKen.Next;
                    naomi.RemoveLast();
                }
            }

            return pontuacao;
        }

        private Int32 PontuacaoNormal()
        {
            var naomi = new LinkedList<Double>(_naomi);
            var ken = new LinkedList<Double>(_ken);
            Int32 pontuacao = 0;
            while (naomi.Count != 0)
            {
                if (naomi.First.Value < ken.First.Value)
                {
                    naomi.RemoveFirst();
                    ken.RemoveFirst();
                }
                else
                {
                    ken.RemoveLast();
                    naomi.RemoveFirst();
                    pontuacao++;
                }
            }
            return pontuacao;
        }

        public String Resultado { get; set; }
    }
}
