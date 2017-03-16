#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[3000];

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    cin >> T;
    int t = 1;
    for (int t = 1;t<=T;t++){
        int n;
        cin >> n;
        memset(a,0,sizeof(a));
        for (int i = 1;i<=2*n-1;i++){
            for (int j = 1;j<=n;j++){
                int w;
                scanf("%d",&w);
                a[w]++;
            }
        }
        printf("Case #%d:", t);
        for (int i = 1; i<=2500;i++){
            if (a[i] % 2 == 1)
                printf(" %d",i);
        }
        cout << endl;
    }
}