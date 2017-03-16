#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <vector>
using namespace std;
inline bool isC(char ch)
{
    return (ch!='a' &&ch!='e' &&ch!='i' &&ch!='o' &&ch!='u');
}
void display()
{
    int Case;
    scanf("%d", &Case);
    for (int ca=1;ca<=Case;ca++) {
        printf("Case #%d: ", ca);
        string s;
        int n, l=0, r=0, ln=0;
        cin>>s>>n;
        //cout << s << endl;
        long long ans = 0;
        while (r<=(int)s.length()) {
            if (r < (int)s.length() && isC(s[r])) {
                if (!isC(s[l])) l=r;
            }
            else {
                if (r==(int)s.length() && !isC(s[l])) break;
                if (isC(s[l])) {
                    long long k = r-1-l+1;
                    if (k>=n) {
                        //cout << l << ' '<< r << ' ' << ln <<  endl;
                        //cout << "left: " << (k-n)*(l-ln) << endl;
                        //cout << "right: " << (k-n)*(s.length()-r) << endl;
                        //cout << "left: " << (l-ln) << endl;
                        //cout << "right: " << (s.length()-r) << endl;
                        //cout << "mid: " << (l-ln+1)*(s.length()-r+1) << endl;
                        //cout << "self: " << (k-n+2)*(k-n+1)/2-1 << endl;
                        ans += (k-n)*(l-ln) + (k-n)*(s.length()-r) + (l-ln+1)*(s.length()-r+1);
                        ans += (k-n+2)*(k-n+1)/2-1;
                        ln = r-n+1;
                    }
                }
                l=r;
            }
            r++;
        }
        cout << ans << endl;
    }
}
int main()
{
    freopen("A-large.in", "r", stdin);
    //freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    display();
    return 0;
}
