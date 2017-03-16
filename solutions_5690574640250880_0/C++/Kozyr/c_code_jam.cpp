#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct {
public:
	int R;
	int C;
	int M;
} Data;

int m[50][50];

void clear(int v) {
	for (int i=0; i<50; i++) {
		for (int j=0; j<50; j++) {
			m[j][i] = v;
		}
	}
}

void print(int R, int C, bool transpose) {
	if (!transpose) {
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				int v = m[i][j];

				switch(v){
				case 0: cout << "."; break;
				case 1: cout << "*"; break;
				case 2: cout << "c"; break;
				}
			}
			cout << endl;
		}
	}
	else {
		for (int j=0; j<R; j++) {
			for (int i=0; i<C; i++) {
				int v = m[i][j];

				switch(v){
				case 0: cout << "."; break;
				case 1: cout << "*"; break;
				case 2: cout << "c"; break;
				}
			}
			cout << endl;
		}
	}
}

void full(int R, int C, char c) {
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (i==(R-1) && j==(C-1))
				cout << "c";
			else
				cout << c;
		}
		cout << endl;
	}
}

int main() {
	int N;

	vector<Data> mD;

	cin >> N;

	int n;
	for (n=1; n<=N; n++) {

		Data d;
		cin >> d.R >> d.C >> d.M;

		mD.push_back(d);
	}

	vector<Data>::iterator iter;
	n=1;

	for(iter=mD.begin(); iter!=mD.end(); iter++)
	{
		cout << "Case #" << n++ << ":" << endl;

		Data d = (*iter);
		//cout << d.R << " " << d.C << " " << d.M << endl;

		int R = min(d.R, d.C);
		int C = max(d.R, d.C);
		bool trans = (d.R > d.C);

		bool imp = false;

		int M = d.M;
		int F = R*C - M;

		if (M == 0) {
			clear(0);
			m[0][0] = 2;
		}
		else if (F == 1) {
			clear(1);
			m[0][0] = 2;
		}
		else if (R == 1) {
			clear(1);
			m[0][0] = 2;
			for(int i=1; i<F; i++)
				m[0][i] = 0;
		}
		else if (R == 2) {
			if (F%2 == 1 || F < 4)
				imp = true;
			else {
				clear(1);
				for(int i=0; i<F/2; i++) {
					m[0][i] = 0;
					m[1][i] = 0;
				}
				m[0][0] = 2;
			}
		}
		else if (F == 2 || F == 3 || F == 5 || F == 7) {
			imp = true;
		}
		else if (F == 4) {
			clear(1);
			m[0][0] = 2;
			m[0][1] = 0;
			m[1][0] = 0;
			m[1][1] = 0;
		}
		else if (F == 6) {
			clear(1);
			m[0][0] = 0;
			m[0][1] = 0;
			m[1][0] = 2;
			m[1][1] = 0;
			m[2][0] = 0;
			m[2][1] = 0;
		}
		else if (F == 9) {
			clear(1);
			m[0][0] = 0;
			m[0][1] = 0;
			m[0][2] = 0;
			m[1][0] = 0;
			m[1][1] = 2;
			m[1][2] = 0;
			m[2][0] = 0;
			m[2][1] = 0;
			m[2][2] = 0;
		}
		else if (M <= (C-2)) {
			clear(0);
			for(int i=0; i<M; i++) {
				m[0][i] = 1;
			}
			m[R-1][C-1] = 2;
		}
		else {
			clear(0);
			while (M>=min(R, C)) {
				if (R<=C) {
					int j = C-1;
					for(int i=0; i<R; i++) {
						m[i][j] = 1;
					}
					M -= R;
					C--;
				}
				else {
					int i = R-1;
					for(int j=0; j<C; j++) {
						m[i][j] = 1;
					}
					M -= C;
					R--;
				}
			}
			if (M == min(R, C)) {
				if (R<=C) {
					for(int i=0; i<R; i++) {
						m[i][C-1] = 1;
					}
				}
				else {
					for(int j=0; j<C; j++) {
						m[R-1][j] = 1;
					}
				}
				m[0][0] = 2;
			}
			else if (M <= max(R, C)-2) {
				if (R<=C) {
					for(int j=0; j<M; j++) {
						m[R-1][C-j-1] = 1;
					}
				}
				else {
					for(int i=0; i<M; i++) {
						m[R-i-1][C-1] = 1;
					}
				}
				m[0][0] = 2;
			}
			else {
				m[R-1][C-1] = 1;
				M--;
				int i=2;
				while (M > 0) {
					m[R-i][C-1] = 1;
					if (M > 1)
						m[R-1][C-i] = 1;
					i ++;
					M -= 2;
				}
				m[0][0] = 2;
			}
		}
		if (imp)
			cout << "Impossible" << endl;
		else
			print(d.R, d.C, trans);
	}

	return 0;
}

