using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;


namespace CounterCulture
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-large (2).in";
        public const string OutputFile = @"A-Large.out";

        private Int64 N = 0;
        private Int64 Resposta;

        public override void LerDados()
        {
            N = ProximoLong();
        }

        public override void Resolver()
        {
            var texto = N.ToString();
            if (N < 21)
            {
                Resposta = N;
                return;
            }
            var ini = ObterBase(texto.Length - 1);
            Int32 metade = texto.Length/2;
            var arr = texto.Substring(0, metade).ToArray();
            Array.Reverse(arr);
            var segunda = texto.Substring(metade);
            var primeira = new string(arr);
            var p1 = Int32.Parse(primeira);
            var p2 = Int32.Parse(segunda);

            var qtd = 0;
            if (p1 != 1 && p2== 0)
            {
                N -= 1;
                texto = N.ToString();
                metade = texto.Length / 2;
                arr = texto.Substring(0, metade).ToArray();
                Array.Reverse(arr);
                segunda = texto.Substring(metade);
                primeira = new string(arr);
                p1 = Int32.Parse(primeira);
                p2 = Int32.Parse(segunda);
                qtd++;
            }
            if (p1 != 1)
                qtd += p1;
            qtd += p2;
            Resposta = qtd + ini;
        }

        public long ObterBase(Int32 pTamanho)
        {
            if (pTamanho == 1)
                return 10;
            var x = pTamanho / 2;
            var b1 = 0;
            for (int y = 0; y < x; y++)
            {
                b1 = b1 * 10 + 9;
            }
            var b2 = b1;
            if (pTamanho % 2 == 1)
            {
                b2 = b2 * 10 + 9;
            }
            return b1 + b2 + 1 + ObterBase(pTamanho - 1);
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resposta);
        }
    }
}
