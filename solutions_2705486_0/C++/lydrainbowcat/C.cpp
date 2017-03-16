#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100],d[100],b[12],n,m,t,T,i,j,k,x,y,z;
char a[11][500000][11],s[100];

void calc(int l,int r,int p,int &x,int &y,int &z)
{
	int len=i-j,k;
	x=z=0,y=d[j];
	for(k=1;k<=len;k++)
		if(s[l+k-1]!=a[len][p][k])
		{
			if(!z) z=l+k-1;
			if(l+k-1-y<5) {x=-1; return;}
			y=l+k-1,x++;
		}
	if(!z) z=m+5;
}

int main()
{
	freopen("garbled_email_dictionary.txt","r",stdin);
	while(~scanf("%s",s+1))
	{
		t=strlen(s+1);
		b[t]++;
		for(i=1;i<=t;i++) a[t][b[t]][i]=s[i];
	}
	fclose(stdin);
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		scanf("%s",s+1);
		m=strlen(s+1);
		memset(f,0x3f,sizeof(f));
		f[0]=0,d[0]=-5; 
		for(i=1;i<=m;i++)
			for(j=max(0,i-10);j<i;j++)
				for(k=1;k<=b[i-j];k++)
				{
					calc(j+1,i,k,x,y,z);
					if(x!=-1&&z-d[j]>4)
						if(f[j]+x<f[i]||f[j]+x==f[i]&&y<d[i])
							f[i]=f[j]+x,d[i]=y;
				}
		printf("Case #%d: %d\n",t,f[m]);
	} 
}
