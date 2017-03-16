using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace GCJ_2012_R1C_A
{
	class Solver
    {
        object _Solve_単テストケース()
        {
            var N = int.Parse(_ReadLine());
            chains = new List<int>[N];
            for (int i = 0; i < N; i++)
            {
                chains[i] = new List<int>();
                var ss = _ReadLine().Split(' ');
                int n1 = int.Parse(ss[0]);
                for (int j = 1; j <= n1; j++)
                {
                    chains[i].Add(int.Parse(ss[j]) - 1);//0..
                }
            }

            /*
            N = 1000;
            chain = new List<int>[N];
            for (int i = 0; i < N; i++)
            {
                chain[i] = new List<int>();
                if( i>0)
                    chain[i].Add(i - 1);
            }
            */


            //  全部チェックするけどメモがある
            {
                memo = new HashSet<int>[N];
                for (int node = 0; node < N; node++)
                {
                    var ans = _ancestors_nullはクロスあり(node);
                    if (ans == null)
                    {
                        return "Yes";
                    }
                }
                return "No";
            }
        }

        List<int>[]chains;

        HashSet<int>[] memo;

        HashSet<int>_ancestors_nullはクロスあり(int node)
        {
            HashSet<int> res = new HashSet<int>();
            //if (memo[node] == null)
            {
                foreach (var parent in chains[node])
                {
                    res.Add(parent);
                }

                foreach (var parent in chains[node])
                {
                    var ps = _ancestors_nullはクロスあり(parent);
                    if (ps == null)
                        return null;    //  親にクロス

                    foreach (var p in ps)
                    {
                        if (res.Contains(p))
                            return null;    //  親の間にクロス
                        res.Add(p);
                    }
                }

                //memo[node] = res;
            }
            //else
            {
                //Debug.WriteLine("hit "+node);
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
