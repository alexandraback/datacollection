#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <algorithm> 
#include <map>
#include <time.h>
#include <set> 
using namespace std;
#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i!=b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())


bool pal(string x){
	int n=x.size();
	if(n<=1)return n==1;
	REP(i,n/2){
		if(x[i]!=x[n-i-1])return false;
	}
	return true;
}
bool pal(__int64 in){
	VI x;
	while(in!=0){
		x.push_back(in%10);
		in/=10;
	}
	int n=x.size();
	if(n<=1)return n==1;
	REP(i,n/2){
		if(x[i]!=x[n-i-1])return false;
	}
	return true;
}

int judge(){
	__int64 a,b;
	scanf("%I64d%I64d",&a,&b);
	__int64 ans=0;
	__int64 st=(__int64)sqrt(double(a));
	__int64 ed=(__int64)sqrt(double(b))+1;
	for(__int64 i=st;i<ed;++i ){
		__int64 i2=i*i;
		if(pal(i)&&i2>=a&&i2<=b&&pal(i2)){
			//printf("%I64d %I64d\n",i,i2);
			ans++;
		}
	}

	return ans;
}
int main(){
	int t;
	cin>>t;
	REP(tt,t){
		int res=judge();
		printf("Case #%d: %d\n",tt+1,res);/*
		switch(res){
		case 0:
			printf("NO\n");
			break;
		case 1:
			printf("YES\n");
			break;
		}*/
	}



	return 1;
	

	
}