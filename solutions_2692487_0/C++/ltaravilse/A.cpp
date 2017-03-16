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

int A,N;
vector<int> motes;

int calc()
{
    int res = 0;
    int a = A;
    vector<int> vec = motes;
    reverse(all(vec));
    while(!vec.empty())
    {
        if(a>vec[vec.size()-1])
        {
            a += vec[vec.size()-1];
            vec.pop_back();
        }
        else
        {
            a = 2*a-1;
            res++;
        }
    }
    return res;
}

int main()
{
	#ifdef ACMTUYO
	freopen("A-small.in","r",stdin);
	freopen("A.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
	{
        cin >> A >> N;
        motes.resize(N);
        forn(i,N)
            cin >> motes[i];
        sort(all(motes));
        int res = N;
        int t = 0;
        if(A!=1)
        while(motes.size()>0)
        {
            res = min(res,calc()+t);
            t++;
            motes.pop_back();
        }
        cout <<"Case #"<< casito << ": "<<res<<endl;
	}
}
