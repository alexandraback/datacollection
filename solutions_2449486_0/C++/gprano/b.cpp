#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
	    
int t[100][100];
int maxl[100];
int maxc[100];

int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	int n,m;
	bool possible = true;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		scanf("%d", &t[i][j]);
	for(int i = 0; i < n; i++)
	{
	    maxl[i] = 0;
	    for(int j = 0; j < m; j++)
		maxl[i] = max(maxl[i],t[i][j]);
	}
	for(int j = 0; j < m; j++)
	{
	    maxc[j] = 0;
	    for(int i = 0; i < n; i++)
		maxc[j] = max(maxc[j],t[i][j]);
	}
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		if(maxl[i] > t[i][j] && maxc[j] > t[i][j])
		    possible = false;
	printf("Case #%d: ",cas);
	if(possible) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
