#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

string s;
int tt;
int r;
char c;

int main(){
    cin>>tt;
    rep(ii,tt)
    {
        cin >> s; s+='+'; r=0; c=s[0];
        rep(i,s.size())
        {
            if(c == s[i])continue;
            else {
                c = s[i]; r++;
            }
        }
        cout << "Case #"<<ii+1<<": "<<r<<endl;
    }
}
