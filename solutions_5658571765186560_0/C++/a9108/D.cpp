#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

string getans(){
	int x,r,c;
	scanf("%d%d%d",&x,&r,&c);
	if (x==1) return "GABRIEL";
	if (x==2) {
		if (r*c%2==0) return "GABRIEL";
	}
	if (x==3&&r*c%3==0){
		if (min(r,c)>=2) return "GABRIEL";
	}
	if (x==4&&r*c%4==0){
		if (min(r,c)>=3) return "GABRIEL";
	}
	return "RICHARD";
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d: %s\n",r,getans().c_str());
	}
	return 0;
}