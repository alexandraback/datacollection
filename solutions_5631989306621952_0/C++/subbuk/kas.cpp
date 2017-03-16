#include<bits/stdc++.h>

using namespace std;

string ans[1010];
int main()
{
freopen("input.txt","r",stdin);
freopen("op.txt","w",stdout);
    int t;
    cin >> t;
    int c=1;
    while(c<=t){
        string s;
        cin >> s;
        ans[1]=s[0];
        for(int i=1;i<s.size();++i)
        {
            string p=ans[i];
            string m=p;
            m=s[i]+ans[i];
            p=ans[i]+s[i];
            ans[i+1]=max(p,m);
        }
        cout << "Case #" << c << ": " << ans[(int)s.size()] << endl;
        c++;
    }
    return 0;
}
