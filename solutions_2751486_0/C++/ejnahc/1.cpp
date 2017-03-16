#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int Test, Cases = 1; scanf("%d", &Test); while(Test--) {
        printf("Case #%d: ", Cases++);

        string L;
        int n;

        cin >> L >> n;
        int l = L.size();

        int cnt = 0;
        for (int i=0; i<=l; ++i) {
            for (int j=0; j<=l-i; ++j) {
                string sub = L.substr(i, j);
                if (sub.size() < 1) continue;
                
                int con = 0;
                for (int k=0; k<sub.size(); ++k) {
                    if (sub[k] != 'a' && sub[k] != 'e' && sub[k] != 'i'
                        && sub[k] != 'o' && sub[k] != 'u')
                        con++;
                    else
                        con = 0;

                    if (con >= n) {
                        cnt++;
                        con = 0;
                        break;
                    }
                }
            }
        }

        cout << cnt << endl;
    }
}