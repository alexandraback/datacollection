/**
* @author Gareve
*/
#define DEBUGs
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

const int MX = 100001;
double P[MX];
int A,B;
bool get(int mask,int x){
	return (mask & (1<<x))>0;
}
double f(int mask){
	double prob = 1.0;
	for(int i=0;i<A;i++){
		if(get(mask,i))
			prob *= P[i];
		else
			prob *= 1.0 - P[i];
	}
	return prob;
}
int cuantas(int mask,int del){//del
	bool ok = true;
	int res = B + 1;
	for(int i=0;i<A - del;i++){
		if(get(mask,i) == false)
			ok = false;
		res --;
	}
	if(ok)
		return del + res;
	else
		return del + res + B + 1;
}
void resuelva(){
	scanf("%d %d",&A,&B);
	for(int i=0;i<A;i++)
		scanf("%lf",&P[i]);
	int lim = 1 << A;
	double prob,expected;
	double keep=0.0,enter= B + 2.0;
	double w;

	double del[A + 1];
	for(int i=1;i<=A;i++)
		del[i] = 0.0;
	for(int i=0;i<lim;i++){
		prob = f(i);
		if(i == lim-1)
			expected = prob * (double)(B - A + 1.0);
		else
			expected = prob * (double)(B - A + 1.0 + B + 1.0);
		keep += expected;
		
		for(int j=1;j<=A;j++){
			w = cuantas(i,j);
			//printf("+ %d: mask = %d: %.0lf\n",j,i,w);
			del[j] += w * prob;
		}
	}
	double res = min(keep,enter);
	for(int i=1;i<=A;i++){
		res = min(res,del[i]);
		//printf("%d: %.6lf\n",i,del[i]);
	}
	printf("%.6lf\n",res);

}
int main(){
	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d: ",i);
		resuelva();
	}

}