#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <iomanip>
#include <sstream>
#include <set>
#include <deque>
#include <climits>
#include <ctime>

using namespace std;
 
#define EPS 1e-11
#define PI acos(-1.0)

typedef pair<int,int> pii;
typedef pair<pii, int> piii;
 
#define DEBUG(n) cout << "->" << #n << " -> " << n << '\n'
#define FILL(arr,n) memset(arr,n,sizeof(arr))
#define FORUP(i,m,n) for(int i=(m),_n=(n); i<_n; i++)
#define FORDOWN(i,m,n) for(int i=(m)-1,_n=(n); i >= _n; i--)
#define FOREACH(iter,n) for(__typeof ((n).begin()) iter=(n).begin(); iter!=(n).end(); iter++)
#define ALL(n) (n).begin(),(n).end()
#define ALLSIZE(n,jum) (n),(n)+(jum)
#define FS first
#define SC second
#define MP make_pair
#define SQR(x) ((x)*(x))

//====== ilcapt ====

bool cmp(piii a, piii b)
{
	if (a.FS.FS != b.FS.FS) return a.FS.FS < b.FS.FS;
	if (a.FS.SC != b.FS.SC) return a.FS.SC < b.FS.SC;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	FORUP(test, 1, T+1)
	{
		int N;
		vector<piii> arr;
		
		scanf("%d", &N);
		FORUP(i,0,N)
		{
			piii tp;
			scanf("%d%d", &tp.FS.SC, &tp.FS.FS);
			tp.SC = 0;
			
			arr.push_back(tp);
		}
		
		int ans = 0;
		int pt = 0;
		while (arr.size() > 0)
		{
			sort(ALL(arr));
			
			int satu = -1, sd = -1, dua = -1;
			
			FORUP(i,0,arr.size())
			{
				if (arr[i].FS.FS <= pt) dua = i;
				else if ((arr[i].FS.SC <= pt) && (arr[i].SC == 0)) 
				{
					if (sd == -1) satu = i;
					else if (arr[i].FS.FS > sd)
						satu = i;
				}
			}

			if (dua != -1)
			{
				ans++;
				pt += (2-arr[dua].SC);
				arr.erase(arr.begin() + dua);
			}
			else if (satu != -1)
			{
				ans++;
				pt++;
				arr[satu].SC = 1;
				//arr.erase(arr.begin() + satu);
			}
			else break;
		}
		
		if (arr.size() > 0) printf("Case #%d: Too Bad\n", test);
		else printf("Case #%d: %d\n", test, ans);
		
	}
	
	return 0;
}
