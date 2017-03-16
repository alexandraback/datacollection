/*

*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
using namespace std;
int a, b, p[10], k, N;
set<int> h;
void display()
{
    int T;
    //scanf("%d",&T);
    //for (int t=1;t<=T;t++) {
        //printf("Case #%d: ", t);
    //}
    scanf("%d",&T);
    for (int t=1;t<=T;t++) {
        printf("Case #%d: ", t);
        scanf("%d%d",&a, &b);
        int ans =0;
        for (int i=a;i<=b;i++) {
            k = (int)log10(i)+1;
            int BASE =1;
            for (int ii=1;ii<k;ii++) BASE *= 10; 
            N = i;
            for (int x=k-1;x>=0;x--) {
                p[x] = N%10;
                N /=10;
            }
            int mn=i;
            h.clear();
            for (int j=0;j<k;j++) {
                N = 0;
                for (int base=BASE, q=j, tim=0;tim<k;tim++, q=(q+1)%k, base/=10) {
                    N+=p[q]*base;
                } 
                if (a<=N && N<=b) {
                    h.insert(N);
                    mn = min(mn, N);
                }
            }
            if (mn == i) {
                for (int j=h.size()-1;j>=0;j--) 
                    ans+=j;
            }
        }
        printf("%d\n", ans);
    }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    display();
    return 0;
}
