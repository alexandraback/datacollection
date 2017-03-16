#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;

const double PI = acos(-1.0);
#define FOR(a,b) for(int i = a; i< b; ++i)
#define SORT(a,b) sort(a.begin(),a.end(),b)
#define MEMS(a,b) memset(a,b,sizeof(a))
template<class T>
inline T gcd(T a , T b) { if(a == 0 || b == 0 || a == b) return max(a,b); return a>b?gcd(a%b,b) : gcd(a,b%a);}
string intToStr(int n) { char p[15];sprintf(p,"%d",n);return string(p);}
int strToInt(string s) { istringstream sin(s); int r; sin >> r; return r;} 

bool Find = false;
set<int> Have;
vector<int> num;
int find_sum = 0;
vector<int> cnt;
int two = 2;

bool G[1010][1010];
int G2[1010][1010];
int in[1010];
vector<int> Top;

void dfs(int r,int cur, int n)
{
	for(int i = 0; i< n; ++i)
	{
		if(G[cur][i])
		{
			G2[r][i] ++;
			dfs(r,i,n);
		}
	}
}

int main()
{
	int T,N,n;
	cin >> T;
	for(int t = 1; t<= T; ++t)
	{	
		cin >> N;
		for(int i = 0; i< N; ++i)
		{
			for(int j = 0; j< N; ++j) 
			{
				G[i][j] = 0;
				G2[i][j] = 0;
			}
			in[i] = 0;
		}
		int m;	
		for(int i = 0; i< N; ++i)
		{
			cin >> m;
			int mi;
			for(int j = 0; j< m; ++j)
			{
				cin >> mi;
				G[i][mi-1] = true;
				//G2[i][mi-1] = true;
				in[mi-1] ++;
			}
		}
		int *tag = new int[N];
		for(int i = 0; i< N; ++i) tag[i] = 0;
		Top.clear();
		for(int i = 0; i< N; ++i)
		{
			int sel = -1;
			for(int j = 0; j< N; ++j)
			{
				if((in[j] == 0) && (tag[j]==0)) {
					sel = j;
					Top.push_back(j);
					tag[j] = 1;
					break;
				}
			}
			if(sel>=0)
				for(int j = 0; j< N; ++j)
				{
					if(G[sel][j])
					{
						in[j]--;
					}
				}
		}
		/*cout << "TopSort: ";
		for(int i = 0; i< Top.size(); ++i)
		{
			cout << Top[i] << " ";
		}
		cout << endl;*/

		for(int i = N-2; i>=0; i--)
		{
			dfs(Top[i],Top[i],N);
		}
		bool OK = false;
		for(int i = 0; i< N; ++i)
		{
			for(int j = 0; j< N; ++j) 
			{
				if(G2[i][j] >= 2) OK = true;
			}
		}
		cout << "Case #" << t << ": ";
		if(OK) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
