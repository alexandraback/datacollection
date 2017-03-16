#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
string s;
int L,T;
long long N;
int a[4][4] = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

int main() {
    freopen("input.in","r",stdin);
    freopen("outputD","w",stdout);
 
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
           printf("Case #%d: ",t);
        scanf("%d%lld",&L,&N);
        cin>>s;
        int curr = 1, one = 1;
        for(int i=0;i<s.size();++i) {
            int t1 = one;
            int t2 = s[i] - 'g';
            int sgn = 1;
            if(t1 < 0) {
                sgn *= -1;
                t1 *= -1;
            }
            if(t2 < 0) {
                sgn *= -1;
                t2 *= -1;
            }
            one = sgn * a[t1-1][t2-1];
        }
        bool fi = false, fj = false;
        for(int rep=1;rep<=min(8LL,N);++rep) {
            for(int i=0;i<s.size();++i) {
                int t1 = curr;
                int t2 = s[i] - 'g';
                int sgn = 1;
                if(t1 < 0) {
                    sgn *= -1;
                    t1 *= -1;
                }
                if(t2 < 0) {
                    sgn *= -1;
                    t2 *= -1;
                }
                curr = sgn * a[t1-1][t2-1];
                if(!fi) {
                    if(curr == 2) {
                        fi = true;
                        curr = 1;
                    }
                } else {
                    if(curr == 3) {
                        fj = true;
                    }
                }
            }
            if(fj) break;
        }
        if(!fj) {
            printf("NO\n");
        } else {
            if(one == 1) {
                printf("NO\n");
            } else if(one == -1) {
                if(N%2 == 1) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            } else {  
                if(N%4 == 2) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}
