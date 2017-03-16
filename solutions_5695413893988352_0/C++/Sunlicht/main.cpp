#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

int po(int n){
    int res = 1;
    for(int i = 0; i < n; i++){
        res *= 10;
    }
    return res;
}

int makeint(string s){
    int res = 0;
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == '?') s[i] = '0';
        res += (s[i] - '0') * po(s.size()-(i+1));
    }
    return res;
}

bool possible(string C, int i){
    for(int j = C.size()-1; j >= 0; j--){
        if(C[j] == '?') {
                i /= 10;
                continue;
        }
        if((int)(C[j] - '0') != i % 10) return false;
        i /= 10;
    }
    return true;
}

int len(int k){
    if(k >= 100) return 3;
    if(k >= 10) return 2;
    if(k >= 0) return 1;
}

int main()
{
    freopen("hey.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T, cnt = 0;
    scanf("%d",&T);
    while(T--){
        cnt++;
        string C, J;
        cin >> C >> J;
        int bestdiff = 1000, besti =0, bestj=0;
        int si = C.size();
        for(int i = 0; i < po(si); i++){
            for(int j = 0; j < po(si); j++){
                if(possible(C,i) && possible(J,j)){
                    int diff = abs(i - j);
                    if(diff < bestdiff){
                        bestdiff = diff;
                        besti = i;
                        bestj = j;
                    }
                }
            }
        }
        cout << "Case #" << cnt << ": ";
        for(int i = 0; i < si-len(besti); i++){
            cout << '0';
        }
        cout << besti;
        cout << " ";
        for(int i = 0; i < si-len(bestj); i++){
            cout << '0';
        }
        cout << bestj;
        cout << endl;
    }
    return 0;
}
