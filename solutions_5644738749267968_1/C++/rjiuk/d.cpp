#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#define FOR(i,p,k) for(int i = (p);i<(k);i++)
typedef long long int LL;
using namespace std;

int t;
double Tab[2][1111];

bool Zuzyte[111];

int latwiejszy(int n)
{
	int pkt = 0;
	FOR(i,0,n)
	{
		double akt = Tab[0][i];
		bool done = 0;
		//sprawdzamy czy jest wiekszy nieuzyty
		FOR(j,0,n)
		{
			if(Tab[1][j]>akt && Zuzyte[j]==0)
			{
				done=1;
				Zuzyte[j]=1;
				break;
			}
		}		
		if(done)
			continue;

		//wkladamy najmniejszy ktory przegrywa
		FOR(j,0,n)
			if(Zuzyte[j]==0)
			{
				pkt++;
				Zuzyte[j]=1;
				break;
			}
	}
	FOR(i,0,n)
		Zuzyte[i]=0;
	return pkt;
}

int trudniejszy(int n)
{
	int maxi = 0;

	FOR(i,0,n+1)
	{	
		int akt = 0;
		FOR(j,0,n-i)
		{
			if(Tab[0][j+i]>Tab[1][j])
				akt++;
		}
		maxi = max(maxi,akt);
	}
	return maxi;
}

void dane()
{
	cin>>t;

	FOR(przy,1,t+1)
	{
		int n;
		scanf("%d",&n);
		
		FOR(i,0,n)
			cin>>Tab[0][i];
		FOR(i,0,n)
			cin>>Tab[1][i];
		
		sort(Tab[1],Tab[1]+n);
		sort(Tab[0],Tab[0]+n);
	
		int drugi = latwiejszy(n);
		int pierw = trudniejszy(n);
		printf("Case #%d: %d %d\n",przy,pierw,drugi);
	}
}

int main()
{
	dane();
	return 0;
}
