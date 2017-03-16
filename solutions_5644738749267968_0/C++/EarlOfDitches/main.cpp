//==================================
//==========   WARNING   ===========
//==================================
//===   Contains too many bugs   ===
//==================================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

#define NAME "D-small-attempt0"


int main()
{
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
    cin >> t;

	for(int Case=1;Case<=t;++Case)
	{
		cout << "Case #" << Case << ": ";
		// Solution
		int n;
		cin >> n;
		vector<double> Naomi(n),Ken(n);
		for(int i=0;i<n;++i)
			cin >> Naomi[i];
		for(int i=0;i<n;++i)
			cin >> Ken[i];
		sort(Naomi.begin(),Naomi.end());
		sort(Ken.begin(),Ken.end());
		set<double> KenU;
		for(int i=0;i<n;++i)
			KenU.insert(Ken[i]);
		int ans1=0,ans2=0;
		for(int i=0;i<n;++i)
			if(Naomi[i]>*KenU.begin())
			{
				++ans1;
				KenU.erase(KenU.begin());
			}

		for(int i=0;i<n;++i)
			KenU.insert(Ken[i]);
		for(int i=0;i<n;++i)
		{
			set<double>::iterator it = KenU.upper_bound(Naomi[n-1-i]);
			if(it==KenU.end())
			{
				++ans2;
				KenU.erase(KenU.begin());
			}
			else
				KenU.erase(it);
		}
		// ends
		cout << ans1 << ' ' << ans2 << endl;
	}

    return 0;
}