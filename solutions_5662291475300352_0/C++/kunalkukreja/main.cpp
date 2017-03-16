#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int n;
		sc(n);
		vector<pii> hikers;
		fore(i,0,n)
		{
		    int d,k,m;
            sc(d);sc(k);sc(m);
            fore(j,0,k)
            {
                hikers.pb(mp(d,m));
                m++;
            }
		}
        n = hikers.sz;
        stable_sort(all(hikers));
		ll fa = n;
		fore(i,0,n)
		{
		    ll count = 0;
		    int dist = (360-hikers[i].ff);
		    double time = ((double)dist/360)*hikers[i].ss;
		    //cout<<hikers[i].ff<<" "<<time<<endl<<endl;
		    fore(j,0,n)
		    {
		        if(j==i)
                    continue;
                double t2 = ((360-(double)hikers[j].ff)/360)*hikers[j].ss;
                if(t2>=time)
                    count++;
                else
                {
                    double speed = (double)360/hikers[j].ss;
                    double distance = speed*time;
                    distance-=(360-hikers[j].ff);
                    count+=distance/360;
                }
		    }
		    fa = min(fa,count);
		}
		printf("%d\n",fa);

	}
	return 0;
}
