#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;
    for (int loop = 1; loop<=T; ++loop) {
        printf("Case #%d: ",loop);
        string S;
        cin>>S;
        int N = S.length();
        int ptr = N-1,ans = 0;
        while (ptr>=0) {
            while (S[ptr]=='-') {
                for (int i = 0; i<=ptr; ++i)
                    S[i] = S[i]=='+'?'-':'+';
                ++ans;
            }
            --ptr;
        }
        printf("%d\n",ans);
    }
    return 0;
}