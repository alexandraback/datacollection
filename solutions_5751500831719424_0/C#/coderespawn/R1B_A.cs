using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014
{
    class Node
    {
        public Node(int id) { this.id = id; }
        public int id;
        public List<int> edges = new List<int>();
    }

    /////////////////////////// Solution ////////////////////////////////
    class R1B_A : GSolution
    {
        private void Process(GStream stream, string[] lines)
        {
            

        }

        public override void ProcessCase(GStream stream, int caseId)
        {
            Console.WriteLine(caseId);
            int N = stream.ReadInt();
            List<string> data = new List<string>();
            for (int i = 0; i < N; i++)
            {
                data.Add(stream.ReadString());
            }
            string[] lines = data.ToArray();


            int index = 1;
            bool impossible = false;
            int totalMoves = 0;


            // Make sure the starting chars are the same
            for (int i = 1; i < lines.Length; i++)
            {
                if (lines[0][0] != lines[i][0])
                {
                    impossible = true;
                    break;
                }
            }

            char previousChar;
            string padding = new string('$', 100);

            for (int i = 0; i < lines.Length; i++)
            {
                lines[i] = lines[i] + padding;
            }

            while (true && !impossible)
            {
                previousChar = lines[0][index - 1];
                var columnCount = new Dictionary<char, int>();
                foreach (string line in lines)
                {
                    char c = line[index];
                    if (!columnCount.ContainsKey(c)) columnCount[c] = 0;
                    columnCount[c]++;
                }
                if (columnCount.Count == 1)
                {
                    if (columnCount.ContainsKey('$'))
                    {
                        // done solving 
                        break;
                    }
                    index++;
                }
                else if (columnCount.Count > 2)
                {
                    impossible = true;
                    break;
                }
                else if (columnCount.Count == 2)
                {
                    // Find which one to fix
                    int previousCharCount = 0;
                    int nextCharCount = 0;
                    char nextChar = '$';
                    foreach (char key in columnCount.Keys)
                    {
                        if (key == previousChar) previousCharCount = columnCount[key];
                        else
                        {
                            nextCharCount = columnCount[key];
                            nextChar = key;
                        }
                    }

                    if (previousCharCount > nextCharCount)
                    {
                        // Insert 
                        for (int i = 0; i < lines.Length; i++)
                        {
                            string line = lines[i];
                            if (index >= line.Length || line[index] != previousChar)
                            {
                                lines[i] = line.Insert(index, previousChar.ToString());
                                totalMoves++;
                            }
                        }

                        index++;

                    }
                    else
                    {
                        // Delete
                        bool deleted = false;
                        for (int i = 0; i < lines.Length; i++)
                        {
                            string line = lines[i];
                            if (line[index] == previousChar)
                            {
                                lines[i] = line.Remove(index, 1);
                                totalMoves++;
                                deleted = true;
                            }
                        }
                        if (!deleted)
                        {
                            impossible = true;
                            break;
                        }
                    }
                    
                }
            }

            // make sure all strings are the same
            foreach (string line in lines) {
                if (line != lines[0]) impossible = true;
            }

            if (impossible)
            {
                stream.PrintCase(caseId, "Fegla Won");
            }
            else
            {
                stream.PrintCase(caseId, totalMoves.ToString());
            }

        }
    }

    /////////////////////////// Bootstrap ////////////////////////////////

    public class Program
    {
        static void Main(string[] args)
        {
            string directory = "R1B_A";
            string filename =
               //"Example.in"
                "A-small-attempt1.in"
                //"A-large-practice.in"
                    ;
            var stream = new GStream(directory + "/" + filename);
            new R1B_A().Run(stream);
            stream.Close();
        }

    }


    /////////////////////////// GCJ Utils ////////////////////////////////
    abstract class GSolution
    {
        abstract public void ProcessCase(GStream stream, int caseId);

        public void Run(GStream stream)
        {
            int numCases = int.Parse(stream.Input.ReadLine());
            for (int i = 0; i < numCases; i++)
            {
                ProcessCase(stream, i + 1);
            }
        }
    }

    class GStream
    {
        StreamReader input;
        public System.IO.StreamReader Input
        {
            get { return input; }
        }

        StreamWriter output;
        public System.IO.StreamWriter Output
        {
            get { return output; }
        }

        public GStream(string inputFilename)
        {
            inputFilename = "../../Data/" + inputFilename;
            var inputFileInfo = new FileInfo(inputFilename);
            string outputFilename = inputFilename.Replace(inputFileInfo.Extension, ".out");

            input = new StreamReader(new FileStream(inputFilename, FileMode.Open));
            output = new StreamWriter(new FileStream(outputFilename, FileMode.Create));
        }

        public void Close()
        {
            input.Close();
            output.Close();
        }

        public void PrintCase(int caseId, string result)
        {
            Output.WriteLine("Case #{0}: {1}", caseId, result);
        }

        public int ReadInt()
        {
            return int.Parse(Input.ReadLine());
        }

        public string[] ReadStringArray()
        {
            return Input.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
        }

        public string ReadString()
        {
            return Input.ReadLine();
        }

        public int[] ReadIntArray()
        {
            string[] tokens = ReadStringArray();
            var result = new List<int>();
            foreach (string token in tokens)
            {
                result.Add(int.Parse(token));
            }
            return result.ToArray();
        }

        public double[] ReadRealArray()
        {
            string[] tokens = ReadStringArray();
            var result = new List<double>();
            foreach (string token in tokens)
            {
                result.Add(double.Parse(token));
            }
            return result.ToArray();
        }

        public void ReadIntArray(out int a, out int b)
        {
            int[] tokens = ReadIntArray();
            a = tokens[0];
            b = tokens[1];
        }

        public void ReadIntArray(out int a, out int b, out int c)
        {
            int[] tokens = ReadIntArray();
            a = tokens[0];
            b = tokens[1];
            c = tokens[2];
        }

        public void ReadRealArray(out double a, out double b, out double c)
        {
            double[] tokens = ReadRealArray();
            a = tokens[0];
            b = tokens[1];
            c = tokens[2];
        }

        public void DiscardLine()
        {
            input.ReadLine();
        }
    }

}
