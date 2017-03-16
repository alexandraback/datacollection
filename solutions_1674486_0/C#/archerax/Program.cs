using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace DiamondInheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            const string InputFilename = @"C:\Users\Anthony\Desktop\A-small-attempt0.in";
            const string OutputFilename = @"C:\Users\Anthony\Desktop\A-small-attempt0.out";

            using (Stream input = File.OpenRead(InputFilename))
            {
                using (Stream output = File.Create(OutputFilename))
                {
                    var app = new Program();
                    app.Run(input, output);
                }
            }
        }

        private void Run(Stream input, Stream output)
        {
            using (TextReader inputReader = new StreamReader(input))
            {
                using (TextWriter outputWriter = new StreamWriter(output))
                {
                    Run(inputReader, outputWriter);
                }
            }
        }

        private void Run(TextReader input, TextWriter output)
        {
            int numCases = int.Parse(input.ReadLine());

            for ( int caseNumber = 1; caseNumber <= numCases; caseNumber++ )
            {
                RunCase(input, output, caseNumber);
            }
        }

        private void RunCase(TextReader input, TextWriter output, int caseNumber)
        {
            int numClasses = int.Parse(input.ReadLine());
            var inheritance = new Dictionary<int, int[]>();

            for ( int i = 1; i <= numClasses; i++ )
            {
                inheritance[i] = input.ReadLine().Split(' ').Select(x => int.Parse(x)).Skip(1).ToArray();
            }

            bool containsDupes = false;

            foreach ( var item in inheritance.Keys )
            {
                var parents = BuildInheritanceList(item, inheritance);

                if ( parents.Distinct().Count() != parents.Count )
                {
                    containsDupes = true;
                }
            }

            output.WriteLine("Case #{0}: {1}", caseNumber, containsDupes ? "Yes" : "No");
        }

        private List<int> BuildInheritanceList(int item, Dictionary<int, int[]> inheritance, List<int> parents = null)
        {
            if ( parents == null )
            {
                parents = new List<int>();
            }

            foreach ( int parent in inheritance[item] )
            {
                parents.Add(parent);
                BuildInheritanceList(parent,inheritance,parents);
            }

            return parents;
        }
    }
}
