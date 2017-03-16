#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

long long E,R,N,V[10100];
vector<pair<long long, long long> > D[10010];

void in(int k, pair<long long, long long> p)
{
	int i;

	for (i=0;i<D[k].size();i++){
		if (D[k][i].first >= p.first && D[k][i].second >= p.second) return;
		if (D[k][i].first <= p.first && D[k][i].second <= p.second){
			D[k].erase(D[k].begin()+i); i--;
		}
	}
	D[k].push_back(p);
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int T,Case=0;
	int i,j,k;
	long long ans,nexte,nexts;

	scanf ("%d",&T); while (T--){
		scanf ("%lld %lld %lld",&E,&R,&N);
		if (R > E) R = E;
		D[0].clear();
		D[0].push_back(make_pair(0,E));
		for (i=1;i<=N;i++){
			scanf ("%lld",V+i);
			D[i].clear();
			for (j=0;j<D[i-1].size();j++){
				nexts = D[i-1][j].first;
				nexte = D[i-1][j].second;
				if (nexte > E - R){
					nexts += (nexte - E + R) * V[i];
					nexte = E - R;
				}
				in(i,make_pair(nexts,min(nexte+R,E)));
				in(i,make_pair(nexts+nexte*V[i],R));
				for (k=0;k<N;k++){
					nexts += R * V[i];
					nexte -= R;
					if (nexte < 0) break;
					in(i,make_pair(nexts,min(nexte+R,E)));
				}
			}
		}

		ans = D[N][0].first;
		for (i=1;i<D[N].size();i++) ans = max(ans,D[N][i].first);
		printf ("Case #%d: %lld\n",++Case,ans);
	}

	return 0;
}