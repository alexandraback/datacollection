#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <cmath>
#define INT64 long long 
using namespace std;

int ldp[10005], rdp[10005];
/*
    2 = i
    3 = j
    4 = k   
*/
int get_int(char c){
    if(c == 'i') return 2;
    if(c == 'j') return 3;
    if(c == 'k') return 4;
    return 1;
}

int compute(int a, int b){
    int c;
    int d = 1;
    if(a < 0){
        d *= -1;
        a *= -1;
    }
    if(b < 0){
        d *= -1;
        b *= -1;
    }
    
    if(a == 1) c = b;
    else if(b == 1) c = a;
    else if(a == b) c = -1;
    else if(a == 2 && b == 3) c = 4;
    else if(a == 2 && b == 4) c = -3;
    else if(a == 3 && b == 2) c = -4;
    else if(a == 3 && b == 4) c = 2;
    else if(a == 4 && b == 2) c = 3;
    else if(a == 4 && b == 3) c = -2;

    return (c * d);
}

int main(){
    int T;
    INT64 l, x;
    char s[10005];
    scanf("%d", &T);

    for (int _T = 1; _T <= T; ++_T)
    {   
        scanf("%lld %lld", &l, &x);
        scanf("%s", s);

        //dp
        ldp[0] = get_int(s[0]);
        rdp[0] = get_int(s[l - 1]);

        for (int i = 1; i < l; ++i)
        {
            ldp[i] = compute(ldp[i - 1], get_int(s[i]));
            rdp[i] = compute(get_int(s[l - 1 - i]), rdp[i - 1]);
        }

        //check all is -1
        int now = ldp[l - 1];
        for (int i = 1; i < (x%4) + 4; ++i)
            now = compute(now, ldp[l - 1]);
        if(now != -1){
            printf("Case #%d: NO\n", _T);
            continue;
        }


        INT64 i_index = -1, k_index = -1;

        //find i
        for (int i = 0; i < l; ++i){
            if(ldp[i] == 2){
                i_index = i;
                break;
            }
        }

        now = ldp[l - 1];
        if(i_index < 0)
            for (int i = 1; i < 5; ++i)
            {   
                if(x <= i || i_index >= 0)
                    break;

                for (int j = 0; j < l; ++j)
                {
                    if(compute(now, ldp[j]) == 2){
                        i_index = l * (INT64)i + j;
                        break;
                    }
                }
                now = compute(now, ldp[l - 1]);
            }

        //find k
        for (int i = 0; i < l; ++i){
            if(rdp[i] == 4){
                k_index = i;
                break;
            }
        }

        now = rdp[l - 1];
        if(k_index < 0)
            for (int i = 1; i < 5; ++i)
            {   
                if(x <= i || k_index >= 0)
                    break;

                for (int j = 0; j < l; ++j)
                {
                    if(compute(now, rdp[j]) == 4){
                        k_index = l * i + j;
                        break;
                    }
                }
                now = compute(now, rdp[l - 1]);
            }

        if(i_index + k_index + 2 < l * x && i_index >= 0 && k_index >= 0)
            printf("Case #%d: YES\n", _T);
        else
            printf("Case #%d: NO\n", _T);
    }


}