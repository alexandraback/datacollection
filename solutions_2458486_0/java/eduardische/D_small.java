import java.io.*;

class D_small
{
	public static void main (String[] args)
	{
		try
		{
			InputStreamReader fi2 = new InputStreamReader(System.in);
			BufferedReader fi = new BufferedReader(fi2);
			int T = Integer.parseInt(fi.readLine());
			for (int iT = 0; iT < T; iT++)
			{
				System.out.print("Case #" + Integer.toString(iT+1) + ":");
				String[] ln = fi.readLine().split("\\s");
				int K = Integer.parseInt(ln[0]);
				int N = Integer.parseInt(ln[1]);
				int[] keys = new int[201];
				Boolean[] key_used = new Boolean[201];
				int i, j;
				for (i = 1; i <= 200; i++)
				{
					keys[i] = 0;
					key_used[i] = false;
				}
				ln = fi.readLine().split("\\s");
				for (String s: ln)
				{
					keys[Integer.parseInt(s)]++;
					key_used[Integer.parseInt(s)] = true;
				}
				int[] opens = new int[N];
				int[][] keys_locked = new int[N][201];
				for (i = 0; i < N; i++)
				{
					ln = fi.readLine().split("\\s");
					opens[i] = Integer.parseInt(ln[0]);
					key_used[Integer.parseInt(ln[0])] = true;
					K = Integer.parseInt(ln[1]);
					for (j = 1; j <= 200; j++) keys_locked[i][j] = 0;
					for (j = 0; j < K; j++)
					{
						keys_locked[i][Integer.parseInt(ln[j+2])]++;
						key_used[Integer.parseInt(ln[j+2])] = true;
					}
				}
				int[] kl = new int[201];
				int klc = 0;
				for (i = 1; i <= 200; i++)
				{
					if (key_used[i])
					{
						kl[klc] = i;
						klc++;
					}
				}
				int total = 1 << N;
				int[][] a = new int[total][N];
				for (i = 0; i < total; i++)
				{
					for (j = 0; j < N; j++) a[i][j] = N;
				}
				int mask, mask2;
				int[] k = new int[201];
				for (mask = 0; mask < total; mask++)
				{
					if ((mask == 0) || (a[mask][0] < N))
					{
						mask2 = mask;
						for (i = 1; i <= 200; i++) k[i] = keys[i];
						int len = 0;
						for (i = 0; i < N; i++)
						{
							if ((mask2 % 2) == 1)
							{
								len++;
								for (j = 0; j < klc; j++)
								{
									k[kl[j]] += keys_locked[i][kl[j]];
								}
								k[opens[i]]--;
							}
							mask2 /= 2;
						}
						Boolean flag = true;
						for (i = 1; i <= 200; i++)
						{
							if (k[i] < 0)
							{
								flag = false;
								break;
							}
						}
						if (flag)
						{
							mask2 = mask;
							for (i = 0; i < N; i++)
							{
								if (((mask2 % 2) == 0) && (k[opens[i]] > 0))
								{
									int newmask = mask + (1 << i);
									j = 0;
									while (j < len)
									{
										if (a[mask][j] == a[newmask][j]) j++;
										else break;
									}
									if (((j < len) && (a[mask][j] < a[newmask][j])) || (j == len))
									{
										for (j = 0; j < len; j++) a[newmask][j] = a[mask][j];
										a[newmask][len] = i;
									}
								}
								mask2 /= 2;
							}
						}
					}
				}

				if (a[total-1][0] == N) System.out.println(" IMPOSSIBLE");
				else
				{
					for (i = 0; i < N; i++) System.out.print(" " + Integer.toString(a[total-1][i] + 1));
					System.out.println();
				}

			}
		}
		catch (IOException e) {}
	}
}