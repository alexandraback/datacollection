#include <bits/stdc++.h>
using namespace std;
int T,N;
bool used[10];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%d",&N);
		if (!N){
			printf("INSOMNIA\n");
			continue;
		}
		int ss=0,t=0,step=0;
		memset(used,0,sizeof(used));
		for (step=0;ss<10;){
			step+=N;
			int x=step;
			while (x){
				t=x%10;
				if (!used[t])ss++,used[t]=1;
				x/=10;
			}
		}
		printf("%d\n",step);
	}
}