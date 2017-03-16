#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
bool submit=true;
int t,n;
LL ps,s[103];
int main(){
	if(submit){
		freopen("A-large.in.txt","r",stdin);
		freopen("A-large.out","w",stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> ps >> n;
		for(int j=0;j<n;j++) cin >> s[j];
		sort(s,s+n);
		int ans=n,cnt=0;
		LL cur=ps;
		if(ps==1) ans=n;
		else{
			for(int j=0;j<n;j++){
				while(cur<=s[j]) cur=cur*2-1,cnt++;
				ans=min(ans,cnt+n-1-j);
				cur+=s[j];
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
