#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int T;
double r,t;
double ans;
int R,M,N,K;
int v[10];

bool you5,you3,you4,you25,you35,you33,you23,you13,you2,you24,you34;

int main()
{
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d:\n",i);
		cin >> R >> N >> M >> K;
		for(int j=1;j<=R;j++)
		{
			you5=you25=you35=you13=you23=you3=you4=you2=you24=you34=0;
			for(int k=1;k<=K;k++)
			{
				cin>>v[k];
				if(v[k]%125==0) you35=1;
				if(v[k]%25==0) you25=1;
				if(v[k]%5==0) you5=1;
				if(v[k]%27==0) you33=1;
				if(v[k]%9==0) you23=1;
				if(v[k]%3==0) you3=1;
				if(v[k]%64==0) you34=1;
				if(v[k]%16==0) you24=1;
				if(v[k]%4==0) you4=1;
				if(v[k]%2==0) you2=1;
			}
			if(you35)
			{
				printf("555\n");
				continue;
			}
			if(you34)
			{
				printf("444\n");
				continue;
			}			
			if(you33)
			{
				printf("333\n");
				continue;
			}
			if(you25)
			{
				if(you3) 
				{
					printf("355\n");
					continue;
				}
				if(you4)
				{
					printf("455\n");
					continue;
				}
				if(you2)
				{
					printf("255\n");
					continue;
				}
			}
			if(you24)
			{
				if(you5) 
				{
					printf("445\n");
					continue;
				}
				if(you3)
				{
					printf("344\n");
					continue;
				}
					printf("244\n");
					continue;
			}			
			if(you23)
			{
				if(you5) 
				{
					printf("335\n");
					continue;
				}
				if(you4)
				{
					printf("334\n");
					continue;
				}
				if(you2)
				{
					printf("233\n");
					continue;
				}
			}	
			if(you5)
			{
				if(you3)
				{
					if(you4)
					{
						printf("345\n");
						continue;
					}
					if(you2)
					{
						printf("235\n");
						continue;
					}
					printf("335\n");
					continue;
				}
				if(you2)
				{
					printf("225\n");
					continue;
				}
				printf("445\n");
				continue;
			}
			if(you4)
			{
				if(you3)
				{
					printf("223\n");
					continue;
				}
				printf("222\n");
				continue;
			}
			printf("222\n");
		}
		
	}
	return 0;
}
