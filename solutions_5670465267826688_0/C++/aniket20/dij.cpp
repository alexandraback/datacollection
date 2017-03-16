#include<bits/stdc++.h>
#define ll long long
using namespace std;

char val1[10005],val2[10005];
bool sign1[10005],sign2[10005];
char ch[4]={'1','i','j','k'};
char matr[4][4],signs[4][4];
int get(char ch)
{
	if(ch=='1') return 0;
	if(ch=='i') return 1;
	if(ch=='j') return 2;
	if(ch=='k') return 3;
}
void init()
{
	matr[0][0]='1';
	matr[0][1]='i';
	matr[0][2]='j';
	matr[0][3]='k';
	matr[1][0]='i';
	matr[1][1]='1';
	matr[1][2]='k';
	matr[1][3]='j';
	matr[2][0]='j';
	matr[2][1]='k';
	matr[2][2]='1';
	matr[2][3]='i';
	matr[3][0]='k';
	matr[3][1]='j';
	matr[3][2]='i';
	matr[3][3]='1';
	signs[0][0]=0;
	signs[0][1]=0;
	signs[0][2]=0;
	signs[0][3]=0;
	signs[1][0]=0;
	signs[1][1]=1;
	signs[1][2]=0;
	signs[1][3]=1;
	signs[2][0]=0;
	signs[2][1]=1;
	signs[2][2]=1;
	signs[2][3]=0;
	signs[3][0]=0;
	signs[3][1]=0;
	signs[3][2]=1;
	signs[3][3]=1;
}
int main()
{
	int t,i,ans,val,cnt=1,l,x,n,j;
	string s,str;
	scanf("%d",&t);
	init();
	while(t--)
	{
		scanf("%d %d",&l,&x);
		cin>>s;
		str=s;
		for(i=1;i<x;i++)
		{
			str+=s;
		}
		n=l*x;
	//	cout<<str;
		val1[0]=str[0];
		sign1[0]=0;
		for(i=1;i<n;i++)
		{
			val1[i]=matr[get(val1[i-1])][get(str[i])];
			sign1[i]=sign1[i-1]^signs[get(val1[i-1])][get(str[i])];
		}
		val2[n-1]=str[n-1];
		sign2[n-1]=0;
		for(i=n-2;i>=0;i--)
		{
			val2[i]=matr[get(str[i])][get(val2[i+1])];
			sign2[i]=sign2[i+1]^signs[get(str[i])][get(val2[i+1])];
		}
		// for(i=0;i<n;i++)
		// {
		// 	cout<<val2[i]<<" "<<sign2[i]<<endl;
		// }
		int fl=0;
		for(i=0;i<n;i++)
		{
			if(val1[i]=='i' && sign1[i]==0)
			{
				for(j=i+2;j<n;j++)
				{
					if(val2[j]=='k' && val1[j-1]=='k' && sign2[j]==0 && sign1[j-1]==0)
					{
						fl=1;
						break;
					}
				}
				if(fl==1)
				{
					break;
				}
			}
		}
		if(fl==1)
		printf("Case #%d: YES\n",cnt);
		else
		printf("Case #%d: NO\n",cnt);
		cnt++;
	}
	return 0;
}
