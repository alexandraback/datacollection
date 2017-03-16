#include <iostream>
#include <string>
using namespace std;

int shy[1010];
string str;

int main( ) {
    int t , n , num , res;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.txt","w",stdout);
    cin >> t;
    for ( int k = 1 ; k<=t ; ++k ) {
        cin >> n >> str;
        for ( int i = 0 ; i<=n ; ++i ) {
            shy[i] = str[i] - '0';
        }
        num = res = 0;
        for ( int i = 0 ; i<=n ; ++i ) {
            if ( shy[i]!=0 && num<i ) {
                res += i - num;
                num += i - num;
            }
            num += shy[i];
        }
        cout << "Case #" << k << ": " << res << endl;
    }
    fclose(stdout);
    return 0;
}

