#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>

using namespace std;

bool check(char ch) {
    return ch == 'a' || ch == 'e' || ch=='i' ||ch=='o' || ch =='u';
}

int main() {
    int C;
    cin >> C;
    for(int cases = 1; cases <= C; ++cases) {
        string S;
        int N;
        cin >> S >> N;
        int len = S.length();
        int ans = 0;
        
        for(int i =0; i < len; ++i) {
            for(int j = i; j <len; ++j) {
                int p = 0;
                for(int k=i; k <=j; ++k) {
                    if(check(S[k])) {
                        p = 0;
                    } else ++p;
                    
                    if(p >= N) {
                        ++ ans;
                        break;
                    }
                }
            }
         }

        printf("Case #%d: %d\n", cases, ans); 
    }
    return 0;
}

