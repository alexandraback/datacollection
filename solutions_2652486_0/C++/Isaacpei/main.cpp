#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

const int INF=0x3f3f3f3f;
typedef long long ll;
const int M=1001;
const int mod=7340033;
const double eps=1e-6;
const double Pi=2*acos(0.0);

inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int bit(int x){return 1<<x;}
inline double dabs(double x){return x>0?x:(-x);}
inline int abs(int x){return x>0?x:(-x);}
inline int lowbit(int x){return x&(-x);}

int cas=1,T;
int n,m,k,r;
int a[10],b[10];
bool vis[130],tmp[130];

void decode(int x){
	for(int i=0;i<n;i++){
		a[i]=x%(m-1)+2;
		x/=m-1;
	}
}

int go(int x){
	int ans=1;
	for(int i=0;i<n;i++){
		if(x&1) ans*=a[i];
		x/=2; 
	}
	return ans;
}

bool check(){
	memset(tmp,0,sizeof(tmp));
	for(int i=(2<<n)-1;i>=0;i--){
		int t=go(i);
		tmp[t]=1;
	}
	/*if(a[0]==3&&a[1]==4&&a[2]==3){
		cout<<vis[28]<<endl;
		for(int i=0;i<130;i++)
			if(vis[i]&&!tmp[i]) cout<<i<<endl;;
		cout<<endl;
	}*/
	for(int i=1;i<130;i++){
		if(vis[i]&&!tmp[i]) return 0;
	}
	return 1;
}

int main(){
    //ios::sync_with_stdio(0);
    //freopen("C-small-1-attempt0.txt","r",stdin);
    freopen("out.txt","w",stdout);
    for(cin>>T;cas<=T;cas++){
    	cout<<"Case #"<<cas<<": "<<endl;
    	cin>>r>>n>>m>>k;
    	int d,t=1;
    	for(int i=0;i<n;i++) t*=m-1;
    	while(r--){
    		memset(vis,0,sizeof(vis));
    		for(int i=0;i<k;i++) {
    			cin>>d;
    			vis[d]=1;
    		}
    		for(int i=t-1;i>=0;i--){
    			decode(i);
    			if(check()){
    				for(int i=0;i<n;i++) cout<<a[i];
    				cout<<endl;
    				break;
    			}
    		}
    	}
    }
    return 0;
}
