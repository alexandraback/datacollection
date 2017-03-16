#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T,N,i,j,k,z,a[1001],b[1001],s,c,f,t[1001],l,q[1001],r[1001],n,y[1001],m;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		for(j=0;j<N;j++) {scanf("%d %d",&a[j],&b[j]);q[j]=a[j];r[j]=b[j];}
		sort(a,a+N);
		sort(b,b+N);
		for(j=0;j<N;j++) {t[j]=0;y[j]=0;}
		s=0;
		c=0;
		f=1;
		for(j=0;j<N;j++)
		{
			l=0;
			m=3000;
			for(k=0;k<N;k++)
			{
				if(b[j]==r[k] && !y[k])
				{
					for(z=0;z<N;z++) if(a[z]==q[k]) {if(t[z]==1) l=1;else {l=0;y[k]=1;break;}}
					if(l==0) break;
				}
				if(l) {y[k]=1;}
			}
			if(b[j]<=s && !l) {c+=1;s+=2;}
			else if(b[j]<=s) {c+=1;s++;}
			else
			{
				for(k=0;k<N && s<b[j] && a[k]<=s;k++)
					if(!t[k])
						{s+=1;c++;t[k]=1;}
				if(b[j]<=s && !l) {c+=1;s+=2;}
				else if(b[j]<=s) {c+=1;s++;}
				else f=0;
			}
		}
		if(f) printf("Case #%d: %d\n",i,c);
		else printf("Case #%d: Too Bad\n",i);
	}
	return 0;
}				
		
