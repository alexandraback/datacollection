#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, cases = 1;
    string s;
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    scanf("%d", &t);
    while(t--){
        cin>>s;
        string t;
        for(int i=0;i<s.size();i++){
            if(i==0)t+=s[0];
            else {
                if(t[0]>s[i])t = t+s[i];
                else t = s[i] + t;
            }
        }
        printf("Case #%d: ", cases++);
        cout<<t<<"\n";
    }
    return 0;
}
