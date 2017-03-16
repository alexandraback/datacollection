using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Brattleship
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-small-attempt0 (3).in";
        public const string OutputFile = @"A_Small.out";

        private Int32 R, W, C, Resultado = 0;

        public override void LerDados()
        {
            var numeros = ProximoInteiros();
            R = numeros[0];
            C = numeros[1];
            W = numeros[2];
        }

        public override void Resolver()
        {
            var t = (C/W)*R;
            t += W;
            if (C%W == 0)
                t -= 1;
            Resultado = t;

        }

        public override void EscreverResposta()
        {
            Out.WriteLine(Resultado);
        }
    }
}
