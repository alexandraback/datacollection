#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char input[105],target[105];
int in[50],tar[50];
bool check[50];

int conv(char c)
{
	if(c=='A') return 0;
	if(c=='B') return 1;
	if(c=='C') return 2;
	if(c=='D') return 3;
	if(c=='E') return 4;
	if(c=='F') return 5;
	if(c=='G') return 6;
	if(c=='H') return 7;
	if(c=='I') return 8;
	if(c=='J') return 9;
	if(c=='K') return 10;
	if(c=='L') return 11;
	if(c=='M') return 12;
	if(c=='N') return 13;
	if(c=='O') return 14;
	if(c=='P') return 15;
	if(c=='Q') return 16;
	if(c=='R') return 17;
	if(c=='S') return 18;
	if(c=='T') return 19;
	if(c=='U') return 20;
	if(c=='V') return 21;
	if(c=='W') return 22;
	if(c=='X') return 23;
	if(c=='Y') return 24;
	if(c=='Z') return 25;
}

int main()
{
	int test,k,l,s;
	scanf("%d",&test);
	char temp;
	for(int a=1;a<=test;a++)
	{
		bool noans=false;
		float ans;
		memset(in,0,sizeof(in));
		memset(tar,0,sizeof(tar));
		memset(check,false,sizeof(check));
		scanf("%d %d %d",&k,&l,&s);
		scanf("%s",input);
		scanf("%s",target);
		for(int b=0;b<k;b++)
		{
			in[conv(input[b])]++;
			check[conv(input[b])]=true;
		}
		for(int b=0;b<l;b++)
		{
			if(!check[conv(target[b])])
			{
				noans=true;
				break;
			}
		}
		int rem=l;
		int banana;
		float pel=1;
		if(!noans)
		{
			for(int b=l;b>=1;b--)
			{
				bool ada=true;
				for(int d=0;d<l;d++)
				{
					if(target[d]!=target[d%b])
					{
						ada=false;
						break;
					}
				}
				if(ada) rem=min(rem,b);
			}
			banana=1;
			int w=s-l;
			banana+=w/rem;
			for(int b=0;b<l;b++)
			{
				pel=pel*in[conv(target[b])]/k;
			}
			pel=(s-l+1)*pel;
			ans=banana-pel;
		}
		if(!noans)printf("Case #%d: %.6f\n",a,ans);
		else printf("Case #%d: 0.0\n",a);
	}
}
