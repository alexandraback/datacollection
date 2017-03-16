#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int cases,cnt = 0;
    cin >> cases;
    while(cases--){
        cnt++;
        string s;
        int p = 0, m = 0, flips = 0;
        bool pint = false, mint = false;
        cin >> s;
        bitset<100> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '+') {
                    st[i] = 1;
                if(mint){
                    mint = false;
                }
                pint = true;
            }
            if(s[i] == '-') {
                    st[i] = 0;
                if(!mint){
                    if(pint){
                        flips++;
                        pint = false;
                    }
                    flips++;
                    mint = true;
                }
            }
        }
        cout << "Case #" << cnt << ": " << flips << endl;
    }
    return 0;
}
