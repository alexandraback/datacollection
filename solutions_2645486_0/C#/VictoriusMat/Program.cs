using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using GoogleCodeJam._2013;

namespace GoogleCodeJam
{
    class Program
    {
        /// <summary>
        /// Objeto contendo a resolução do exercício
        /// </summary>
        private static Exercicio exercicio = new Round1B();

        static void Main(string[] args)
        {
            try
            {
                #region Inicia controle de tempo
                Stopwatch watch = new Stopwatch();
                watch.Start();
                #endregion

                FileInfo inputFile = new FileInfo(@"D:\Projetos\GoogleCodeJam\In\" + args[0] + ".in");
                using(StreamReader inputStream = new StreamReader(inputFile.OpenRead()))
                {
                    StringBuilder output = new StringBuilder();
                    while (!inputStream.EndOfStream)
                    {
                        #region Recupera numero de casos
                        string linha = inputStream.ReadLine();
                        int numCasos = Convert.ToInt32(linha);
                        #endregion

                        #region Gera sequencia de resultados
                        for (int i = 1; i <= numCasos; i++)
                        {
                            System.Console.WriteLine("Resolvendo " + i + "/" + numCasos);
                            int numeroDeLinhas = 2;
                            var linhas = new string[numeroDeLinhas];
                            for (int j = 0; j < numeroDeLinhas; j++)
                            {
                                linhas[j] = inputStream.ReadLine();
                            }
                            output.AppendLine("Case #" + i + ": " + exercicio.resolveLinhas(linhas));
                        }
                        #endregion
                    }
                    #region Escreve output
                    FileInfo outputFile = new FileInfo(@"D:\Projetos\GoogleCodeJam\Out\" + args[0] + ".out");
                    using (StreamWriter outputStream = new StreamWriter(outputFile.OpenWrite()))
                    {
                        outputStream.Write(output);
                    }
                    #endregion

                    #region Mostra mensagem de sucesso
                    watch.Stop();
                    System.Console.Write("A resposta foi gerada com sucesso em " + watch.Elapsed.TotalSeconds + " segundos");
                    #endregion
                }
            }
            catch (Exception e)
            {
                System.Console.Write("Erro ao ler input: " + e.Message + "." + e.StackTrace); 
            }
        }
    }
}
