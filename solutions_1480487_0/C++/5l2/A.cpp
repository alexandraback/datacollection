#include<iostream>
#include<algorithm>
using namespace std;
int a[210],N, X;
int b[210];
bool cmp(int x,int y){return x<y;}
int main()
{
    int i,j,T;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d",&T);
	for(i=1;i<=T;++i)
	{
		printf("Case #%d:",i);
		scanf("%d",&N);
		//for(j=0;j<1000010;++j) hash[j]=0;
		for(X=j=0;j<N;++j) {scanf("%d",&a[j]); b[j]=a[j]; X+=a[j];}
		sort(b,b+N,cmp);
		for(j=0;j<N;++j) 
		{
			double tmp=X,avg=1000;
			for(int k=0;k<N;++k)
			{
				tmp+=b[k]-a[j];
				if(tmp/(k+1)<=avg) avg=(tmp)/(k+1);
			}
			if(avg<0) printf(" %.6lf",0);
			else printf(" %.6lf",100*avg/X);
		}
		printf("\n");
	}
    return 0;
}