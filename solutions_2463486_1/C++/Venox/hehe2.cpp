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
__int64 data[40]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001};//generate by Pre()
int px=40;

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
/*
void Pre(){
	__int64 st=1;
	__int64 ed=10000002;
	for(__int64 i=st;i<ed;++i ){
		__int64 i2=i*i;
		if(pal(i)&&pal(i2)){
			data[px++]=i2;
			printf("%I64d,",i2);
		}
	}

}*/
int judge(){
	__int64 a,b;
	scanf("%I64d%I64d",&a,&b);
	int i=0,ans=0;
	while(data[i]<a)++i;

	for(;i<px&&data[i]<=b;++i ){
		ans++;
	}

	return ans;
}
int main(){
	int t;
	cin>>t;
	//Pre();
	REP(tt,t){
		int res=judge();
		printf("Case #%d: %d\n",tt+1,res);
	}



	return 1;
	

	
}