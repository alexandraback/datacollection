#include <iostream>
#include <sstream>
#include <climits>
#include <cstddef>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<pair<ll,ll>,string> P;


int T;

struct TYPE {int w,e,s;};
int strength[10000000];
const int compensation=5000000;
vector<TYPE> attack[800000];

int main()
{
	cin>>T;

	for (int CASE = 1; CASE <= T; CASE++)
	{
		int N;
		cin>>N;

		for (int i = 0; i < 800000; i++) attack[i].clear();

		for (int i = 0; i < N; i++)
		{
			int di,ni,wi,ei,si,delta_di,delta_pi,delta_si;
			cin>>di>>ni>>wi>>ei>>si>>delta_di>>delta_pi>>delta_si;

			for (int j = 0; j < ni; j++)
			{
				TYPE t;
				t.e=ei*2;t.w=wi*2;t.s=si;
				attack[di].push_back(t);

				di+=delta_di;
				wi+=delta_pi;ei+=delta_pi;
				si+=delta_si;
			}
		}

		int ans=0;
		memset(strength,0,sizeof(strength));

		for (int i = 0; i < 800000; i++)
		{
			for (int j = 0; j < attack[i].size(); j++)
			{
				TYPE t=attack[i][j];

				bool flag=true;
				for (int k = t.w; k <= t.e; k++)
				{
					if (strength[k+compensation]<t.s) flag=false;
				}
				if (!flag) ans++;
			}

			for (int j = 0; j < attack[i].size(); j++)
			{
				TYPE t=attack[i][j];
				for (int k = t.w; k <= t.e; k++) strength[k+compensation]=max(strength[k+compensation],t.s);
			}
		}

		cout<<"Case #"<<CASE<<": "<<ans<<endl;
	}

	return 0;
}