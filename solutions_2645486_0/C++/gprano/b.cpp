#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int e,r,n;
int v[10];
	

int f(int juice, int act, int g)
{
    if(act == n)
	return g;
    int g2 = 0;
    for(int spend = 0; spend <= juice; spend++)
	g2 = max(g2,f(min(e,juice-spend+r),act+1,g+v[act]*spend));
    return g2;
}
    
    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	scanf("%d%d%d",&e,&r,&n);
	for(int i = 0; i < n; i++)
	    scanf("%d",&v[i]);
	printf("Case #%d: %d\n",cas,f(e,0,0));
    }
    return 0;
}
