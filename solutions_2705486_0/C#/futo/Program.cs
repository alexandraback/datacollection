using System;
using System.IO;
using System.Collections.Generic;

namespace c
{


	class MainClass
	{
		public static int[] intvec(string s)
		{
			string[] x = s.Split (' ');
			int[] ret = new int[x.Length];
			for(int i = 0; i<ret.Length; i++)
				ret[i] = int.Parse (x[i]);
			
			return ret;
		}

		public static void go(string w, int index, Dictionary<string, bool> dd)
		{
			for(; index < w.Length; index++)
			{
				string newword = w.Substring (0, index) + "*" + w.Substring (index+1);
				dd[newword] = true;
				go (newword, index+5, dd);
			}
		}


		public static int checkword1(string s, Dictionary<string , bool> dd, int mini)
		{
			for(int i = mini; i<s.Length; i++)
			{
				if (dd.ContainsKey(s.Substring (0,i)+"*"+s.Substring (i+1)))
					return i;

			}

			return -1;
		}

		
		public static int checkword2(string s, Dictionary<string , bool> dd, int mini)
		{
			for(int i = mini; i<s.Length; i++)
				for(int j = mini; j<=i-5; j++)

				{
					if (dd.ContainsKey(s.Substring (0,j)+"*"+s.Substring (j+1, i-j-1)+"*"+s.Substring (i)))
						return i;
				}
			
			return -1;
		}

	


		public static void Main (string[] args)
		{
			TextReader r = new StreamReader(args[1]);
			TextWriter w = new StreamWriter(args[2]);

			TextReader rd = new StreamReader(args[0]);

			string[] dict= rd.ReadToEnd ().Split ('\n');
			int max = 0;

			Dictionary<string, bool> dd = new Dictionary<string, bool>();

			Console.Write ("Loading Dictionary ");
			foreach(var word in dict)
			{
				if (word.Length > max) max = word.Length;
				dd[word] = true;
				go (word, 0, dd);
			}
			Console.WriteLine (" {0} words, maxlen = {1}", dd.Count, max);

			Console.WriteLine (" Done");

			rd.Close ();



			int t = int.Parse (r.ReadLine ());
			
			for(int c = 1; c <= t; c++)
			{
				string ret = "";
				string word = r.ReadLine ();

				int n = word.Length;

				int[,] best = new int[n+1, 6];

				for(int i =0; i<n+1; i++)
					for(int j = 0; j<=5; j++)
						best[i,j] = 100000;

				best[0,0] = 0;

				for(int i = 0; i<n; i++)
					for(int j = 0; j<=5; j++)
				{
					if (best[i,j] == 100000) continue;

					 
					for(int len = 1; len<=10 && i+len<=n; len++)
					{
						int mmin = best[i,j];
						int nj, count;
						string ww = word.Substring (i, len);
						if (dd.ContainsKey (ww))
						{
							nj = j-len;
							if (nj < 0) nj = 0;

							if (mmin < best[i+len, nj])
								best[i+len, nj] = mmin;
						} else
						{
							if ((count = checkword1(ww, dd, j))>=0) 
							{
								nj = 5-len-count;
								if (nj < 0) nj = 0;
								if (mmin+1 < best[i+len, nj])
									best[i+len, nj] = mmin+1;

							}
							if ((count = checkword2(ww, dd, j))>=0) 
							{
								nj = 5-len-count;
								if (nj < 0) nj = 0;
								if (mmin+2 < best[i+len, nj])
									best[i+len, nj] = mmin+2;
								
							}
						}

					


					}

				}

				int sol = best[n, 0];
				for(int j = 1; j<=5; j++)
				{
					if (best[n, j] < sol) sol = best[n,j];
				}

				Console.WriteLine ("Case #{0}: {1}", c, sol);
				w.WriteLine ("Case #{0}: {1}", c, sol);
			}
			
			w.Close ();
			
		}

	}
}
