#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 2000000000
#define MEMSET_INF 127

int main(int argc, char const *argv[])
{
	ll n,e,r,t;
	vii v;
	int energy[10001];
	int potential[10001];
	cin>>t;
	for (int i = 0; i < t; ++i)
	{

		ll aux;
		ll total=0;
		ll ans=0;
		cin>>e>>r>>n;

		for (int j = 0; j < 10001; ++j)
		{
			energy[j]=e;
		}
		memset(potential,0,sizeof potential);
		for (int j = 0; j < n; ++j)
		{
			cin>>aux;
			v.pb(mp(aux,j));
		}

		sort(v.begin(),v.begin()+n);
		ll cons;
		for (int j = n-1; j >= 0; --j)
		{
			cons=energy[v[j].S]-potential[v[j].S];
			total+=v[j].F*cons;
			

			int aux2=energy[v[j].S]-r;
			int k=v[j].S-1;
			while((k>=0)&&(aux2>=0))
			{
				potential[k]=max(aux2,potential[k]);
				k--;
				aux2-=r;
			}
			aux2=energy[v[j].S]-cons+r;
			k=v[j].S+1;
			while((k<n)&&(aux2<e))
			{
				energy[k]=min(aux2,energy[k]);
				k++;
				aux2=aux2+r;
			}
		}


		printf("Case #%d: %lld\n",i+1,total);

		v.clear();

	}
	return 0;
}