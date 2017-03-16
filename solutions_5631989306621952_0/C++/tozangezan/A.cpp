#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
char in[1100];
int main(){
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%s",in);
		string now="";
		for(int i=0;in[i];i++){
			string A=now+in[i];
			string B=in[i]+now;
			now=max(A,B);
		}
		printf("Case #%d: %s\n",t,now.c_str());
	}
}