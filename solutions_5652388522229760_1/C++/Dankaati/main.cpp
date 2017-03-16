#include <bits/stdc++.h>

using namespace std;

int y, n;
bool t[10];
bool jo() {
    bool jo=true;
    for(int i=0;i<10;i++) if(!t[i]) jo=false;
    return jo;
}
void feldolgoz(int a) {
    if(a==0) return;
    t[a%10]=true;
    feldolgoz(a/10);
}


int main()
{
    freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
cin >> y;
for(int x=1;x<=y;x++) {
    for(int i=0;i<10;i++) t[i]=false;
    cin >> n;
    int a=0;
    while(!jo() && a<=100000) {
        a++;
        feldolgoz(n*a);
    }
    cout << "Case #" << x << ": ";
    if(a>100000) {
        cout << "INSOMNIA";
    } else {
        cout << a*n;
    }
    cout << endl;
}
    return 0;
}
