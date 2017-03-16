#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool b[2000005];
int a[15];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int test,Case,A,B; scanf("%d",&test);
	for (Case=1;Case<=test;Case++){
		memset(b,0,sizeof(b));
		scanf("%d%d",&A,&B); long long ans=0;
		for (int i=A;i<=B;i++) if (!b[i]){
			int c=1,x=i,y=1,l=0; b[i]=1;
			while (x) a[++l]=x%10,x/=10,y*=10; y/=10; x=i;
			for (int j=1;j<l;j++){
				x=x/10+a[j]*y;
				if (A<=x && x<=B && !b[x]) b[x]=1,c++;
				}
			ans+=c*(c-1)/2;
			}
		cout<<"Case #"<<Case<<": "<<ans<<endl;
		}
	return 0;
}
