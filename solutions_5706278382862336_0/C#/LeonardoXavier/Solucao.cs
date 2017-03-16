using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace A
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"A-small-attempt0.in";
        public const string OutputFile = @"A-small.out";

        public Int64 P { get; set; }

        public Int64 Q { get; set; }

        public String Resposta { get; set; }


        public override void LerDados()
        {
            var numero = ProximaLinha().Split(new string[] { "/" }, StringSplitOptions.RemoveEmptyEntries);
            P = Int64.Parse(numero[0]);
            Q = Int64.Parse(numero[1]);
        }

        public override void Resolver()
        {
            Int64 nivel = 0, quantidade = 0, divisor = 0, tmp;
            tmp = Q;
            while (tmp != 1)
            {
                if (tmp % 2 != 0)
                {
                    divisor = tmp;
                    break;
                }
                if (tmp > P)
                    nivel++;
                tmp = tmp / 2;
                quantidade++;
            }
            if (divisor != 0)
            {
                if (P % divisor != 0)
                    Resposta = "impossible";
                else
                    Resposta = nivel.ToString();
            }
            else
            {
                Resposta = nivel.ToString();
            }


        }




        public override void EscreverResposta()
        {
            Out.WriteLine(Resposta);
        }
    }
}
