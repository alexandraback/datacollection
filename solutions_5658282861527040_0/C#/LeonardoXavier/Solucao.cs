using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace B
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-small-attempt0.in";
        public const string OutputFile = @"B-Small.out";

        public Int32 A { get; set; }

        public Int32 B { get; set; }

        public Int32 K { get; set; }


        public String Resultado { get; set; }

        public override void LerDados()
        {
            var inteiros = ProximoInteiros();
            A = inteiros[0];

            B = inteiros[1];

            K = inteiros[2];
        }

        public override void Resolver()
        {
            Int32 qtd = 0;
            for (int x = 0; x < A; x++)
            {
                for (int y = 0; y < B; y++)
                {
                    if ((x & y) < K)
                        qtd++;
                }
            }
            Resultado = qtd.ToString();
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resultado);
        }
    }
}
