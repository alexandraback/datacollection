using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Drawing;

namespace Pogo
{
    class MainClass
    {
        enum Orientation
        {
            East = 0,
            West = 1,
            North = 2,
            South = 3
        }
        
        const int MAX_MOVES = 500;
        static Random _rng = new Random();
        static int _pogoStep;
        static StringBuilder moves = new StringBuilder(MAX_MOVES);

        public static void Main(string[] args)
        {
            int maxOutputLength = 128;

            using (var sr = new StreamReader("in.txt"))
            using (var sw = new StreamWriter("out.txt"))
            {

                int totalCases = Int32.Parse(sr.ReadLine());

                for (int testCaseCounter = 0; testCaseCounter < totalCases; testCaseCounter++)
                {
                    //Read input
                    var line = sr.ReadLineOfTokens();
                    int x = line.ReadInt();
                    int y = line.ReadInt();

                    //Solve problem
                    string result;
                    while (!FindResult(x, y, out result))
                    {
                        ;
                    }

                    //Output result
                    var sb = new StringBuilder(maxOutputLength);
                    sb.AppendFormat("Case #{0}: {1}", (testCaseCounter + 1).ToString(), result);
                    sw.WriteLine(sb.ToString());
                }
            }
        }

        static bool FindResult(int x, int y, out string result)
        {
            _pogoStep = 0;
            moves.Clear();
            var targetPoint = new Point(x, y);            
            
            Point currPoint = new Point(0,0);
            for (int moveCounter = 0; moveCounter < MAX_MOVES; moveCounter++)
			{
                _pogoStep++;
                currPoint = MoveRandom(currPoint);                
                if (currPoint == targetPoint)
                {
                    result = moves.ToString();
                    return true;
                }
			}

            result = string.Empty;
            return false;  
        }

        static Point MoveRandom(Point p)
        {
            int orientation = _rng.Next(4);

            switch ((Orientation)orientation)
            {
                case Orientation.East:
                    return MoveEast(p);
                    break;
                case Orientation.West:
                    return MoveWest(p);
                    break;
                case Orientation.North:
                    return MoveNorth(p);
                    break;
                case Orientation.South:
                    return MoveSouth(p);
                    break;                
                default:
                    throw new IndexOutOfRangeException("Boom");                    
            }
        }

        static Point MoveEast(Point p)
        {
            moves.Append("E");            
            return Point.Add(p, new Size(_pogoStep, 0));
        }

        static Point MoveWest(Point p)
        {
            moves.Append("W");
            return Point.Add(p, new Size(-_pogoStep, 0));
        }

        static Point MoveNorth(Point p)
        {
            moves.Append("N");
            return Point.Add(p, new Size(0, _pogoStep));
        }

        static Point MoveSouth(Point p)
        {
            moves.Append("S");
            return Point.Add(p, new Size(0, -_pogoStep));
        }
    }

    /// <summary>
    /// Represents a line of tokens.
    /// </summary>
    public class LineOfTokens
    {
        string[] _tokens;
        int _nextToken;

        /// <summary>
        /// Initializes a new instance of the <see cref="firsttest.LineOfTokens"/> class.
        /// </summary>
        /// <param name='tokens'>
        /// Tokens.
        /// </param>
        public LineOfTokens(string[] tokens)
        {
            if (tokens == null) throw new ArgumentNullException("tokens");

            _tokens = tokens;
            _nextToken = 0;
        }

        /// <summary>
        /// Reads the next int.
        /// </summary>
        /// <returns>
        /// The int.
        /// </returns>
        public int ReadInt()
        {
            return Int32.Parse(_tokens[_nextToken++]);
        }

        /// <summary>
        /// Reads all tokens as ints.
        /// </summary>
        /// <returns>
        /// The ints.
        /// </returns>
        public IEnumerable<int> ReadAllInts()
        {
            return _tokens.Select(x => Int32.Parse(x));
        }
    }

    /// <summary>
    /// A box that holds a value.
    /// </summary>
    public class Box<T>
    {
        T boxedVal;

        /// <summary>
        /// Gets or sets the value.
        /// </summary>
        /// <value>
        /// The value in the box.
        /// </value>
        public T Value { get; set; }

        public Box(T val)
        {
            boxedVal = val;
        }
    }

    /// <summary>
    /// Useful extension methods.
    /// </summary>
    public static class Extensions
    {
        /// <summary>
        /// Reads a line of tokens from a StreamReader.
        /// </summary>
        /// <returns>
        /// The line of tokens.
        /// </returns>
        /// <param name='sr'>
        /// The StreamReader from where to read the line of tokens.
        /// </param>
        public static LineOfTokens ReadLineOfTokens(this StreamReader sr)
        {
            string[] tokens = sr.ReadLine().Split(' ');
            return new LineOfTokens(tokens);
        }

        /// <summary>
        /// Reads a matrix of ints from a StreamReader. The matrix will have rowNum rows.
        /// </summary>
        /// <returns>
        /// The matrix of ints.
        /// </returns>
        /// <param name='sr'>
        /// The StreamReader from where to read the matrix.
        /// </param>
        /// <param name='rowNum'>
        /// The number of rows of the matrix.
        /// </param>
        public static int[][] ReadMatrixOfInts(this StreamReader sr, int rowNum)
        {
            var matrix = new int[rowNum][];
            for (int j = 0; j < rowNum; j++)
            {
                matrix[j] = sr.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
            }

            return matrix;
        }
    }
}
