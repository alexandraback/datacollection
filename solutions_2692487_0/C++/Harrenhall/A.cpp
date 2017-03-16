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
lint mons[105];
lint cost[105];

void init(){
	
}
		
void solve(){
	lint a,n;//10e6 100
	cin>>a>>n;
	INITW(cost,0,105);
	REP(i,n)cin>>mons[i];
	
	
	sort(mons,mons+n);
	lint c=0;
	REP(i,n){
		
		while(a<=mons[i]){
			if(a<2){
				cout<<n;
				return;
			}
			a+=(a-1);
			c++;
		}
		cost[i]=c;
		a+=mons[i];
	}
	lint min=n;
	REP(i,n){
		if(cost[i]+(n-i-1) < min)min=cost[i]+(n-i-1);
	}
	cout<<min;
}
