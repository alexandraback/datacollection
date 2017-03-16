#include "bits/stdc++.h"
using namespace std;

#define pb push_back
typedef long long ll;

int ab[11][11], ac[11][11], bc[11][11];
struct trp
{
	int x,y,z;
	trp(){}
	trp(int x, int y, int z):x(x),y(y),z(z){}
};
#define mp make_pair
bool operator <(const trp &a, const trp &b)
{
	return mp(a.x, mp(a.y,a.z)) < mp(b.x, mp(b.y,b.z));
}

bool operator ==(const trp &a, const trp &b)
{
	return mp(a.x, mp(a.y,a.z)) == mp(b.x, mp(b.y,b.z));
}


void solve(int test)
{
	int a,b,c,K;
	cin >> a >> b >> c >> K;
	for (int i = 0; i < a; i++)
	   for (int j = 0; j < b; j++)
	      ab[i][j] = 0;
	for (int i = 0; i < a; i++)
	   for (int j = 0; j < c; j++)
	      ac[i][j] = 0;
	for (int i = 0; i < b; i++)
	   for (int j = 0; j < c; j++)
	      bc[i][j] = 0;
	
  //  int ci = 0;
    vector<vector<int> > g(a);
    for (int i = 0; i < a; i++)
    {
    	g[i].resize(b);
    	for (int j = 0; j < b; j++)
    	   g[i][j] = ((j+i)%b);
    }
   /* for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
           cout << g[i][j] << " \n"[j==b-1];*/
    vector<trp> ans;
    for (int i = 0; i < min(K,c); i++)
        for (int j = 0; j < a; j++)
           for (int k = 0; k < b; k++)
           {
               ab[j][k]++;
               int q = (g[j][k] + i)%c;
               ac[j][q]++;
               bc[k][q]++;
               
              // cout << j << ' ' << k << ' ' <<  q << endl;
               ans.pb(trp(j,k,q));
               assert(ab[j][q] <= K);
               assert(ac[j][q] <= K);
               assert(bc[k][q] <= K);
           }
    cout << "Case #" << test << ": " << ans.size() << endl;
    sort(ans.begin(), ans.end());
    int d = ans.size();
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    assert(ans.size() == d);
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i].x+1 << ' ' << ans[i].y+1 << ' ' << ans[i].z + 1 << endl;
    
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve(i+1);
	return 0;
}