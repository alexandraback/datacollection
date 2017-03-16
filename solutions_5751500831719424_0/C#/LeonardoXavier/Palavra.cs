using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace A
{
    public class Palavra
    {

        public String P { get; set; }

        public Palavra(String pPalavra)
        {

            Sequencia = String.Empty;
            foreach (var p in pPalavra)
            {
                if (Sequencia == String.Empty || Sequencia[Sequencia.Length - 1] != p)
                {
                    Sequencia += p;
                    Repeticoes.Add(1);
                }
                else
                {
                    Repeticoes[Sequencia.Length - 1]++;
                }
            }
        }

        public String Sequencia { get; set; }

        public List<Int32> Repeticoes = new List<int>();



    }
}
