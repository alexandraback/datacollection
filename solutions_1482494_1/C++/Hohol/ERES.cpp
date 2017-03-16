#pragma comment(linker,"/STACK:300000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4800)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <deque>
#include <bitset>
#include <numeric>
#include <ctime>
#include <queue>

using namespace std;

#define show(x) cout << #x << " = " << (x) << endl;
#define fori(i,n) for(int i = 0; i < (n); i++)
#define forab(i,a,b) for(int i = (a); i <= (b); i++)
#define sz(v) int((v).size())
#define all(v) (v).begin(),(v).end()
const double pi = 3.1415926535897932384626433832795;
template<class T> T abs(const T &a) { return a >= 0 ? a : -a; };
template<class T> T sqr(const T &x) { return x * x; }
typedef pair<int,int> ii;
typedef long long ll;
///////////////////////////////////////

string itoa(int n)
{
	char buf[20];
	sprintf(buf,"%d",n);
	return buf;
}

vector<ii> v;
int n;
const int inf = int(1e9);
int curPts;

bool better(ii &a, ii &b)
{
	return a.second > b.second;
}

/*int f(int curAns,int curPts,int ind,vector<int> &t)
{
	curPts++;
	if(t[ind] == 0)
		curAns += 2;
	else
		curAns++;
	t[ind] = 2;
	vector<ii> p;
	fori(i,sz(t))
		if(t[i] != 2)
			p.push_back(ii(v[i].second,i));
	sort(all(p));
	fori(i,sz(p))
	{
		if(v[p[i].second].second > curPts)
			return inf;
		if(t[p[i].second] == 0)
			curPts += 2;
		else
			curPts += 1;
		curAns++;
	}
	return curAns;
}/**/

string solve()
{
	cin >> n;
	v.resize(n);
	fori(i,n)
		cin >> v[i].first >> v[i].second;
	curPts = 0;
	int cnt = 0;
	vector<int> t(n);
	int curAns = 0, bans = inf;
	while(cnt != n)
	{
		int ind = -1;
		fori(i,n)
			if(t[i] != 2 && v[i].second <= curPts)
			{
				ind = i;
				break;
			}
		if(ind == -1)
		{
			fori(i,n)
				if(t[i] == 0 && v[i].first <= curPts  &&
					(ind == -1 || better(v[i],v[ind])))
					ind = i;
		}
		if(ind == -1)
		{
			curAns = inf;
			break;
		}
		curAns++;
		if(v[ind].second <= curPts)
		{			
			cnt++;
			if(t[ind] == 0)
				curPts += 2;
			else
				curPts += 1;
			t[ind] = 2;
		}
		else
		{
			t[ind] = 1;
			curPts++;
		}			
	}
	bans = min(bans,curAns);
	if(bans == inf)
		return "Too Bad";
	else
		return itoa(bans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int testCount;
	cin >> testCount;
	for(int testNo = 1; testNo <= testCount; testNo++)
	{
		string ans = solve();
		cout << "Case #" << testNo << ": " << ans << endl;
	}
}