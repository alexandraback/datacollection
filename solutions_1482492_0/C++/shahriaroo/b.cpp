									/*	In the name of God	*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
typedef long long ll;

using namespace std;

double d,a,t[1001],x[1001],mx,v,nx,dt,dx;
int n,an;

double val(double t){
	return .5*a*t*t+v*t+mx;
}
double eps=1e-8;
double bs(){
	double l=t[n-2],r=1e8,m,tx,tx2;
	while (r-l>eps){
		m=(r+l)/2;
		if (n>1)
			tx=x[n-2]+(m-t[n-2])*(dx)/dt;
		else
			tx=x[0]+.5*a*m*m;
		tx=min(tx,.5*a*m*m+v*m+mx);
		if (tx-d>eps)
			r=m;
		else
			l=m;
	}
	return m;
}

int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
	int ti,tc,i,k;
	scanf("%d",&tc);
	rep(ti,tc){
		printf("Case #%d:\n",ti+1);
		if (ti==9)
			i=0;
		scanf("%lf %d %d",&d,&n,&an);
		rep(i,n)
			scanf("%lf %lf",&t[i],&x[i]);
		rep(k,an){
			scanf("%lf",&a);
			mx=0;
			v=0;
			rep(i,n-2){
				dt=t[i+1]-t[i];
				dx=x[i+1]-x[i];
				nx=val(dt);
				if (nx>x[i+1]){
					mx=x[i+1];
					v=dx/dt;
				}
				else{
					mx=nx;
					v+=a*dt;
				}
			}
			if (n>1){
				dt=t[i+1]-t[i];
				dx=x[i+1]-x[i];
			}
			else{
				dx=0;
				dt=1;
			}
			printf("%lf\n",bs());
		}
	}
	
	return 0;
}