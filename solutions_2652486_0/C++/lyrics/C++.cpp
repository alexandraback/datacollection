#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#define sz(a) ((int)(a).size())
#define foreach(i, Type, v) for(Type::iterator i=v.begin(); i!=v.end(); i++)
using namespace std;
typedef long long llong;
typedef pair<int, int> Item;

const int Maxn = 1000+10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int compareTo(double a, double b) { return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }

int a[10];

int main()
{
	int cas, R, N, M, K;
	ios::sync_with_stdio(0);
	freopen("aaa.in", "r", stdin);
	freopen("aaa.out", "w", stdout);

	cin>>cas;
	for(int c=1; c<=cas; c++)
	{
		cin>>R>>N>>M>>K;
		printf("Case #%d:\n", c);
		for(int _r=0; _r<R; _r++)
		{
			for(int _k=0; _k<K; _k++)
				cin>>a[_k];
			bool f = false;
			for(int i=2; !f&&i<=M; i++)
			for(int j=i; !f&&j<=M; j++)
			for(int k=j; !f&&k<=M; k++)
			{
				set<int> st;
				st.insert(1);  st.insert(i);  st.insert(j);  st.insert(k);
				st.insert(i*j);  st.insert(i*k);  st.insert(j*k);  st.insert(i*j*k);
				bool flags = true;
				for(int l=0; l<K; l++)
					if( st.find(a[l]) == st.end() )
					{
						flags = false;
						break;
					}
				if( flags )
				{
					f = true;
					printf("%d%d%d\n", i, j, k);
				}
			}
		}
	}

	return 0;
}
