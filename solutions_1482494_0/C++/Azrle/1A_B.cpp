#include<fstream>
using namespace std;

ifstream cin("B-small-attempt0.in");
ofstream cout("B-small-attempt0.out");

int main() {
    int t, c;
    int n, i,j, a[1000],b[1000], level[1000];
    int star, ln, step;
    bool change;

    cin>>t;
    for (c=1; c<=t; ++c) {
        cin>>n;
        for (i=0;i<n;++i) {
            cin>>a[i]>>b[i];
            level[i] = 0;
        }
        ln=n;
        change = true;
        star = 0;
        step = 0;
        while (ln>0 && change) {
            change = false;
            for (i=0; i<n; ++i) {
                if (level[i] != 2 && b[i]<=star) {
                    star+=(2-level[i]);
                    level[i] = 2;
                    change = true;
                    ln--;
                    ++step;
                }
            }
            if (change) continue;
            for (i=0; i<n; ++i) {
                if (level[i] == 0 && a[i]<=star) {
                    star++;
                    level[i] = 1;
                    change = true;
                    ++step;
                    break;
                }
            }
        }
        cout<<"Case #"<<c<<": ";
        if (ln>0) cout<<"Too Bad"; else cout<<step;
        cout<<endl;
    }
    return 0;
}
