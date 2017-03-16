#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

static int R, C, M, target;
static ifstream in;
static ofstream out;

static vector<vector<char>> b;
static vector<vector<bool>> f;
static vector<vector<bool>> v;

static int click;

void verRec(int i, int j){
	if (b[i][j] == '*')
		return;

	if (f[i][j])
		return;

	f[i][j] = true;
	v[i][j] = true;

	int si = max(0, i - 1);
	int sj = max(0, j - 1);
	int ei = min(i + 2, R);
	int ej = min(j + 2, C);

	int count = 0;
	for (int p=si; p < ei; ++p){
		for (int q=sj; q < ej; ++q){
			count += (b[p][q] == '*');
		}
	}

	if (count){
		return;
	}

	for (int p = si; p < ei; ++p){
		for (int q = sj; q < ej; ++q){
			v[p][q] = true;
			verRec(p, q);
		}
	}	
}

bool verify(int i, int j){
	v.assign(R, vector<bool>(C));
	f.assign(R, vector<bool>(C));
	verRec(i, j);
	for (int p = 0; p < R; ++p){
		for (int q = 0; q < C; ++q){
			if (!v[p][q] && b[p][q] == '.')
				return false;
		}
	}
	return true;
}

bool rec(int num, int m){
	if (m == M){
		for (int p = 0; p < R; ++p){
			for (int q = 0; q < C; ++q){
				if (b[p][q] == '.' && verify(p, q)){
					click = p*C+q;
					return true;
				}
			}
		}
		return false;
	}

	b[num / C][num % C] = '*';

	if (rec(num + 1, m + 1))
		return true;

	b[num / C][num % C] = '.';

	if (R*C-num-1 >= M-m){
		return rec(num + 1, m);
	}

	return false;
}

void proc(int tc){
	in >> R >> C >> M;
	target = R * C - M;

	out << "Case #" << tc << ":" << endl;
	
	b.assign(R, vector<char>(C, '.'));
	if (rec(0, 0)){
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < C; ++j){
				if (i*C + j == click)
					out << 'c';
				else
					out << b[i][j];
			}
			out << endl;
		}
	}
	else{
		out << "Impossible" << endl;
	}
}

int main(){
	in.open("C-small-attempt3.in");
	out.open("C-small-attempt3.out");

	int T;
	in >> T;
	for (int tc = 1; tc <= T; ++tc){
		proc(tc);
	}
}