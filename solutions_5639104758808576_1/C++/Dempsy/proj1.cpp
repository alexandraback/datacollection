#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    freopen("A-large.in","r",stdin);
    freopen("output","w",stdout);
    int t,n,tot,tmp,now;
    //char tmpc;
    string str;
    scanf ("%i",&t);
    for (int i=0;i<t;i++) {
        cin >>n>>str;
        tot=0;now=0;
        now=str[0]-'0';
        for (int j=1;j<=n;j++) {
            tmp=str[j]-'0';
            if (j>now) {
                tot+=j-now;
                now=j;
            }
            now=now+tmp;
        }
        cout << "Case #"<<i+1<<": " << tot << endl;
    }
    
    return 0;
}
