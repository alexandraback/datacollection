#include <bits/stdc++.h>

using namespace std;

int t;
int kq, r, c, w;


int main(){
    #ifndef ONLINE_JUDGE
     freopen("A-large.in","r",stdin);
     freopen("output.out","w",stdout);
    #endif // ONLINE_JUDGE
   scanf("%d",&t);
    for(int iT = 1; iT <= t; iT++){
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: ",iT);
        kq = (c-1)/w+w+(c/w)*(r-1);
        cout << kq << "\n";
    }
    return 0;
}
