//! \brief for small input, O(T*L*X) ~ 1e6

#include <vector>
#include <map>
#include <cstdio>
using namespace std;

//L [1, 1e4] L*X [1, 1e4]
#define MAX_SIZE 10001 
char s[MAX_SIZE];

//index/value: meaning 
//1: 1 (do not use 0 to keep sign)
//2: i
//3: j
//4: k
//sign should be absorbed
//
typedef enum {V1 = 1, VI,  VJ, VK} VTYPE;
static const int a[5][5] =
    {   {0, 0,  0,  0,  0},
        {0, V1, VI, VJ, VK},
        {0, VI, -V1,VK, -VJ},
        {0, VJ, -VK, -V1,VI},
        {0, VK, VJ, -VI, -V1}
    };
bool sol(char *s, int L, int X, map<char, VTYPE> &toV)
{
    int l, r;
    int product = V1;
    int n = L*X; 
    int sign = 1;
    for(l = 0; l < n; l++){
        char c = s[l%L];
        product = a[product][toV[c]];
        if(product < 0){
            product = -product;
            sign = -sign; 
        }
        if((sign == 1) && (product == VI)){
            break;
        }
    }
    if(l >  n - 3){
        return false;
    }
    //reset
    product = V1;
    sign = 1;
    for(r = n - 1; r >= 0; r--){
        char c = s[r%L];
        //sleepy bug fix in wrong sleepy position
        product = a[toV[c]][product];
        if(product < 0){
            product = -product;
            sign = -sign;
        }
        if((sign == 1) && (product == VK)){
            break;
        }
    }
    // r > l + 1
    product = V1;
    sign = 1;
    for(int i = l + 1; i < r; i ++){
        char c = s[i%L];
        product = a[product][toV[c]];
        if(product < 0){
            product = -product;
            sign = -sign;
        }
    }
    if((sign == 1) && (product == VJ)){
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
