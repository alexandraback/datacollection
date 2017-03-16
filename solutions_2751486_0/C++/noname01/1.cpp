#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[1000002],sum[1000002],len,t,n,i;
void init(){
  int i;
  char ch;
  memset(a,0,sizeof(a));
  memset(sum,0,sizeof(sum));
  len=0;
  scanf("%c",&ch);
  while(ch!=' '){
	len++;
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')a[len]=0;
	else a[len]=1;
	scanf("%c",&ch);
  }
  scanf("%d\n",&n);
  for(i=1;i<=len;i++)
	sum[i]=a[i]+sum[i-1];
}
int check(int l,int r){
  int i,s=0;
  for(i=l;i<=r;i++)
	if(a[i]==1){
	  s++;
	  if(s>=n)return(1);
	}
	else s=0;
  return(0);
}
void solve(){
  int i,j,ans=0;
  for(i=1;i<=len;i++)
	for(j=i;j<=len;j++)
	  if(check(i,j))ans++;
	printf("%d\n",ans);
}
int main(){
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  scanf("%d\n",&t);
  for(i=1;i<=t;i++){
	printf("Case #%d: ",i);
	init();
	solve();
  }
  fclose(stdin);
  fclose(stdout);
  return(0);
}
