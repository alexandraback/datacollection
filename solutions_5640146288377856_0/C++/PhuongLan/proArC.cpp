#include <bits/stdc++.h>

using namespace std;

int t;
int kq, r, c, w;


int main(){
    #ifndef ONLINE_JUDGE
     freopen("A-small-attempt0.in","r",stdin);
     freopen("output.out","w",stdout);
    #endif // ONLINE_JUDGE
   scanf("%d",&t);
    for(int iT = 1; iT <= t; iT++){
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: ",iT);
        kq = ((c-1)/w+w)*r;
        cout << kq << "\n";
    }
    return 0;
}
