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
#define P pair<int,int>

using namespace std;

const int MX = 2001;
int val[2][MX];
int n;
bool v[2][MX];
int res;
vector<int> vc;

int busca2(int stars){
	int x;
	for(int i=0;i<n;i++){
		x = vc[i];
		if(v[1][x] == false and v[0][x] == false and val[1][x] <= stars)
			return x;
	}
	return -1;
}
int busca1(int stars){
	int x;
	for(int j=1;j>=0;j--){
		for(int i=0;i<n;i++){
			x = vc[i];
			if(v[j][x] == false and val[j][x] <= stars){
				v[j][x] = true;
				return x;
			}
		}
	}
	return -1;
}
void dfs(int d,int stars){
	if(stars == 2 * n){
		res = d;
		return;
	}

	int x = busca2(stars);
	if(x != -1){
		v[1][x] = true;
		v[0][x] = true;
		dfs(d+1,stars + 2);
		return;
	}
	x = busca1(stars);
	if(x != -1){
		dfs(d+1,stars + 1);
	}
}
bool comp(int a,int b){
	if(val[1][a] == val[1][b])
		return val[0][a] > val[0][b];
	return val[1][a] > val[1][b];
}
void resuelva(){
	scanf("%d",&n);
	vc.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&val[0][i],&val[1][i]);
		vc[i] = i;
	}
	sort(vc.begin(),vc.end(),comp);
	res = -1;
	memset(v,false,sizeof(v));
	dfs(0,0);
	if(res == -1)
		printf("Too Bad\n");
	else
		printf("%d\n",res);	
}
int main(){
	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d: ",i);
		resuelva();
	}

}