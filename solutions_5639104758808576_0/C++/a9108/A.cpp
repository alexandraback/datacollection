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

int getans(){
	int s;
	char v[10000];
	scanf("%d%s",&s,v);
	int cur=v[0]-'0',ans=0;
	for (int i=1;i<=s;i++){
		for (;cur<i;cur++,ans++);
		cur+=v[i]-'0';
	}
	return ans;
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d: %d\n",r,getans());
	}
	return 0;
}