#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

int n,p,p1,p2,p3,k,s;

int main(){
	int _,cas=0;
	scanf("%d",&_);
	while (_--){
		int ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for (int i=0;i<n;++i){
			scanf("%d",&k);
			p1=k/3;
			p2=k%3;
			if (p2!=0) p1++;
			
			if (p1>=p){ 
				++ans;
				continue;
			}
			
			if (k==0 || s==0 || p2==1) continue;
			p1++;
			if (p1>=p){
				++ans;
				--s;
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
			
			
