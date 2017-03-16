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

long double vec[200000];
long double corr[200000];

long double calc(int a, int b, int back)
{
    return corr[a-back]*(2*back+b+1)+(1-corr[a-back])*(2*back+b+1+a+b+1);
}

int main()
{
	#ifdef ACMTUYO
	freopen("A-small.in","r",stdin);
	freopen("A-small.out","w",stdout);
	#endif
    int casos;
    cin >> casos;
    for(int casito=1;casito<=casos;casito++)
    {
        cout << "Case #"<< casito << ": ";
        int a,b;
        cin >> a >> b;
        b-=a;
        forn(i,a)
            cin >> vec[i];
        corr[0] = 1.;
        for(int i=1;i<=a;i++)
            corr[i] = corr[i-1]*vec[i-1];
        long double res = a+b+2;
        forn(i,a+1)
            res = min(res,calc(a,b,i));
        printf("%.6f\n",(double)res);
    }
}
