using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace B_RevengeOfThePancakes
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-small-attempt0.in";
        public const string OutputFile = @"B.out";

        private bool[] _dados;
        private bool[] _buffer;
        private long _movimentos = 0;


        public override void LerDados()
        {
            _dados = ProximaLinha().Select(pX => pX == '+').ToArray();
            _buffer = new bool[_dados.Length];
        }

        public override void Resolver()
        {

            for (int x = _dados.Length - 1; x >= 0; x--)
            {
                if (!_dados[x])
                    Organizar(x);
            }
        }

        private void Organizar(int pLimite)
        {
            _movimentos++;
            if (_dados[0])
                InverterInicio(pLimite);

            for (int x = 0; x <= pLimite; x++)
            {
                _buffer[pLimite - x] = !_dados[x];
            }

            for (int x = 0; x <= pLimite; x++)
            {
                _dados[x] = _buffer[x];
            }
        }

        private void InverterInicio(int pLimite)
        {
            _movimentos++;
            for (int x = 0; x <= pLimite; x++)
            {
                if (!_dados[x])
                    break;
                _dados[x] = false;
            }
        }


        public override void EscreverResposta()
        {
            Out.WriteLine(_movimentos);
        }
    }
}
