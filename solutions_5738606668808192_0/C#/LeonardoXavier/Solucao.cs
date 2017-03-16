using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;


namespace C_CoinJam
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"C_large.txt";
        public const string OutputFile = @"C_large.out";

        public long Limite = 10000;

        public BigInteger InicialNumber, FinalNumber;

        public int Qtd;

        public List<Resultado> Resultado = new List<Resultado>();

        public override void LerDados()
        {
            var dados = ProximoInteiros();
            var numeroInicial = string.Empty;
            var numeroFinal = string.Empty;
            for (int x = 1; x <= dados[0]; x++)
            {
                numeroFinal += "1";
                if (x == 1 || x == dados[0])
                    numeroInicial += "1";
                else
                    numeroInicial += "0";
            }

            Qtd = dados[1];
            InicialNumber = ConvertBase.ObterNumeroDecimal(numeroInicial, 2);
            FinalNumber = ConvertBase.ObterNumeroDecimal(numeroFinal, 2);
        }

        public override void Resolver()
        {


            while (true)
            {
                Limite *= 100;
                var binarioAtual = InicialNumber;

                while (Resultado.Count != Qtd && binarioAtual <= FinalNumber)
                {
                    binarioAtual += 2;
                    
                    var atual = new Resultado
                    {
                        Numero = ConvertBase.ToBinaryString(binarioAtual)
                    };
                    if(Resultado.Any(pX => pX.Numero == atual.Numero))
                        continue;
                    for (int b = 2; b <= 10; b++)
                    {
                        var numeroDecimal = ConvertBase.ObterNumeroDecimal(atual.Numero, b);
                        var divisor = PrimeNumber.ObterDivisor(numeroDecimal, Limite);
                        if (divisor == null)
                            break;
                        atual.Divisores.Add(divisor.Value);
                        if (b == 10)
                            Resultado.Add(atual);
                    }
                }

                if (Resultado.Count == Qtd)
                    break;
            }

        }

        public override void EscreverResposta()
        {
            foreach (var resultado in Resultado)
            {
                Out.Write($"{Environment.NewLine}{resultado.Numero} {(string.Join(" ", resultado.Divisores))}");
            }
            
        }
    }
}
