// Author : dstorm
// Problem D : Deceitful War
// Compiler : Mingw (G++)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int>::iterator it;
vector<int>::iterator kit;
vector<int>::iterator nit;
// Same for War & DWar
vector<int>::iterator choose_ken(vector<int> &ken,int nc)
{	for(it = ken.begin() ; it != ken.end(); ++it)
		if(*it > nc)
			return it;
	return ken.begin();
}
int War(vector<int> naomi,vector<int> ken,int n)
{	int i,np=0;
	int nc,kc;
	for(i=0;i<n;i++)
	{	nc=naomi.front();
		kit = choose_ken(ken,nc);
		kc = *kit;
		//printf("%d %d\n",nc,kc);
		if(nc > kc)
			np++;
		naomi.erase(naomi.begin());
		ken.erase(kit);
	}
	return np;
}
// For DWar
vector<int>::iterator choose_naomi(vector<int> &naomi,vector<int> &ken,int &told)
{	int minn = naomi.front() , mink = ken.front(), maxk = ken.back();
	if(minn < mink)
	{	told = maxk - 1;
		return naomi.begin();
	}
	told = maxk + 1;
	return naomi.begin();
}
int DWar(vector<int> naomi,vector<int> ken,int n)
{	int i,np=0;
	int nc,kc,nt;
	for(i=0;i<n;i++)
	{	nit = choose_naomi(naomi,ken,nt);
		kit = choose_ken(ken,nt);
		nc = *nit;
		kc = *kit;
		//printf("%d %d %d\n",nc,nt,kc);
		if(nc > kc)
			np++;
		naomi.erase(nit);
		ken.erase(kit);
	}
	return np;
}
int main()
{	int t,i,j,n,iw;
	double w;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{	vector<int> naomi,ken;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{	scanf("%lf",&w);
			iw = (int)round(w*1000000);
			naomi.push_back(iw);
		}
		for(j=0;j<n;j++)
		{	scanf("%lf",&w);
			iw = round(w*1000000);
			ken.push_back(iw);
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		/*naomi.erase(naomi.begin());
		printf("%lf",naomi.front());
		*/
		/*
		for(j=0;j<n;j++)
			printf("%d ",naomi[j]);
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d ",ken[j]);
		*/
		int wp = War(naomi,ken,n);
		int dwp = DWar(naomi,ken,n);
		printf("Case #%d: %d %d\n",i,dwp,wp);
	}
	return 0;
}