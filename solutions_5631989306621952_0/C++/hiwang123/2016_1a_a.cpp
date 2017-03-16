//hi
#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define LL long long int
int main(void){
    int t,hh;
    scanf("%d",&t);
    for(hh=1;hh<=t;hh++){
		char s[1005];
		scanf("%s",s);
		int n=strlen(s),i;
		char ans[1005],tmp[1005];
		ans[0]=s[0],ans[1]='\0';
		for(i=1;i<n;i++){
			if(s[i]>=ans[0]){
				tmp[0]=s[i], tmp[1]='\0';
				strcat(tmp,ans);
				strcpy(ans,tmp);
			}else{
				ans[i]=s[i];
				ans[i+1]='\0';
			}
		}
		ans[n]='\0';
		printf("Case #%d: %s\n",hh,ans);
	}
    return 0;
}
