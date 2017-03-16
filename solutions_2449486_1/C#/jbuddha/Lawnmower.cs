/// <summary>
/// Solution for Code Jam Problem - Lawnmower
/// Author - JSSVPrasad Buddha
/// </summary>
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;
using System.Text;
using System.Linq;

namespace CodeJam2013
{
    [TestClass]
    public class Lawnmower
    {
        static string inputfile = @"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Lawnmower-large.in";
        static string outputfile = @"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Lawnmower-large.out";
        static StringBuilder solution = new StringBuilder();
        static string[] lines = File.ReadAllLines(inputfile);

        static FileStream fs = new FileStream(@"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Global.out", FileMode.Create);
        static StreamWriter sw = new StreamWriter(fs);
        static TextWriter tmp = Console.Out;

        [TestMethod]
        public void LawnmowerSolver()
        {
            int lineCount = lines.Length;
            for (int line = 1, tc = 1; line < lineCount; tc++)
            {

                int[] temp = lines[line++].Split(' ').Select(x => int.Parse(x)).ToArray();
                int n = temp[0];
                int m = temp[1];

                Lawn lawn = new Lawn(n, m);
                for(int i = 0; i < n;i++)
                {
                    temp = lines[line++].Split(' ').Select(x => int.Parse(x)).ToArray();
                    lawn.SetLine(temp, i);
                }
                for (int i = 0; i < n; i++ )
                    lawn.CutHorizontally(i);
                for (int i = 0; i < m; i++)
                    lawn.CutVertically(i);
                for (int i = 0; i < m; i++)
                    lawn.CutVertically(i);
                for (int i = 0; i < n; i++)
                    lawn.CutHorizontally(i);

                lawn.Print();
                solution.AppendLine("Case #" + tc + ": " + lawn.Check());
            }

            File.WriteAllText(outputfile, solution.ToString());
            return;
        }

        public class Lawn
        {
            private string _emptyrow = "..................................................";
            private int[][] _lawn, _temp, _inverse, _requiredpattern;
            private int _size;
            private int _n, _m;
            public Lawn(int n,int m)
            {
                _n = n;
                _m = m;
                int[] max = new int[_m];
                for (int i = 0; i < _m; i++)
                    max[i] = Int32.MaxValue;
                _lawn = new int[_n][];
                _inverse = new int[_m][];
                _temp = new int[_n][];
                _requiredpattern = new int[_n][];
                for (int i = 0; i < _n; i++)
                {
                    _lawn[i] = new int[_m];
                    max.CopyTo(_lawn[i], 0);
                    _temp[i] = new int[_m];
                    _requiredpattern[i] = new int[_m];
                }
                for (int i = 0; i < _m; i++)
                {
                    _inverse[i] = new int[_n];
                }


            }

            public void SetLine(int[] heights, int n)
            {
                _requiredpattern[n] = heights;
                
                for (int i = 0; i < _m; i++)
                {
                    _inverse[i][n] = heights[i];
                }
            }

            public string Print()
            {
                StringBuilder str = new StringBuilder("Required Pattern: \n");
                for (int i = 0; i < _n; i++)
                {
                    str.AppendLine(String.Join(" ", _requiredpattern[i]));
                }

                str.AppendLine("Inverse Lawn: ");
                for (int i = 0; i < _m; i++)
                {
                    str.AppendLine(String.Join(" ", _inverse[i]));
                }

                str.AppendLine("Current Lawn: ");
                for (int i = 0; i < _n; i++)
                {
                    str.AppendLine(String.Join(" ", _lawn[i]));
                }
                string s = str.ToString();
                Console.WriteLine(s);
                return s;
            }



            public void CutHorizontally(int n)
            {
                int height = _requiredpattern[n].Max();
                for(int i = 0; i < _m; i++)
                {
                        if(_lawn[n][i] >= height)
                            _lawn[n][i] = height;
                }
                return;
            }

            public void CutVertically(int m)
            {
                int height = _inverse[m].Max();
                for (int i = 0; i < _n; i++)
                {
                    if (_lawn[i][m] >= height)
                        _lawn[i][m] = height;
                }
                return;
            }

            public string Check()
            {
                for (int i = 0; i < _n; i++)
                {
                    for (int j = 0; j < _m; j++)
                    {
                        if (_requiredpattern[i][j] != _lawn[i][j])
                            return "NO";
                    }
                }
                return "YES";
            }

            //public void CutVertically(int m)
            //{
            //    int height = _requiredpattern[_n].Max();
            //    for (int i = 0; i < _n; i++)
            //    {
            //        if (_lawn[_n][i] >= height)
            //            _lawn[_n][i] = height;
            //    }
            //    return;
            //}

            //public void Transpose()
            //{
            //    _inverse = new string[_size];
            //    _inverse[0] = _lawn[0][0].ToString() + _lawn[1][0] + _lawn[2][0] + _lawn[3][0];
            //    _inverse[1] = _lawn[0][1].ToString() + _lawn[1][1] + _lawn[2][1] + _lawn[3][1];
            //    _inverse[2] = _lawn[0][2].ToString() + _lawn[1][2] + _lawn[2][2] + _lawn[3][2];
            //    _inverse[3] = _lawn[0][3].ToString() + _lawn[1][3] + _lawn[2][3] + _lawn[3][3];
            //}

            

            
        }

        [TestCleanup]
        public void CleanUp()
        {
            // This method Sets the test output to a text file rather than Standard Output for seeing the output without indentation issues
            // To disable redirecting output to text file, comment next line
            Console.SetOut(tmp);
            sw.Close();
        }

        [TestInitialize]
        public void Initialize()
        {
            Console.SetOut(sw);
        }
    }
}
