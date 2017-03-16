#define _CRT_SECURE_NO_DEPRECATE
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <queue>
#include <set>	
#include <cstring>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ii, int>	iii;
typedef vector<ii>		vii;
typedef vector<iii>		viii;
typedef vector<int>		vi;
typedef vector<char>	vc;
typedef vector<vc>		vvc;
typedef vector<string>	vs;
typedef unsigned long long	ull;
typedef vector<ull>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265


int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int R,C,M;
		cin >> R >> C >> M;
		//cout << R << " " << C << " " << M << "(" << (R*C - M) << ")" << endl;

		string out = "";
		if (M == R*C-1) {
			vvc out_arr(R,vc(C,'*'));
			out_arr[0][0] = 'c';
			
			for (int r=0; r<R; r++) {
				if (r!=0) out += '\n';
				for (int c=0; c<C; c++) {
					out += out_arr[r][c];
				}
			}
		} else if (R==1 && C==1) {
			out = "c";
		} else if (R == 1) {
			if (M <= C - 2) {
				out = "c.";
				int i = 0;
				for (;i < C-M-2; i++) out += ".";
				for (i += 2; i<C; i++) out += "*";
			} else out = "Impossible";
		} else if (C == 1) {
			if (M <= R - 2) {
				out = "c\n.";
				int i = 0;
				for (;i < R-M-2; i++) out += "\n.";
				for (i += 2; i<R; i++) out += "\n*";
			} else out = "Impossible";
		} else if (R == 2) {
			int remaining_empty = C*R - 4 - M;
			if (remaining_empty <  0 || remaining_empty % 2 == 1) {
				out = "Impossible";
			} else {
				out = "c.";
				int i = 0;
				for (;i < remaining_empty/2; i++) out += ".";
				for (i += 2; i<C; i++) out += "*";
				out += "\n..";
				i = 0;
				for (;i < remaining_empty/2; i++) out += ".";
				for (i += 2; i<C; i++) out += "*";
			}
		} else if (C == 2) {
			int remaining_empty = C*R - 4 - M;
			if (remaining_empty <  0 || remaining_empty % 2 == 1) {
				out = "Impossible";
			} else {
				out = "c.\n..";
				int i = 0;
				for (;i < remaining_empty/2; i++) out += "\n..";
				for (i += 2; i<R; i++) out += "\n**";
			}
		} else {
			int remaining_empty = C*R - 4 - M;
			
			bool failure = (remaining_empty <  0) || 
						   (remaining_empty == 1) || 
						   (remaining_empty == 3) ;
			if (!failure) {
				vvc out_arr(R,vc(C,'*'));

				out_arr[0][0] = 'c';
				out_arr[0][1] = '.';
				out_arr[1][0] = '.';
				out_arr[1][1] = '.';

				// 2 lines completely filled
				if (remaining_empty >= (C - 2) * 2 + 2) {
					for (int c=2; c<C; c++) {
						remaining_empty -= 2;
						out_arr[0][c] = '.';
						out_arr[1][c] = '.';
					}
					int r = 2;
					for (; remaining_empty > 0 &&  r<R; r++) {
						for (int c=0; remaining_empty > 0 && c<C; c++) {
							out_arr[r][c] = '.';
							remaining_empty --;
						}
					}
					// .....
					// .....
					// .****
					// 1 left on new line: add one of previous
					r = R-1;
					while (out_arr[r][0] == '*') r--;
					if (out_arr[r][0] == '.' && out_arr[r][1] == '*') {
						out_arr[r][1] = '.';
						out_arr[r-1][C-1] = '*';
					}

				} else {
					// ....*
					// ....*
					// *****
					if (remaining_empty % 2 == 1)  {
						out_arr[2][0] = '.';
						out_arr[2][1] = '.';
						out_arr[2][2] = '.';
						remaining_empty -= 3;
					}
					for (int c=2; remaining_empty > 0; c++) {
						out_arr[0][c] = '.';
						out_arr[1][c] = '.';
						remaining_empty -= 2;
					}
				}

				for (int r=0; r<R; r++) {
					if (r!=0) out += '\n';
					for (int c=0; c<C; c++) {
						out += out_arr[r][c];
					}
				}

			}
			if (failure) out = "Impossible";
		}



		cout << "Case #"<< t<< ":\n" << out << endl;
	}



	return EXIT_SUCCESS;
}