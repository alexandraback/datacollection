using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace A
{
	public class DiamondInheritance
	{
		public void Solve(String input_path, String output_path)
		{
			ArrayList outputs = new ArrayList();
			using (FileStream fs = new FileStream(input_path, FileMode.Open))
			{
				using (StreamReader reader = new StreamReader(fs))
				{
					
					int n = Convert.ToInt32(reader.ReadLine());
					String output = "";
					while (!reader.EndOfStream)
					{
						for (int j = 0; j < n; j++)
						{
							String strs0 = reader.ReadLine();
							int N = Convert.ToInt32(strs0);
							String[] strs = new String[N];
							for (int i = 0; i < N; i++)
							{
								strs[i] = reader.ReadLine();
							}
							int[,] M = GetGraph(N, strs);
							if (FloydWarshall(M, N))
								output = "Yes";
							else
								output = "No";
							outputs.Add(output);
						}
					}
				}
			}

			using (FileStream wfs = new FileStream(output_path, FileMode.Create))
			{
				using (StreamWriter writter = new StreamWriter(wfs))
				{
					int i = 0;
					foreach (String str in outputs)
					{
						String s = "Case #" + (++i) + ": ";
						s += str;
						writter.WriteLine(s);
					}
				}
			}
		}
		int[,] GetGraph(int N, String[] strs)
		{
			int[,] M = new int[N, N];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					M[i, j] = 10000;

			for (int i = 0; i < N; i++)
			{
				String row = strs[i];
				String[] nums = row.Split(' ');
				int m = Convert.ToInt32(nums[0]) + 1;
				for (int j = 1; j < m; j++)
				{
					int neighbor = Convert.ToInt32(nums[j]) - 1;
					M[i, neighbor] = 1;
				}
			}
			return M;
		}

		private bool FloydWarshall(int [,] matrix, int N)
		{
			for (int k = 0; k < N; k++)
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
					{
						int p_ij = matrix[i,j];
						int p_ik = matrix[i,k];
						int p_kj = matrix[k,j];

						if (p_ik != 10000 && p_kj != 10000)
						{
							if (p_ij != 10000)
								return true;
							int d = p_ik + p_kj;
							matrix[i, j] = d;
						}
					}
			return false;
		}
	}
}
