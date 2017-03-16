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

bool anda(long double k, vector<long double> &vec, int pos)
{
    double db = vec[pos]+k;
    double falta = 0;
    forn(i,vec.size())
    if(i!=pos&&vec[i]<db)
        falta+=db-vec[i];
    return (falta+k<=1);
}

int main()
{
	#ifdef ACMTUYO
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
	    int n;
	    cin >> n;
	    vector<long double> vec(n);
	    double todo = 0;
	    forn(i,n)
	    {
	        cin >> vec[i];
	        todo+= vec[i];
	    }
	    forn(i,n)
            vec[i]/=todo;
        vector<long double> res(n);
        forn(i,n)
        {
            long double mx = 1.,mn = 0.;
            while(mx-mn>1e-9)
            {
                double k = (mx+mn)/2;
                if(anda(k,vec,i)==true)
                    mn = k;
                else
                    mx = k;
            }
            res[i] = mn;
        }
	    cout << "Case #" << casito << ":";
	    forn(i,n)
            printf(" %.6f",(double)(100* res[i]));
        cout << endl;
	}
}
