#include<iostream>
#include<cstdio>
using namespace std;
int a[1001],t,n,s0,i;
void init(){
  int i,j;
  scanf("%d%d",&s0,&n);
  for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
  for(i=1;i<=n-1;i++)
	for(j=i+1;j<=n;j++)
	  if(a[i]>a[j])swap(a[i],a[j]);
}
void solve(){
  int i,p,s,ans=n,sum;
  if(s0>1){
	for(p=0;p<=n;p++){
	  s=s0;
	  sum=0;
	  for(i=1;i<=p;i++)
		if(s>a[i])
		  s+=a[i];
		else{
		  s+=s-1;
		  sum++;
		  i--;
		}
	  sum+=n-p;
	  ans=min(ans,sum);
	}
  }
  printf("%d\n",ans);
}
int main(){
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  scanf("%d",&t);
  for(i=1;i<=t;i++){
	init();
	printf("Case #%d: ",i);
	solve();
  }
  fclose(stdin);
  fclose(stdout);
  return(0);
}
