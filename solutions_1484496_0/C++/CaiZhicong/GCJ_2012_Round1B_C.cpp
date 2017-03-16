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

void dfs(int cur,int n,int sum)
{
	if(Find) return ;
	if(cur == n)
	{
		if(sum != 0)
		{
			if(Have.find(sum) != Have.end())
			{
				Find = true;
				find_sum = sum;
				return ;
			}
			else
			{
				Have.insert(sum);
			}
		}
	}
	else
	{
		dfs(cur+1,n,sum);
		if(Find) return ;
		dfs(cur+1,n,sum+num[cur]);

	}
}

void dfs2(int cur,int n,int sum)
{
	//cout << "two = " << two << endl;
	if(two == 0) return ;
	if(cur == n)
	{
		//cout << sum << endl;
		if(sum == find_sum)
		{
			for(int i = 0; i< n; ++i)
			{
				if(cnt[i])
				{
					cout << num[i] << " ";
				}
			}
			cout << endl;
			two --;
			if(two == 0) return ;
		}
	}
	else
	{
		cnt[cur] = 0;
		dfs2(cur+1,n,sum);
		cnt[cur] = 1;
		dfs2(cur+1,n,sum+num[cur]);
	}
}

int main()
{
	int T,N,n;
	cin >> T;
	for(int t = 1; t<= T; ++t)
	{	
		cin >> N;
		Find = false;
		Have.clear();
		num.clear();
		for(int i = 0; i< N; ++i)
		{
			cin >> n; 
			num.push_back(n);
		}
		cout << "Case #" << t << ":\n";
		dfs(0,N,0);
		if(!Find) cout << "Impossible\n";
		else
		{
			cnt.clear();
			for(int i = 0; i< N; ++i) cnt.push_back(0);
			two = 2;
			dfs2(0,N,0);
		}
	}
	return 0;
}
