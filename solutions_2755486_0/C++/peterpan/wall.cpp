#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include <boost/foreach.hpp>
#define foreach_         BOOST_FOREACH
#define foreach_r_       BOOST_REVERSE_FOREACH

using namespace std;

#define MAXN 1001
#define WL 2002

class Attack
{
  public:
	int d,w,e,s;
	Attack(int d,int w,int e,int s) { this->d = d; this->w = w; this->e = e; this->s = s;}
	bool operator < (const Attack & other) const { return d < other.d; }
	void print() { printf("%d,[%d,%d],%d\n",d,w,e,s); }
};

int main()
{
	int T,tcase,res,N;
	int di, ni, wi, ei, si, ddi, dpi, dsi;
	int wall[WL],woff=(WL/2);

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&N);
		vector<Attack> a;
		for(int i=0;i<N;i++)
		{
			scanf("%d %d %d %d %d %d %d %d", &di, &ni, &wi, &ei, &si, &ddi, &dpi, &dsi);

			for(int j=0;j<ni;j++)
			{
				a.push_back(Attack(di,wi,ei,si));
				di += ddi;
				wi += dpi;
				ei += dpi;
				si += dsi;
			}

		}

		sort(a.begin(),a.end());

		res=0;
		for(int i=0;i<WL;i++)
			wall[i]=0;

		unsigned i=0;
		while(i<a.size())
		{
			unsigned oldi=i,newi;

			//a[i].print();
			di=a[i].d;
			//printf("DAY %d\n",di);
			//proc di
			while(a[i].d==di && i<a.size())
			{
				int flag=0;
				for(int j=2*a[i].w+woff; j<=2*a[i].e+woff; j++)
				{
					if(wall[j]<a[i].s)
					{
						flag=1;
						break;
					}
				}
				res += flag;
				//a[i].print();
				//printf("\t%d\n",flag);
				
				i++;
			}
			newi=i;
			//raise wall;
			for(i=oldi;i<newi;i++)
			{
				for(int j=2*a[i].w+woff; j<=2*a[i].e+woff; j++)
					wall[j]=max(wall[j],a[i].s);
			}
		}

		
		printf("Case #%d: %d\n",tcase,res);
	}
	return 0;
}
