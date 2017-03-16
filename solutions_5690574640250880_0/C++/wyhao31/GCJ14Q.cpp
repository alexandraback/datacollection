#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in("C-small-attempt7.in.txt");
ofstream out("C-small-out");
//#define in cin
//#define out cout

bool work(vector<int> &c, int minv, int maxv, int sum, int dep) {
	if (sum == 0) return true;
	if (dep == 0) return false;
	for (int i = maxv; i >= minv; i--) {
		if (sum - i < 0) continue;
		c.push_back(i);
		if (work(c, minv, i, sum-i, dep-1)) return true;
		c.pop_back();
	}
	return false;
}

int main()
{
	int T, R, C, M;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> R >> C >> M;
		char board[64][64];
		memset(board, '*', sizeof(board));
		bool flag = false;
		if (R == 1 || C == 1) {
			if (R == 1 && C == 1) {
				if (M == 0) {
					board[0][0] = 'c';
					flag = true;
				}
			} else if (R == 1) {
				if (M < R * C) {
					board[0][0] = 'c';
					for (int i = 1; i < C - M; i++) board[0][i] = '.';
					flag = true;
				}
			} else if (C == 1) {
				if (M < R * C) {
					board[0][0] = 'c';
					for (int i = 1; i < R - M; i++) board[i][0] = '.';
					flag = true;
				}
			}
		} else {
			int NM = R * C - M;
			if (NM < 4) {
				if (NM == 1) {
					board[0][0] = 'c';
					flag = true;
				}
			} else {
				for (int i = 2; i <= C; i++) {
					int l = NM-2*i;
					if (l == 0) {
						for (int p = 0; p < 2; p++)
							for (int q = 0; q < i; q++)
								board[p][q] = '.';
						board[0][0] = 'c';
						flag = true;
						break;
					} else {
						vector<int> vi;
						if (work(vi, 2, i, l, R-2)) {
							flag = true;
							for (int p = 0; p < 2; p++)
								for (int q = 0; q < i; q++)
									board[p][q] = '.';	
							for (int p = 0; p < vi.size(); p++) {
								for (int q = 0; q < vi[p]; q++)
									board[2+p][q] = '.';
							}
							board[0][0] = 'c';
							break;
						}
					}
				}
			}
		}		
		out << "Case #" << cnt << ":" << endl;
		if (flag) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)
					out << board[i][j];
				out << endl;
			}
		} else {
			out << "Impossible" << endl;
		}
	}
	return 0;
}


// C
/*
int main()
{
	int T, R, C, M;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> R >> C >> M;
		char board[64][64];
		memset(board, '*', sizeof(board));
		bool flag = false;
		if (R == 1 || C == 1) {
			if (R == 1 && C == 1) {
				if (M == 0) {
					board[0][0] = 'c';
					flag = true;
				}
			} else if (R == 1) {
				if (M < R * C) {
					board[0][0] = 'c';
					for (int i = 1; i < C - M; i++) board[0][i] = '.';
					flag = true;
				}
			} else if (C == 1) {
				if (M < R * C) {
					board[0][0] = 'c';
					for (int i = 1; i < R - M; i++) board[i][0] = '.';
					flag = true;
				}
			}
		} else {
			if (M > R * C - 4) {
				if (M == R * C - 1) {
					board[0][0] = 'c';
					flag = true;
				}
			} else {
				int NM = R * C - M;
				for (int h = 2; h <= R; h++) {
					int w = NM / h;
					if (w <= 1 || w > C || (w >= C && w * h < NM)) continue;
					else {
						int l = NM - w * h;
						if (l == 0 || (l >= 2 && l <= h-1)) {
							for (int i = 0; i < h; i++)
								for (int j = 0; j < w; j++)
									board[i][j] = '.';
							for (int i = 0; i < l; i++)
								board[i][w] = '.';
							board[0][0] = 'c';
							flag = true;
							break;
						} else {
							if ((h == 3 && R == 3 && w >= 5) || (h >= 4 && R >= 4 && w >= 5)) {
								for (int i = 0; i < h; i++)
									for (int j = 0; j < w; j++)
										board[i][j] = '.';
								board[0][w] = board[1][w] = '.';
								board[0][2] = '*';
								board[0][0] = 'c';
								flag = true;
								break;					
							}
						}
					}
				}
			}
		}

		out << "Case #" << cnt << ":" << endl;
		if (flag) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)
					out << board[i][j];
				out << endl;
			}
		} else {
			out << "Impossible" << endl;
		}
	}
	return 0;
}
*/

/*
// D
bool cmp(double d1, double d2) {
	return d1 > d2;
}

int playDWar(double *Naomi, double *Ken, int N) {
	sort(Naomi, Naomi + N);
	sort(Ken, Ken + N);
	int kl = 0, kr = N-1;
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (Naomi[i] > Ken[kl]) {
			res++;
			kl++;
		} else {
			kr--;
		}
	}
	return res;
}

int playWar(double *Naomi, double *Ken, int N) {
	bool f[1024];
	memset(f, false, sizeof(f));
	sort(Naomi, Naomi + N);
	sort(Ken, Ken + N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		bool lose = false;
		for (int j = 0; j < N; j++) {
			if (!f[j] && Ken[j] > Naomi[i]) {
				f[j] = true;
				lose = true;
				break;
			}
		}
		if (!lose) res++;
	}
	return res;
}

int main()
{
	int T, N;
	double Naomi[1024], Ken[1024];
	in >> T;
	for (int cnt = 1; cnt <= T; cnt ++) {
		in >> N;
		for (int i = 0; i < N; i++) in >> Naomi[i];
		for (int i = 0; i < N; i++) in >> Ken[i];
		out << "Case #" << cnt << ": " << playDWar(Naomi, Ken, N) << " " << playWar(Naomi, Ken, N) << endl;
	}
	return 0;
}
*/


/*
// B
int main()
{
	int T;
	double C, F, X;
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		in >> C >> F >> X;
		int N = floor((F * X / C - F - 2) / F);
		if (N < 0) N = 0;
		else N++;
		double res = 0;
		for (int i = 0; i < N; i++) {
			res += (C / (2+i*F));
		}
		res += X / (2+N*F);
		out << "Case #" << cnt << ": " << fixed << setprecision(7) << res << endl;
	}
	return 0;
}
*/
/*
// A
int main()
{
	int T;
	bool flag[17];
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		memset(flag, 0, sizeof(flag));
		int a1, a2, t;
		in >> a1;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				in >> t;
				if (a1 == i) flag[t] = true;
			}
		}
		in >> a2;
		int hit = 0, res;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				in >> t;
				if (a2 == i && flag[t] == true) {
					hit++;
					res = t;
				}
			}
		}
		out << "Case #" << cnt << ": ";
		if (hit == 1) out << res;
		else if (hit == 0) out << "Volunteer cheated!";
		else out << "Bad magician!";
		out << endl;
	}
	return 0;
}
*/