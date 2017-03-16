#include <iostream>
#include <cstdio>
using namespace std;
int x,r,c;
int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    int T,tc(1);
    cin >> T;
    while(T--){
        cin >> x >> r >> c;
        bool ans(1);
        if (x>=7) ans = false;
        else if(x>r && x>c) ans = false;
        else if((r*c)%x!=0) ans = false;
        else if((x+1)/2>min(r,c)) ans = false;
        else if(x==1 || x==2 || x==3) ans = true;
        else if(x==4) ans = (min(r,c)>2);
        else if(x==5)ans = !(min(r,c)==3 && max(r,c)==5);
        else if(x==6) ans = (min(r,c)>3);
        cout << "Case #" << tc++ << ": ";
        if(ans) cout << "GABRIEL" << endl;
        else cout << "RICHARD" << endl;
    }
    return 0;
}
