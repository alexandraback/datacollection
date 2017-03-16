#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

typedef long long ll;

char D[10005];

int DB[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2,-1, 4,-3},
	{0, 3,-4,-1, 2},
	{0, 4, 3,-2,-1}
};

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		ll X;
		int N;
		scanf("%d%lld%s", &N, &X, D);
		int res = 1, sign = 1, piv = 1, tot = 1;
		for(int k = 0; k < 10 && k < X; k++){
			for(int i = 0; i < N; i++){
				int c = D[i] == 'i'? 2: D[i] =='j'? 3 : 4;
				res = DB[res][c];
				if( res < 0 ) sign = -sign, res = -res;
				if( piv == 1 && res == 2 && sign == 1 ) piv++;
				else if( piv == 2 && res == 4 && sign == 1 ) piv++;
			}
			if( k == 0 ) tot = sign * res;
		}
		//*
		int mul = tot, as = 1;
		while(X){
			if( X&1 ){
				if( (as < 0) ^ (mul < 0 ) ) as = -DB[abs(as)][abs(mul)];
				else as = DB[abs(as)][abs(mul)];
			}
			mul = DB[abs(mul)][abs(mul)]; X /= 2;
		}//*/
		/*
		for(int k = 10; k < X; k++){
			if( tot < 0 ) res = -DB[res][-tot];
			else res = DB[res][tot];
			if( res < 0 ) sign = -sign, res = -res;
		}//*/

		string ans;
		if( as == -1 && piv == 3) ans = "YES";
		else ans = "NO";
		printf("Case #%d: %s\n", t, ans.c_str());
	}
	return 0;
}