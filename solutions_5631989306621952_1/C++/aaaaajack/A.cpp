#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	char s[2000];
	for(int cs=1;cs<=T;cs++){
		scanf("%s",s);
		string tmp,nw;
		for(int i=0;s[i];i++){
			nw=string(1,s[i]);
			tmp=max(nw+tmp,tmp+nw);
		}
		printf("Case #%d: ",cs);
		cout<<tmp<<endl;
	}
	return 0;
}