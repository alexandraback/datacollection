#include <iostream>
#include <map>
using namespace std;
#define pb push_back
int T, A,B,ans;

int osn,tosn;

void rotate(int &n)
{
	int t=1;
	int p=0;
	while (!p)
	{
		t*=10;
		p=n%t;
	}
	n=n/t;
	n+=(osn*10/t)*p;

}



int can_recycle(int n)
{
	map<int, bool> used;
	used.clear();
	int ananas=0;
	int b=n;

	for (int i=0; i<tosn; i++)
	{
		rotate(b);
		if ((b>n) && (b<=B) && !used[b]) ananas++;
		used[b]=1;
	}
	return ananas;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >>T;
	for (int q=1; q<=T; q++)
	{
		printf("Case #%d: ", q);
		scanf("%d%d", &A,&B);
		ans=0;
		osn=1; tosn=0;
		while (osn*10<=A) 
		{
			osn*=10; tosn++;
		}

		for (int i=A; i<=B; i++)
			ans+=can_recycle(i);

		printf("%d\n",ans);

	}
	return 0;

}