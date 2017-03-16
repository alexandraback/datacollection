using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJAm
{

    class Diamond
    {
        Dictionary<int, List<int>> _paths;
        Dictionary<int, bool> _visitedPaths;
        private int[] ReturnIntArray(string[] firstLine)
        {
            int[] _arraay = new int[firstLine.Length];
            for (int i = 0; i < firstLine.Length; i++)
            {
                _arraay[i] = int.Parse(firstLine[i]);
            }

            return _arraay;
        }

        public string CheckIfDiamondExist(StreamReader streamReader)
        {
            int numTestCases = int.Parse(streamReader.ReadLine());
            _paths = new Dictionary<int, List<int>>();

            
            for (int i = 1; i <= numTestCases; i++)
            {
                string inputString = streamReader.ReadLine();
                int[] inputAsNumber = ReturnIntArray(inputString.Split(' '));
                _paths.Add(i, new List<int>());
                for (int j = 1; j <= inputAsNumber[0]; j++)
                    _paths[i].Add(inputAsNumber[j]);
            }


            for (int i = 1; i <= numTestCases;i++ ){
                _visitedPaths = new Dictionary<int, bool>();
                if (_paths[i].Count>1)
                    if (visitPaths(i))
                        return "Yes";
            }

            return "No";
        }

        private bool visitPaths(int currentPos)
        {

            for (int i = 0; i < _paths[currentPos].Count; i++)
            {
                if (_visitedPaths.ContainsKey(_paths[currentPos][i]))
                    return true;
                else
                    _visitedPaths.Add(_paths[currentPos][i], true);

                if (visitPaths(_paths[currentPos][i]))
                    return true;
            }
            return false;
        }


    }

    class Program
    {
        private static FileStream inputFileStream;
        private static StreamReader streamReader;

        private static FileStream outputFileStream;
        private static StreamWriter streamWriter;

        static void initializeGCJSample(string[] args)
        {
            inputFileStream = new FileStream(args[0], FileMode.Open);

            outputFileStream = new FileStream(args[1], FileMode.Create);

            streamReader = new StreamReader(inputFileStream);

            streamWriter = new StreamWriter(outputFileStream);
        }


        static void Main(string[] args)
        {
            String SampleName = "A-large";
            String currentDir = System.IO.Directory.GetCurrentDirectory();
            currentDir = currentDir.Replace("\\bin\\Debug", "");

            string[] myArgs = {currentDir + @"\" + SampleName + ".in",
                               currentDir + @"\" + SampleName + ".out"};

            initializeGCJSample(myArgs);

            int numTestCases = int.Parse(streamReader.ReadLine());
            Console.WriteLine("Num Test Cases: " + numTestCases.ToString());

            Diamond _diamonds = new Diamond();

            for (int numCase = 0; numCase < numTestCases; numCase++)
            {
                string result = _diamonds.CheckIfDiamondExist(streamReader);

                streamWriter.WriteLine("Case #" + (numCase + 1) + ": " + result);
                Console.WriteLine("Case #" + (numCase + 1) + ": " + result);
            }

            streamWriter.Flush();

            Console.WriteLine();
            Console.WriteLine("PROCES DONE! Press a key to close.");
            Console.ReadKey();
        }
    }
}
