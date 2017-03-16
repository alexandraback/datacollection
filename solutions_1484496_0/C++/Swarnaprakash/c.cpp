// Author: Swarnaprakash
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cassert>

using namespace std;

const int M = 105;
const int INF = 0x3f3f3f3f;
const bool debug=true;

#define SET(x,v)	memset(x,v,sizeof(x))
#define ALL(x) 		(x).begin() , (x).end()
#define SZ(x)		((int)((x).size()))
#define DB(x) 		if(debug) cout << #x << " : " << x <<endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

int mask[2000005];
int a[40];
int n;

void print(int m) {
    bool first = true;
    for(int j=0;j<n;++j) {
        if(m&1<<j) {
            if(!first)
                putchar(' ');
            first=false;
            printf("%d",a[j]);
        }
    }
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;++t) {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        SET(mask,-1);
        bool found = false;
        printf("Case #%d:\n",t);
        for(int i=1;i<(1<<n)-1 && !found;++i) {
            int csum = 0;
            for(int j=0;j<n;++j)
                if(i&1<<j)
                    csum += a[j];
            if(mask[csum] != -1 && mask[csum] != i) {
                found = true;
                print(mask[csum]);
                puts("");
                print(i);
                puts("");
            }
            mask[csum] = i;
        }
        if(!found) {
            puts("Impossible");
        }
    }
    return 0;
}

