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

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=(int)n-1;i>=0;i--)
#define all(v) v.begin(),v.end()

using namespace std;

int E, R, N;
vector<int> vec;

int dp[16][8];

int calc(int pos, int sobra)
{
    if(pos==-1)
        return 0;
    int res = 0;
    for(int i=R;i<=E;i++)
    {
        if(i-sobra+R>=0)
        {
            int aux = vec[pos]*max(i-sobra+R,0)+calc(pos-1,i);
            res = max(res,aux);
        }
    }
    return res;
}

int main()
{
	#ifdef ACMTUYO
	freopen("B-small.in","r",stdin);
    freopen("B.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
        cin >> E >> R >> N;
        R = min(R,E);
        vec.resize(N);
        forn(i,N)
            cin >> vec[i];
        cout <<"Case #"<< casito << ": "<<calc(N-1,R)<<endl;
	}
}
