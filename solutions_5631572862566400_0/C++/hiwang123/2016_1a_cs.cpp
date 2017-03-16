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
		int n;
		scanf("%d",&n);
		int i,j;
		int s[20];
		int l[20];
		for(i=0;i<n;i++) s[i]=i+1;
		for(i=0;i<n;i++)
			scanf("%d",&l[i+1]);
		int ans=0;
		do{
			for(j=1;j<=n;j++){
				int cnt=0;
				for(i=0;i<j;i++)
					if(s[(i+1)%j]==l[s[i]] || s[(i-1+j)%j]==l[s[i]]) cnt++;
				if(cnt==j) ans=max(ans,cnt);
			}
		}while(next_permutation(s,s+n));
		printf("Case #%d: %d\n",hh,ans);
	}
    return 0;
}
