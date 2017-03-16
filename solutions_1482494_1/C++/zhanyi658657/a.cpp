#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;



int main()
{
	

	freopen("log.txt", "rb+", stdin);
	freopen("ans.txt", "w", stdout);
	long testcase;
	long A[2000], B[2000];
	int markA[2000], markB[2000];
	scanf("%d", &testcase);
	int n;
	for(int i = 1;i <= testcase;i++)
	{
		
		scanf("%d", &n);
		for(int j = 1;j <= n;j++)
		{
			scanf("%d%d", &A[j], &B[j]);
		}
		for(int j = 1;j <= n;j++)
		{
			for(int k = j;k <= n;k++)
			{
				if(B[k] < B[j])
				{
					swap(A[k], A[j]);
					swap(B[k], B[j]);
				}
			}
		}
		int num = 0;
		int star = 0;
		int k;
		memset(markA, 0, sizeof(markA));
		memset(markB, 0, sizeof(markB));
		for(k = 1;k <= n;)
		{
			if(B[k] <= star)
			{
				markB[k] = 1;star += 2;
				if(markA[k] == 1)star--;
				k++;
				num++;
			}
			else
			{
				int find = 0;
				for(int s = n;s >=k;s--)
				{
					if(star >= A[s] && markA[s] == 0)
					{
						markA[s] = 1;
						star++;
						find = 1;
						num++;
						break;

					}
				}
				if(!find)break;
			}
		}
		if(k > n)
		{
			cout<<"Case #"<<i<<": "<<num<<endl;//Too Bad"<<endl;

		}
		else
		{
			cout<<"Case #"<<i<<": Too Bad"<<endl;
		}
 
	}
	return 0;

	
}
