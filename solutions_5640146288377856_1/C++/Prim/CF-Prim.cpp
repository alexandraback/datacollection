#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define ii pair <int, int>
#define vii vector < ii >
#define vll vector <ll>
#define hash1 10000000000000061ll
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define na(x) ((x)<P?(x):(x)-P)
#define X first
#define Y second
using namespace std;
//__________________________

int n, t, ans,r,c,w;
//_________________________________________
int main(){

	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

	cin>>t;
	for(int t1 = 1; t1 <= t; ++t1){
		scanf("%d%d%d",&r,&c,&w);
		ans = r*(c/w);
		ans += w-1;
		if(c > w && c%w > 0) ans++;

		printf("Case #%d: %d\n", t1, ans);
	}

    return 0;
}
