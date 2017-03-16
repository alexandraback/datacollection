#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <string.h>
#include <list>
#include <time.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define PI 3.14159265358979
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define L(s) (int)((s).size())
#define sz(s) (int)((s).size())
#define ms(x) memset(x,0,sizeof(x))
#define ms1(x) memset(x,-1,sizeof(x))
#define del(y,x) erase(y.begin()+x)

typedef long long ll;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const ll MOD = 1000000007;

ll ABS(ll a) {
    if(a<0)
        return a*(-1);
    else
        return a;
}

//vector<int> raz;
//vector<int> pr;
//vector<bool> prime(60,true);
//void gen()
//{
//	prime[1] = false;
//	for(int i = 2;i <=50;i++)
//	{
//		if(prime[i])
//		{
//			for(int j = i * i;j<=50;j+=i)
//			{
//				prime[j] = false;
//			}
//			pr.pb(i);
//		}
//	}
//}
vector<vector<int> > mat;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int test = 1;
	while(T--)
	{
		mat.clear();
		ll n,ch;
		cin >> n >> ch;
		mat.resize(n);
		for(int i = 0;i < n;i++)
		{
			mat[i].resize(n);
			for(int j = 0;j < n;j++)
			{
				mat[i][j] = 0;
			}
		}
		int mx = n - 2;
		vector<ll> prev;
		for(int i = 0;i < mx;i++)
		{
			ll sum = 1;
			for(int j = 0;j < i;j++)
			{
				sum+=prev[j];
			}
			prev.pb(sum);
		}
		for(int i = 1;i < n - 1;i++)
		{
			for(int j = 1;j < i;j++)
			{
				mat[i][j] = 1;
			}
			mat[i][n-1] = 1;
		}
		int uk = L(prev) - 1;
		while(ch && uk>=0)
		{
			if(ch>=prev[uk])
			{
				ch-=prev[uk];
				mat[0][uk + 1] = 1;
			}
			uk--;
		}
		if(ch==1){
			mat[0][n-1] = 1;
			ch--;
		}
		printf("Case #%d: ",test++);
		if(ch==0)
		{
			printf("POSSIBLE\n");
			for(int i = 0;i < n;i++)
			{
				for(int j = 0;j < n;j++)
				{
					cout << mat[i][j];
				}
				cout << endl;
			}
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}

	}

    return 0;
}