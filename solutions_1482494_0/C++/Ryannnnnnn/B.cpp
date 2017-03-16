#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define INF (~0U>>2)
#define eps (1e-6)
#define SZ(x) (int)((x).size())
#define foreach(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)

typedef long long LL;

int n,A[1000],B[1000],done[1000];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    
    int test; scanf("%d", &test);
    for (int caseN=1;caseN<=test;caseN++){
        printf("Case #%d: ",caseN);
        scanf("%d",&n);
        for (int i=0;i<n;i++){
            scanf("%d %d",&A[i],&B[i]);
            done[i]=0;
        }
        int ans=0,star=0;
        while (1){
            int move=0;
            for (int i=0;i<n;i++)
                if (done[i]==0 && star>=B[i]){
                    ans++;
                    star+=2;
                    move=1;
                    done[i]=2;
                    break;
                }
            if (move==1) continue;
            for (int i=0;i<n;i++)
                if (done[i]==1 && star>=B[i]){
                    ans++;
                    star+=1;
                    move=1;
                    done[i]=2;
                    break;
                }
            if (move==1) continue;
            int k=-1;
            for (int i=0;i<n;i++)
                if (done[i]==0 && star>=A[i]){
                    if (k==-1 || B[i]>B[k]){
                        k=i;
                    }
                }
            if (k!=-1){
                ans++;
                star+=1;
                move=1;
                done[k]=1;
            }
            if (move==1) continue;
            break;
        }
        if (star<2*n) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
    return 0;
}

