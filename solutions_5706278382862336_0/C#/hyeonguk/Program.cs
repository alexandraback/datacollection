using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;


namespace CodeJam
{
    public static class CodeJamIOHelper
    {
        public static string[] ToTokens(this string str)
        {
            return str.Split(new string[] { Environment.NewLine, " ", "\t" }, StringSplitOptions.RemoveEmptyEntries);
        }

        public static string[] ToLines(this string str)
        {
            return str.Split(new string[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);
        }
    }

    public class CodeJamIO : IDisposable
    {
        string _input;
        public string Input
        {
            get
            {
                return _input;
            }
        }

        string[] _tokens;
        public string[] Tokens
        {
            get
            {
                return _tokens;
            }
        }

        string[] _lines;
        public string[] Lines
        {
            get
            {
                return _lines;
            }
        }

        System.IO.StreamWriter _output;
        public System.IO.StreamWriter Output
        {
            get
            {
                return _output;
            }
        }

        int _nextLine;
        int _nextToken;

        public CodeJamIO(string inputFilePath, string outputFilePath)
        {
            _input = System.IO.File.ReadAllText(inputFilePath);
            _lines = _input.ToLines();

            _nextLine = 0;
            _nextToken = 0;

            _output = new System.IO.StreamWriter(outputFilePath);
        }

        public string GetLine()
        {
            if (_tokens != null && _nextToken < _tokens.Length)
            {
                throw new InvalidOperationException();
            }

            if (_nextLine < _lines.Length)
            {
                _tokens = null;
                _nextToken = 0;
                return _lines[_nextLine++];
            }
            else
            {
                throw new System.IO.EndOfStreamException();
            }
        }

        public int GetInt()
        {
            return int.Parse(GetToken());
        }

        public double GetDouble()
        {
            return double.Parse(GetToken());
        }

        public long GetLong()
        {
            return long.Parse(GetToken());
        }

        public string GetToken()
        {
            if (_tokens != null && _nextToken < _tokens.Length)
            {
                return _tokens[_nextToken++];
            }
            else
            {
                if (_nextLine < _lines.Length)
                {
                    _tokens = _lines[_nextLine++].ToTokens();
                    _nextToken = 0;

                    return GetToken();
                }
                else
                {
                    throw new ArgumentOutOfRangeException();
                }
            }
        }

        public void Write(string str)
        {
            _output.Write(str);
        }

        public void WriteLine()
        {
            _output.WriteLine();
        }

        public void WriteLine(string str)
        {
            _output.WriteLine(str);
        }

        public void Dispose()
        {
            _output.Dispose();
        }
    }
}


namespace PartElf
{
    class Program
    {
        static void Main(string[] args)
        {
            Debug.Assert(SolveInput("1/2") == "1");
            Debug.Assert(SolveInput("3/4") == "1");
            Debug.Assert(SolveInput("1/4") == "2");
            Debug.Assert(SolveInput("2/23") == "impossible");
            Debug.Assert(SolveInput("123/31488") == "8");
            Debug.Assert(SolveInput("1/16") == "4");
            Debug.Assert(SolveInput("1/128") == "7");
            Debug.Assert(SolveInput("63/64") == "1");
            Debug.Assert(SolveInput("1/2") == "1");
            Debug.Assert(SolveInput("2147483647/2147483648") == "1");

            using (CodeJam.CodeJamIO io = new CodeJam.CodeJamIO("input.txt", "output.txt"))
            {
                int n = io.GetInt();
                for (int i = 1; i <= n; i++)
                {
                    var input = io.GetToken();
                    string output = SolveInput(input);

                    io.Output.WriteLine(string.Format("Case #{0}: {1}", i, output));
                }
            }
        }

        static string SolveInput(string input)
        {
            int answer = Solve(input);
            if (answer == 0 || answer > 40)
            {
                return "impossible";
            }
            return answer.ToString();
        }

        static int Solve(string input)
        {
            var inputs = input.Split(new[] { "/" }, StringSplitOptions.RemoveEmptyEntries);
            BigInteger a = BigInteger.Parse(inputs[0]);
            BigInteger b = BigInteger.Parse(inputs[1]);

            return Solve(a, b);
        }

        static BigInteger Gcd(BigInteger a, BigInteger b)
        {
            if (a == 0)
            {
                return b;
            }
            return Gcd(b % a, a);
        }

        static int Solve(BigInteger a, BigInteger b)
        {
            BigInteger gcd = Gcd(a, b);
            a /= gcd;
            b /= gcd;

            int count = 0;
            while (true)
            {
                Console.WriteLine(a.ToString() +"/" + b.ToString());

                if (count > 42)
                {
                    return count;
                }
                if (b % 2 == 1)
                {
                    b *= 2;
                    a *= 2;
                }
                b /= 2;
                count++;
                if (a >= b)
                {
                    break;
                }
                a = a / 2;
                if (a == 0)
                {
                    a = 1;
                }
            }
            return count;
        }
    }
}
