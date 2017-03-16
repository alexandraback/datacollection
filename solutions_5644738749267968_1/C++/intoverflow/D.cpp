#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;
int main()
{
std::ios_base::sync_with_stdio(0);

int T;
cin>>T;
	for (int ct=1;ct<=T;ct++)
	{
	set <double> ken,kend;
	set <double> naomi,naomid;
	int n;
	int score=0,scored=0;
	cin>>n;
		for (int ct2=0;ct2<n;ct2++)
		{
		double a;
		cin>>a;
		naomi.insert(a);
		}
		for (int ct2=0;ct2<n;ct2++)
		{
		double a;
		cin>>a;
		ken.insert(a);
		}
		naomid=naomi;
		kend=ken;

				
				set<double>::iterator nit;
				set<double>::iterator kit;
				set<double>::reverse_iterator nitr;
				set<double>::reverse_iterator kitr;
				//War
				for (nit=naomi.begin();nit!=naomi.end();nit++)
				{
					kit=ken.upper_bound(*nit);
					if (kit==ken.end()) {score++;ken.erase(ken.begin());}
					else ken.erase(kit);
					
				}
				//Deceitful War
				while (!naomid.empty())
				{
				nitr=naomid.rbegin();
				kitr=kend.rbegin();
				nit=naomid.begin();
				kit=kend.begin();
					if (*nitr>*kitr)
					{
					scored++;
					naomid.erase(--(nitr.base()));
					kend.erase(--(kitr.base()));
					}
					else
					{
					
					naomid.erase(nit);
					kend.erase(--(kitr.base()));
					}
				}
		printf("Case #%d: %d %d\n",ct,scored,score);
	}
}
