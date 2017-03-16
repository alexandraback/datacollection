#include<bits/stdc++.h>
using namespace std;
int i, j, k, l, x, y, z, m, n, t;
map < int, char > chk;
int main()
{
    freopen("A-small-attempt0.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int cs = 1;
    cin >> t;
    string s;

    while(t--){

        cin >> s;

        chk.clear();

        char c = s[0];
        chk[0] = c;

        int start = 0;
        int ending = 0;

        for(i = 1; i < s.size(); i++){
            if(s[i] >= c){
                start--;
                chk[start] = s[i];
                c = s[i];
            }
            else{
               ending++;
               chk[ending] = s[i];
            }
        }
        printf("Case #%d: ", cs++);
        for(i = start; i <= ending; i++){
            cout << chk[i] ;
        }
        cout << endl;


    }

    return 0;
}
