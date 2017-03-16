#include <bits/stdc++.h>

using namespace std;

string s;
int y, ki;
char c;


int main()
{
freopen("2.in","r",stdin);
freopen("2.out","w",stdout);
cin >> y;
for(int x=1;x<=y;x++) {
    cout << "Case #" << x << ": ";
    c='+';
    ki=0;
    cin >> s;
    for(int i=s.size()-1;i>=0;i--) {
        if(c!=s[i]) {
            ki++;
            c=s[i];
        }
    }
    cout << ki << endl;
}
    return 0;
}
