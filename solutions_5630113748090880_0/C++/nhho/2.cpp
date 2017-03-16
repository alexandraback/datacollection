#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define pb push_back
#define LL long long
#define co complex<double>

#define MAX 100005
#define AMAX 1500
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int t,n,ta,tb,y[105][105],aa,bb;
vector<int> x[105];

bool go(int a,int b){
	if(!b){
		if(ta<n){
			aa=0;
			bb=ta++;
			if(go(a,1))return 1;
			ta--;
		}
		if(tb<n){
			aa=1;
			bb=tb++;
			if(go(a,1))return 1;
			tb--;
		}
	}
	if(a==2*n-1)return 1;
	if(ta<n){
		vector<bool> tt;
		tt.clear();
		F1(c,0,n){
			if(y[ta][c]){
				if(y[ta][c]!=x[a][c])break;
				tt.pb(0);
			}else{
				tt.pb(1);
				y[ta][c]=x[a][c];
			}
		}
		ta++;
		if(tt.size()==n&&go(a+1,b))return 1;
		ta--;
		F1(c,0,tt.size())if(tt[c])y[ta][c]=0;
	}
	if(tb<n){
		vector<bool> tt;
		tt.clear();
		F1(c,0,n){
			if(y[c][tb]){
				if(y[c][tb]!=x[a][c])break;
				tt.pb(0);
			}else{
				tt.pb(1);
				y[c][tb]=x[a][c];
			}
		}
		tb++;
		if(tt.size()==n&&go(a+1,b))return 1;
		tb--;
		F1(c,0,tt.size())if(tt[c])y[c][tb]=0;
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	F2(a,1,t){
		scanf("%d",&n);
		memset(y,0,sizeof(y));
		F1(b,0,2*n-1){
			x[b].clear();
			F1(c,0,n){
				scanf("%d",&ta);
				x[b].pb(ta);
			}
		}
		sort(x,x+(2*n-1));
		ta=tb=0;
		go(0,0);
		printf("Case #%d:",a);
		if(aa)F1(b,0,n)printf(" %d",y[b][bb]);
		else F1(b,0,n)printf(" %d",y[bb][b]);		
		printf("\n");
	}
	//system("pause");
	return 0;
}
