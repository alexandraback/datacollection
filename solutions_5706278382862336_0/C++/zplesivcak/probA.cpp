#include <iostream>
using namespace std;

#define FORD(k,a,b) for(auto k=(a); k >= (b); --k)
#define FOR(k,a,b) for(auto k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
typedef long long LL;

LL gcd(LL a, LL b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

int T;
LL br,nz;
LL p2[41];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio (false);

    p2[40] = 1;
    FORD(i,39,0)
        p2[i]=p2[i+1]*2LL;

    cin >> T;
    FOR(cas,1,T) {
        char tmp;
        cin >> br >> tmp >> nz;

        LL gcd1 = gcd(br,nz);
        br /= gcd1;
        nz /= gcd1;

        if( p2[0]%nz == 0 ) {
            LL rd = (p2[0]/nz) * br;

            int id=0;
            for(; id<=40; ++id)
                if(rd >= p2[id]) break;
            
            
            if(id > 40)
                cout << "Case #" << cas << ": impossible" << endl;
            else
                cout << "Case #" << cas << ": " << id << endl;

        } else {
            cout << "Case #" << cas << ": impossible" << endl;
        }


    }


    return 0;
}
