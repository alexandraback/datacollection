using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace C_FashionPolice
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = false;
        public const bool UseStandardIO = false;
        public const string InputFile = @"C-small-attempt4.in";
        public const string OutputFile = @"C-small5.out";

        int J, P, S, K;
        Dictionary<string, int> _utilizados = new Dictionary<string, int>();
        List<string> _possiveis = new List<string>();


        public override void LerDados()
        {
            var valores = ProximoInteiros();
            J = valores[0];
            P = valores[1];
            S = valores[2];
            K = valores[3];
        }

        public override void Resolver()
        {

            int match = 0;
            int limite = 0;
            int zerados = 0;
            while (true)
            {
                for (int j = 1; j <= J; j++)
                {
                    for (int p = 1; p <= P; p++)
                    {
                        for (int s = S; s > 0; s--)
                        {
                            var jps = $"j{j}p{p}s{s}";
                            if (Validar(jps) > 0)
                                continue;

                            var jp = $"j{j}p{p}";
                            var js = $"j{j}s{s}";
                            var ps = $"p{p}s{s}";

                            var n = 0;
                            n += Validar(jp);
                            n += Validar(js);
                            n += Validar(ps);
                            

                            if (n <= limite)
                            {
                                Adicionar(jp);
                                Adicionar(js);
                                Adicionar(ps);
                                Adicionar(jps);
                                _possiveis.Add($"{j} {p} {s}");
                                match++;
                            }
                        }
                    }
                }

                if (match == 0)
                    zerados++;
                else
                {
                    zerados = 0;
                    match = 0;
                }
                if (zerados == 100)
                    break;
                limite++;
            }

            
        }

        public int Validar(string pComb)
        {
            int qtd;
            if (_utilizados.TryGetValue(pComb, out qtd))
                return qtd >= K ? 10000 : qtd;
            _utilizados.Add(pComb, 0);
            return 0;
        }

        public void Adicionar(string pComb)
        {
            _utilizados[pComb]++;
        }

        public override void EscreverResposta()
        {
            Out.WriteLine(_possiveis.Count);
            foreach (var possivel in _possiveis)
            {
                Out.WriteLine(possivel);
            }
        }
    }
}
