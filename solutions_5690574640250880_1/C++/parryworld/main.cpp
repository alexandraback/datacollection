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

char a[55][55];
char ans[55][55];

void solve(){
	int t;
	cin>>t;
	int r,c,m;
	bool fv;
	bool ismine;
	for(int cs=1;cs<=t;cs++){
		cin>>r>>c>>m;
		if(r<=c) fv=1;
		else{
			swap(r,c);
			fv=0;
		}
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++) a[i][j]='*';
        if(r*c==m+1){
            ismine=1;
        }
		else if(r==1){
			for(int i=2;i<=c-m;i++) a[1][i]='.';
			ismine=1;
		}
		else if(r==2||((r*c-m)%2==0&&(r*c-m)/2<=c)){
			if((r*c-m)%2||(r*c-m)==2) ismine=0;
			else{
				ismine=1;
				for(int i=1;i*2<=r*c-m;i++){
					a[1][i]='.';
					a[2][i]='.';
				}
			}
		}
		else{
			if(r*c-m<8) ismine=0;
			else{
				ismine=1;
				for(int i=3;i<=c;i++){
					int n=r*c-m;
					int h=(n-1)/i+1;
					if(h>r) continue;
					int hh=n%i;
					if(hh==0) hh=i;
					for(int j=1;j<h;j++)
						for(int k=1;k<=i;k++) a[j][k]='.';
					for(int k=1;k<=hh;k++) a[h][k]='.';
					if(hh==1){
						a[h][2]='.';
						a[h-1][i]='*';
					}
					break;
				}
			}
		}
		if(fv){
			for(int i=1;i<=r;i++)
				for(int j=1;j<=c;j++) ans[i][j]=a[i][j];
		}
		else{
			for(int i=1;i<=r;i++)
				for(int j=1;j<=c;j++) ans[j][i]=a[i][j];
			swap(r,c);
		}
		ans[1][1]='c';
		cout<<"Case #"<<cs<<": "<<endl;
		if(ismine){
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++) cout<<ans[i][j];
				cout<<endl;
			}
		}
		else cout<<"Impossible"<<endl;
	}
}

int main()
{
   	freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    //ios :: sync_with_stdio(false);
    solve();
    return 0;
}
