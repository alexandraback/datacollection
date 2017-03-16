#include <cstdio>

int v(char c) {
    switch(c) {
        case 'i': return 2;
        case 'j': return 3;
        case 'k': return 4;
    }
    return 0;
}

int tab[5][5];

void fill_tab() {
    tab[1][1] = 1;
    tab[1][2] = 2;
    tab[1][3] = 3;
    tab[1][4] = 4;
    
    tab[2][1] = 2;
    tab[2][2] = -1;
    tab[2][3] = 4;
    tab[2][4] = -3;
    
    tab[3][1] = 3;
    tab[3][2] = -4;
    tab[3][3] = -1;
    tab[3][4] = 2;
    
    tab[4][1] = 4;
    tab[4][2] = 3;
    tab[4][3] = -2;
    tab[4][4] = -1;
}

int mul(int a, int b) {
    int sign = 1;
    
    if (a < 0) {
        sign *= -1;
        a *= -1;
    }
    
    if (b < 0) {
        sign *= -1;
        b *= -1;
    }
    
    return sign * tab[a][b];
}

int expo(int b, long long e) {
    int mod = (int) (e % 4);
    int ret = 1;
    for (int i = 0; i < mod; i++) {
        ret = mul(ret, b);
    }
    return ret;
}

char str[10010];

int main() {
    int t, l, trials, curr;
    long long x;
    
    bool possible;
    
    fill_tab();
    
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        scanf("%d %lld", &l, &x);
        scanf("%s", str);
        
        possible = false;
        
        trials = 0;
        int search = v('i');
        curr = 1;
        int block = 1;
        
        for (int j = 0; j < l; j++) {
            block = mul(block, v(str[j]) );   
        }
        
        //printf("block: %d\n", block);
        
        for (int j = 0; j < x && trials < 6; j++, trials++) {
            for (int k = 0; k < l && search < 4; k++) {
                curr = mul(curr, v(str[k]) );
                
                if (curr == search) {
                    curr = 1;
                    search++;
                    trials = 0;
                }
            }
        }
        
        if (search == 4 && expo(block, x) == -1) {
            possible = true;  
        };
        
        printf("Case #%d: ", i);
        if (possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}