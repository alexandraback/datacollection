#include <cstdio>
#include <algorithm>

using namespace std;

int bst = 1000000005;

int sol(int cse)
{
    int n,a;
    int i,j,k;
    int arr[1005];
    scanf("%d %d",&a,&n);
    for(i=0;i<n;i++) scanf("%d",arr+i);
    sort(arr,arr+n);
    bst = n;
    for(i=0,j=0;i<n and a>1;i++) {
        while(a<=arr[i]) {
            a += a-1;
            j++;
        }
        a += arr[i];
        bst = min(bst,j+n-i-1);
    }
    printf("Case #%d: %d\n",cse,bst);
    return 0;
}
    
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}
