#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
#include<cassert>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

typedef pair<int,int> p2;
double t[2000][2000];
int N,X,Y;
double solve(){
	cin>>N>>X>>Y;
	int len=0,total=0;
	while(total+2*len+1<=N){
	  total+=2*len+1;
		len+=2;
	}
//	cout<<len<<endl;
	if(X<0)X=-X;
	if(X+Y<len)return 1;
	if(X+Y>len)return 0;
	int desired=len-X+1;
	memset(t,0,sizeof(t));
	int left=N-total;
	t[0][0]=1.0;
	for(int i=0;i<=len;i++)for(int j=0;j<=len;j++)if(i+j<left){
		if(i<len&&j<len){
			t[i+1][j]+=t[i][j]/2;
			t[i][j+1]+=t[i][j]/2;
		}else if(i<len){
			t[i+1][j]+=t[i][j];
		}else if(j<len){
			t[i][j+1]+=t[i][j];
		}else {
			assert(0);
		}
	}
	double ans=0;
	for(int i=0;i<=len;i++)for(int j=0;j<=len;j++)if(j>=desired&&i+j==left){
		ans+=t[i][j];
	}
	return ans;
}
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){ 
    printf("Case #%d: %.6lf\n",c,solve());
  }
}
