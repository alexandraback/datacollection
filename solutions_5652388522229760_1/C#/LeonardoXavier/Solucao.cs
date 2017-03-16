using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;


namespace A_CountingSheep
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-large.in";
        public const string OutputFile = @"A-large.out";

        private BigInteger _inicial;
        private long _qtd = 0;
        private BigInteger _numero;
        public override void LerDados()
        {
            _inicial = ProximoBigInteger();
        }

        public override void Resolver()
        {
            HashSet<char> _caracteres = new HashSet<char>();
            if (_inicial == 0)
            {
                _qtd = -1;
                return;
            }

            BigInteger atual = 1;
            while (_caracteres.Count != 10)
            {
                _qtd++;
                _numero = _inicial*atual++;
                foreach (var c in _numero.ToString())
                    _caracteres.Add(c);
            }

        }

        public override void EscreverResposta()
        {
            if (_qtd < 0)
                Out.WriteLine("INSOMNIA");
            else
                Out.WriteLine(_numero);
        }
    }
}
