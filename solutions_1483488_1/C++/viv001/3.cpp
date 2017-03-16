#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int main()
{
	int T,n1,n2,fin;
	char s1[10],s2[10];
	char *p;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		map <int,int> A;
		int ans=0;
		scanf("%d",&n1);
		scanf("%d",&n2);
		if(n1<=9)
		{
		      printf("Case #%d: 0\n",i);
		      continue;
		}

		for(int num=n1;num<=n2;num++)
		{
			p=&s1[0];
			int k,rot=0,dig;
			char temp;
			sprintf(p,"%d",num);
			dig=strlen(s1);
			strcpy(s2,s1);
			while(rot!=dig-1)
			{
			temp=s2[0];
			for(k=1;s2[k]!=0;k++)
				s2[k-1]=s2[k];
			s2[k-1]=temp;
			s2[k]=0;
			p=&s2[0];

			sscanf(p,"%d",&fin);
			if(A[fin]!=num && fin>num && fin<=n2 && s2[0]!='0')
			{
				ans++;
				A[fin]=num;
			}
			rot++;
			}

		}

		printf("Case #%d: %d\n",i,ans);
		A.clear();

	}
	return 0;
}
