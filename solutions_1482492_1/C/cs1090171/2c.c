#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))


int t,n;
bool fg=false;
double d,a,t1,t2,x1,x2,f,p;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>d>>n>>a;
		cin>>t1>>x1;
		f=0;
		fg=false;
		for(int j=1;j<n;j++){
			cin>>t2>>x2;
			if(fg==true) continue;
			if(x2>d && fg==false){
				f=t1+(d-x1)/((x2-x1)/(t2-t1));
				fg=true;
				continue;
			}
			if(x2==d){
				f=t2;
				fg=true;
				continue;
			}
			t1=t2;
			x1=x2;
		}	
			cout<<"Case #"<<i<<":"<<endl;
		for(int j=0;j<a;j++){
			cin>>p;
			double u=pow((2*d/p),0.5);
				printf("%.20f\n",maX(u,f));
		}
	}
	return 0;
}
