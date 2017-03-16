#include<iostream>
#include<cstdio>
using namespace std;
int a[5][5], b[5][5];
int main() {
    freopen("C:\\Users\\Guiping\\Downloads\\in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;  cin>>T;
    for(int cas=1; cas<=T; ++cas){
        double c, f, x; cin>>c>>f>>x;
        double dx = 2.0, ans = x/dx, s = 0;
        while(true) {
            s += c/dx;
            if(x/(dx+f)+s>ans) break;
            ans = x/(dx+f)+s;
            dx += f;
        }
        printf("Case #%d: %.7lf\n", cas, ans);
    }
    return 0;
}





