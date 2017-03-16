//Aleksander Łukasiewicz
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

typedef long long int LL;
const int MAXN = 1000000;
const int PRZ = 1500;

struct attack
{
    int day, w, e, S;
};

int t, N;
int wall[MAXN + 3];
attack tab[MAXN + 3];

bool cmp(attack a, attack b)
{
    return a.day < b.day;
}

int main()
{
    scanf("%d", &t);
    for(int pp=1; pp<=t; pp++)
    {
	for(int i=0; i<=MAXN; i++)
	    wall[i] = 0;
	stack< pair<int,int> > relax;
	int m = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
	    int n, delta_d, delta_p, delta_s;
	    attack nomad;
	    scanf("%d %d %d %d %d %d %d %d", &nomad.day, &n, &nomad.w, &nomad.e, &nomad.S, &delta_d, &delta_p, &delta_s);
	    tab[m++] = nomad;
	    for(int j=0; j<n-1; j++)
	    {
		nomad.day += delta_d;
		nomad.w += delta_p;
		nomad.e += delta_p;
		nomad.S += delta_s;
		tab[m++] = nomad;
	    }
	}

	sort(tab, tab+m, cmp);
	int res = 0, prevday = -1;
	for(int i=0; i<m; i++)
	{
	    if(tab[i].day != prevday)
	    {
		while(!relax.empty())
		{
		    int ind = relax.top().first, popraw = relax.top().second;
		    wall[ind] = max(wall[ind], popraw);
		    relax.pop();
		}
	    }
// 	    for(int j=-200 + PRZ; j<=200+PRZ; j++)
// 		printf("%d ", wall[j]);
// 	    puts("");
// 	    printf("attack: %d %d %d %d\n", tab[i].day, tab[i].w, tab[i].e, tab[i].S);
	    bool check = false;
	    for(int j=2*tab[i].w + PRZ; j<=2*tab[i].e + PRZ; j++)
		if(wall[j] < tab[i].S)
		{
		    check = true;
		    relax.push( make_pair(j, tab[i].S) );
		}
	    if(check)
	    {
// 		puts("succeds");
		res++;
	    }
// 	    else
// 		puts("fails");
	    prevday = tab[i].day;
	}

	printf("Case #%d: %d\n", pp, res);
    }

return 0;
}