#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define LL long long
#define U unsigned

string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[]={0,2,4,5,6,7,8,9,1,3};

int cnt[30];

void change(int v, int d) {
	FOR(i,0,words[v].size()) {
		cnt[words[v][i] - 'A']+=d;
	}
}

bool check(int num) {
	change(num,-1);
	FOR(i,0,26) {
		if (cnt[i] < 0)
		{
			change(num,1);
			return false;
		}
	}
	return true;
}
string res;
string s;

int main()
{
#ifdef Fcdkbear
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        double beg = clock();
#else
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
#endif

        int tests;
        scanf("%d",&tests);
        int N = 38;
        FOR(testNumber, 1, tests+1) {
        	printf("Case #%d: ",testNumber);
        	MEMS(cnt,0);
        	cin>>s;
        	FOR(i,0,s.size())
        		cnt[s[i]-'A']++;
        	res = "";
        	FOR(i,0,10)
        	{
        		while (check(order[i])) {
        			res += (order[i] + '0');
        		}
        	}
        	sort(res.begin(), res.end());
        	printf("%s\n",res.c_str());
        }

#ifdef Fcdkbear
        double end = clock();
        fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
        return 0;
}
