#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<string.h>
#include<set>
#include<time.h>

using namespace std;

int R, N, M, K, T;

vector< set<int> > S;
set< int > ALL;

set<int> Union(const set<int> &me, const set<int> &you)
{
	set<int> ret;

	set<int>::iterator it;
	
	for(it = me.begin(); it != me.end(); ++it)
	{
		if(you.count(*it) == 1)
		{
			ret.insert(*it);
		}
	}
	
	return ret;
}

int main(void)
{
	int l1, l2, l3, l4, l0;

	srand(time(0));

	S.resize(5*5*5+1);

	for(l1 = 2; l1 <= 5; l1++)
	{
		for(l2 = 2; l2 <= 5; l2++)
		{
			for(l3 = 2; l3 <= 5; l3++)
			{
				int val = l1 * 100 + l2 * 10 + l3;

				ALL.insert(val);

				S[1].insert(val);
				S[l1].insert(val);
				S[l2].insert(val);
				S[l3].insert(val);
				S[l1*l2].insert(val);
				S[l1*l3].insert(val);
				S[l2*l3].insert(val);
				S[l1*l2*l3].insert(val);
			}
		}
	}

	scanf("%d",&T);
	{
		printf("Case #%d:\n",1);

		scanf("%d %d %d %d", &R, &N, &M, &K);

		for(l0=1;l0<=R;l0++)
		{
			set<int> wow = ALL;
			for(l1 = 1; l1 <= K; l1++)
			{
				int product;

				scanf("%d", &product);

				wow = Union(wow, S[product]);
			}

			if(wow.size() == 0)
			{
				wow = ALL;
			}

			vector<int> who;
			set<int>::iterator it;
			for(it = wow.begin(); it != wow.end(); ++it)
			{
				who.push_back(*it);
			}

			random_shuffle(who.begin(), who.end());

			printf("%d\n", who[0]);
		}
	}

}
