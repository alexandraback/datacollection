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

double calc(double radio)
{
    return radio*radio - (radio-1)*(radio-1);
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
        double r, t;
        cin >> r >> t;
        int res = 0;
        double radio = r+1;
        while(t>=-1e-9)
        {
            t -= calc(radio);
            radio += 2.;
            res++;
        }
        res--;
        cout <<"Case #"<< casito << ": "<<res<<endl;
	}
}
