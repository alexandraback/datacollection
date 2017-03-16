using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MoreProblems
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"C-small-attempt1 (1).in";
        public const string OutputFile = @"C-small2.out";


        private Int64 C, D, V;
        private List<Int32> _valores;
        private Int32 resposta = 0;

        public override void LerDados()
        {
            var x = ProximoInteiros();
            C = x[0];
            D = x[1];
            V = x[2];
            _valores = new List<int>(ProximoInteiros());
        }

        public override void Resolver()
        {
            for (int x = 1; x < V; x++)
            {
                if(_valores.Contains(x))
                    continue;
                if (Validar(x, _valores.Where(pX => pX < x).OrderBy(pX => pX).ToList(), 0))
                    continue;
                _valores.Add(x);
                resposta++;
            }
        }

        private Boolean Validar(int target, List<Int32> lista, int idx)
        {
            if (lista.IndexOf(target) >= idx)
                return true;
            if (idx == lista.Count)
                return false;
            for (int x = idx; x < lista.Count; x++)
            {
                if(Validar(target - lista[x], lista, x + 1))
                    return true;
            }
            return Validar(target, lista, idx + 1);
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(resposta);
        }
    }
}
