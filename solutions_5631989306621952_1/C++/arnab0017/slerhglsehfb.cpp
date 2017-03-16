#include<bits/stdc++.h>
using namespace std;

char str[1009];

int main(){
	
	freopen("input.txt", "r" , stdin);
	freopen ("output.txt","w",stdout);
	int t,r,i,n;
	char head;
	scanf("%d",&t);
	for(r=1;r<=t;++r){
		deque< char >gq;
		scanf("%s",str);
		printf("Case #%d: ",r);
		n=strlen(str);
		for(i=0;i<n;++i){
			if(i==0){
				head=str[i];
				gq.push_back(str[i]);
			}
			else{
				if(str[i]>=head){
					head=str[i];
					gq.push_front(str[i]);
				}
				else{
					gq.push_back(str[i]);
				}
			}
		}
		for(i=0;i<gq.size();++i){
			printf("%c",gq[i]);
		}
		printf("\n");
	}
	
	fclose(stdout);
	return 0;
}
