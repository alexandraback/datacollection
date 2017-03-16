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
typedef pair<int, pii> piii;
 
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

int main()
{
	int T;
	scanf("%d", &T);
	
	FORUP(test, 1, T+1)
	{
		double esum[100005];
		double arr[100005];
		
		int A, B;
		scanf("%d%d", &A, &B);
		
		FORUP(i, 0, A)
			scanf("%lf", &arr[i]);
			
		esum[0] = arr[0];
		FORUP(i,1,A)
			esum[i] = esum[i-1] * arr[i];
		
		double ans = 0.0;
		int jb, js;
		
		//keep typing
		jb = B - A + 1;
		js = jb + B + 1;
		ans = (esum[A-1] * jb) + ((1.0-esum[A-1]) * js);
		
		//enter
		jb = 1 + B + 1;
		js = 1 + B + 1;
		ans = min(ans, (esum[A-1] * jb) + ((1.0-esum[A-1]) * js));
		
		//backspace
		FORUP(i, 1, A)
		{
			jb = (i*2) + (B-A+1);
			js = jb + B+1;
			
			int pos = A - 1 - i;
			ans = min(ans, (esum[pos] * jb) + ((1.0-esum[pos]) * js));
			
		}
		printf("Case #%d: %.6lf\n", test, ans);
	}
	
	return 0;
}
