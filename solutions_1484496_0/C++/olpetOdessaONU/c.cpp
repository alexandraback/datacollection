#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>

using namespace std;

#define ll long long
#define pii pair<ll,int>
#define vi vector<int>
#define vit vi::iterator
#define vpi vector<pii >
#define sq(x) (x)*(x)

int n;
int mas[1000];

vpi answ;

void calc(int mask, int pos, ll sum)
{
	if(pos==n)
	{
		answ.push_back(pii(sum, mask));
		return;
	}
	calc(mask,pos+1,sum);
	calc(mask|(1<<pos),pos+1,sum+mas[pos]);
}

void test(int t)
{
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%d",&mas[i]);
	answ.clear();
	calc(0,0,0);
	sort(answ.begin(), answ.end());
	printf("Case #%d:\n",t);
	for(int i=1; i<answ.size(); ++i)
		if(answ[i].first==answ[i-1].first)
		{
			int a = answ[i-1].second;
			int b = answ[i].second;
			for(int j=0; j<n; ++j)
			{
				if(a&1)
				{
					printf("%d",mas[j]);
					if(a==1)
						printf("\n");
					else
						printf(" ");
				}
				a>>=1;
			}
			for(int j=0; j<n; ++j)
			{
				if(b&1)
				{
					printf("%d",mas[j]);
					if(b==1)
						printf("\n");
					else
						printf(" ");
				}
				b>>=1;
			}
			return;
		}
	printf("Impossible\n");
}

int main()
{
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0; i<t; ++i)
		test(i+1);
	return 0;
}