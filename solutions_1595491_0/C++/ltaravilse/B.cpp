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

int main()
{
	#ifdef ACMTUYO
	freopen("B-small.in","r",stdin);
	freopen("B.out","w",stdout);
	#endif
	int casos;
	cin >> casos;
	for(int casito=1;casito<=casos;casito++)
	{
	    int res = 0;
	    int n,s,p;
	    cin >> n >> s >> p;
	    vector<int> vec(n);
	    forn(i,n)
            cin >> vec[i];
        forn(i,n)
        {
            int t = vec[i];
            if(p+2*max(p-1,0)<=t)
                res++;
            else if(p+2*max(p-2,0)<=t&&s>0)
            {
                res++;
                s--;
            }
        }
	    cout << "Case #"<< casito<< ": "<< res << endl;
	}
}
