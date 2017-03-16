#include<fstream>
#include<iomanip>
using namespace std;

ifstream cin("A-small-attempt2.in");
ofstream cout("A-small-attempt2.out");

int main() {
    int T, c, a, b, i, j;
    int d;
    double expect, min, p[100001], tmp, x;
    cin>>T;
    for (c=1; c<=T; ++c) {
        cin>>a>>b;
        for (i=0;i<a;++i) cin>>p[i];
        // enter
        tmp = 1;
        for (i=0; i<a; ++i) tmp *= p[i];
        if (a==b) expect = tmp+(1-tmp)*(b+2); else expect = b+2;

        min = expect;

        d= -1;

        // delete 0-a chars
        for (i=0;i<=a;++i) { //delete i's chars
            tmp = 1;
            for (j=0;j<a-i;++j) {
                tmp*=p[j]; // before, all right
            }
            expect = tmp*(i+i+b-a+1);

            // something wrong before
            expect += (1-tmp)*(i+i+b-a+1+b+1);

            if (expect < min) {
                min = expect;
                d=i;
            }
        }

        cout<<"Case #"<<c<<": "<< fixed << setprecision(6) << min <<endl;

    }
    return 0;
}
