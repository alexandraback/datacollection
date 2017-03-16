#include<bits/stdc++.h>
#define cin file
#define cout file2

using namespace std;

main() {

    ifstream file("D-large.in");
    ofstream file2("D-large.out");

    int test;
    cin>>test;
    for (int t=1; t<=test; t++) {

        int x, r, c;
        cin>>x>>r>>c;

        if ((r*c)%x!=0) goto last;
        if (x>=7) goto last;
        if (r<x && c<x) goto last;
        if (x==3) {
            if (r==1 || c==1) goto last;
        }
        if (x==4) {
            if (r<=2 || c<=2) goto last;
        }
        if (x==5) {
            if (r<=2 || c<=2) goto last;
            if (r==3 || c==3) {
                if (r==5 || c==5) goto last;
            }
        }
        if (x==6) {
            if (r<=3 || c<=3) goto last;
            if (r==4 || c==4) {
                if (r==6 || c==6) goto last;
            }
        }

        cout<<"Case #"<<t<<": GABRIEL"<<endl;
        goto last2;
        last:;
        cout<<"Case #"<<t<<": RICHARD"<<endl;
        last2:;
    }
}
