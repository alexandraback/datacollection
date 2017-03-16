#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int values;
	int maxn;
	bool iss;
};

node score[200];

int sov(int n, node sc[] , int s , int p)
{
	for (int i = 0 ; i < n ; i++)
	{
		sc[i].iss =false;
		if(sc[i].values%3 != 1 && sc[i].values >= 2)
			sc[i].iss = true;
		sc[i].maxn = sc[i].values%3 == 0 ? sc[i].values/3 : sc[i].values/3+1;
	}
	int sum = 0;
	int sn = 0;
	for (int i = 0 ;  i < n ; i++)
	{
		if(sc[i].maxn >= p)
			sum++;
		else
		{
			if(sc[i].iss) //¿ÉÒÔ¿¼ÂÇ¼Ó1
			{
				if(sn < s)
				{
					if(sc[i].maxn + 1 >= p)
						sum++ , sn++;
				}
			}
		}
	}
	return sum;
}
void show(int n, int s , int p , node sc[])
{
	printf("%d %d %d",n,s,p);
	for (int i = 0 ; i < n ; i++)
	{
		printf(" %d",sc[i].values);
	}
	printf("\n");
}
int main()
{
	int t,n,s,p;
	cin >> t;
	
	for (int i = 1 ; i <= t ; i++)
	{
		cin >> n >> s >> p;
		for (int j = 0 ; j < n ; j++)
			cin >> score[j].values;
		//show(n,s,p,score);
		printf("Case #%d: %d\n",i,sov(n,score,s,p));
	}	
	return 0;
}