// template

#include "stdafx.h"

#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define rep(i,m) for(int i=0;i<(int)(m);i++)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;

int R, N, M, K;
vector<int> product;
int ans[3];
bool check(int a, int b, int c)
{
	vector<int> p;
	p.clear();
	int count = 0;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
			{
				p.push_back( a*i + b*j + c*k);
			}
	for (int i=0; i<K; i++)
		if (find(p.begin(), p.end(), product[i]) == p.end()) return false;
	return true;
}
void Solve()
{
	for (int i=2; i<=5; i++)
		for (int j=2; j<=5; j++)
			for (int k=2;k<=5; k++)
			{
				if (check(i, j, k)) 
					{
						ans[0] = i;
						ans[1] = j;
						ans[2] = k;
						return;
				}
			}
}
#define SMALL
//#define LARGE
int main() {
	freopen("c.txt", "rt", stdin);
#ifdef SMALL
	freopen("C-small-1-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.out","wt",stdout);
#endif
	int T;

	int tmp;
	cin >> T;
	for (int i =1; i<=T; i++)
	{
		cout << "Case #" << i << ": ";
		cin >> R >> N >> M >> K;
		for (int k=0; k<R; k++)
		{
			product.clear();
			for (int j=0; j<K; j++)
			{
				cin >> tmp;
				product.push_back(tmp);
			}
			Solve();
			cout << ans[0] << ans[1] << ans[2] << endl;
		}
	}
}




