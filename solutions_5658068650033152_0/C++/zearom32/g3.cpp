#include <iostream>
#include <cstdio>
using namespace std;
int n,m,u;
void solve(){
    int i,j,k;
    int ans = u;
    for ( i = 1; i<= n-2; i++)
    {
        for (j = 1; j<= m-2; j++){
            if (i*j +2*j + 2*i >= u){
                k = 2*(i+j);
                if (ans > k) ans = k;
                break;
            }else
            {
                int w = i*j + 2*(i+j);
                k = 2*(i+j) + u-w;
                if(ans > k) ans = k;
            }
        }
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i<= t; i++){
        printf("Case #%d: ",i);
        cin >> n>> m>> u;
       solve(); 
    }
    return 0;
}
