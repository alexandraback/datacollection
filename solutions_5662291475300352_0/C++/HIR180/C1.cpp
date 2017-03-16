#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int t; cin >> t;
	for(int ss=1;ss<=t;ss++)
	{
		printf("Case #%d: ",ss);
		int n;
		int pos,num,sp;
		cin >> n;
		P p[2]; int nx=0;
		for(int i=0;i<n;i++)
		{
			cin >> pos >> num >> sp;
			for(int j=0;j<num;j++)
			{
				p[nx+j] = mp(pos,sp+j);
			}
			nx+=num;
		}
		sort(p,p+nx);
		if(nx == 1)
		{
			cout << 0 << endl; continue;
		}
		else
		{
			if(p[0].sc < p[1].sc)
			{
				ll t0 = 1LL*(720-p[0].fi) * p[0].sc;
				ll t1 = 1LL*(360-p[1].fi) * p[1].sc;
				cout << (t0<=t1) << endl;
			}
			else
			{
				ll t0 = 1LL*(360-p[0].fi) * p[0].sc;
				ll t1 = 1LL*(720-p[1].fi) * p[1].sc;
				cout << (t1<=t0) << endl;
			}
		}
	}
}