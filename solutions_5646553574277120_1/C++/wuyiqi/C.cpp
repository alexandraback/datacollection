#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int C, D, V;
int a[1000];
int main()
{
        freopen("C-large.in", "r", stdin);
        freopen("out.txt", "w", stdout);
        int t,ca=1;
        scanf("%d", &t);
        while(t--) {
                scanf("%d%d%d", &C,&D,&V);
                for(int i = 0; i < D; i++) {
                        scanf("%d", &a[i]);
                }
                std::sort(a, a + D);
                long long no = 0;
                int ret = 0;
                for(int i = 0; i < D; i++) {
                        while(no + 1 < a[i] && no < V) {
                                ret++;
                                no += (no + 1) * C;
                        }
                        if(no < V) {
                                no += 1LL * a[i] * C;
                        }
                }
                while(no < V) {
                        ret++;
                        no += (no + 1) * C;
                }
                printf("Case #%d: %d\n",ca++, ret);
        }
        return 0;
}
