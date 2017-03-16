//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
using namespace std;

int t,n,star,z,ans;
bool ktmu;

int main()
{
	scanf("%d",&t);
	FORN(i,t)
	{
		scanf("%d",&n);
		PII data[n];
		bool udah[n];
		FORN(j,n)
			scanf("%d%d",&data[j].se,&data[j].fi);
		printf("Case #%d: ",i+1);
		sort(data,data+n);
		RES(udah,false);
		star = 0;
		z = 0;
		ans = 0;
		while(z < n)
		{
			if (data[z].fi <= star)
			{
				if (udah[z])
					star++;
				else
				{
					star += 2;
					udah[z] = true;
				}
				z++;
				ans++;
			}
			else
			{
				ktmu = true;
				while (ktmu)
				{
					ktmu = false;
					FOR(j,z+1,n)
						if ((data[j].se <= star) && (!udah[j]))
						{
							star++;
							udah[j] = true;
							ans++;
							if (data[z].fi > star)
								ktmu = true;
							break;
						}
				}
				if (data[z].fi <= star)
				{
					if (udah[z])
						star++;
					else
					{
						star += 2;
						udah[z] = true;
					}
					z++;
					ans++;
				}
				else
				{
					if ((data[z].se <= star) && (!udah[z]))
					{
						star++;
						ans++;
						udah[z] = true;
					}
					if (data[z].fi <= star)
					{
						if (udah[z])
							star++;
						else
						{
							star += 2;
							udah[z] = true;
						}
						z++;
						ans++;
					}
					else
					{
						ktmu = true;
						while (ktmu)
						{
							ktmu = false;
							FOR(j,z+1,n)
								if ((data[j].se <= star) && (!udah[j]))
								{
									star++;
									udah[j] = true;
									ans++;
									if (data[z].fi > star)
										ktmu = true;
									break;
								}
						}
						if (data[z].fi <= star)
						{
							if (udah[z])
								star++;
							else
							{
								star += 2;
								udah[z] = true;
							}
							z++;
							ans++;
						}
						else
							break;
					}
				}
			}
		}
		if (star < n*2)
			printf("Too Bad\n");
		else
			printf("%d\n",ans);
	}
}
