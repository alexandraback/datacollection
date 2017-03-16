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
int a[10],b[15];

void go(int x){
	int tmp[10];
	memset(tmp,0,sizeof(tmp));
	for(int i=2;i<=7;i++){
		if(x%i==0){
			while(x%i==0){
				tmp[i]++;
				x/=i;
			}
		}
	}
	for(int i=2;i<=7;i++)
		a[i]=max(a[i],tmp[i]);
}

void check(){
	int x=n;
	while(a[2]&&a[3]){
		a[2]--;
		a[3]--;
		cout<<6;
		x--;
	}
	while(a[7]){
		a[7]--;
		cout<<7;
		x--;
	}
	while(a[5]){
		a[5]--;
		cout<<5;
		x--;
	}
	while(a[2]>=3){
		a[2]-=3;
		cout<<8;
		x--;
	}
	while(a[2]>=2){
		a[2]-=2;
		cout<<4;
		x--;
	}
	while(a[3]){
		cout<<3;
		a[3]--;
		x--;
	}
	while(x){
		cout<<2;
		x--;
	}
	cout<<endl;
}

int main(){
    //ios::sync_with_stdio(0);
    freopen("C-small-2-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    for(cin>>T;cas<=T;cas++){
    	cout<<"Case #"<<cas<<": "<<endl;
    	cin>>r>>n>>m>>k;
    	int d;
    	while(r--){
    		memset(a,0,sizeof(a));
    		for(int i=0;i<k;i++) {
    			cin>>d;
    			go(d);
    		}
    		//for(int i=2;i<=7;i++) cout<<a[i]<<' ';
    		//	cout<<endl;
    		check();
    	}
    }
    return 0;
}
