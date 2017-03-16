using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r0pa
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default)) 
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var input = inputStream.ReadLine().Split(' ')[1].Select(c => int.Parse(c.ToString())).ToArray();

                    var standingPeople = 0;
                    var additionalPeople = 0;
                    for (var i = 0; i < input.Length; i++)
                    {
                        if (standingPeople < i)
                        {
                            var extraPeople = i - standingPeople;
                            additionalPeople += extraPeople;
                            standingPeople += extraPeople;
                        }

                        standingPeople += input[i];
                    }

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, additionalPeople);
                }
            }
        }
    }
}
