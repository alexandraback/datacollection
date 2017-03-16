#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
#include<fstream>

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()
#define INF 1000000000

using namespace std;

vector<string> words[16];
string st;
int dp[4096][4096];
int dp2[4096];

int calc3(int t)
{
    if(t==0)
        return 0;
    if(dp2[t]!=-1)
        return dp2[t];
    dp2[t] = INF;
    for(int i=max(0,t-11);i<t;i++)
        dp2[t] = min(dp2[t],calc3(i)+dp[i][t]);
    return dp2[t];
}

int calc2(int mn, string &st2,int t)
{
    int res = 0, last = -10;
    forn(i,st2.size())
    if(st[mn+i]!=st2[i])
    {
        if(i-last<5)
            return INF;
        res++;
        if(res>=t)
            return INF;
    }
    return res;
}

int calc(int mn, int mx)
{
    if(mx>st.size())
        return INF;
    int res = INF;
    forn(i,words[mx-mn].size())
        res = min(res,calc2(mn,words[mx-mn][i],res));
    //cout << mn <<" "<< mx << " "<< aux <<" "<< res << endl;
    return res;
}

int main()
{
	#ifdef ACMTUYO
	ifstream fin;
	fin.open("dict.txt");
	forn(i,16)
        words[i].clear();
	while(fin >> st)
        words[st.size()].push_back(st);
    fin.close();
	freopen("C-small.in","r",stdin);
	freopen("C.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
        cin >> st;
        int n = st.size();
        forn(i,n+2)
        forn(j,n+2)
            dp[i][j] = INF;
        forn(i,n+2)
        for(int j=i+1;j<i+11;j++)
            dp[i][j] = calc(i,j);
        forn(i,n+1)
            dp2[i] = -1;

        int res = calc3(n);
        cout <<"Case #"<< casito << ": "<<res<<endl;
	}
}
