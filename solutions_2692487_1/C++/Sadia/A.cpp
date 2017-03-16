#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))
#define MAXN 1000006
int array[MAXN], ans[MAXN];
int main()
{
    //freopen("data.txt", "r", stdin);
    freopen("inputA.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);
    int t,T,A,N,i,c;
    scanf("%d", &T);
    for (t=1; t<=T; ++t)
    {
        scanf("%d %d", &A, &N);
        for (i=0; i<N; ++i) scanf("%d", &array[i]);
        if (A==1)
        {
            printf("Case #%d: %d\n",t,N);
            continue;
        }
        sort(array, array+N);
        c = 0;
        for (i=0; i<N; ++i)
        {
            while(A<=array[i])
            {
                A += A-1;
                ++c;
            }
            ans[i] = c;
            A += array[i];
        }
        A = MINI(N,c);
        for (i=N-1; i>=0; --i)
        {
            A = MINI(A, ans[i] + N-i-1);
        }
        printf("Case #%d: %d\n",t,A);
    }
    return 0;
}
