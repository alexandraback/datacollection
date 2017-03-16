#include <stdio.h>
#include <string.h>
#include <time.h>

#include <vector>
#include <queue>
#include <algorithm>

struct BigInt {
    int len;
    int dig[210];

    BigInt() {
        len = 1;
        memset(dig, 0, sizeof(dig));
    }
    BigInt(int x) {
        len = 1;
        memset(dig, 0, sizeof(dig));
        dig[0] = x;
    }

    BigInt& operator++() {
        dig[0] ++;
        for (int i=0; dig[i] >= 10; i++) {
            dig[i] -= 10;
            if (i < len-1) {
                dig[i+1] ++;
            } else {
                dig[i+1] = 1;
                len++;
            }
        }
        return *this;
    }

    BigInt operator*(const BigInt &b) const {
        BigInt ret;
        for (int i=0; i<len; i++) {
            for (int j=0; j<b.len; j++) {
                ret.dig[i+j] += dig[i] * b.dig[j];
                ret.dig[i+j+1] += ret.dig[i+j] / 10;
                ret.dig[i+j] %= 10;
            }
        }
        ret.len = len + b.len - 1;
        if (ret.dig[ret.len]) ret.len++;
        return ret;
    }

    bool operator<(const BigInt &b) const {
        if (len != b.len) return len < b.len;
        for (int i=len-1; i>=0; i--) {
            if (dig[i] != b.dig[i]) return dig[i] < b.dig[i];
        }
        return false;
    }

    bool operator<=(const BigInt &b) const {
        if (len != b.len) return len < b.len;
        for (int i=len-1; i>=0; i--) {
            if (dig[i] != b.dig[i]) return dig[i] < b.dig[i];
        }
        return true;
    }

    BigInt operator/(int b) const {
        BigInt ret;
        ret.len = len;
        int cur = 0;
        for (int i=len-1; i>=0; i--) {
            ret.dig[i] = (cur * 10 + dig[i]) / b;
            cur = (cur * 10 + dig[i]) % b;
        }
        while (ret.len>1 && !ret.dig[ret.len-1]) ret.len--;
        return ret;
    }

    BigInt reverse() const {
        BigInt ret;
        ret.len = len;
        for (int i=0; i<len; i++) ret.dig[len-1-i] = dig[i];
        return ret;
    }

    BigInt palindrome1() const {
        BigInt ret;
        ret.len = 2*len-1;
        for (int i=0; i<len; i++) ret.dig[i] = dig[i];
        for (int i=0; i<len; i++) ret.dig[ret.len-1-i] = dig[i];
        return ret;        
    }

    BigInt palindrome2() const {
        BigInt ret;
        ret.len = 2*len;
        for (int i=0; i<len; i++) ret.dig[i] = dig[i];
        for (int i=0; i<len; i++) ret.dig[ret.len-1-i] = dig[i];
        return ret;        
    }

    bool isPalindrome() const {
        for (int i=0; i<len/2; i++) {
            if (dig[i] != dig[len-1-i]) return false;
        }
        return true;        
    }

    BigInt last(int n) const {
        BigInt ret;
        ret.len = n;
        for (int i=0; i<n; i++) ret.dig[i] = dig[i];        
        return ret;
    }

    BigInt extend(int n) const {
        BigInt ret;
        ret.len = len+1;
        for (int i=0; i<len; i++) ret.dig[i] = dig[i];        
        ret.dig[len] = n;
        return ret;
    }

    static BigInt scan() {
        char inp[110];
        scanf("%s", inp);

        BigInt ret;
        ret.len = strlen(inp);

        for (int i=0; i<ret.len; i++) {
            ret.dig[ret.len-1-i] = inp[i] - '0';
        }
        return ret;
    }

    void print() const {
        for (int i=len-1; i>=0; i--) {
            printf("%d", dig[i]);
        }
        puts("");
    }
};

std::vector<BigInt> list;

void DFS(BigInt test) {
    //if (test.len < 10) test.print();
    if (test.len > 10) return;
    BigInt lower = test * test;
    BigInt rev = test.reverse();
    BigInt upperL = rev * rev; 
    ++rev;
    BigInt upperR = rev * rev;
    if (upperL.len == upperR.len) {
        BigInt cmp = lower.last(upperL.len).reverse();
        if (upperR <= cmp || cmp < upperL) return;
    } else {
        BigInt cmp1 = lower.last(upperL.len).reverse(),
               cmp2 = lower.last(upperR.len).reverse();
        if ((upperR <= cmp1 || cmp1 < upperL) && 
            (upperR <= cmp2 || cmp2 < upperL)) return;
    }
    for (int i=0; i<10; i++) {
        DFS(test.extend(i));
    }
    BigInt pal1 = test.palindrome1(), pal2 = test.palindrome2();
    BigInt val1 = pal1 * pal1, val2 = pal2 * pal2;
    if (val1.isPalindrome()) list.push_back(val1);
    if (val2.isPalindrome()) list.push_back(val2);
}

int bsearch (const std::vector<BigInt> &list, const BigInt &v) {
    int l=0, r=list.size(), m;
    while (l+1 < r) {
        m = (l+r-1)/2;
        if (list[m] < v) l = m+1;
        else r = m+1;
    }
    return l;
}
int main() {
    clock_t clk = clock();
    for (int i=1; i<10; i++) {
        DFS(BigInt(i));
    }
    //printf ("%d %f\n", list.size(), clock() - (float)clk/CLOCKS_PER_SEC);
    std::sort(list.begin(), list.end());
    int casN;
    scanf("%d", &casN);
    for (int i=0; i<casN; i++) {
        BigInt low = BigInt::scan(), high = BigInt::scan();
        ++high;
        printf("Case #%d: %d\n", i+1, 
                       bsearch(list, high) - bsearch(list, low));
    }
    return 0;
}
