#include <bits/stdc++.h>

using namespace std;

/*
From high case induction we found that center (size K) is equal to <next level pattern> of <center of original sequence>
Original sequence <G>[G]L: <GGG>[GGG]GGL
Original sequence <G>[G]G: <GGG>[GGG]GGG
Original sequence <G>[L]G: <GGG>[GLG]GGG
Original sequence <G>[L]L: <GGG>[GLL]GLL
Original sequence <L>[G]G: <LGG>[GGG]GGG
Original sequence <L>[G]L: <LGL>[GGG]LGL
Original sequence <L>[L]G: <LLG>[LLG]GGG    <LLG> LLG GGG LLG LLG GGG GGG GGG GGG
Original sequence <L>[L]L: <LLL>[LLL]LLL

Small case select center is always correct answer (S == K) because there is only one LL...LL in center
if (S>K) then only select center

and first (size K , 1->K) is equal to <next level pattern> of <first of original sequence>

Small case select first is always correct answer (S == K) because there is only one LL...LL in first
if (S>K) then only select first group (1->K)

if (S<K)

Position of center K=3,C=2 -> ceil(9/2) = 5 = ceil((K^2)/2)

LGGG
LGGL
LGLG
LGLL
LLGG
LLGL
LLLG
LLLL

LG
LG
LG
LG
LG
LG
LG
LG
LLGGG
LLGGL
LLGLG
LLGLL
LLLGG
LLLGL
LLLLG
LLLLL

*/


int main() {
    cout<<fixed; ios::sync_with_stdio(false);
    int t; cin>>t;
    for (int _t=1;_t<=t;_t++) {
        int k,c,s; cin>>k>>c>>s;
        cout<<"Case #"<<_t<<": ";
        if (s>=k) {
            s=k;
            for (int i=1;i<=k;i++) {
                cout<<i<<' ';
            }

        }
        cout<<endl;
    }

    return 0;
}

/*
Original sequence GGG: G[G]GGG[G]GGG
Original sequence GGL: G[G]GGG[G]GGL
Original sequence GLG: G[G]GGL[G]GGG
Original sequence GLL: G[G]GGL[L]GLL
Original sequence LGG: L[G]GGG[G]GGG
Original sequence LGL: L[G]LGG[G]LGL
Original sequence LLG: L[L]GLL[G]GGG
Original sequence LLL: L[L]LLL[L]LLL

if (select some column then all selected row don't have LL....LL (same L in some row)) choose and return selected row
*/
