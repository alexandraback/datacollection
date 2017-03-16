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

int
main(void)
{
    int T;
    int i, j, n;
    char tbl[256];
    char buf[1024];

    cin >> T;
    string s0("ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv");
    string s1("our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up");
    
    for(i=0;i<s0.size();i++) {
        tbl[s0[i]] = s1[i];
    }
    tbl['z'] = 'q';
    tbl['q'] = 'z';

    cin.getline(buf, sizeof(buf));
    for(i=1;i<=T;i++) {
        cin.getline(buf, sizeof(buf));
        for(j=0;j<1024;j++) {
            buf[j] = tbl[buf[j]];
        }
        // for(j=0;j<s.size();j++) {
        //     s[j] = tbl[s[j]];
        // }

        printf("Case #%d: %s\n", i, buf);
        // cout << "Case #" << i << ": " << s << endl;
    }
    
    return 0;
}
