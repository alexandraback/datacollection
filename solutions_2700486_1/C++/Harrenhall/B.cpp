#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <math.h>
#include <cstring>
#include <gmp.h> // shiny bigint library from http://gmplib.org

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPA(i,a,n) for(int i=(a);i<((a)+(n));i++)
#define INITW(var,value,width) for(int whslkfje=0;whslkfje<(width);whslkfje++) var[whslkfje]=(value)
#define INITHW(var,value,height,width) for(int hwesaft=0;hwesaft<(height);hwesaft++) \
		 for(int whslkfje=0;whslkfje<(width);whslkfje++) var[hwesaft][whslkfje]=(value)
		 
#define AR 15000

typedef long long lint;
using namespace std;
void solve();
void init();

int main(){
	init();

	int T;
	cin>>T;
	string str;
	getline(cin, str);
	
	for(int t=1;t<=T;t++){
		cout<<"Case #"<<t<<": ";
		solve();
		cout<<"\n";
	}
}


double prob[AR][AR];

lint layer[1123456];
void init(){
	lint total=6,i=1,adding=9;
	layer[0]=1;
	while(total<1123456){
		layer[i]=total;
		total+=adding;
		i++;
		adding+=4;
	}
	
	INITHW(prob,0,AR,AR);
	REP(i,AR)prob[i][0]=1;
	REPA(i,1,AR-1)REPA(j,1,AR-1){
		prob[i][j] = 0.5*(prob[i-1][j] + prob[i-1][j-1]);
	}
}
		
void solve(){
	lint n,x,y;
	cin>>n>>x>>y;//20|10e6,≤ 10,000.
	if(x<0)x*=-1;
	
	lint lnr=0;
	while(layer[lnr] <n)lnr++;
	
	if((x+y)/2 < lnr){
		cout<<1;
		return;
	}
	if((x+y)/2 > lnr){
		cout<<0;
		return;
	}
	if(lnr==0){
		if(x+y==0) cout<<1;
		else cout<<0;
		return;
	}
	lint rest=n-layer[lnr-1];
	lint needed = y+1;
	
	if(rest - (lnr*2) >=needed){
		cout<<1;
		return;
	}
	if(x==0){
		cout<<0;
		return;
	}
	cout<<prob[rest][needed];
}
