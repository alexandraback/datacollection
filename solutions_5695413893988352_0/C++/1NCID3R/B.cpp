#include <bits/stdc++.h>
using namespace std;

char in[2][20];
int num[2][20];
char buffer[20];

int arr[2][2][20];

void getmax(int k, int pos)
{
	if(in[k][pos]==0)
		return;
	if(in[k][pos]=='?')
		num[k][pos] = 9;
	else
		num[k][pos] = in[k][pos]-'0';
	getmax(k,pos+1);
}

void getmin(int k, int pos)
{
	if(in[k][pos]==0)
		return;
	if(in[k][pos]=='?')
		num[k][pos] = 0;
	else
		num[k][pos] = in[k][pos]-'0';
	getmin(k,pos+1);
}

bool f1(int pos)
{
	if(in[0][pos]==0)
		return true;

	if(in[0][pos]=='?')
	{
		if(in[1][pos]=='?')
		{
			if(f1(pos+1))
				num[0][pos] = num[1][pos] = 0;
			else
			{
				num[0][pos] = 1;
				num[1][pos] = 0;
				getmax(1,pos+1);
				getmin(0,pos+1);
			}

			return true;
		}

		if(f1(pos+1))
		{
			num[0][pos] = num[1][pos] = in[1][pos]-'0';
			return true;
		}

		if(in[1][pos]=='9')
			return false;
		num[1][pos] = in[1][pos]-'0';
		num[0][pos] = num[1][pos]+1;
		getmax(1,pos+1);
		getmin(0,pos+1);
		return true;
	}

	if(in[1][pos]=='?')
	{
		if(f1(pos+1))
		{
			num[0][pos] = num[1][pos] = in[0][pos]-'0';
			return true;
		}

		if(in[0][pos]=='0')
			return false;
		num[0][pos] = in[0][pos]-'0';
		num[1][pos] = num[0][pos]-1;
		getmax(1,pos+1);
		getmin(0,pos+1);
		return true;
	}
	num[0][pos] = in[0][pos]-'0';
	num[1][pos] = in[1][pos]-'0';

	if(in[0][pos]>in[1][pos])
	{
		getmax(1,pos+1);
		getmin(0,pos+1);
		return true;
	}

	if(in[0][pos]==in[1][pos])
		return f1(pos+1);
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(int cn=1; cn<=t; cn++)
	{
		for(int i=0; i<2; i++)
			scanf("%s",in[i]);
		int s = strlen(in[0]);

		printf("Case #%d:",cn);

		bool b1 = f1(0);
		for(int i=0; i<2; i++)
			for(int j=0; j<s; j++)
				arr[0][i][j] = num[i][j];
		/*
		puts("");
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<s; j++)
				printf("%d",num[i][j]);
			puts("");
		}
		*/
		strcpy(buffer,in[0]);
		strcpy(in[0],in[1]);
		strcpy(in[1],buffer);

		bool b2 = f1(0);
		for(int i=0; i<2; i++)
			for(int j=0; j<s; j++)
				arr[1][i][j] = num[1-i][j];
		/*
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<s; j++)
				printf("%d",num[i][j]);
			puts("");
		}
		*/

		strcpy(buffer,in[0]);
		strcpy(in[0],in[1]);
		strcpy(in[1],buffer);

		long long a[2][2] = {{0,0},{0,0}};
		for(int i=0; i<2; i++)
			for(int j=0; j<2; j++)
				for(int k=0; k<s; k++)
					a[i][j] = a[i][j]*10 + arr[i][j][k];
		if(b1 && b2)
		{
			int d1 = a[0][0]-a[0][1];
			int d2 = a[1][1]-a[1][0];
			if(d1<d2 || (d1==d2 && (a[0][0]<a[1][0] || (a[0][0]==a[1][0] && a[0][1]<a[1][1]))))
			{
				for(int i=0; i<2; i++)
				{
					printf(" ");
					for(int j=0; j<s; j++)
						printf("%d",arr[0][i][j]);
				}
				printf("\n");
			}
			else
			{
				for(int i=0; i<2; i++)
				{
					printf(" ");
					for(int j=0; j<s; j++)
						printf("%d",arr[1][i][j]);
				}
				printf("\n");
			}
		}
		else if(b1)
		{
			for(int i=0; i<2; i++)
			{
				printf(" ");
				for(int j=0; j<s; j++)
					printf("%d",arr[0][i][j]);
			}
			printf("\n");
		}
		else
		{
			for(int i=0; i<2; i++)
			{
				printf(" ");
				for(int j=0; j<s; j++)
					printf("%d",arr[1][i][j]);
			}
			printf("\n");
		}
	}
}