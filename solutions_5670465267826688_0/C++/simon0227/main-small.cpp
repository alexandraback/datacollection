#include <iostream>

using namespace std;

int trans(int res, char letter) {
    int sign = 1;
    if(res < 0) {
        sign = -1;
        res *= -1;
    }
    char tmp = res + 'a';
   // printf("%c\n", tmp);
    int ans = 0;
    if(tmp == letter) return -1 * sign;

    if(tmp == 'i' && letter == 'k') {
        ans = ('j' - 'a') * (-1);
//        printf("(i,k): %d\n", ans);
    }
    if(tmp == 'i' && letter == 'j') {
        ans = ('k' - 'a');
    }
    if(tmp == 'j' && letter == 'k') {
        ans = ('i' - 'a');
    }
    if(tmp == 'j' && letter == 'i') {
        ans = ('k' - 'a') * (-1);
    }
    if(tmp == 'k' && letter == 'i') {
        ans = ('j' - 'a');
    }
    if(tmp == 'k' && letter == 'j') {
        ans = ('i' - 'a') * (-1);
    }
    return ans * sign;
}

int divide(int res, char letter) {

    if(res == 1) {
        return 'a' - letter;
    }
    
    if(res == -1) {
        return letter - 'a';
    }

    int sign = 1;
    if(res < 0) {
        sign = -1;
        res *= -1;
    }
    char tmp = res + 'a';
    if(tmp == 'i' && letter == 'i') {
        return sign * 1;
    }
    if(tmp == 'i' && letter == 'j') {
        return sign * ('k' - 'a');
    }
    if(tmp == 'i' && letter == 'k') {
        return sign * ('a' - 'j');
    }
    if(tmp == 'j' && letter == 'i') {
        return sign * ('a' - 'k');
    }
    if(tmp == 'j' && letter == 'j') {
        return sign * 1;
    }
    if(tmp == 'j' && letter == 'k') {
        return sign * ('i' - 'a');
    }
    if(tmp == 'k' && letter == 'k') {
        return sign * 1;
    }
    if(tmp == 'k' && letter == 'i') {
        return sign * ('j' - 'a');
    }
    if(tmp == 'k' && letter == 'j') {
        return sign * ('a' - 'i');
    }
}

bool solve(int L, int X, char p[]) {
    int tail = L;
    for(int i = 1; i < X; i++) {
        for(int j = 0; j < L; j++) {
            p[tail] = p[j];
            tail++;
        }
    }
    p[tail] = '\0';
    //printf("%s\n", p);

    /*
     * 8,9,10,-1,1
     */
    int iIdx = 0, jIdx = 0;
    int kRes = 1, iRes = 1, jRes = 1;
    for(int i = 0; i < tail; i++) {
        if(kRes == 1) {
            kRes = p[i] - 'a';
        }
        else if(kRes == -1) {
            kRes = 'a' - p[i];
        }
        else {
            kRes = trans(kRes, p[i]);
        }
    }

   // printf("kRes = %d\n", kRes);

    for(int i = 0; i < tail; i++) {
        if(iRes == 1) iRes = p[i] - 'a';
        else if(iRes == -1) iRes = 'a' - p[i];
        else iRes = trans(iRes, p[i]);
        //update kRes;
        kRes = divide(kRes, p[i]);
 //       printf("i=%d: iRes= %d, kRes = %d\n",i, iRes, kRes);
        if(iRes == 8) {
            jRes = 1;
            int tmpKRes = kRes;
            for(int j = i + 1; j < tail; j++) {
                if(jRes == 1) jRes = p[j] - 'a';
                else if(jRes == -1) jRes = 'a' - p[j];
                else jRes = trans(jRes, p[j]);
                //updte tmpkRes;
                tmpKRes = divide(tmpKRes, p[j]);
//                printf("\tj=%d: jRes= %d, kRes = %d\n",j, jRes, tmpKRes);

                if(jRes == 9 && tmpKRes == 10) {
                    return true;
                }
            }
        }
    }
    return false;
}


int main() {
    freopen("C-small-attempt1.in", "r", stdin);
//    freopen("data.in", "r", stdin);
    int T;
    int X;
    int L;
    char p[10024];
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        scanf("%d %d", &L, &X);
        scanf("%s", p);
//        printf("%d %lld %s\n", L, X, p);
        bool res = solve(L,X,p);
        printf("Case #%d: %s\n", i, (res == true ? "YES" : "NO"));
    }
    return 0;
}
