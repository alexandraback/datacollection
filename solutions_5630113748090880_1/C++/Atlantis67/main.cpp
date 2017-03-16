#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include <limits.h>
#include<cmath>
#include<map>
#include<queue>
#include<set>
using namespace std;

#define N 100005
#define M 100005
#define LL long long

//为自己加油O(∩_∩)O~

const long long  mod =1000000007;
int q[3000];
int main()
{
    int T;
    freopen("1.out","w",stdout);
    scanf("%d",&T);
    int t=T;
    while (T--){
        int n;
        scanf("%d",&n);
        memset(q,0,sizeof(q));
        vector<int> v;
        v.clear();
        for (int j=0;j<2*n-1;j++) {
            for (int k=0;k<n;k++){
                int g;
                scanf("%d",&g);
                q[g]++;
            }
        }
        printf("Case #%d:",t-T);
        for (int j=0;j<3000;j++) {
            if (q[j]%2==1)
            printf(" %d",j);
        }
        printf("\n");
    }
    return 0;
}








