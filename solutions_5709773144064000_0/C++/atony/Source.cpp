#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 51;
const int MAXM = 2000011;
const int MAXK = 201;
const int INF = 1000000001;
const double eps = 1e-5;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,cas,i;
	double c,f,x,es,ans,t,res;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		ans=x/2; t=2; es=0;
		for(i=0;1;i++)
		{
			res=es+c/t+x/(f+t);
			if(res>ans)
				break;
			ans=res;
			es=es+c/t;
			t=f+t;
		}
		printf("Case #%d: %.7lf\n",cas,ans);
	}
	return 0;
	
}