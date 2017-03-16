#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    for (int ttt=1;ttt<=t;ttt++) {
        int x, r, c;
        cin >> x>>r>>c;
        //cout << "Case #" << ttt<< ": "<<x<<" " << r<<" "<<c<<": ";
        cout << "Case #" << ttt<< ": ";

        if (x<=2) {
            if (r*c%x!=0) {
                cout << "RICHARD"<<endl;
            }
            else {
                cout << "GABRIEL"<<endl;
            }
        }
        if (x==3) {
            if (r*c%x!=0 || min(r, c)<1+(x-1)/2 || max(r, c)<x) {
                cout << "RICHARD"<<endl;
            }
            else {
                cout << "GABRIEL"<<endl;
            }
        }
        if (x==4) {
            if (r*c%x!=0 || min(r, c)<1+(x-1)/2|| max(r, c)<x) {
                cout << "RICHARD"<<endl;
            }
            else {
                if ((r==2 && c==4) || (c==2 && r==4)) {
                    cout << "RICHARD"<<endl;
                }
                else {
                    cout << "GABRIEL"<<endl;
                }
            }
        }
    }
    return 0;
}
