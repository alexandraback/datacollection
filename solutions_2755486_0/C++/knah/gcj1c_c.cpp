#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <string>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define FN "gcj1c_c"

int heights[4000005];

struct tribe {
	int n;
	int d;
	int s;
	int w,e;
	int ds;
	int dp;
	int dd;
	bool operator<(const tribe &o) const {
		return d < o.d;
	}
};

tribe ts[1000];

int main()
{
	
	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;
	vector<tribe> attacks;
	attacks.reserve(2000000);
	for(int i = 0; i < t; i++)
	{
		 int n;
		 in >> n;
		 int ans = 0;
		 set<int> coords;
		 unordered_map<int,int> cm;
		 attacks.clear();
		 for(int j = 0; j < n; j++)
		 {
			 in >> ts[j].d >> ts[j].n >> ts[j].w >> ts[j].e >> ts[j].s >> ts[j].dd >> ts[j].dp >> ts[j].ds;
			 ts[j].w *= 2;
			 ts[j].e *= 2;
			 ts[j].dp *= 2;
			 for(int k = 0; k < ts[j].n; k++)
			 {
				 coords.insert(ts[j].w+ts[j].dp*k);
				 coords.insert(ts[j].w+ts[j].dp*k-1);
				 coords.insert(ts[j].e+ts[j].dp*k);
				 coords.insert(ts[j].e+ts[j].dp*k+1);
				 tribe ca = ts[j];
				 ca.w = ts[j].w+ts[j].dp*k;
				 ca.e = ts[j].e+ts[j].dp*k;
				 ca.d = ts[j].d+ts[j].dd*k;
				 ca.s = ts[j].s+ts[j].ds*k;
				 if(ca.s < 0)
					 break;

				 attacks.push_back(ca);
			 }
		 }

		 sort(attacks.begin(), attacks.end());

		 int j = 0;
		 for(auto it = coords.begin(); it != coords.end(); ++it)
		 {
			 cm[*it] = j;
			 j++;
		 }
		 memset(heights,0,sizeof(int)*j);

		 vector<tribe> apply;
		 for(int j = 0; j < attacks.size(); j++)
		 {
			 if(!apply.empty() && attacks[j].d != apply[0].d)
			 {
				 for(int k = 0; k < apply.size(); k++)
				 {
					 for(int m = cm[apply[k].w]; m <= cm[apply[k].e]; m++)
						 heights[m] = max(heights[m],apply[k].s);
				 }
				 apply.clear();
			 }

			 bool yus = false;
			 for(int k = cm[attacks[j].w]; k <= cm[attacks[j].e]; k++)
			 {
				 if(heights[k] < attacks[j].s)
				 {
					 yus = true;
					 break;
				 }
			 }

			 if(yus)
			 {
				 apply.push_back(attacks[j]);
				 ans++;
			 }
		 }

		 out << "Case #" << (i+1) << ": " << ans << "\n";
	}

	out.close();
	return 0;
}