#include <bits/stdc++.h>

const int MAX_L = 5e5 + 5;


enum { ONE, I, J, K, mONE, mI, mJ, mK};

const int mul[][8] = {{ONE,      I,    J,    K, mONE,   mI,   mJ,   mK},
                      {I,     mONE,    K,   mJ,   mI,  ONE,   mK,    J},
                      {J,       mK, mONE,    I,   mJ,    K,  ONE,   mI}, 
                      {K,        J,   mI, mONE,   mK,   mJ,    I,  ONE}, 
                      {mONE,    mI,   mJ,   mK,  ONE,    I,    J,    K}, 
                      {mI,     ONE,   mK,    J,    I, mONE,    K,   mJ}, 
                      {mJ,       K,  ONE,   mI,    J,   mK, mONE,    I},
                      {mK,      mJ,    I,  ONE,    K,    J,   mI, mONE}};

int s[MAX_L];
int v_r2l[MAX_L];

int get_val ( char c ) {
    if ( c == 'i' ) {
        return I;
    }
    if ( c == 'j' ) {
        return J;
    }
    return K;
}


int main ( void ) {

    bool seen_I;
    long long x;
    std::string s0;
    int tc, l0, t, l, v, i;


    std::cin >> t;

    for ( tc = 1 ; tc <= t ; ++ tc ) {
        std::cout << "Case #" << tc << ": ";
        std::cin >> l0 >> x >> s0;
        x = std::min(x, 16L + (x & 3L));
    
        l = l0 * x;
        for ( i = 0 ; i < l0 ; ++ i ) {
            s[i] = get_val(s0[i]);
        }

        v = ONE;
        for ( i = l - 1 ; i >= 0 ; -- i ) {
            v = mul[s[i%l0]][v];
            v_r2l[i] = v;
        }

        v = ONE;
        seen_I = false;
        for ( i = 0 ; i < l ; ++ i ){
            seen_I |= (v == I);
            if ( v_r2l[i] == K && v == K && seen_I ) {
                std::cout << "YES\n";
                goto next_case;
            }
            v = mul[v][s[i%l0]];
        }
        
        std::cout << "NO\n";
        next_case:;
    }

    return 0;
}
