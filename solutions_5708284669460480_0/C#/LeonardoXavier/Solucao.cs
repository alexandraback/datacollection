using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace TypewriterMonkey
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-small-attempt1 (2).in";
        public const string OutputFile = @"B-Small2.out";

        private Int32 K, L, S;
        private String Keyboard, Target;
        private Decimal Resultado;
        private Dictionary<char, Int32> _key;


        public override void LerDados()
        {
            var inteiros = ProximoInteiros();
            K = inteiros[0];
            L = inteiros[1];
            S = inteiros[2];

            Keyboard = ProximaLinha();
            Target = ProximaLinha();
        }

        public override void Resolver()
        {

            _key = Keyboard.GroupBy(pX => pX).ToDictionary(pX => pX.Key, pX => pX.Count());
            if (Target.Any(pX => !_key.ContainsKey(pX)))
            {
                return;
            }
            var rec = L;
            for (int x = 1; x < L; x++)
            {
                if (Target.EndsWith(Target.Substring(0, x)))
                    rec = L - x;
            }

            var sobra = (S - L);

            var qtd = 1 + (sobra / rec);

            Decimal prob = 1;
            foreach (var letra in Target)
            {
                prob *= _key[letra] / (Decimal)K;
            }

            var r = qtd*prob;

            Resultado = qtd - r;

        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resultado.ToString("0.0000000", CultureInfo.GetCultureInfo("en-US")));
        }
    }
}
