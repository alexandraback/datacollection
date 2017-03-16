using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;


namespace D_Fractiles
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"D-small-attempt2.in";
        public const string OutputFile = @"D-small.out";


        private int k, c, s;

        private List<BigInteger> _resultados = new List<BigInteger>();

        private int idxPercorrido = 0;


        public override void LerDados()
        {
            var dados = ProximoInteiros();
            k = dados[0];
            c = dados[1];
            s = dados[2];
        }

        public override void Resolver()
        {
            var needed = Math.Ceiling((decimal)k / (decimal)c) ;
            //needed = needed < 1 ? 1 : needed;
            if (s < needed)
                return;

            var root = new Node(k, 0, c, 1);
            for (int x = 0; x < needed; x++)
                _resultados.Add(ObterNumero(root.ObterNode(idxPercorrido)));
        }

        public BigInteger ObterNumero(Node pNode)
        {
            if (idxPercorrido < k - 1)
                idxPercorrido++;

            if (pNode.C == pNode.CLimite)
                return pNode.Kc;
            return ObterNumero(pNode.ObterNode(idxPercorrido));
        }

        public override void EscreverResposta()
        {
            if (_resultados.Count == 0)
                Out.WriteLine("IMPOSSIBLE");
            else
                Out.WriteLine(string.Join(" ", _resultados));
        }
    }
}
