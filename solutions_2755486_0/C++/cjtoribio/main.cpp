#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define SHIFT (5000000)
int wall[2*SHIFT];
struct Tribe
{
	int doa,l,r,s,next_a,total_a,dd,ds;
	bool operator<(const Tribe &T)const
	{
		return doa > T.doa;
	}
};
int main()
{
	freopen("input.in","r",stdin);
	freopen("out.txt","w",stdout);
//	
	int TC;
	cin >>TC;
	for(int tc=1; tc<=TC; ++tc)
	{
		memset(wall,0,sizeof(wall));
		int N;
		cin >> N;
		priority_queue<Tribe> PQ;
		for(int i = 0; i < N; ++i)
		{
			Tribe t;
			cin >> t.doa >> t.total_a >> t.l >> t.r >> t.s >> t.next_a >> t.dd >> t.ds;
			PQ.push(t);
		}
		int cnt = 0;
		while(PQ.size())
		{
			int d = PQ.top().doa;
//			cout <<"----"<<endl<< d << endl;
			vector<Tribe> V;
			while(PQ.size() > 0 && PQ.top().doa == d)
			{
				Tribe t = PQ.top(); PQ.pop();
				int ok = 0;
				for(int i = 2*t.l; i <= 2*t.r && !ok; ++i)
					if(wall[SHIFT + i] < t.s)
						ok = 1;
				cnt += ok;
				V.push_back(t);
//				cout << t.s <<"\t("<<t.l<<","<<t.r<<")"<<" "<<ok<< endl;
			}
			for(int i = 0; i < V.size(); ++i)
			{
				for(int j = 2*V[i].l ; j <= 2*V[i].r; ++j)
					wall[SHIFT + j] = max(wall[SHIFT + j] , V[i].s);
				V[i].total_a--;
				if(V[i].total_a > 0)
				{
					V[i].doa += V[i].next_a;
					V[i].s += V[i].ds;
					V[i].l += V[i].dd;
					V[i].r += V[i].dd;
					PQ.push(V[i]);
				}
			}
		}
		cout <<"Case #"<<tc<<": "<< cnt << endl;
	}
	
	
	
}
