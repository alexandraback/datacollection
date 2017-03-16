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

#define NAME "B-small-attempt0"


int main()
{
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);

	int t;
    cin >> t;

	for(int Case=1;Case<=t;++Case)
	{
		cout << "Case #" << Case << ": ";
		// Solution
		double C,F,X;
		cin >> C >> F >> X;
		double ans = 1e100;
		double temp = 0;
		for(int i=0;i<=10000;++i)
		{
			ans = min(ans,temp+X/(F*i+2.));
			temp += C/(F*i+2.);
		}
		// ends
		cout << fixed << setprecision(9) << ans << endl;
	}

    return 0;
}