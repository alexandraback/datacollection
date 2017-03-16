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

int n,surprising,mn;

bool g(int x,int fin){
	x-= fin;
	int least = max(0,fin-1);
	x -= least;
	x -= least;
	return x>=0;
}
bool g2(int x,int fin){
	x-= fin;
	int least = max(0,fin-2);
	x -= least;
	x -= least;
	return x>=0;
}

bool possible(int x){
	for(int i=mn;i<=10;i++){
		if(g(x,i))
			return true;
	}
	return false;
}

bool possible2(int x){
	for(int i=mn;i<=40;i++){
		if(g2(x,i))
			return true;
	}
	return false;
}
void resuelva(){
	scanf("%d %d %d",&n,&surprising,&mn);
	
	int res = 0;
	int x;
	vector<int> vc;

	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(possible(x))
			res++;
		else
			vc.push_back(x);
	}
	foreach(it,vc){
		if(surprising <= 0)
			break;
		if(possible2(*it)){
			res++;
			surprising--;
		}
	}

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