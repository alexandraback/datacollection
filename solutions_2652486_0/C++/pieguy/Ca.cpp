#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

bool good(int *v, int *a){
    set<int> s;
    for(int i=0; i<8; i++){
        int m=1;
        for(int j=0; j<3; j++)
            if((i>>j)&1)
                m*=a[j];
        s.insert(m);
    }
    for(int i=0; i<7; i++)
        if(!s.count(v[i]))
            return false;
    return true;
}

int main()
{
    int T, R, N, M, K;
    scanf("%d%d%d%d%d", &T, &R, &N, &M, &K);
    printf("Case #1:\n");
    while(R--){
        int v[12];
        for(int i=0; i<K; i++)
            scanf("%d", v+i);
        int a[3];
        int A[3];
        for(a[0]=2; a[0]<=5; a[0]++)
        for(a[1]=2; a[1]<=5; a[1]++)
        for(a[2]=2; a[2]<=5; a[2]++){
            if(good(v, a)){
                A[0]=a[0];
                A[1]=a[1];
                A[2]=a[2];
            }
        }
        printf("%d%d%d\n", A[0], A[1], A[2]);
    }
}
