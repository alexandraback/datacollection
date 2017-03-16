#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main () {
    int tc;

    cin >> tc;
    int co = 0;
    while ( tc-- ) {
        int rs = 0;
        string s;
        cin >> s;
        int len = (int)s.size();
        int n;
        cin >> n;
        for ( int i = 0; i < len; i++ ) {
            for ( int j = i + n; j <= len; j++  ) {
            int coun = 0;
            for ( int k = i; k < j; k++ ) {
                  if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                    coun = 0;
                  else
                    coun += 1;
                  if  ( coun >= n ) {
                    rs += 1;
                    break;
                  }
            }
            }
        }
         printf("Case #%d: %d\n", ++co, rs );
    }
}
