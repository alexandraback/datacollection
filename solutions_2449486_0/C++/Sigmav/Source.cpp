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
typedef unsigned long	ul;
typedef vector<ul>		vul;
typedef vector<bool>	vb;
typedef vector<vi>		vvi;
typedef vector<vii>		vvii;
typedef vector<double>	vd;
#define INF 1000000000
#define PI 3.14159265

vvi lawn;
int START_HEIGHT = 2;

bool path_to_edge(int x, int y, int h, int N, int M) {
	//if (x==0 || x==N-1 || y==0 || y==M-1) return true;

	// try <-->
	bool pos = true;
	for (int p=0; p<N; p++) 
		pos = pos && (lawn[p][y] <= h);
	if (pos) return true;

	// try /\  \/ 
	pos = true;
	for (int p=0; p<M; p++) 
		pos = pos && (lawn[x][p] <= h);
	return pos;
}

int main(int argc, char *argv[]){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	// init
	for (int i=0; i<105; i++) {
		vi row(105,100);
		lawn.push_back(row);
	}

	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {

		// Input
		int N, M;
		cin >> N >> M;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				cin >> lawn[i][j];
			}
		}

		bool out = true;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				out = out && path_to_edge(i,j,lawn[i][j],N,M);
				//if (!out) cout << i << " " << j << endl;
			}
		}
		
		if (out) cout << "Case #" << t << ": YES\n";
		else cout << "Case #" << t << ": NO\n";
	}


	return EXIT_SUCCESS;
}