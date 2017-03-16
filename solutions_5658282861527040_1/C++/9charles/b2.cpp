#include<cstdio> 
#include<cstring> 
#include<cctype> 
#include<cmath> 
#include<cstdlib> 
#include<ctime> 
#include<iostream> 
#include<iomanip> 
#include<sstream> 
#include<vector> 
#include<string> 
#include<queue> 
#include<stack> 
#include<utility> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<bitset> 
#include<sstream>
#include<limits>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

ll memo[50][5][5][5];
int A,B,K;

ll f(int pos, int a, int b, int k){
	//printf("%d %d %d %d\n",pos,a,b,k);
	if(pos==-1){
		return (a==1&&b==1&&k==1);		
	}
	if(memo[pos][a][b][k]!=-1){return memo[pos][a][b][k];}
	ll resp=0;
	int digA=!!((1<<pos)&A), digB=!!((1<<pos)&B), digK=!!((1<<pos)&K);
	for(int x=0;x<2;x++){
		for(int y=0;y<2;y++){
			int k2=x&y;
			if(a==0&&x>digA)continue;
			if(b==0&&y>digB)continue;
			if(k==0&&k2>digK){continue;}
			int na=a,nb=b,nk=k;
			if(a==0&&x<digA){na=1;}
			if(b==0&&y<digB){nb=1;}
			if(k==0&&k2<digK){nk=1;}
			resp+=f(pos-1,na,nb,nk);			
		}
	}
	return memo[pos][a][b][k]=resp;
}

int main(){
	int T;
	scanf("%d",&T);
	//printf("%d*\n",7&11);
	for(int caso=1;caso<=T;caso++){
		scanf("%d%d%d",&A,&B,&K);
		memset(memo,-1,sizeof(memo));  //isso funciona???
		printf("Case #%d: %lld\n",caso,f(30,0,0,0));
	}
	return 0;
}
