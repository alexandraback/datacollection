#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<sstream>
#include<set>
#include<cctype>
#include<cassert>
using namespace std;

#ifdef ONLINE_JUDGE

#define assert(x)
#define dbg(x)
#define dbgline()

#else

#define dbg(x) do { cout << "DEBUG, line " << __LINE__ << " (" << __func__ << "), " << #x << ": " << x << endl; } while(0)
#define trace() do { cout << "TRACE, line " << __LINE__ << " (" << __func__ << ")" << endl; } while(0)

#endif

const int N = 22;
const int S = 100005;
int s[N];
int prev[N*S];

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&s[i]);
	int mx = n*S;

	for(int i=0; i<mx; i++) prev[i]=-1;
	prev[0]=0;

	vector<int>x,y;
	int X=-1, Y=-1;;
	for(int i=0; i<n; i++){
		for(int j=mx; j>=0; j--) if(j+s[i]<=mx && prev[j]!=-1){
			if(prev[j+s[i]]!=-1){
				x.push_back(s[i]);
				X = j;
				Y = j+s[i];
				//printf("i %d, j %d\n",i,j);
			}
			else{
				prev[j+s[i]] = s[i];
			}
			if(X!=-1) break;
		}
		if(X!=-1) break;
	}
	if(X!=-1){
		while(X!=Y){
			//printf("%d %d\n",X,Y);
			if(X>Y){
				x.push_back(prev[X]);
				X -= prev[X];
			} else {
				swap(x,y);
				swap(X,Y);
			}
		}
		for(int i=0; i<x.size(); i++) printf("%d ",x[i]); printf("\n");
		for(int i=0; i<y.size(); i++) printf("%d ",y[i]); printf("\n");
	} else {
		printf("Impossible\n");
	}
}

int main(){
	int z;
	scanf("%d",&z);
	for(int testc=1; testc<=z; testc++){
		printf("Case #%d:\n", testc);
		solve();
	}
}
