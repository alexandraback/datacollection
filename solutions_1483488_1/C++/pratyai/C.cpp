#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

map<string,long long>eqv;

int main()
{
    freopen("C-large.in", "rt", stdin);
    freopen("C-large.out", "wt", stdout);
    int T;
    cin>>T;
    for (int cas=1; cas<=T; ++cas)
    {
        eqv.clear();
        stringstream fao;
        int A, B;
        cin>>A>>B;
        for (int i=A; i<=B; ++i) fao<<i<<' ';
        for (int i=A; i<=B; ++i)
        {
            string tmp;
            fao>>tmp;
            int tz = tmp.length();
            int p = 0;
            for (int j=1; j<tz; ++j)
            {
                int k;
                for (k=0; k<tz && tmp[(p+k)%tz]==tmp[(j+k)%tz]; ++k);
                if (k<tz && tmp[(p+k)%tz]>tmp[(j+k)%tz]) p = j;
            }
            if (p) tmp = tmp.substr(p)+tmp.substr(0,p);
            ++eqv[tmp];
        }
        long long cnt = 0;
        for (map<string,long long>::iterator i=eqv.begin(); i!=eqv.end(); ++i)
        {
            long long& u = i->second;
            cnt += (u*(u-1))>>1;
        }
        printf("Case #%d: %lld\n", cas, cnt);
    }
    return 0;
}
