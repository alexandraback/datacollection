//! \brief for big input, O(T*3*4L) ~ 1e7

#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cassert>
using namespace std;

typedef long long ll;

// L [1, 1e4] X [1, 1e12] L*X [1, 1e16]
#define MAX_SIZE 10001 
char s[MAX_SIZE];

//index/value: meaning 
//1: 1 (do not use 0 to keep sign)
//2: i
//3: j
//4: k
//sign should be absorbed
//
typedef enum {V0 = 0, V1 = 1, VI,  VJ, VK} VTYPE;
static const int a[5][5] =
    {   {V0, V0,  V0,  V0,  V0},
        {V0, V1, VI, VJ, VK},
        {V0, VI, -V1,VK, -VJ},
        {V0, VJ, -VK, -V1,VI},
        {V0, VK, VJ, -VI, -V1}
    };
// newSign * newV = sign * v1 * v2
// update the sign to newSign and return newV 
VTYPE mul(VTYPE v1, VTYPE v2, int &sign)
{
    int v = a[v1][v2];
    if(v < 0){
        v = -v;
        sign = -sign;
    }
    return (VTYPE)v;
}
int mulWithSign(int v1, int v2){
    int sign = 1;
    if(v1 < 0){
        v1 = -v1;
        sign = -sign;
    }
    if(v2 < 0){
        v2 = -v2;
        sign = -sign;
    }
    VTYPE v = mul((VTYPE)v1, (VTYPE)v2, sign);
    return sign*v;
}

//! \brief search in [0, min(T - 1, n - 1)]
//! \return position if reach the target 
ll mulRightFind(char *s, int L, ll X, map<char, VTYPE> &toV, VTYPE target)
{
    //n <= TL <= 4*L <= 4e4, int
    const int TL = 4*L;
    int n = min((ll)TL, (ll)L*X);
    VTYPE product = V1;
    int sign = 1;
    for(int l = 0; l < n; l++){
        VTYPE t = toV[s[l%L]];
        product = mul(product, t, sign);
        if((sign == 1) && (product == target)){
            return l;
        }
    }
    return -1;
}
ll mulLeftFind(char *s, int L, ll X, map<char, VTYPE> &toV, VTYPE target)
{
    ll n = (ll)L*X;
    const int TL = 4*L;
    ll minPos = max(0LL, n - TL);
    VTYPE product = V1;
    int sign = 1;
    for(ll r = n - 1; r >= minPos; r--){
        VTYPE t = toV[s[r%L]];
        product = mul(t, product, sign);
        if((sign == 1) && (product == target)){
            return r;
        }
    }
    return -1;
}

//if not in range , return VI
//othwise return s[start]*s[start+1]*...s[last]
int mulRangeRight(char *s, int L, map<char, VTYPE> &toV, ll start, ll last)
{
    assert(last >= start);
    int product = V1;
    const int TL = 4*L;
    start %= TL;
    last %= TL; 
    if(last < start){
        last += TL;
    }
    for(int i = start; i <= last; i ++){
        VTYPE t = toV[s[i%L]];
        product = mulWithSign(product, t);
    }
    return product; 
}

bool sol(char *s, int L, ll X, map<char, VTYPE> &toV)
{
    ll l, r;
    ll n = L*X; 
    l = mulRightFind(s, L, X, toV, toV['i']);
    if((l < 0) || (l > n - 3)){
        return false;
    }
    //reset
    r = mulLeftFind(s, L, X, toV, toV['k']);
    if(r <= l + 1){
        return false;
    }
    if(mulRangeRight(s, L, toV, l + 1, r - 1) == VJ){
        return true;
    }else{
        //V1 or others
        return false;
    }
}
int main(int argc, char **argv)
{
    // Initialization character mapping
    map<char, VTYPE> toV;
    toV['1'] = V1;
    toV['i'] = VI;
    toV['j'] = VJ;
    toV['k'] = VK;

    // [1, 100]
    int T, L, X;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d%d", &L, &X);
        scanf("%s", s);
        if(sol(s, L, X, toV)){
            printf("Case #%d: YES\n", t);
        }else{
            printf("Case #%d: NO\n", t);
        }
    }
    return 0;
}
