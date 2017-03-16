#include <cstdio>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int R, C, M, E;
bool flip;

void print(vector<string> ans)
{
	if(flip){
		vector<string> f(C, string(R, '.'));
		rep(i, R) rep(j, C)
			f[j][i] = ans[i][j];
		ans = f;
	}

	ans[0][0] = 'c';
	rep(i, ans.size()){
		puts(ans[i].c_str());
	}
}

void solve()
{
	scanf("%d%d%d", &R, &C, &M);
	E = R*C - M;

	flip = false;
	if(R>C){
		swap(R, C);
		flip = true;
	}

	vector<string> ans(R, string(C, '*'));

	if(E == 1){
		print(ans);
		return;
	}

	if(R == 1){
		rep(i, E) ans[0][i] = '.';
		print(ans);
		return;
	}

	if(R == 2){
		if(E%2 == 1 || E == 2){
			puts("Impossible");
		}
		else{
			rep(i, E/2) ans[0][i] = ans[1][i] = '.';
			print(ans);
		}
		return;
	}

	if(M <= (R-2)*(C-2)){
		int rem = M;
		int x=C-1, y=R-1;

		rep(i, R) rep(j, C) ans[i][j] = '.';
		while(rem){
			ans[y][x] = '*';
			--x;
			--rem;
			if(x == 1){
				x = C-1;
				--y;
			}
		}

		print(ans);
		return;
	}

	rep(_, 2){
		reps(w, 2, C+1){
			if(E%w == 1) continue;
			if(E/w < 2) continue;
			if((E+w-1)/w > R) continue;

			int rem = E;
			int x=0, y=0;
			while(rem){
				ans[y][x] = '.';
				--rem;
				x++;
				if(x == w){
					x = 0;
					++y;
				}
			}

			print(ans);
			return;
		}

		swap(R, C);
		flip = !flip;
		ans = vector<string>(R, string(C, '*'));
	}

	puts("Impossible");
	cerr << E << endl;
}

int main()
{
	int T;
	scanf("%d", &T);
	rep(i, T){
		printf("Case #%d:\n", i+1);
		solve();
	}

	return 0;
}
