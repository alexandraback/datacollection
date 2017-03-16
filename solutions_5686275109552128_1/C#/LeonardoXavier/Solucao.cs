using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace InfiniteHouseOfPancakes
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"B-large (1).in";
        public const string OutputFile = @"B-large.out";

        private Int32[] _pratos;
        private Int32 _maximo;
        private Int32 _resposta;

        public override void LerDados()
        {
            ProximaLinha();
            _pratos = ProximoInteiros();
            Array.Sort(_pratos, Compare);
            _maximo = _pratos[0];
        }

        public override void Resolver()
        {
            _resposta = _maximo;
            var quantidade = 0;
            var invalido = false;
            for (int x = 1; x < _maximo; x++)
            {
                quantidade = x;
                invalido = false;
                for (int y = 0; y < _pratos.Length; y++)
                {
                    var div = _pratos[y] / x;
                    div -= _pratos[y] % x == 0 ? 1 : 0;
                    quantidade += div;
                    if (quantidade > _resposta)
                    {
                        invalido = true;
                        break;
                    }
                }
                if(invalido)
                    continue;
                _resposta = quantidade;
            }
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(_resposta);
        }

        public int Compare(Int32 x, Int32 y)
        {
            return y.CompareTo(x);
        }
    }
}
