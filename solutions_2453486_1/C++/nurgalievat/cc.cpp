#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<set>
#include<deque>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<list>
#include<stack>
#include<queue>
#include<sstream>
#include<cstring>
#include<functional>
using namespace std;

#pragma comment(linker, "/STACK:64000000")
#define ALL(X) (X).begin(),(X).end()
#define sqr(X) ((X)*(X))

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef long long LLL;
typedef unsigned long long HL;
const double EPS = 1e-8;
const int INF = 1e9;
const LLL LINF = 1e18;

string f[4];

inline int CHECK(set<char>& st)
{
	if(st.find('.')!=st.end())
		return 0;
	bool X = (st.find('X')!=st.end());
	bool O = (st.find('O')!=st.end());
	if(X&&O)
		return 0;
	if(X)
		return 1;
	if(O)
		return 2;
	return 0;
}

inline int checkH(int x)
{
	set<char> st;
	for(int i=0;i<4;i++)
		st.insert(f[x][i]);
	return CHECK(st);
}

inline int checkV(int x)
{
	set<char> st;
	for(int i=0;i<4;i++)
		st.insert(f[i][x]);
	return CHECK(st);
}

inline void checkD(set<int> &res)
{
	set<char> st1, st2;
	for(int i=0;i<4;i++)
	{
		st1.insert(f[i][i]);
		st2.insert(f[4-i-1][i]);
	}
	res.insert(CHECK(st1));
	res.insert(CHECK(st2));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"Case #"<<i+1<<": ";
		bool draw = true;
		//input
		for(int j=0;j<4;j++)
		{
			cin>>f[j];
			for(int k=0;k<4;k++)
				if(f[j][k]=='.')
					draw = false;
		}
		//solve
		set<int> results;
		for(int j=0;j<4;j++)
		{
			results.insert(checkH(j));
			results.insert(checkV(j));
		}
		checkD(results);
		//
		bool X = (results.find(1)!=results.end());
		bool O = (results.find(2)!=results.end());
		if(X)
			cout<<"X won";
		else if(O)
			cout<<"O won";
		else if(draw)
			cout<<"Draw";
		else
			cout<<"Game has not completed";
		cout<<endl;
	}

    return 0;
}