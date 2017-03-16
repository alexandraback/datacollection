#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int arr[100][50];
bool usable[100];

int cnt[9999];
void tmain()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<2*N-1; i++)
	{
		usable[i] = true;
		for(int j=0; j<N; j++)
			scanf("%d",&arr[i][j]);
	}
	int ranl = 0;
	int ranr = N-1;
	for(int _=0; _<N-1; _++)
	{
		int maxv = 0;
		int maxi = 0;
		int maxi2=0;
		bool maxcd = false;
		for(int i=0; i<2*N-1; i++)
			if(usable[i])
				if(maxv<arr[i][ranr])
				{
					maxv = arr[i][ranr];
					maxcd = false;
					maxi = i;
				}
				else if(maxv==arr[i][ranr])
				{
					maxcd = true;
					maxi2 = i;
				}
		int minv = 9999;
		int mini = 0;
		int mini2= 0;
		bool mincd = false;
		for(int i=0; i<2*N-1; i++)
			if(usable[i])
				if(minv>arr[i][ranl])
				{
					minv = arr[i][ranl];
					mincd = false;
					mini = i;
				}
				else if(minv == arr[i][ranl])
				{
					mincd = true;
					mini2 = i;
				}
		if(mincd)
		{
			ranl++;
			usable[mini] = usable[mini2] = false;
		}
		else
		{
			ranr--;
			usable[maxi] = usable[maxi2] = false;
		}
	}
	//ans: ranl
	int fus=0;
	for(int i=0; i<2*N-1; i++)
	{
		if(usable[i])
		{
			fus=i;
			break;
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<2*N-1; i++)
		cnt[arr[i][ranl]]++;
	for(int i=0; i<N; i++)
		if(i!=ranl)
			cnt[arr[fus][i]]--;
	for(int i=0; i<9999;i++)
		if(cnt[i])
			printf("%d ",i);
	puts("");
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
}
