#include <iostream>

using namespace std;

int T;

long long d1,d2;
long long m1,m2;
int n;

int main()
{
    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> n;

        int nn = 1;
        int x;
        cin >> d1 >> x >> m1;

        if(x==2) {
            nn=2;
            d2 = d1;
            m2 = m1+1;
        }
        if(n==2) {
            cin >> d2 >> x >> m2;
            nn=2;
        }

        cout << "Case #" << t << ": ";
        if(nn==1) {
            cout << 0;
        } else if(((m1*(720-d1)) <= (m2*(360-d2))) || ((m1*(360-d1)) >= (m2*(7200-d2)))) {
            cout << 1;
        } else cout << 0;

        cout << endl;
    }

    return 0;
}
