#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <functional>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int main()
{
#ifdef MICRO_LOCAL
//	freopen("in.put", "r", stdin);
	clock_t timer_start = clock();
#endif
/*------------------------------------------------------------------------------------*/
    int T;
    scanf("%d",&T);
    for (int tc=1; tc<=T; tc++) {
        char a[4]="",b[4]="";
        scanf("%s %s", a, b);
        int len = strlen(a);
        if (len == 1) {
            a[2] = a[0];
            b[2] = b[0];
            a[0] = a[1] = b[0] = b[1] = '0';
        }
        else if (len == 2) {
            a[2] = a[1];
            a[1] = a[0];
            b[2] = b[1];
            b[1] = b[0];
            a[0] = b[0] = '0';
        }
        int diff=INT_MAX;
        char ans1[4]="", ans2[4]="";
        for (int i=0; i<1000; i++) {
            int a0=i/100, a1=(i/10)%10, a2=i%10;
            bool a0q=false, a1q=false, a2q=false;
            a0q = a[0]=='?' ? true : false;
            a1q = a[1]=='?' ? true : false;
            a2q = a[2]=='?' ? true : false;
            for (int j=0; j<1000; j++) {
                int b0=j/100, b1=(j/10)%10, b2=j%10;
                bool b0q=false, b1q=false, b2q=false;
                b0q = b[0]=='?' ? true : false;
                b1q = b[1]=='?' ? true : false;
                b2q = b[2]=='?' ? true : false;

                if (a0q) a[0] = a0+'0';
                if (a1q) a[1] = a1+'0';
                if (a2q) a[2] = a2+'0';
                if (b0q) b[0] = b0+'0';
                if (b1q) b[1] = b1+'0';
                if (b2q) b[2] = b2+'0';
                
                int t = abs(atoi(a) - atoi(b));
                if (t < diff) {
                    diff = t;
                    strcpy(ans1, a);
                    strcpy(ans2, b);
                }

                if (b0q) b[0] = '?';
                if (b1q) b[1] = '?';
                if (b2q) b[2] = '?';
            }
            if (a0q) a[0] = '?';
            if (a1q) a[1] = '?';
            if (a2q) a[2] = '?';
        }
        printf("Case #%d: %s %s\n", tc, ans1+3-len, ans2+3-len);
    }
/*------------------------------------------------------------------------------------*/
#ifdef MICRO_LOCAL
	printf("\nElapsed time : %.2lfms\n", ((double)clock() - (double)timer_start)/1000.0);
#endif
	return 0;
}
