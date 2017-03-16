using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B_Cookies
{
    class Program
    {
        static void Main(string[] args)
        {

            var linhas = File.ReadAllLines("input.txt");
            var quantidade = Convert.ToInt32(linhas[0].Trim());
            var teste = new TestCase[quantidade];
            for (int x = 1; x <= quantidade; x++)
            {
                teste[x - 1] = new TestCase(x, linhas[x]);

            }
#if DEBUG
            foreach (var t in teste)
            {
                t.Processar();
            }
#else
            Parallel.ForEach(teste, t => t.Processar());
#endif

            File.AppendAllLines("Output.txt", teste.Select(pX => pX.Resultado));
        }
    }
}
