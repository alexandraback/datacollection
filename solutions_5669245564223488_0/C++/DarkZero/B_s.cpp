#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

char str[20][200];
int t;
int n;
int ans = 0;

int mark[20] = {0};
int seq[20]={0};
int stop[200]={0};

void init()
{
	memset(str, 0, sizeof(str));
	ans = 0;
	memset(mark, 0, sizeof(mark));
	memset(seq, 0, sizeof(seq));
	return ;
}

bool check()
{
	int i,j;
    memset(stop, 0, sizeof(int)*200);
	char now =' ';
	for(i=1;i<=n;i++)
	{
		int len = strlen(str[ seq[i] ]);
		for(j=0;j<len;j++)
		{
			//cout<<str[ seq[i] ][j]<<" ";
			if( stop[ str[ seq[i] ][j] ] ==1)
				return false;
			if(str[seq[i]][j] != now)
			{
				stop[now] = 1;
				now = str[seq[i]][j];
			}
		}
		//cout<<endl;
	}
	if(stop[now] == 1)
		return false;
	return true;
}

void DFS(int now)
{
	//cout<<now<<endl;
	if(now == n+1)
	{
		if( check() )
		{
			ans++;
		}
		return;
	}
	
	int i;
	for(i=1;i<=n;i++)
	{
		if(mark[i]==0)
		{
			seq[now] = i;
			mark[i] = 1;
			DFS(now+1);
			mark[i] = 0;
			seq[now] = 0;
		}
	}
	return;
}

int main()
{
	freopen("BS.txt", "r", stdin);
	freopen("BS1.txt", "w", stdout);
	scanf("%d", &t);
	int files;
	for(files=1; files<=t; files++)
	{
		init();
		scanf("%d", &n);
		int i;
		for(i=1;i<=n;i++)
			scanf("%s", str[i]);
		
		DFS(1);
		printf("Case #%d: %d\n", files, ans);
	}
	//system("pause");
	return 0;
}