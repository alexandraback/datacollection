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

double n,c,f,x;

void dane()
{
	cin>>n;
	FOR(przy,0,n)
	{
		cin>>c>>f>>x;
		double mini = x/2;
		int razy = 0;
		double time = 0;
		double przybywa = 2;
		int x2 =x;		
		while(x2--)
		{
			//licze ile kukisów mi zostanie i sekund to zajmie
			double dod_czas = c/przybywa;
			razy++;
			time+=dod_czas;
			przybywa+=f;
			
			//liczymy ile minie czasu aby uzuskac na ilus farmach x
			mini = min(mini,time+x/przybywa);
		}
		printf("Case #%d: %.7f\n",przy+1,mini);
	}
}

int main()
{
	dane();
	return 0;
}
