using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dynamic
{


    class Program
    {
        static StreamReader streamReader = new StreamReader(@"D:\A-small-attempt0.in");
 

        static void Main(string[] args)
        {
            int test = Convert.ToInt32(streamReader.ReadLine());
            List<int> results = new List<int>();

            while (test != 0)
            {
                ArminGame game;
                // dane
                string[] liniaAN = streamReader.ReadLine().Split(' ');
                int ArminMote = Convert.ToInt32(liniaAN[0]);
                int OtherMoteCount = Convert.ToInt32(liniaAN[1]);
                string[] liniaMoteSize = streamReader.ReadLine().Split(' ');
                List<int> otherMotes = new List<int>();

                for (int i = 0; i < OtherMoteCount; ++i)
                    otherMotes.Add(Convert.ToInt32(liniaMoteSize[i]));
                   
                

                game = new ArminGame(ArminMote, otherMotes);
             //   Console.WriteLine(game.FindBestSolution());
                results.Add(game.FindBestSolution());
                // dane wczytane
                test--;
            }
            CodejamIO.WriteToFile(results.ToArray(), @"D:\exe1.txt");
            Console.ReadKey();
        }
        
    }
}
