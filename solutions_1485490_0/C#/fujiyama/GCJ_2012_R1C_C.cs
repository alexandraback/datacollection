using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;
using System.Diagnostics;
using System.Numerics;

namespace GCJ_2012_R1C_C
{
	class Solver
    {
        object _Solve_単テストケース()
        {
            var ss = _ReadLine().Split(' ');
            N = int.Parse(ss[0]);
            M = int.Parse(ss[1]);

            a = new long[N];
            A = new int[N];
            {
                ss = _ReadLine().Split(' ');
                for (var i = 0; i < N; i++)
                {
                    a[i] = long.Parse(ss[i * 2]);
                    A[i] = int.Parse(ss[i * 2 + 1]);
                }
            }

            b = new long[M];
            B = new int[M];
            {
                ss = _ReadLine().Split(' ');
                for (var i = 0; i < M; i++)
                {
                    b[i] = long.Parse(ss[i * 2]);
                    B[i] = int.Parse(ss[i * 2 + 1]);
                }
            }

            /*
            {
                N = 100;
                M = 100;
                a = new long[N];
                b = new long[M];
                A = new int[N];
                B = new int[M];
                Random r = new Random();
                for (int i = 0; i < 100; i++)
                {
                    a[i] = 100000000000L*(r.Next(10)+1);
                    b[i] = 100000000000L * (r.Next(10) + 1);
                    A[i] = r.Next(2);
                    B[i] = r.Next(2);
                }
            }
            */

            _memo = new Dictionary<long, Dictionary<long, long>>[N + 1, M + 1];


            return _max(0, 0, 0, 0);
        }

        int N;
        int M;
        long[] a;
        int[] A;
        long[] b;
        int[] B;

        Dictionary<long,Dictionary<long,long>>[,] _memo;

        long? _get(int ai, long aoffs, int bi, long boffs)
        {
            if (_memo[ai, bi] == null)
                _memo[ai, bi] = new Dictionary<long, Dictionary<long, long>>();

            if (!_memo[ai, bi].ContainsKey(aoffs))
                _memo[ai, bi].Add(aoffs, new Dictionary<long, long>());

            if (_memo[ai, bi][aoffs].ContainsKey(boffs))
                return _memo[ai, bi][aoffs][boffs];
            return null;
        }

        void _set(int ai, long aoffs, int bi, long boffs,long val)
        {
            if (_memo[ai, bi] == null)
                _memo[ai, bi] = new Dictionary<long, Dictionary<long, long>>();

            if (!_memo[ai, bi].ContainsKey(aoffs))
                _memo[ai, bi].Add(aoffs, new Dictionary<long, long>());

            //  かぶりありうる
            if (!_memo[ai, bi][aoffs].ContainsKey(boffs) )
                _memo[ai, bi][aoffs].Add(boffs, val);
        }

        

        long _max(int ai,long aoffs,int bi,long boffs)
        {
            var m = _get(ai, aoffs, bi, boffs);
            if (m != null)
                return m.Value;

            long res = 0;

            //  auto
            for (; ; )
            {

                if (ai >= N || bi >= M)
                {
                    return res;
                }

                if (A[ai] != B[bi])
                    break;

                long plus = Math.Min(a[ai] - aoffs, b[bi] - boffs);
                res += plus;
                aoffs += plus;
                boffs += plus;
                if (aoffs == a[ai])
                {
                    ai++;
                    aoffs = 0;
                }
                if (boffs == b[bi])
                {
                    bi++;
                    boffs = 0;
                }
            }

            res += Math.Max(_max(ai+1,0,bi,boffs),_max(ai,aoffs,bi+1,0));

            //  入力時と違うとこ指してるかも
            _set(ai, aoffs, bi, boffs, res);

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
