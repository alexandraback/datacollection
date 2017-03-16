#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

int jp[555][555],js[555][555],ps[555][555];
int aa[5];
pair<int,pair<int,int> > pp[100000];
bool field[15][15][15];
int main()
{
	int test;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int j,p,s,k;
		scanf("%d %d %d %d",&j,&p,&s,&k);
		aa[0]=j;
		aa[1]=p;
		aa[2]=s;
		aa[3]=k;
		sort(aa,aa+4);
		int ans=aa[0]*aa[1]*aa[2];
		printf("Case #%d: %d\n",a,ans);
		memset(jp,0,sizeof(jp));
		memset(js,0,sizeof(js));
		memset(ps,0,sizeof(ps));
		memset(field,false,sizeof(field));
		for(int c=0;c<k;c++)
		{
		for(int bb=1;bb<=j;bb++)
		{
			for(int b=1;b<=p;b++)
			{
				if(field[bb][b][(b+bb-1+c)%s+1]==false)
				printf("%d %d %d\n",bb,b,(b+bb-1+c)%s+1);
				field[bb][b][(b+bb-1+c)%s+1]=true;
			}
		}
		}
		//
	}
}
