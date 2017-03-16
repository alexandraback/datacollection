using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace A
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-small-attempt1.in";
        public const string OutputFile = @"A-small1.out";


        public Palavra[] Palavras { get; set; }

        public Int32 N { get; set; }

        public String Resposta { get; set; }

        public override void LerDados()
        {
            N = ProximoInteiro();
            Palavras = new Palavra[N];
            for (int x = 0; x < N; x++)
            {
                Palavras[x] = new Palavra(ProximaLinha());
            }
        }

        public override void Resolver()
        {
            for (int x = 1; x < N; x++)
            {
                if (System.String.CompareOrdinal(Palavras[0].Sequencia, Palavras[x].Sequencia) != 0)
                {
                    Resposta = "Fegla Won";
                    return;
                }
            }
            Int64 total = 0;
            for (int x = 0; x < Palavras[0].Repeticoes.Count; x++)
            {
                Int32 acoes = Int32.MaxValue;
                var max = Palavras.Max(pX => pX.Repeticoes[x]);
                for (int y = 1; y <= max; y++)
                {
                    var a = Palavras.Sum(pX => Math.Abs(pX.Repeticoes[x] - y));
                    if (a < acoes)
                        acoes = a;
                }
                total += acoes;
            }
            Resposta = total.ToString();
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resposta);
        }
    }
}
