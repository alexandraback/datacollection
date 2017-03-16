using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace GCJ_2012_R1B_A    //  この名前で問題識別
{
	class Solver
    {
        object _Solve_単テストケース()
        {
            var ss = _ReadLine().Split(' ');
            var N = int.Parse(ss[0]);
            var a = new int[N];
            for (int i = 0; i < N; i++)
            {
                a[i] = int.Parse(ss[i + 1]);
            }

            //
            int sum = 0;
            foreach (var s in a)
                sum += s;

            //
            var zeros = 0;
            var sum2 = sum;
            foreach (var s in a)
            {
                double ans = 200.0 / N;
                ans -= (100.0 * s / sum);
                if (ans < 0.0)
                {
                    zeros++;
                    sum2 -= s;
                }
            }

            //
            var res = "";
            foreach (var s in a)
            {
                double ans = 200.0/N;
                ans -= (100.0*s/sum);
                if (ans < 0.0)
                    ans = 0.0;
                else
                {
                    ans = (( (double)sum2+sum)/(N-zeros)-s)/sum*100.0;
                }

                if (res.Length > 0)
                    res += " ";

                res += ans.ToString();
            }
                
            return res;
        }


        void _事前処理があれば()
		{

        }

        #region 基本的に固定で

        void _指定ファイルを読んで指定ファイルに書きだす(string inputFileName, string outputFileName)
		{
			if (!File.Exists(inputFileName))
			{
				Debug.WriteLine("\nNot Exist " + inputFileName);
				return;
			}

			using (_sr = new StreamReader(inputFileName))
			using (_sw = new StreamWriter(outputFileName))
			{
				Debug.WriteLine("\nStart... " + inputFileName);

				_事前処理があれば();

				int T = int.Parse(_ReadLine());
				for (int t = 1; t <= T; t++)
				{
					var s = _Solve_単テストケース();
					_WriteLine(String.Format("Case #{0}: {1}", t, s));
				}
			}
		}

		StreamReader _sr;
        StreamWriter _sw;

        string _ReadLine()
        {
            return _sr.ReadLine();
        }

        void _Write(string s)
        {
            Debug.Write(s);
            _sw.Write(s);
        }

        void _WriteLine(string s)
        {
            _Write(s +System.Environment.NewLine );
        }
 
        static void Main(string[] args)
        {
            var m = System.Reflection.MethodInfo.GetCurrentMethod();
            var problem_id = m.DeclaringType.Namespace;

            var solver = new Solver();
            foreach (var sub in _subs)
	        {
                var inputFileName = @"..\..\"+problem_id+"."+sub+".txt";
                var outputFileName = @"..\..\"+problem_id+"."+sub+".out.txt";
                solver._指定ファイルを読んで指定ファイルに書きだす(inputFileName,outputFileName);
            }
		}

        static string[] _subs = new string[] { "Sample", "Small", "Large" };

		#endregion

	}

}
