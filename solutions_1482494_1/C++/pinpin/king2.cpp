#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Data {
    int lvl;
    int st2;
    int stars;
    bool operator<(const Data& d) const {
        if (this->stars < d.stars)
            return true;
        if (this->stars > d.stars)
            return false;
        if (this->st2 > d.st2)
            return true;
        if (this->st2 < d.st2)
            return false;
        return (this->lvl < d.lvl);
    }
};

int
main(void)
{
    int T, N;
    int i, j;
    int A, B;
    int ret;
    int a, b;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N;
        vector<Data> vda(N), vdb(N);
        for(j=0;j<N;j++) {
            cin >> vda[j].stars >> vdb[j].stars;
            vda[j].st2 = vdb[j].stars;
            vda[j].lvl = j;
            vdb[j].lvl = j;
        }
        sort(vda.begin(), vda.end());
        sort(vdb.begin(), vdb.end());
        
        int msk_a[2000];
        int msk_b[2000];
        int st = 0;

        memset(msk_a, 0, sizeof(msk_a));
        memset(msk_b, 0, sizeof(msk_b));
        
        ret = 0;
        a = b = 0;
        while (true) {
            if ((vdb[b].stars <= st) && !(msk_a[vdb[b].lvl])) {
                st += 2;
                msk_b[vdb[b].lvl] = 1;
                msk_a[vdb[b].lvl] = 1;
                b++;
                ret++;
            } else if ((vdb[b].stars <= st)) {
                st += 1;
                msk_b[vdb[b].lvl] = 1;
                b++;
                ret++;
            } else if (a == N) {
                break;
            } else if (msk_a[vda[a].lvl]) {
                a++;
            } else if ((vda[a].stars > st)) {
                break;
            } else if ((vda[a].stars <= st)) {
                st += 1;
                msk_a[vda[a].lvl] = 1;
                a++;
                ret++;
            }
#if 0
             cout << "(a,b)=(" << a << "," << b << ")" << endl;
              printf("msk_a = %08x\n", msk_a);
              printf("msk_b = %08x\n", msk_b);
              printf("st = %d\n", st);
#endif
            if (b == N)
                break;
        }
        if (b == N) {
            printf("Case #%d: %d\n", i, ret);
        } else {
            printf("Case #%d: Too Bad\n", i);
        }        
    }
    
    return 0;
}
