#include<cstdio>
#include<cstring>
#define N 1007
int n,m;
char str[N];
struct Audience{
	int level,number;
}	a[N];
int main(){
//	freopen("A-small-attempt1.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,tt=0;
	int i,cnt,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,str);
		m=0;
		for(i=0;i<=n;++i)
		if('1'<=str[i] && str[i]<='9'){
			a[m].level=i;
			a[m].number=str[i]-'0';
			++m;
		}
		ans=0,cnt=0;
		for(i=0;i<m;++i){
			if(cnt>=a[i].level){
			}
			else{
				ans+=a[i].level-cnt;
				cnt=a[i].level;
			}
			cnt+=a[i].number;
		}
		printf("Case #%d: %d\n",++tt,ans);
	}
	return 0;
}
/*
4
4 11111
1 09
5 110011
0 1
 */
