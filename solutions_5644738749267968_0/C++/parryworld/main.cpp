#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#define mp make_pair
#define pb push_back
#define SCAN(n) scanf("%d",&n)
#define SCAN2(a,b) scanf("%d%d",&a,&b)
#define SCANS(a) scanf("%s",a)
#define PRINT(n) printf("%d\n",n)
#define sqr(a) ((a)*(a))
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N=1200010;
const int M=3000010;
const int INF=1e9;
const int MOD=1e9+7;
const double eps=1e-6;

int n;
double a[1010],b[1010];

int work(double* a,double* b){
	int r=n;
	int ans=0;
	for(int i=n;i>0;i--){
		if(a[r]>b[i]){
			r--;
			ans++;
		}
	}
	return ans;
}

void solve(){
	int t;
	cin>>t;
	for(int cs=1;cs<=t;cs++){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		cout<<"Case #"<<cs<<": "<<work(a,b)<<' '<<n-work(b,a)<<endl;
	}
}

int main()
{
   	freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    //ios :: sync_with_stdio(false);
    solve();
    return 0;
}
