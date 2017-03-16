#include<bits/stdc++.h>
using namespace std;

int nq,n,m,J,P,S,col;
int a[30],b[30][4],used[10][10];

int main()
{//freopen("Cs.in","r",stdin);
 //freopen("Cs.out","w",stdout);

 int q,i,j,k,flag,np,s,x,y,z,s1;
 
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d%d%d%d",&J,&P,&S,&m);
 	//cout<<q<<endl;
	n=0;
 	for(i=1;i<=J;i++)
 		for(j=1;j<=P;j++)
 			for(k=1;k<=S;k++)
 			{	n++;
 				b[n][1]=i;
 				b[n][2]=j;
 				b[n][3]=k;
 			}		
 	s=0;
 	for(i=0;i<(1<<n);i++)
 	{	s1=0;
 		for(j=1;j<=n;j++)
 			if(i&(1<<(j-1))) s1++;
 		if(s1<=s) continue;
 		//col++;
		memset(used,0,sizeof(used));
		flag=1;
		for(j=1;j<=n;j++)
			if(i&(1<<(j-1)))
			{	x=b[j][1];
				y=b[j][2];
				z=b[j][3];
				if((++used[x][J+y])>m)
				{	flag=0;
					break;
				}
				if((++used[J+y][J+P+z])>m)
				{	flag=0;
					break;
				}
				if((++used[x][J+P+z])>m)
				{	flag=0;
					break;
				}
			}
		if(flag)
		{	s=s1;
			np=i;
		}
	}
	printf("Case #%d: %d\n",q,s);
	//cout<<np<<endl;
	for(i=1;i<=n;i++)
		if(np&(1<<(i-1)))
			printf("%d %d %d\n",b[i][1],b[i][2],b[i][3]);
 }
 return 0;
}
