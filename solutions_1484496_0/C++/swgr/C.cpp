#include<iostream>
#include<map>

using namespace std;

int d[1000],n;

void print(int mask)
{
	bool first = true;
	for(int i=0;i<n;i++)
	{
		if (mask&(1<<i))
		{
			if (!first) printf(" ");
			else first = false;
			printf("%d",d[i]);
		}
	}
	printf("\n");
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>d[i];

		map<int,int> s;

		printf("Case #%d:\n",tt);

		bool found = false;

		for(int i=1;i<(1<<n);i++)
		{
			int sum = 0;
			for(int j=0;j<n;j++)
				if (i&(1<<j)) sum+=d[j];
			if (s.count(sum)!=0)
			{
				print(s[sum]);
				print(i);
				found = true;
				break;
			}
			else
				s[sum] = i;
		}

		if (!found)
			printf("Impossible\n");

	}
	return 0;
}
