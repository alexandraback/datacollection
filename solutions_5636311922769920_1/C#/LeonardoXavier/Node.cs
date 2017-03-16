using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace D_Fractiles
{
    public class Node
    {

        public Node(int pK, int pC, int pCLimite, BigInteger pKc)
        {
            K = pK;
            C = pC;
            Kc = pKc;
            CLimite = pCLimite;

            /*if (pC == pCLimite)
                return;

            Nodes = new Node[pK];
            var novos = ((pKc - 1) * pK) + 1;
            for (int x = 0; x < pK; x++)
                Nodes[x] = new Node(pK, pC + 1, pCLimite, novos + x);*/
        }

        public int K { get; private set; }

        public int C { get; private set; }

        public int CLimite { get; set; }

        public BigInteger Kc { get; private set; }


        public Node ObterNode(int idx)
        {
            if (C >= CLimite)
                return null;
            return new Node(K, C + 1, CLimite, ((Kc - 1) * K) + 1 + idx);
        }

       // public Node[] Nodes { get; private set; }
    }
}
