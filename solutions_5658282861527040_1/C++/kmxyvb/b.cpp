#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

long long f[40][3][3][3];

int TestCase,Case,i,j,k,l,_j,_k,_l,_A,_B,__A,__B,__K,A,B,K;

int main()
{
//	freopen("b.in","rb",stdin);
//	freopen("b.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d%d",&A,&B,&K);
		A--;B--;K--;
		memset(f,0,sizeof f);
		for(j=0;j<2;j++)
			for(k=0;k<2;k++)
				for(l=0;l<2;l++)
					f[0][j][k][l]=1;
		for(i=0;i<31;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
					for(l=0;l<2;l++)
		for(_A=0;_A<2;_A++)
			for(_B=0;_B<2;_B++)
			{
				__A=((A>>i)&1);
				__B=((B>>i)&1);
				__K=((K>>i)&1);
				if(j==0&&_A>__A)continue;
				if(k==0&&_B>__B)continue;
				if(l==0&&(_A&_B)>__K)continue;
				_j=j;
				_k=k;
				_l=l;
				if(_A<__A)_j=1;
				if(_B<__B)_k=1;
				if((_A&_B)<__K)_l=1;
				f[i+1][j][k][l]+=f[i][_j][_k][_l];
			}
		cout<<"Case #"<<Case<<": "<<f[31][0][0][0]<<endl;
	}
	return 0;
}
