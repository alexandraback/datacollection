#include <iostream>
#include <string>
#include <cassert>
using namespace std;

char mp[26] = {'y', 'h', 'e', 's', 'o', // abcde
               'c', 'v', 'x', 'd', 'u', // fghij
               'i', 'g', 'l', 'b', 'k', // klmno
               'r', 'z', 't', 'n', 'w',// pqrst
               'j', 'p', 'f', 'm', 'a',// uvwxy
               'q' };// z

int main() {
    int n;
    cin>>n;
    string s;

    cin.ignore();
    for(int tc=1; tc<=n; ++tc) {
        getline(cin, s);
        for(int i=0; i<s.length(); ++i)
            if(s[i] >= 'a' && s[i] <= 'z') s[i] = mp[s[i]-'a'];
        cout<<"Case #"<<tc<<": "<<s<<endl;
    }
}
