#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cctype>
#include<iostream>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define pb push_back
#define sz(c) (int)(c).size()
#define INF  (1<<30)
#define EPS  1e-8
#define SET(NAME)   (memset(NAME,-1,sizeof(NAME)))
#define CLR(NAME)   (memset(NAME,0,sizeof(NAME)))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define LL long long
#define FOR(_name,_A,_B)  for(int _name=_A;_name<=(_B);_name++)

#define IN CAT(FILE_NAME,".in")
#define OUT CAT(FILE_NAME,".out")
#define CAT(a,b) a##b
//---------------------------------------------------------------

LL E,R,N,V[10002];
LL memo[12][12];


int fun(int i,int e){
	if(i>=N) return 0;
	if(memo[i][e]>=0) return memo[i][e];
	LL mx=-INF;
	for(int j=0;j<=e;j++){
	
		mx=max(mx,fun(i+1,min(e-j+R,E))+V[i]*j);
	}
	return memo[i][e]=mx;
}
void reset(){}
LL process(){	

	SET(memo);
	return fun(0,E);
}

#define FILE_NAME "B-small-attempt0"
int main(){
	
	//freopen("in.txt","rt",stdin);
	freopen(IN,"rt",stdin);
	freopen(OUT,"wt",stdout);
	int T,cas=1;
	cin>>T;
	while(T--){
	
		cin>>E>>R>>N;
		for(int i=0;i<N;i++){
			cin>>V[i];
		}
		printf("Case #%d: ",cas++);
		cout<<process()<<endl;
	}
	

	return 0;
}