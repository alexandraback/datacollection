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

#define FILE_NAME "A-large"


//---------------------------------------------------------------

int A,N,mot[1002];
//int memo[12][2202];
map<int,int> has[102];
void reset(){

	//SET(memo);
	for(int i=0;i<102;i++)
		has[i].clear();
}
int fun(int i,int a){

	
	if(i>=N) return 0;
	if(has[i].find(a)!=has[i].end()) 
		return has[i][a];
	if(mot[i]<a) 
		return has[i][a]=fun(i+1,a+mot[i]);
	
	int r1=1+fun(i+1,a);//rem
	
	
	int r2=INF;
	if(a>1){
		
		r2=fun(i,a+a-1)+1;
	}
	return has[i][a]=min(r1,r2);

}
int process(){	
	reset();
		sort(mot,mot+N);
		return fun(0,A);
}


int main(){
	
	//freopen("in.txt","rt",stdin);
	freopen(IN,"rt",stdin);
	freopen(OUT,"wt",stdout);
	
	int T,cas=1;
	cin>>T;
	while(T--){
		cin>>A>>N;
		for(int i=0;i<N;i++){
			cin>>mot[i];
		}
		printf("Case #%d: %d\n",cas++,process());
	}
	
	

	return 0;
}