#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const char x[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b',
                    'k','r','z','t','n','w','j','p','f','m','a','q'};

int main() {
    freopen("myh.in","r",stdin); 
    freopen("myh.out","w",stdout);
    int n;
    string s;
    scanf("%d", &n);
    getline(cin, s);
    for (int k = 1; k <= n; ++k) {
        getline(cin, s);
        printf("Case #%d: ", k);
        for (int i = 0; i < s.size(); ++i)
         if (s[i] == ' ') printf(" ");
         else printf("%c", x[s[i]-'a']);
        cout << endl;
    }
    
    return 0;
}
