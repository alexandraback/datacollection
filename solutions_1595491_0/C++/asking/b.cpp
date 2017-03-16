#include <iostream>
#include <stdio.h>
#include <cstring> //for strlen, memcpy and memset.
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i(a), _n(b); i<=_n; i++)
#define FORD(i,a,b) for(int i(a), _n(b); i>=_n; i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define PR(c,x) ((c).find(x) != (c).end()) 
#define CP(c,x) (find(all(c),x) != (c).end()) 
#define SZ(a) int((a).size())a
#define X first
#define Y second
#define pb push_back
#define MEMST(a,i) memset(a,i,sizeof(a))
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> PII; 
//#define ONLINE_JUDGE

const int MXN = 100 + 10;

int arr[MXN];
int vmin, vmax;

void calcRange(int p)
{
	vmin = 0, vmax = -1;
	if(p >= 2)
	{
		vmax = 3 * (p-1);
		vmin = vmax - 1;
	}
	else if(p == 1)
	{
		vmax = 0;
		vmin = 1;
	}
}

int main()
{
    
    #ifndef ONLINE_JUDGE 
    freopen("B-small-attempt0.in","r",stdin); 
    freopen("b_small_out.txt","w",stdout); 
    #endif

    int case_n;
    int n, s, p, tmp;
    
    scanf("%d ", &case_n);
    FOR(case_i, 1, case_n)
    {
		int cnt = 0, tentative = 0;
		
		scanf("%d %d %d", &n, &s, &p);
		calcRange(p);
		FOR(i, 1, n)
		{
			scanf("%d", &tmp);
			if(tmp > vmax)
			{
				cnt ++;
			}
			else if(tmp >= vmin && tmp <= vmax)
			{
				tentative ++;
			}
		}
		
		cnt += min(tentative, s);
		
        printf("Case #%d: %d\n", case_i, cnt);
    }

    #ifndef ONLINE_JUDGE 
    fclose(stdin); 
    fclose(stdout); 
    #endif
    
    return 0;
}
