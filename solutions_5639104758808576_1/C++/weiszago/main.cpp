#include <iostream>
#include <cstdio>
using namespace std;

int t;
int n;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    for (int j=1;j<=t;j++) {
        cin >> n;
        int m=0;
        int kum=0;
        for (int i=0;i<=n;i++) {
            char c;
            int x;
            cin >> c;
            x=c-'0';
            m=max(m, i-kum);
            kum+=x;
        }
        cout << "Case #" << j<< ": " << m<<endl;
    }
    return 0;
}
