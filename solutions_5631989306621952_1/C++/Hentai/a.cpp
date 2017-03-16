#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int T;
string S;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int casei = 1; casei <= T; ++casei){
        cin >> S;
        string ans = "";
        ans += S[0];
        for(int i = 1; i < S.length(); ++i){
            if(S[i] >= ans[0])
                ans = S[i] + ans;
            else
                ans += S[i];
        }
        cout << "Case #" << casei << ": " << ans << endl;
    }
    return 0;
}
