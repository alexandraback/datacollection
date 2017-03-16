#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
#include<algorithm>

int t,x,y,sum,p,n;
int check[2005];
int group[2005];

void input()
{
	scanf("%d%d",&x,&y);
	sum = abs(x)+abs(y);
}

bool DFS(int su,int ad,int lim)
{
	if(su<0)return false;
	if(su==0)return true;
	if(su<=lim&&check[su]!=t){
		group[su]=ad;
		return true;
	}
	int i;
	for(i=lim;i>=1;i--){
		if(check[i]==t){
			if(DFS(su+i,ad,lim-1)){
				group[i]=ad;
				return true;
			}
		}
		else{
			if(DFS(su-i,ad,lim-1)){
				group[i]=ad;
				return true;
			}
		}
	}
	return false;
}

void solve()
{
	int i,dif,m,ad,tmp,pp=0,qq=0;
	for(n=(int)sqrt(sum*2);;n++){
		if(n*(n+1)/2>=sum && (n*(n+1)/2-sum)%2==0)break;
	}
	for(i=1;i<=n;i++)group[i]=0;
	p=dif=n*(n+1)/2-sum; dif/=2; p/=2; m=n;
	while(dif!=0){
		if(dif>m){
			check[m]=t;
			dif -= m; m--;
		}
		else{
			check[dif]=t;
			break;
		}
	}
	if(abs(x)<abs(y))ad=1;
	else ad=2;
	tmp=std::min(abs(x),abs(y));
	DFS(tmp,ad,n);
	for(i=1;i<=n;i++)if(group[i]!=ad)group[i]=3-ad;
	for(i=1;i<=n;i++){
		if(group[i]==1&&(check[i]==t&&x>0||check[i]!=t&&x<=0)){
			pp-=i;
			printf("W");
		}
		else if(group[i]==1){
			printf("E");
			pp+=i;
		}
		else if(group[i]==2&&(check[i]==t&&y>0||check[i]!=t&&y<=0)){
			printf("S");
			qq-=i;
		}
		else if(group[i]==2){
			printf("N");
			qq+=i;
		}
	}
	printf("\n");
	if(pp!=x||qq!=y)printf("Nope! %d,%d\n",pp,qq);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		input();
		printf("Case #%d: ",t);
		solve();
	}
}