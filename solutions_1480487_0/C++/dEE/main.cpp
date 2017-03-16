
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

#define DBG 0

int main() {
    int tc; scanf("%d", &tc);
    for(int t=1;t<=tc;t++) {
        int a[256];
        int N; scanf("%d", &N);
        int Num = N;
        int Sum = 0;
        for(int i=0;i<N;i++){ scanf("%d",&a[i]); Sum+=a[i]; }
        for(int i=0;i<N;i++) {
            double ans = 100.0*(2.0*Sum-N*a[i])/(N*Sum);
            if (ans < 0) { a[i]=-1; Num--; }
        }
        int Sum2 = 0;
        for(int i=0;i<N;i++) if(a[i]!=-1) Sum2+=a[i];
        
        printf("Case #%d: ", t);
        double ans;
        for(int i=0;i<N;i++) {
            if (a[i] == -1) ans = 0;
            else {
                if (Num == 0 || Sum == 0) ans = 100;
                else ans = 100.0*(Sum+Sum2-Num*a[i])/(Num*Sum);
            }
            printf("%.6f%c", ans, (i==N-1)?'\n':' ');
        }
    }
    return 0;
}
