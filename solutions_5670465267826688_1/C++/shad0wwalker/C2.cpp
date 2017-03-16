#include<iostream>
#include<cstdio>
using namespace std;
int mul[4][4]={0,2,4,6,2,1,6,5,4,7,1,2,6,4,3,1};
int v[1000000],w[10010];

 int multiply(int x,int y)
 {
 	int ok=(x&1)^(y&1),p=mul[x>>1][y>>1];
 	if(ok) p=p^1;
 	return p;
 }

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("out1.txt","w",stdout);
	int k,t,l,x,i,j,end;
	char s[10010];
	bool ok;
	v[0]=0;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		scanf("%d%d%s",&l,&x,s+1);
		if(x>12) x=x%4+12;
		end=x*l;ok=0;
		for(i=1;i<=l;i++){
			if(s[i]=='i') w[i]=2;
			else if(s[i]=='j') w[i]=4;
			else w[i]=6;
		}
		for(i=0;i<x;i++)
			for(j=1;j<=l;j++)
				v[i*l+j]=multiply(v[i*l+j-1],w[j]);
		if(v[end]==1)
		for(i=1;i<end;i++)
			if(v[i]==2)
			for(j=i+1;j<end;j++)
				if(v[j]==6){
					ok=1;
					break;
				}
		if(ok) printf("Case #%d: YES\n",k);
		else printf("Case #%d: NO\n",k);
	}
 return 0;
}

