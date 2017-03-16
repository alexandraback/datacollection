#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

long long DFS(int a,int b,int k,int lev)
{
	if(lev==0){
		return (a+1)*(b+1)-(a==1&&b==1&&k!=1);
	}
	long long bit = 1<<lev, ans=0;
	int aa = a&bit, bb = b&bit, kk = k&bit;
	if(a==bit*2-1&&b==bit*2-1&&k==bit*2-1){
		return (long long)(a+1)*(b+1);
	}
	if(aa!=0&&bb!=0&&kk!=0)ans += DFS(a-aa,b-bb,k-kk,lev-1);
	if(aa!=0)ans += DFS(a-aa,(bb!=0)?bit-1:b,(kk!=0)?bit-1:k,lev-1);
	if(bb!=0)ans += DFS((aa!=0)?bit-1:a,b-bb,(kk!=0)?bit-1:k,lev-1);
	ans += DFS((aa!=0)?bit-1:a,(bb!=0)?bit-1:b,(kk!=0)?bit-1:k,lev-1);
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int T,A,B,K;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d%d%d",&A,&B,&K);
		printf("%lld\n",DFS(A-1,B-1,K-1,29));
	}
}
