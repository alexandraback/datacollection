#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int bas[100][100];
int haut[100][100];
bool seen[100][100];
int h, n, m;
priority_queue<pair<double, pair<int, int> >, 
	       vector<pair<double, pair<int, int> > >,
	       greater<pair<double, pair<int, int> > > > tas;

double temps(pair<int, int> a, pair<int, int> b, double depart, bool zero)
{
    if(b.first < 0 || b.first > n-1 || b.second < 0 || b.second > m-1)
	return -1.;
    if(seen[b.first][b.second])
	return -1.;
    if(haut[b.first][b.second] - bas[a.first][a.second] < 50 ||
       haut[b.first][b.second] - bas[b.first][b.second] < 50 ||
       haut[a.first][a.second] - bas[b.first][b.second] < 50)
	return -1.; //impossible
    if(zero && haut[b.first][b.second] - h >= 50)
	return 0.; //avant la marée basse
    double wait = max(0.,(((double) h) - 10.*depart + 50. - ((double)haut[b.first][b.second]))/10.);
    if(((double)h) - 10.*(depart+wait) - ((double)bas[a.first][a.second]) >= 20.)
	wait += 1.;
    else wait += 10.;
    return wait + depart;
}

int main()
{
    int nbcas;
    scanf("%d", &nbcas);
    for(int cas = 1; cas <= nbcas; cas++)
    {
	scanf("%d%d%d", &h, &n, &m);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		scanf("%d", &haut[i][j]);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		scanf("%d", &bas[i][j]);
	for(int i = 0; i < n; i++)
	    for(int j = 0; j < m; j++)
		seen[i][j] = false;
	while(!tas.empty()) tas.pop();
	bool zero = true;
	tas.push(make_pair(0.,make_pair(0,0)));
	while(true)
	{
	    pair<double, pair<int, int> > curr = tas.top();
	    tas.pop();
	    double mtn = curr.first;
	    pair<int, int> coo = curr.second;
	    seen[coo.first][coo.second] = true;
	    if(mtn > 0.00000001) zero = false;
	    if(coo.first == n-1 && coo.second == m-1)
	    {
		printf("Case #%d: %lf\n", cas, mtn);
		break;
	    }
	    for(int dx = -1; dx < 2; dx++)
		for(int dy = -1; dy < 2; dy++)
		    if(dx*dy == 0)
		    {
			pair<int, int> voisin = make_pair(coo.first+dx, coo.second+dy);
			double quand = temps(coo,voisin,mtn,zero);
			if(quand > -0.1)
			    tas.push(make_pair(quand,voisin));
		    }
	}
    }
    return 0;
}
