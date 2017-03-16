#include <cstdio>
#include <cassert>

using namespace std;

struct num {
    char c;
    bool neg;
};

int pow;
int len;
num str[20000];

num multiply(num a, num b) {
    bool negate = false;
    num ans;
    if (a.neg || b.neg) {
        negate = !(a.neg && b.neg);
        a.neg = false;
        b.neg = false;
        ans = multiply(a, b);
        if (negate == true)
            ans.neg = !ans.neg;
        return ans;
    }
    if (a.c == '1')
        return b;
    if (b.c == '1')
        return a;
    if (a.c == b.c) {
        ans.c = '1';
        ans.neg = true;
        return ans;
    }
    if (a.c > b.c) {
        ans = multiply(b, a);
        ans.neg = !ans.neg;
        return ans;
    }
    if (a.c == 'i' && b.c == 'j') {
        ans.c = 'k';
        ans.neg = false;
        return ans;
    }
    if (a.c == 'i' && b.c == 'k') {
        ans.c = 'j';
        ans.neg = true;
        return ans;
    }
    if (a.c == 'j' && b.c == 'k') {
        ans.c = 'i';
        ans.neg = false;
        return ans;
    }
    fprintf(stderr, "%c %c\n", a.c, b.c);
    assert(false);
}
    
        

int main() {
	int T, TT;
    scanf("%d", &TT);
    for (T = 1; T <= TT; T++) {
        fprintf(stderr, "%d\n", T); 
        
        printf("Case #%d: ", T);
        
        scanf("%d %d", &len, &pow);
        char temp[20000];
        scanf("%s", temp);
        
        int i, j;
        for (i = 0; i < len; i++) {
            str[i].neg = false;
            str[i].c = temp[i];
        }
        
        if (len*pow < 3) {
            printf("NO\n");
            continue;
        }
        
        num line = str[0];
        for (i = 1; i < len; i++)
            line = multiply(line, str[i]);
        
        fprintf(stderr, "got line\n");
        
        if (line.c == '1' && line.neg == false) {
            printf("NO\n");
            continue;
        }
        
        if (line.c == '1' && pow % 2 != 1) {
            printf("NO\n");
            continue;
        }
        
        if (line.c != '1' && pow % 4 != 2) {
            printf("NO\n");
            continue;
        }
        
        bool made = false;
        int counti = 0;
        for (i = 0; i < 4 && !made; i++) {
            num curr;
            curr.c = '1';
            curr.neg = false;
            for (j = 0; j < i; j++)
                curr = multiply(curr, line);
            for (j = 0; j < len && !made; j++) {
                curr = multiply(curr, str[j]);
                if (curr.c == 'i' && curr.neg == false) {
                    made = true;
                    counti = i * len + j + 1;
                }
            }
        }
        if (!made) {
            printf("NO\n");
            continue;
        }
        
        made = false;
        int countk = 0;
        for (i = 0; i < 4 && !made; i++) {
            num curr;
            curr.c = '1';
            curr.neg = false;
            for (j = 0; j < i; j++)
                curr = multiply(curr, line);
            for (j = len - 1; j >= 0 && !made; j--) {
                curr = multiply(str[j], curr);
                if (curr.c == 'k' && curr.neg == false) {
                    made = true;
                    countk = i * len + len-j-1;
                }
            }
        }
        if (!made) {
            printf("NO\n");
            continue;
        }
        
        if (counti + countk < len*pow)
            printf("YES\n");
        else
            printf("NO\n");
        
    }
}