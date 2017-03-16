#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define FOR(i,s,e) for(int i=(s); i<(e); ++(i))
#define FORE(i,s,e) for(int i=(s); i<=(e); ++(i))
#define fs first
#define se second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
int gcd(int a,int b){if(b==0)return a; if(b>a) return gcd(b,a); return gcd(b,a%b);}

int N, M;
int data[128][128];
int maxVert[128];
int maxHori[128];

int solve()
{
    cin >> N >> M;
    FOR(i,0,N) FOR(j,0,M) cin >> data[i][j];
    FOR(i,0,N) maxHori[i] = -1;
    FOR(j,0,M) maxVert[j] = -1;

    FOR(j,0,M) FOR(i,0,N) {
        maxVert[j] = max(maxVert[j],data[i][j]);
        maxHori[i] = max(maxHori[i],data[i][j]);
    }

    bool result = true;
    FOR(i,0,N) FOR(j,0,M) {
        if( data[i][j] < maxVert[j] && data[i][j] < maxHori[i] ) {
            result = false;
            break;
        }
    }
    cout << ((result)?"YES":"NO") << endl;
	return 0;
}

int main()
{
	freopen("BL.in","r",stdin);
	freopen("BL.out","w",stdout);

	int test;
	scanf("%d",&test);
	for(int i = 0; i < test; ++i)
	{
	    printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
