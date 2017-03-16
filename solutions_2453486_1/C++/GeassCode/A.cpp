#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 110
int n;
char mp[maxn][maxn];
int check(char ch)
{
	int i,j;
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for(i=0;i<n;i++){
		cnt1=cnt2=0;
		for(j=0;j<n;j++){
			if(mp[i][j]==ch||mp[i][j]=='T')cnt1++;
			if(mp[j][i]==ch||mp[j][i]=='T')cnt2++;
			if(i==j&&(mp[i][j]==ch||mp[i][j]=='T'))cnt3++;
			if(i+j==n-1&&(mp[i][j]==ch||mp[i][j]=='T'))cnt4++;
		}
	//	printf("%d %d %d\n",i,cnt1,cnt2);
		if(cnt1>=4||cnt2>=4)return 1;
	}
	if(cnt3>=4||cnt4>=4)return 1;
	return 0;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int i,j,k;
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		n=4;
		int cnt=0;
		for(i=0;i<n;i++){
			scanf("%s",mp[i]);
		//	printf("%s\n",mp[i]);
			for(j=0;j<n;j++){
				if(mp[i][j]!='.'){
					cnt++;
				}
			}
		}
		printf("Case #%d: ",cas);
		if(check('X')){
			printf("X won\n");
		}else if(check('O')){
			printf("O won\n");
		}else if(cnt<n*n){
			printf("Game has not completed\n");
		}else printf("Draw\n");
	}
	return 0;
}
