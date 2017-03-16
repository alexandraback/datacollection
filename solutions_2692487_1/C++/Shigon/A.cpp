#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <valarray>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>

#define PB push_back
#define SIZE(x) (int)x.size()
#define st first
#define nd second

using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> para;

class problem
{
private:
	int A,N;
	VI val;
	int solve()
	{
		sort(val.begin(),val.end());
		int suma=A;
		int cnt=0;
		int minWyn=-1;

		if (suma==1) return N;

		int i;
		for (i=0; i<N; ++i)
		{
			int x=val[i];
			if (x>=suma)
			{
				int tmpWyn=cnt+N-i;
				if (minWyn==-1 || tmpWyn<minWyn) minWyn=tmpWyn;

				while (x>=suma)
				{
					suma=suma*2-1;
					++cnt;
				}
			}
			suma+=x;
		}
		if (minWyn==-1 || cnt<minWyn) minWyn=cnt;
		return minWyn;
	}
public:
	void czytaj()
	{
		cin>>A>>N;
		val.resize(N);
		for (int i=0; i<N; ++i) cin>>val[i];
	}
	void wypiszWynik()
	{
		int wynik=solve();
		cout<<wynik;
	}
};

int main()
{
	ios::sync_with_stdio(0);

	int Testow; cin>>Testow;
	for (int nrTestu=1; nrTestu<=Testow; ++nrTestu)
	{
		problem Prob;
		Prob.czytaj();
		cout<<"Case #"<<nrTestu<<": ";
		Prob.wypiszWynik();
		cout<<endl;
	}

	return 0;
}