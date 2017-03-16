#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;


#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())


long long gcd(long long a,long long b){
	long long tmp;
	while(b!=0){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
void judge(){
	long long  a,b;
	char y;
	cin>>a>>y>>b;	
	if(a==b&&a==0){
		cout<<"impossible";
		return;
	}
	long long f=gcd(a,b);
	a/=f;
	b/=f;
	long long x=b;
	int t=0;
	while(x!=0){
		if((x&1)!=0){
			if((x>>1)!=0){
				cout<<"impossible";
				return;
			}
			t++;
			break;
		}
		x>>=1;
		t++;
	}
	if(t>41){
		cout<<"impossible";
		return;
	}
	x=a;
	int ans=0;
	for(int i=0;i<t;++i){
		if(x&1)ans=t-i-1;
		x>>=1;
	}
	cout<<ans;
	return;


}
int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		cerr<<tt<<endl;
		printf("Case #%d: ",tt+1);
		judge();
		
		printf("\n");
	}




	return 1;



}