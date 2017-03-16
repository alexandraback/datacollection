#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int tc,n,m,p,a;

int main() {
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        scanf("%d%d%d",&n,&m,&p);
        int c1=0,c2=0;
        for (int i=0; i<n; i++) {
            scanf("%d",&a);
            if (a >= p*3-2) c1++;
            if (a >= p*3-4 && a >= p) c2++;
        }
        //printf("%d %d\n",c1,c2);
        printf("Case #%d: %d\n",t,c1+min(c2-c1,m));
    }
}
