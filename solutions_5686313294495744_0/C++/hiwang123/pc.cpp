//hi
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long int
struct S{
	char a[30],b[30];
}s[20];
int rl[20];
int main(void){
    int t;
    scanf("%d",&t);
    int hh;
    for(hh=1;hh<=t;hh++){
		int n;
		scanf("%d",&n);
		int i,j,k;
		for(i=0;i<n;i++){
			scanf("%s%s",s[i].a,s[i].b);
		}
		int ans=0;
		for(i=0;i<(1<<n);i++){
			int ok=1;
			int fcnt=0;
			for(j=0;j<n;j++){
				if(i&(1<<j))
					rl[j]=1;
				else
					rl[j]=0, fcnt++;
			}
			for(j=0;j<n;j++){
				if(rl[j]==1) continue;
				int x=0,y=0;
				for(k=0;k<n;k++){
					if(rl[k]==0) continue;
					if(strcmp(s[j].a,s[k].a)==0) x=1;
					if(strcmp(s[j].b,s[k].b)==0) y=1;
				}
				if(x+y!=2) ok=0;
			}
			for(j=0;j<n;j++){
				if(rl[j]==0) continue;
				int x=0,y=0;
				for(k=0;k<n;k++){
					if(k==j) continue;
					if(rl[k]==0) continue;
					if(strcmp(s[j].a,s[k].a)==0) x=1;
					if(strcmp(s[j].b,s[k].b)==0) y=1;
				}
				if(x+y==2) ok=0;
			}
			if(ok==1){
				//printf("%d\n",i);
				ans=max(ans,fcnt);
			}
		}
		printf("Case #%d: %d\n",hh,ans);
	}
    return 0;
}
