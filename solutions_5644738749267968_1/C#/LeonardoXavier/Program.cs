using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D_War
{
    class Program
    {
        static void Main(string[] args)
        {
            var linhas = File.ReadAllLines("input.txt");
            var quantidade = Convert.ToInt32(linhas[0].Trim());
            var teste = new Jogo[quantidade];
            var dados = new string[3];
            for (int x = 0; x < quantidade; x++)
            {
                for (var y = 0; y < 3; y++)
                {
                    dados[y] = linhas[x * 3 + 1 + y];
                }
                teste[x] = new Jogo(x + 1, dados);

            }
#if DEBUG
            foreach (var t in teste)
            {
                t.Processar();
            }
#else
            Parallel.ForEach(teste, t => t.Processar());
#endif

            File.AppendAllLines("out2.txt", teste.Select(pX => pX.Resultado));
        }
    }
}
