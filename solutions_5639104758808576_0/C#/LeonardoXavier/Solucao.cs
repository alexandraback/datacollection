using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Classificacao
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-small-attempt0.in";
        public const string OutputFile = @"A-small.out";


        private Int32[] _pessoas;
        private long _convidados;

        public override void LerDados()
        {
            var partes = ProximaLinha().Split();
            _pessoas = new int[Int32.Parse(partes[0]) + 1];
            for (int x = 0; x < _pessoas.Length; x++)
            {
                _pessoas[x] = Int32.Parse(partes[1].Substring(x, 1));
            }
        }

        public override void Resolver()
        {
            var disponivel = 0;
            _convidados = 0;
            for (int x = 0; x < _pessoas.Length; x++)
            {
                disponivel += _pessoas[x];
                if (x >= disponivel)
                {
                    var novos = x - disponivel + 1;
                    _convidados += novos;
                    disponivel += novos;
                }
            }
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(_convidados);
        }
    }
}
