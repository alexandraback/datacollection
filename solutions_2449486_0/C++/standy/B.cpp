#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN = 110;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef vector <string> VS;
typedef vector <LL> VL;

int G[MAXN][MAXN];

int main()
{
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int T;	cin >> T;
	
	for(int cas = 1; cas <= T; ++ cas)
	{
		int N, M;
		cin >> N >> M;
		for(int i = 0; i < N; ++ i)
			for(int j = 0; j < M; ++ j)
				cin >> G[i][j];
		
		bool flag = 1;
		for(int i = 0; i < N; ++ i)
			for(int j = 0; j < M; ++ j)
			{
				bool rBig = 0;
				for(int c = 0; c < M; ++ c)
					if(G[i][c] > G[i][j])
						rBig = 1;
				bool cBig = 0;
				for(int r = 0; r < N; ++ r)
					if(G[r][j] > G[i][j])
						cBig = 1;
				if(rBig && cBig)	flag = 0;	
			}
		
		cout << "Case #" << cas << ": " << (flag ? "YES" : "NO") << endl; 
	}
	
	
	return 0;	
}
