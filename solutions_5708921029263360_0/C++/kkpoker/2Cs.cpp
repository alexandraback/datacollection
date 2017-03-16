#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N =15;
const int p =14;
int hash(int x,int y,int z)
{
	
}
int a,b,c,K;
//int hs1[N][N][N];
int hs2[N][N][N];
int stk[25000][3],top;
int ans;

int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	int T;
	cin>>T;
	for(int xx=1;xx<=T;xx++)
	{
		printf("Case #%d: ",xx);
		cin>>a>>b>>c>>K;
		top=0;
	//memset(hs1,0,sizeof(hs1));
		memset(hs2,0,sizeof(hs2));
		ans=0;
		for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
		for(int k=c;k>=1;k--)
		{
			hs2[i][0][k]++;hs2[0][j][k]++;hs2[i][j][0]++;
			if(hs2[i][0][k]<=K && hs2[0][j][k]<=K && hs2[i][j][0]<=K)
			{
				stk[++top][0]=i,stk[top][1]=j,stk[top][2]=k;
			}
			else 
			{hs2[i][0][k]--;hs2[0][j][k]--;hs2[i][j][0]--;}
		}
		cout<<top<<endl;
		for(int i=1;i<=top;i++)	cout<<stk[i][0]<<' '<<stk[i][1]<<' '<<stk[i][2]<<endl;
	}
	return 0;
} 
/*
100
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
1 1 1 3
2 2 3 10
3 3 3 4
1 2 3 6
1 2 3 3
1 1 1 2
1 1 1 1
1 1 2 9
1 1 1 6
2 3 3 2
1 2 2 4
1 2 3 7
2 2 2 2
3 3 3 7
1 1 3 3
2 3 3 6
3 3 3 2
1 2 2 8
2 2 3 8
1 2 3 10
1 1 2 3
1 1 3 7
1 2 2 6
1 3 3 5
1 2 2 7
2 2 2 6
2 2 3 9
1 2 2 5
1 1 2 6
1 2 3 5
1 2 2 2
1 2 3 8
2 2 3 4
2 2 2 10
3 3 3 9
2 2 2 8
1 1 2 1
2 2 2 4
1 1 1 8
1 2 2 1
1 1 3 10
1 1 3 8
1 1 2 7
1 1 1 5
1 3 3 10
1 1 2 5
1 3 3 1
1 2 3 9
1 2 3 4
2 3 3 9
2 2 2 9
1 2 2 10
1 3 3 6
2 2 3 5
2 3 3 7
2 2 3 1
3 3 3 1
1 1 1 4
2 3 3 3
1 1 3 1
2 2 2 7
2 2 3 7
2 3 3 1
2 2 2 3
2 2 3 3
1 2 2 9
1 3 3 7
1 1 2 2
1 1 3 9
1 1 1 7
1 3 3 8
1 3 3 3
2 3 3 8
1 1 3 6
3 3 3 8
1 3 3 2
2 2 3 6
2 3 3 4
2 2 2 1
3 3 3 10
2 3 3 5
1 3 3 4
3 3 3 6
1 1 3 4
1 1 2 8
3 3 3 5
1 1 3 5
1 1 2 10
1 3 3 9
2 2 3 2
2 2 2 5
2 3 3 10
1 1 1 9
1 1 2 4
3 3 3 3
1 2 2 3



*/
