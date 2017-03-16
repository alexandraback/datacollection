#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <list>
#include <stack>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <functional>

#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef  long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;
typedef priority_queue<int> PQI;
const int Mod = 1e9 + 7;
inline LL FIX(LL a) {return (a % Mod + Mod) % Mod;}
#define MP(x,y) make_pair(x,y)
#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define take(x,y) (((x)>>(y)) & 1ll)
#define mv(n) (1<<(n))
#define what_is(x) cerr << #x << " is " << x << endl;
#define eb emplace_back
#define pb push_back
#define UNQ(x) (sort(begin(x),end(x)),x.erase(unique(begin(x),end(x)),end(x)))

void mul(int &sign,char &x,char y) {
    if(x == '0') {
        x = y;
        return;
    }else if(x == 'i') {
        switch(y){
                case 'i':
                x = '0';sign = -sign;break;
                case 'j':
                x = 'k';break;
                case 'k':
                x = 'j';sign = -sign;break;
                default:
                break;
        }
    }else if(x == 'j') {
        switch(y) {
            case 'i':
                x = 'k';sign = -sign;break;
            case 'j':
                x = '0';sign = -sign;break;
            case 'k':
                x = 'i';break;
            default:
                break;
        }
    }else if(x == 'k') {
        switch(y) {
            case 'i':
                x = 'j';break;
            case 'j':
                x = 'i';sign = -sign;break;
            case 'k':
                x = '0';sign = -sign;break;
            default:
                break;
        }
    }
    return;
}

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,cas = 0;
    cin>>T;
    while(T--) {
        int L,X;
        cin>>L>>X;
        string tmp;
        cin>>tmp;
        string s;
        for(int i = 0;i < X;i++) s += tmp;
        
        int sign = 1;
        char ret = '0';
        int pos = -1;
        for(int i = 0;i < s.length();i++) {
            mul(sign,ret,s[i]);
            if(ret == 'i' && sign == 1) {
                pos = i;
                break;
            }
        }
        if(pos == -1) {
            printf("Case #%d: NO\n",++cas);
            continue;
        }
        sign = 1;ret = '0';
        int pre = pos;pos = -1;
        for(int i = pre + 1;i < s.length();i++) {
            mul(sign,ret,s[i]);
            if(ret == 'j' && sign == 1) {
                pos = i;
                break;
            }
        }
        if(pos == -1) {
            printf("Case #%d: NO\n",++cas);
            continue;
        }
        sign = 1;ret = '0';
        pre = pos;pos = -1;
        for(int i = pre + 1;i < s.length();i++) {
            mul(sign,ret,s[i]);
        }
        if(ret == 'k' && sign == 1) {
            printf("Case #%d: YES\n",++cas);
        }else {
            printf("Case #%d: NO\n",++cas);
        }
    }
    return 0;
}















