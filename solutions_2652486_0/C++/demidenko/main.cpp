#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#define abs(x) ((x)<0?-(x):(x))
#define _max(x,y) ((x)<(y)?(y):(x))
#define _min(x,y) ((x)<(y)?(x):(y))
#define sqr(x) ((x)*(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define forc(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define fill(m,v) memset(m,v,sizeof(m))
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
inline int random(int x){ if(RAND_MAX==32767) return (rand()<<15^rand())%x; else return rand()%x; }
typedef long long ll;
using namespace std;

int n,m;
int i,j,k,l;
int R,K, M, a[1111], x[1111];;
int c[333];
bool g[55][55];
bool u[55], p[55], u2[55];
int f[55];

int n2, n1;
bool dfs_kuhn(int v){
    if(u[v]) return false;
    u[v]=true;
    for(int i=0;i<n2;++i) if(g[v][i]){
        if(f[i]<0 || dfs_kuhn(f[i])){
            f[i]=v;
            return true;
        }
    }
    return false;
}

int sb[22];
void mm(){
	int i,j,k;
	int mn = 1<<n;
	for(int ms=0;ms<mn;++ms){
		int pr = 1;
		for(i=0;i<n;++i) if(ms>>i&1) pr*=a[i];
		for(j=0;j<K;++j) sb[j*mn+ms]=pr;
	}
	
	fill(g,0);
	n2 = K;
	n1 = mn*K;
	for(i=0;i<n1;++i)
	for(j=0;j<n2;++j) if(x[j]==sb[i]) g[i][j]=1;
	
	
	fill(f,255);
    for(i=0;i<n1;++i) if(!u2[i]){
        fill(u,0);
        dfs_kuhn(i);
    }
}


bool fl;
void go(int i){
	if(i==n){
		
		mm();
		
		for(i=0;i<K;++i) if(f[i]==-1) return;
		
		fl = 1;
		return;
	}
	
	for(a[i]=2;a[i]<=M;++a[i]){
		go(i+1);
		if(fl) return;
	}
}

int main(){
	FILE*_fin=freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	cin>>tn;
	int cnt=0;
	for(ti=1; ti<=tn; ++ti){
			
		cin>>R>>n>>M>>K;
		
		cout<<"Case #"<<ti<<": "<<endl;
		
		for(int ri=0;ri<R;++ri){
			getar(x,K);
			fl=0;
			go(0);
			if(fl){
				for(i=0;i<n;++i) cout<<a[i]; cout<<endl;
				++cnt;
			}else{
				for(i=0;i<n;++i) cout<<1; cout<<endl;
			}
		}
	}
	
	cerr<<cnt<<endl;
	
	return 0;
}
