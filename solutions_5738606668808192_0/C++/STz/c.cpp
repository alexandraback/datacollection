#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define N 111111
#define M 222222
#define md 1000000007
#define ll long long

char r[50];
void f(int m, int n){
    r[0] = '1', r[n-1] = '1', r[n] = 0;
    for(int i=2;i<n;i+=2) r[i-1] = r[i] = '0' + ((m&(1<<(i/2-1))) ? 1 : 0);
}
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int s=1;s<=t;s++){
        printf("Case #%d:\n",s);
        int n, j;
        scanf("%d%d",&n,&j);
        // n % 2 == 0, easy:
        for(int i=0;i<j;i++) f(i, n), printf("%s 3 4 5 6 7 8 9 10 11\n", r);
    }
}