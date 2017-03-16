#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


int main() {
    freopen("D-large.in","r",stdin);
    freopen("output4.txt","w",stdout);
    int t,x,r,c;
    string str;
    scanf ("%i",&t);
    for (int i=0;i<t;i++) {
        cin >> x >> r >> c;
        if (x>6) cout << "Case #"<<i+1<<": " << "RICHARD" << endl; else {
            if (x==1)  cout << "Case #"<<i+1<<": " << "GABRIEL" << endl; else {
                if ((r%x!=0)&&(c%x!=0)) cout << "Case #"<<i+1<<": " << "RICHARD" << endl; else {
                    if (r%x!=0) std::swap(r,c);
                    if (x==6) {
                        if (c>=4) cout << "Case #"<<i+1<<": " << "GABRIEL" << endl; else
                            cout << "Case #"<<i+1<<": " << "RICHARD" << endl;
                    } else {
                        if (c>=x-1)cout << "Case #"<<i+1<<": " << "GABRIEL" << endl; else
                            cout << "Case #"<<i+1<<": " << "RICHARD" << endl;
                    }
                }
            }
        }
    }
    
    return 0;
}
