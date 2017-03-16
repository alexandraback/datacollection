using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Problem1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var input = new StreamReader("../../input.txt"))
            using (var output = new StreamWriter("../../output.txt"))
            {
                int caseCount = int.Parse(input.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var inputWord = input.ReadLine();
                    var outputWord = "";
                    foreach (var character in inputWord)
                    {
                        if (outputWord == "")
                        {
                            outputWord += character;
                        } else
                        {
                            if (character > outputWord[0])
                            {
                                outputWord = character + outputWord;
                            } else if (character < outputWord[0])
                            {
                                outputWord = outputWord + character;
                            } else
                            {
                                var index = 0;
                                while (index < outputWord.Length && outputWord[index] == character)
                                {
                                    index++;
                                }

                                if (index == outputWord.Length || character > outputWord[index])
                                {
                                    outputWord = character + outputWord;
                                } else
                                {
                                    outputWord = outputWord + character;
                                }
                            }
                        }
                    }

                    output.WriteLine("Case #{0}: {1}", caseNumber, outputWord);
                }
            }
        }
    }
}
