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
#define LL unsigned long long
#define FOR(_name,_A,_B)  for(int _name=_A;_name<=(_B);_name++)

#define IN CAT(FILE_NAME,".in")
#define OUT CAT(FILE_NAME,".out")
#define CAT(a,b) a##b
//---------------------------------------------------------------

LL r,t;
void reset(){}
void process(){	}
bool eq(LL n){
	return (2*n*n+2*r*n-n)<=t;
}
LL bin(LL l,LL h){

		if(l>h) return h;
		LL mid=(l+h)/2;
		if(eq(mid))
			return bin(mid+1,h);
		return bin(l,mid-1);
}
LL getUpper(){
	
	LL a=sqrt(t),b=t/r;
	return min(a,b);
}
#define FILE_NAME "A-large (1)"
int main(){
	
	//freopen("in.txt","rt",stdin);
	freopen(IN,"rt",stdin);
	freopen(OUT,"wt",stdout);
	
	int T,cas=1;
	cin>>T;
	while(T--){
		cin>>r>>t;
		LL ret=bin(1,getUpper()+1);
		printf("Case #%d: ",cas++);
		cout<<ret<<endl;
	}
	

	return 0;
}