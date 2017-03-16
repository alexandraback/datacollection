using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace OminousOmino
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"D-large.in";
        public const string OutputFile = @"D-Large.out";


        public Int32 X, R, C;

        private bool _possivel;

        public override void LerDados()
        {
            var numeros = ProximoInteiros();
            X = numeros[0];
            R = numeros[1];
            C = numeros[2];
        }

        public override void Resolver()
        {
            if (X > 6)
                return;
            var minimo = X / 2 + X % 2;
            if (X > 3)
                minimo++;
            if (R < minimo || C < minimo)
                return;
            _possivel = R * C % X == 0;
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(_possivel ? "GABRIEL" : "RICHARD");
        }
    }
}
