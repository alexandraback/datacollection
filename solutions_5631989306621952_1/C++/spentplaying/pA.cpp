#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<string.h>
#include<set>
#include<deque>
typedef long long lnt;
char a[1010];
std::deque<char>dq;
int main(){
	int n,k,i,T,t=0;
	freopen("A-large.in","r",stdin);
	freopen("pAout.txt","w",stdout);
	scanf("%d",&T);
	int s;
	while(T--){
		t++;
	 	
	 	scanf("%s",a);
	 	s=strlen(a);
	 	dq.push_back(a[0]);
	 	for(k=1;k<s;k++){
	 		if(a[k]>=dq.front()) dq.push_front(a[k]);
	 		else dq.push_back(a[k]);
	 	}
		printf("Case #%d: ",t);
	 	while(dq.size()){
	 		printf("%c",dq.front());
	 		dq.pop_front();
	 	}
	 	puts("");
	}
}
