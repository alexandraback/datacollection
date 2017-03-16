using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
    public class Program
    {
        public static void Main(string[] args)
        {
            // ToDo
            var inputPath = @"C:\GCJ_TestData\B-small-attempt0.in";
            //var inputPath = @"C:\GCJ_TestData\A-large.in";

            //var inputPath = @"C:\GCJ_TestData\file.in";
            var outputPath = @"C:\GCJ_TestData\file.out";

            var solver = new SolveB();
            var solutionStrings = new List<string>();

            using (StreamReader fileReader = new StreamReader(inputPath))
            {
                var numOfProblems = MathHelper.ConvertToInt(fileReader.ReadLine());

                for (var problemNumber = 1; problemNumber <= numOfProblems; problemNumber++)
                {
                    var solution = solver.Solve(fileReader);
                    var solutionString = "Case #" + problemNumber + ": " + solution;

                    solutionStrings.Add(solutionString);
                }
            }

            using (StreamWriter fileWriter = new StreamWriter(outputPath))
            {
                foreach (var solution in solutionStrings)
                {
                    fileWriter.WriteLine(solution);
                }
            }            
        }

        private class SolveA : ISolver
        {
            string result = "";

            List<string> chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".ToCharArray().Select(c => c.ToString()).ToList();
            List<int> countOfEachParty;

            public string Solve(StreamReader fileReader)
            {
                result = "";

                var numOfParties = MathHelper.ConvertToInt(fileReader.ReadLine());
                countOfEachParty = MathHelper.ConvertToInts(fileReader.ReadLine(), ' ').ToList();

                while (true)
                {
                    var max = countOfEachParty.Max();
                    if (max == 0)
                    {
                        break;
                    }

                    var count = countOfEachParty.Where(x => x == max).Count();
                    if (count > 2)
                    {
                        var firstIndex = countOfEachParty.IndexOf(max);

                        Add(firstIndex);
                        continue;
                    }
                    else if (count == 2)
                    {
                        var firstIndex = countOfEachParty.IndexOf(max);
                        var lastIndex = countOfEachParty.LastIndexOf(max);

                        Add(firstIndex, lastIndex);
                        continue;
                    }
                    else
                    {
                        var firstIndex = countOfEachParty.IndexOf(max);

                        Add(firstIndex);
                        continue;
                    }
                }

                return result;
            }

            private void Add(int v)
            {
                countOfEachParty[v] -= 1;

                result += chars[v] + " ";
            }

            private void Add(int v, int w)
            {
                countOfEachParty[v] -= 1;
                countOfEachParty[w] -= 1;

                result += chars[v] + chars[w] + " ";
            }
        }

        private class SolveB : ISolver
        {
            List<bool[]> slides;

            string POSSIBLE = "POSSIBLE";
            string IMPOSSIBLE = "IMPOSSIBLE";

            public string Solve(StreamReader fileReader)
            {
                slides = new List<bool[]>();

                bool possible = false;

                var line = fileReader.ReadLine().Split(' ');
                var buildingCount = MathHelper.ConvertToInt(line[0]);
                var numOfWays = Convert.ToInt64(line[1]);

                for (int i = 0; i < buildingCount; i++)
                {
                    slides.Add(new bool[buildingCount]);
                }

                slides[0][1] = true;
                if (buildingCount == 2)
                {
                    if (numOfWays == 1)
                    {
                        return CreateResult(true);
                    }

                    return CreateResult(false);
                }

                slides[1][2] = true;
                if (buildingCount == 3)
                {
                    if (numOfWays == 1)
                    {
                        return CreateResult(true);
                    }
                    if (numOfWays == 2)
                    {
                        slides[0][2] = true;
                        return CreateResult(true);
                    }

                    return CreateResult(false);
                }
                slides[2][buildingCount - 1] = true;


                slides[1][3] = true;
                if (buildingCount == 4)
                {
                    if (numOfWays == 1)
                    {
                        return CreateResult(true);
                    }
                    if (numOfWays == 2)
                    {
                        slides[0][3] = true;
                        return CreateResult(true);
                    }
                    if (numOfWays == 3)
                    {
                        slides[0][3] = true;
                        slides[2][3] = true;
                        return CreateResult(true);
                    }

                    return CreateResult(false);
                }
                slides[3][buildingCount - 1] = true;

                if (buildingCount == 5)
                {
                    if (numOfWays == 1)
                    {
                        slides[1][2] = false;
                        return CreateResult(true);
                    }
                    if (numOfWays == 2)
                    {
                        return CreateResult(true);
                    }
                    if (numOfWays == 3)
                    {
                        slides[1][4] = true;
                        slides[1][2] = false;
                        slides[1][3] = false;
                        slides[0][2] = true;
                        slides[0][3] = true;
                        return CreateResult(true);
                    }
                    if (numOfWays == 4)
                    {
                        slides[2][3] = true;
                        slides[0][4] = true;
                        return CreateResult(true);
                    }

                    return CreateResult(false);
                }
                
                if (buildingCount == 6)
                {
                    if (numOfWays == 1)
                    {
                        slides[1][2] = false;
                        return CreateResult(true);
                    }
                    if (numOfWays == 2)
                    {
                        return CreateResult(true);
                    }
                    if (numOfWays == 3)
                    {
                        slides[0][4] = true;
                        slides[4][3] = true;
                        return CreateResult(true);
                    }
                    if (numOfWays == 5)
                    {
                        slides[0][4] = true;
                        slides[4][3] = true;
                        slides[2][3] = true;
                        return CreateResult(true);
                    }
                    if (numOfWays == 4)
                    {
                        slides[0][4] = true;
                        slides[4][2] = true;
                        return CreateResult(true);
                    }
                    if (numOfWays == 6)
                    {
                        slides[0][4] = true;
                        slides[4][2] = true;
                        slides[2][3] = true;
                        return CreateResult(true);
                    }

                    return CreateResult(false);
                }

                var foo = Convert.ToString(numOfWays, 2)
                    .Select(c => Convert.ToInt32(c.ToString()) == 1 ? true : false)
                    .Reverse().ToList();

                var lastIndex = foo.LastIndexOf(true);


                return CreateResult(false);
            }

            private string CreateResult(bool possible)
            {
                if (!possible)
                {
                    return IMPOSSIBLE;
                }

                var result = POSSIBLE;
                foreach (var slide in slides)
                {
                    result += Environment.NewLine;
                    var line = slide.Select(x => x ? 1.ToString() : 0.ToString()).Aggregate((a, b) => a + b);

                    result += line;
                }

                return result;
            }
        }

        private class SolveC : ISolver
        {
            public string Solve(StreamReader fileReader)
            {
                throw new NotImplementedException();
            }
        }

        private class SolveD : ISolver
        {
            public string Solve(StreamReader fileReader)
            {
                throw new NotImplementedException();
            }
        }
    }    
}
