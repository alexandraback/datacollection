

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemC(), Console.In, Console.Out);
        }
    }

    public class Wrapper
    {
        public static void Solve(IProblem problem, TextReader input, TextWriter output)
        {
            var parser = new InputParser(input);
            int T = parser.GetInt();

            for (int i = 0; i < T; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, problem.SolveOneCase(parser)));
            }
        }
    }

    public interface IProblem
    {
        string SolveOneCase(InputParser input);
    }
}﻿

namespace Contest
{
    using System.Collections.Generic;
    using System.Text;

    public class ProblemC : IProblem
    {
        private const string IMp = "\r\nImpossible";
        private const string m = "*";
        private const string e = ".";
        private const string c = "c";

        public string SolveOneCase(InputParser input)
        {
            int R = input.GetInt();
            int C = input.GetInt();
            int M = input.GetInt();

            bool transposed = false;
            if( R< C)
            {
                int s = C;
                 C = R;
                 R = s;
                transposed = true;
            }
                
            string[,] res = new string[R,C];

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    res[i, j] = e;
                }
            }
            res[R-1, C-1] = c;

            int L = C*R - M;

            if(M==0)
            {
                ;
            }
            else if ( L == 1)
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        res[i, j] = m;
                    }
                }
                res[R-1, C-1] = c;

            }
            else
            {


                if (C == 1)
                {
                    for (int i = 0; i < M; i++)
                    {
                        res[i, 0] = m;
                    }

                }

                if (C == 2)
                {
                    if (L % 2 == 1 || L == 2 || L == 3)
                        return IMp;

                    int mm = 0;
                    for (int i = 0; i < R; i++)
                    {
                        for (int j = 0; j < C; j++)
                        {
                            res[i, j] = m;
                        }
                        mm += 2;

                        if (mm == M)
                            break;
                    }
                }

                if( C > 2)
                {
                    if (L == 2 || L == 3 || L == 5 || L == 7)
                        return IMp;

                    int mm = 0;
                    int i1 = 0, j1 = 0;
                    for (int i = 0; i < R; i++)
                    {
                        if( M == mm)
                            break;


                        if( M - mm - C >=0)
                        {
                           for (int j = 0; j < C; j++)
                           {
                               res[i, j] = m;
                           }
                            mm += C;

                            i1++;

                        }
                        else 
                        {
                            for (int j = 0; j < M - mm; j++)
                            {
                                res[i, j] = m;
                                j1++;
                            }
                            mm = M;
                        }
                    }

                    int r1 = i1 + 1;
                    int c1 = 0;
                    j1--;

                    if( r1== R)
                    {
                        r1--;
                        i1--;
                        j1 = C - 1;

                        for (int i = 0; i < C; i++)
                        {
                            if(res[r1,i] != m)
                            {
                                c1 = i;
                                break;
                            }
                        }
                    }

                    while (!valid(res, R, C))
                    {
                        if( r1 == R)
                        {
                            r1 = i1 + 1;
                            c1++;
                        }

                        if(j1 == c1)
                        {
                            i1--;
                            j1 = C - 1;
                            continue;
                        }

                        res[r1, c1] = m;
                        res[i1, j1] = e;


                        j1--;
                        r1++;
                    }
                }
            }



            res = Trans(res, transposed, ref R, ref C);
            var sb = new StringBuilder();
            sb.AppendLine();

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    sb.Append(res[i, j]);
                }
                sb.AppendLine();
            }


            return sb.ToString();
        }

        private string[,] Trans(string[,] str, bool t, ref int R, ref int C )
        {
            if (!t)
                return str;

            var res = new string[C,R];

            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    res[j, i] = str[i, j];
                }
            }

            int s = C;
            C = R;
            R = s;

            return res;
        }

        private bool valid(string[,] str, int R,  int C )
        {
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    if( str[i,j] != e )
                        continue;

                    if( i != 0)
                    {
                        if(j!=0)
                            if(Isempty(str, R, C, i-1, j-1)) continue;

                        if(Isempty(str, R, C, i-1, j)) continue;

                        if (j+1 != C)
                            if (Isempty(str, R, C, i - 1, j + 1)) continue;
                    }

                    if (j != 0)
                        if (Isempty(str, R, C, i, j - 1)) continue;
                    if (j + 1 != C)
                        if (Isempty(str, R, C, i, j + 1)) continue;

                    if (i +1 != R)
                    {
                        if (j != 0)
                            if (Isempty(str, R, C, i +1, j - 1)) continue;

                        if (Isempty(str, R, C, i + 1, j)) continue;

                        if (j + 1 != C)
                            if (Isempty(str, R, C, i + 1, j + 1)) continue;
                    }


                    return false;
                }
            }

            return true;
        }

        public bool Isempty(string[,] str, int R,  int C, int i, int j)
        {
            if (str[i, j] == m)
                return false;

            if (i != 0)
            {
                if (j != 0)
                    if (str[i - 1, j - 1] == m) return false; ;

                if (str[i - 1, j] == m) return false; ;

                if (j + 1 != C)
                    if (str[i - 1, j + 1] == m) return false; ;
            }

            if (j != 0)
                if (str[i, j - 1] == m) return false; ;
            if (j + 1 != C)
                if (str[i, j + 1] == m) return false; ;

            if (i + 1 != R)
            {
                if (j != 0)
                    if (str[i + 1, j - 1] == m) return false; ;

                if (str[i + 1, j] == m) return false; ;

                if (j + 1 != C)
                    if (str[i + 1, j + 1] == m) return false; ;
            }

            return true;
        }



    }
}
﻿

namespace Contest
{
    using System.Collections;
    using System;
    using System.IO;

    public class InputParser
    {
        private readonly TextReader _textReader;

        private IEnumerator _enumerator;

        public InputParser(TextReader textReader)
        {
            this._textReader = textReader;
            this._enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return _textReader.ReadLine();
        }

        public string[] GetStringArray()
        {
            return ReadLine().Split(new string[0], StringSplitOptions.RemoveEmptyEntries);
        }

        public int[] GetIntArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new int[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = int.Parse(tokens[i]);
            }

            return values;
        }

        public long[] GetLongArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new long[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = long.Parse(tokens[i]);
            }

            return values;
        }

        public string GetString()
        {
            while (_enumerator.MoveNext() == false)
            {
                _enumerator = GetStringArray().GetEnumerator();
            }

            return (string)_enumerator.Current;
        }

        public int GetInt()
        {
            return int.Parse(GetString());
        }

        public long GetLong()
        {
            return long.Parse(GetString());
        }
    }
}