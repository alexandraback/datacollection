#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    string s = "";
    string r = "";

    cin >> t;
    rep(ii,t)
    {
        cin >> s;
        r = "";
        rep(i,s.size())
        {
            bool f = false;
            rep(j, r.size()){
                if(s[i] > r[j]){
                    f = true;
                    break;
                }
                else {
                    if(s[i] < r[j]){
                        break;
                    }
                }
            }

            if(f){
                r = s[i] + r;
            }
            else {
                r = r + s[i];
            }
        }
        cout << "Case #"<<ii+1<<": "<<r<<endl;
    }
}
