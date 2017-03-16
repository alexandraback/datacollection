using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace osmos
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader(@"..\..\input.txt"))
            using (var outputStream = new StreamWriter(@"..\..\output.txt"))
            {
                var caseCount = int.Parse(inputStream.ReadLine());
                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var parameters = inputStream.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
                    var myMotesSize = parameters[0];
                    var otherMotes = inputStream.ReadLine().Split(' ').Select(s => long.Parse(s)).OrderBy(mote => mote).ToArray();

                    var operations = 0L;
                    var solutions = new HashSet<long>();
                    for (var i = 0; i < otherMotes.Length; i++)
                    {
                        if (myMotesSize > otherMotes[i])
                        {
                            myMotesSize += otherMotes[i];
                        }
                        else
                        {
                            solutions.Add(operations + otherMotes.Length - i); //a possible solution is to remove all other motes
                            var newMotesSize = myMotesSize - 1;
                            if (newMotesSize == 0)
                            {
                                operations = long.MaxValue;
                                break;
                            }
                            while (myMotesSize <= otherMotes[i])
                            {
                                myMotesSize += myMotesSize - 1;
                                operations++;
                            }
                            myMotesSize += otherMotes[i];
                        }
                    }

                    if (solutions.Any())
                    {
                        var minimum = solutions.Min();
                        if (minimum < operations)
                            operations = minimum;
                    }

                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, operations);
                }
            }
        }
    }
}
