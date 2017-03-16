#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int a,b;
set<int> ss;
	
int gao(int k){
	ss.clear();
	char s[20];
	sprintf(s,"%d",k);
	int p=strlen(s);
	int tmp;
	for (int i=0;i<p;++i){
		s[p+i]=s[i];
		s[p+i+1]='\0';
		sscanf(s+i+1,"%d",&tmp);
		if (tmp>k && tmp<=b){ 
			ss.insert(tmp);
//			cout << k << ' ' << tmp << endl;
		}
	}
	return ss.size();
}
	
int main(){
	long long ans;
	int _,cas=0;
	scanf("%d",&_);
	while (_--){
		scanf("%d%d",&a,&b);
		ans=0;
		for (int i=a;i<b;++i) ans+=gao(i);
		printf("Case #%d: ",++cas);
		cout << ans << endl;
	}
	return 0;
}
