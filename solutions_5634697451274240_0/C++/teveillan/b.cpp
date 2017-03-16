#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define MEM(arr, v) memset(arr, v, sizeof(arr))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

int main()
{
	freopen("Bin", "r", stdin);
    freopen("out", "w", stdout);
    int casnum;
    string str;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        cin >> str;
        int num = 0, flag = 0;
        int len = str.size();
        DWN(i, len-1, 0) {
            int x = (str[i]=='-'?0:1);
            if((x^flag) == 0) flag ^=1, ++num;
        }
        printf("Case #%d: %d\n", casid, num);

    }
    return 0;
}

