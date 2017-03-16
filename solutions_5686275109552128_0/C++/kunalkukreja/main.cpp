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
		cin>>n;
		vi a;
		fore(i,0,n)
		{
		    int tt;
		    cin>>tt;
		    a.pb(tt);
		}
		int ma = *(max_element(all(a)));
		int mi = *(min_element(all(a)));
		int fa = ma;
		fore(i,1,ma+1)
		{
		    int add = 0;
		    fore(j,0,n)
		    {
		        if(i>=a[j])
                    continue;
                add += ceil((double)(a[j])/i) - 1;
		    }
		    fa = min(fa,i+add);
		}
		cout<<fa<<endl;
	}
	return 0;
}
