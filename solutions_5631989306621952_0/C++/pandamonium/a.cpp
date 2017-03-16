#include <bits/stdc++.h>
using namespace std;
int t;
deque <char> dq;
char curr,str[1005];
int main(){
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		scanf("%s",str);
		int l=strlen(str);
		curr=str[0];
		dq.clear();
		dq.push_back(str[0]);
		for(int x=1;x<l;x++){
			if(str[x]>=curr){
				dq.push_front(str[x]);
				curr=str[x];
			}
			else dq.push_back(str[x]);
		}
		printf("Case #%d: ",c);
		for(int x=0;x<l;x++) printf("%c",dq[x]);
		printf("\n");
	}
	return 0;
}
