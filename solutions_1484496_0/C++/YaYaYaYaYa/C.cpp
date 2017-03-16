#include <stdio.h>
#include <string.h>

int aa[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];

int main()
{
	int n, num, count;

	int number[20];
	bool find;
	char line[10000];
	
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &n);
	for (int ca = 1; ca <= n; ++ca)
	{
		scanf("%d", &num);find = false;
		for (int j = 0; j < num; ++j)
			scanf("%d", &number[j]);
		for (int a = 0; a <= 1; ++a)
			for (int b = 0; b <= 1; ++b)
				for (int c = 0; c <= 1; ++c)
					for (int d = 0; d <= 1; ++d)
						for (int e = 0; e <= 1; ++e)
							for (int f = 0; f <= 1; ++f)
								for (int g = 0; g <= 1; ++g)
									for (int h = 0; h <= 1; ++h)
										for (int i = 0; i <= 1; ++i)
											for (int j = 0; j <= 1; ++j)
												for (int k = 0; k <= 1; ++k)
													for (int l = 0; l <= 1; ++l)
														for (int m = 0; m <= 1; ++m)
															for (int n = 0; n <= 1; ++n)
																for (int o = 0; o <= 1; ++o)
																	for (int p = 0; p <= 1; ++p)
																		for (int q = 0; q <= 1; ++q)
																			for (int r = 0; r <= 1; ++r)
																				for (int s = 0; s <= 1; ++s)
																					for (int t = 0; t <= 1; ++t)
																						aa[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t] = a*number[0]
																						+b*number[1]+c*number[2]+d*number[3]+e*number[4]+f*number[5]+g*number[6]+
																						h*number[7]+i*number[8]+j*number[9]+k*number[10]+l*number[11]+m*number[12]+
																						n*number[13]+o*number[14]+p*number[15]+q*number[16]+r*number[17]+s*number[18]+
																						t*number[19];
		for (int a = 0; a <= 1; ++a)
			for (int b = 0; b <= 1; ++b)
				for (int c = 0; c <= 1; ++c)
					for (int d = 0; d <= 1; ++d)
						for (int e = 0; e <= 1; ++e)
							for (int f = 0; f <= 1; ++f)
								for (int g = 0; g <= 1; ++g)
									for (int h = 0; h <= 1; ++h)
										for (int i = 0; i <= 1; ++i)
											for (int j = 0; j <= 1; ++j)
												for (int k = 0; k <= 1; ++k)
													for (int l = 0; l <= 1; ++l)
														for (int m = 0; m <= 1; ++m)
															for (int n = 0; n <= 1; ++n)
																for (int o = 0; o <= 1; ++o)
																	for (int p = 0; p <= 1; ++p)
																		for (int q = 0; q <= 1; ++q)
																			for (int r = 0; r <= 1; ++r)
																				for (int s = 0; s <= 1; ++s)
																					for (int t = 0; t <= 1; ++t)
		for (int a_ = 0; a_ <= 1; ++a_)
			for (int b_ = 0; b_ <= 1; ++b_)
				for (int c_ = 0; c_ <= 1; ++c_)
					for (int d_ = 0; d_ <= 1; ++d_)
						for (int e_ = 0; e_ <= 1; ++e_)
							for (int f_ = 0; f_ <= 1; ++f_)
								for (int g_ = 0; g_ <= 1; ++g_)
									for (int h_ = 0; h_ <= 1; ++h_)
										for (int i_ = 0; i_ <= 1; ++i_)
											for (int j_ = 0; j_ <= 1; ++j_)
												for (int k_ = 0; k_ <= 1; ++k_)
													for (int l_ = 0; l_ <= 1; ++l_)
														for (int m_ = 0; m_ <= 1; ++m_)
															for (int n_ = 0; n_ <= 1; ++n_)
																for (int o_ = 0; o_ <= 1; ++o_)
																	for (int p_ = 0; p_ <= 1; ++p_)
																		for (int q_ = 0; q_ <= 1; ++q_)
																			for (int r_ = 0; r_ <= 1; ++r_)
																				for (int s_ = 0; s_ <= 1; ++s_)
																					for (int t_ = 0; t_ <= 1; ++t_)
		if (((a!=a_)||(b!=b_)||(c!=c_)||(d!=d_)||(e!=e_)||(f!=f_)||(g!=g_)||(h!=h_)||(i!=i_)||(j!=j_)||(k!=k_)||(l!=l_)||
		(m!=m_)||(n!=n_)||(o!=o_)||(p!=p_)||(q!=q_)||(r!=r_)||(s!=s_)||(t!=t_))&&
		aa[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]==aa[a_][b_][c_][d_][e_][f_][g_][h_][i_][j_][k_][l_][m_][n_][o_][p_][q_][r_][s_][t_])
		{
			line[0] = 0;
			printf("Case #%d:\n", ca);
			if (a) sprintf(line, "%s%d ", number[0]);
			if (b) sprintf(line, "%s%d ", line, number[1]);
			if (c) sprintf(line, "%s%d ", line, number[2]);
			if (d) sprintf(line, "%s%d ", line, number[3]);
			if (e) sprintf(line, "%s%d ", line, number[4]);
			if (f) sprintf(line, "%s%d ", line, number[5]);
			if (g) sprintf(line, "%s%d ", line, number[6]);
			if (h) sprintf(line, "%s%d ", line, number[7]);
			if (i) sprintf(line, "%s%d ", line, number[8]);
			if (j) sprintf(line, "%s%d ", line, number[9]);
			if (k) sprintf(line, "%s%d ", line, number[10]);
			if (l) sprintf(line, "%s%d ", line, number[11]);
			if (m) sprintf(line, "%s%d ", line, number[12]);
			if (n) sprintf(line, "%s%d ", line, number[13]);
			if (o) sprintf(line, "%s%d ", line, number[14]);
			if (p) sprintf(line, "%s%d ", line, number[15]);
			if (q) sprintf(line, "%s%d ", line, number[16]);
			if (r) sprintf(line, "%s%d ", line, number[17]);
			if (s) sprintf(line, "%s%d ", line, number[18]);
			if (t) sprintf(line, "%s%d ", line, number[19]);
			line[strlen(line)-1] = 0;
			puts(line);
			line[0] = 0;
			if (a_) sprintf(line, "%s%d ", number[0]);
			if (b_) sprintf(line, "%s%d ", line, number[1]);
			if (c_) sprintf(line, "%s%d ", line, number[2]);
			if (d_) sprintf(line, "%s%d ", line, number[3]);
			if (e_) sprintf(line, "%s%d ", line, number[4]);
			if (f_) sprintf(line, "%s%d ", line, number[5]);
			if (g_) sprintf(line, "%s%d ", line, number[6]);
			if (h_) sprintf(line, "%s%d ", line, number[7]);
			if (i_) sprintf(line, "%s%d ", line, number[8]);
			if (j_) sprintf(line, "%s%d ", line, number[9]);
			if (k_) sprintf(line, "%s%d ", line, number[10]);
			if (l_) sprintf(line, "%s%d ", line, number[11]);
			if (m_) sprintf(line, "%s%d ", line, number[12]);
			if (n_) sprintf(line, "%s%d ", line, number[13]);
			if (o_) sprintf(line, "%s%d ", line, number[14]);
			if (p_) sprintf(line, "%s%d ", line, number[15]);
			if (q_) sprintf(line, "%s%d ", line, number[16]);
			if (r_) sprintf(line, "%s%d ", line, number[17]);
			if (s_) sprintf(line, "%s%d ", line, number[18]);
			if (t_) sprintf(line, "%s%d ", line, number[19]);
			line[strlen(line)-1] = 0;
			puts(line);
			find = true;
			goto over;
		}
		over:
		if (!find)
		{
			printf("Case #%d:\n", ca);
			printf("Impossible\n");
		}
	}
	return 0;
}
