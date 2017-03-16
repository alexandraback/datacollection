#include <bits/stdc++.h>
#include <unordered_map>
#include <initializer_list>
#include <memory>
#include <vector>
#define mp make_pair
#define pb push_back
#define lo int
#define li long long int
#define db double

#define sz(a) (lo)(a).size()
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
#define DEB(...) fprintf(stderr, __VA_ARGS__)

//=======================
//#define pi 3.14159265358979323
#define eps 1e-9
#define INF 2e9
#define MN 1010
#define SM 2000
//=====================================================

int sign(int a){
	if(a > 0)
		return 1;
	return -1;
}
int q(int a, int b){
	static int ma[4][4] ={
			{
		        1, 2, 3, 4
			},
			{
				2, -1, 4, -3
			},
			{
				3, -4, -1, 2
			},
			{
			    4, 3, -2, -1
			}
	};
	return sign(a) * sign(b) * ma[abs(a) - 1][abs(b) - 1];
}

int binpow(int a, li b){
	if(!b)
		return 1;
	if(b & 1){
		return q(binpow(a, b - 1), a);
	}
	int res = binpow(a, b/  2);
	return q(res, res);
}

int tr(char a){
	static map<char, int> mp= {
			{'i', 2},
			{'j', 3},
			{'k', 4}
	};
	return mp[a];
}

int rev(int a){
	if(abs(a)== 1)
		return a;
	return -a;
}

int ma[1000][1000];
pair<int, int> step[4] = { mp(0, 1), mp(0, -1), mp(1, 0), mp(-1, 0) };
void gen(int x, int y, int ost, vector<pair<int, int>>& ans, vector<vector<pair<int, int>>> & used){
	ans.pb(mp(x, y));
	if(!ost){
		used.pb(ans);
		ans.pop_back();
		return;
	}
	ma[x][y]++;
	FOR(k, 4){
		int i = x + step[k].first;
		int j = x + step[k].second;
		if(i >= 0 && j >= 0 && !ma[i][j]){
			gen(i, j, ost - 1, ans, used);
		}
	}
	ma[x][y]--;
	ans.pop_back();
}

bool apply(int x, int y, int R, int C, int ost, vector<pair<int, int>>& ans, int color){
	if(x < 0 || y < 0 || x >= R || y >= C || ma[x][y] == color)
		return false;
	ma[x][y] = color;
	if(!ost){
		return true;
	}
	int ret = apply(x + ans[ost - 1].first - ans[ost].first, y + ans[ost - 1].second - ans[ost].second, R, C, ost - 1, ans, color);
	if(!ret){
		ma[x][y] = 1 - color;
	}
	return ret;
}

void revx(vector<vector<pair<int, int>>> &used){

}

bool solve(int X, int R, int C, int stage, vector<vector<pair<int, int>>> &used){
	if(!stage){
		used.clear();
		vector<pair<int, int> > temp;
		gen(200, 200, X - 1, temp, used);
		FOR(i, sz(used)){
			DEB("{{");
			FOR(j, sz(used[i])){
				DEB("{%d, %d}, ", used[i][j].first, used[i][j].second);
			}
			DEB("}, 2},\n");
		}
		for(auto item : used){
			bool res = false;
			FOR(i, R) FOR(j, C) {
				if(!res && apply(i, j, R, C, X - 1, item, 1)){
					int ret = solve(X, R, C, stage + 1, used);
					apply(i, j, R, C, X - 1, item, 0);
					if(ret){
						res = true;
					}
				}
			}
			if(!res)
				return false;
		}
		return true;
	}
	if(stage * X == R * C)
		return true;
	FOR(i, R) FOR(j, C){
		for(auto item : used){
			if(apply(i, j, R, C, X - 1, item, 1)){
				int ret = solve(X, R, C, stage + 1, used);
				apply(i, j, R, C, X - 1, item, 0);
				if(ret)
					return true;
			}
		}
	}
	return false;
}

bool answer(int X, int R, int C){
	if(X == 1)
		return true;
	if(X ==2){
		return (R % 2 == 0 || C % 2 == 0);
	}
	if(R > C)
		swap(R, C);
	if(C < X){
		return false;
	}
	if(X == 3){
		if(C == 3){
			if(R == 1)
				return false;
			return true;
		}
		return R == 3;
	}
	if(R <= 2)
		return false;
	return true;
}
int main()
{
#ifdef MYLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("matan.in", "r", stdin);
//    freopen("matan.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T;i++){
    	int X, R, C;
    	cin >> X >> R >> C;
    	vector<vector<pair<int, int>>> used;
    	string res = (answer(X, R, C) ? "GABRIEL" : "RICHARD");
    	printf("Case #%d: ", i);
    	cout << res << endl;
    }
}
