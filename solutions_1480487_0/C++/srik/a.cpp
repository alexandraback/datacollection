#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


void doit(){
	double n, tp=0, ip[205], oh=100,sp,res;
	double tl, th, md;
	cin>>n;
	for(int i=0;i<n;i++){
		 cin>>ip[i];
		 tp+=ip[i];
		 //ip[i]*=100;
	}
	sp=oh/n;
	tl=0,th=20000,md=10000;
	for(int i=0;i<100;i++){
		md=(tl+th)/2;
		res=0;
		for(int j=0;j<n;j++)
		if(md>ip[j]){
			res+=((md-ip[j])/tp);
		}
		if(res<=1)
			tl=md;
		else 
			th=md;
	}
	for(int i=0;i<n;i++){
		if(tl>ip[i])res=(tl-ip[i])*100/tp;
		else res=0;
		printf(" %0.6f",res);
	}
	cout<<endl;
    return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        cout<<"Case #"<<i<<":";
        doit();
    }
    return 0;
}
