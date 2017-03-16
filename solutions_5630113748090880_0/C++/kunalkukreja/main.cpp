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
#define N 3000

int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int n;
		cin>>n;
		vi vis(N,0);
		fore(i,0,2*n-1)
		{
		    fore(j,0,n)
		    {
		        int nn;
		        cin>>nn;
		        vis[nn]++;
		    }
		}
		vi a;
		fore(i,0,N)
		{
		    if(vis[i]%2!=0)
                a.pb(i);
		}
		sort(all(a));
		fore(i,0,a.sz)
            cout<<a[i]<<" ";
        cout<<endl;
	}
	return 0;
}
