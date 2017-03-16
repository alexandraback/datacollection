#include <stdio.h>
#include <string.h>
#include <algorithm>
char s[20];
char t[20];
char mins[20];
char mint[20];
char tmpq[20];
char tmpd[20];
unsigned long long ms=1e18, mt=0, mdif=1e18;
int n;
void check() {
    static unsigned long long v1, v2, diff;
    sscanf(s, "%lld", &v1);
    sscanf(t, "%lld", &v2);
    //printf("%s %s\n", s, t);
    if(v1 < v2)
        diff = v2 - v1;
    else
        diff = v1 - v2;
    if(diff < mdif || diff == mdif && v1 < ms || diff == mdif && v1 == ms && v2 < mt) {
        mdif = diff;
        ms = v1;
        mt = v2;
    }        
}
void solve(int i) {
    if(s[i] == 0){
        check();
        return;
    }
    //fprintf(stderr, "%s %s", s, t);
    if(s[i] == '?' && t[i] == '?') {
        s[i] = '0';
        t[i] = '0';
        solve(i + 1);
        s[i] = '0';
        t[i] = '1';
        solve(i);
        s[i] = '1';
        t[i] = '0';
        solve(i);
        s[i] = '?';
        t[i] = '?';
        return;
    }
    
    if(s[i] != '?' && t[i] != '?' && t[i] == s[i]) {
        solve(i + 1);
        return;
    }
    char *q, *d;
    if(s[i] == '?' || s[i] != '?' && t[i] < s[i]) {
        q = s;
        d = t;
    } else {
        q = t;
        d = s;
    }
    int flag= q[i] == '?';
    if (d[i] != '9') {
        memcpy(tmpq, q, 20);
        memcpy(tmpd, d, 20);
        if(flag)
            q[i] = d[i] + 1;
        for(int j = i + 1; j < n; j++)
            if (q[j] == '?')
                q[j] = '0';
        for(int j = i + 1; j < n; j++)
            if (d[j] == '?')
                d[j] = '9';
        check();
        memcpy(q, tmpq, 20);
        memcpy(d, tmpd, 20);
    }
    if (d[i] != '0') {
        memcpy(tmpq, q, 20);
        memcpy(tmpd, d, 20);
        if(flag)
            q[i] = d[i] - 1;
        for(int j = i + 1; j < n; j++)
            if (q[j] == '?')
                q[j] = '9';
        for(int j = i + 1; j < n; j++)
            if (d[j] == '?')
                d[j] = '0';
        check();
        memcpy(q, tmpq, 20);
        memcpy(d, tmpd, 20);
    }
    if(flag) {
        q[i] = d[i];
        solve(i+1);
        q[i] = '?';
    }
}
int ch2(int v, char *s) {
    int j = n-1;
    while(j >= 0 && (v % 10 == s[j] -'0' ||  s[j] =='?'))
        v /= 10, j--;
    return !(v >0) && j==-1;
}
void solve2() {
    for(int v1 = 0; v1 < 1000; v1++) 
        for (int v2 = 0; v2 <1000; v2++) {
            if(!ch2(v1, s) || !ch2(v2, t))
                continue;
            int diff;
            if(v1 < v2)
                diff = v2 - v1;
            else
                diff = v1 - v2;
            if(diff < mdif || diff == mdif && v1 < ms || diff == mdif && v1 == ms && v2 < mt) {
                mdif = diff;
                ms = v1;
                mt = v2;
            }    
        }
    
}
int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        ms=1e18, mt=0, mdif=1e18;
        scanf("%s %s", s, t);
        printf("Case #%d: ", i);
        n = strlen(s);
        //solve2();
        solve(0);
        char buf[20];
        sprintf(buf, "c0%dlld", n);
        buf[0] = '%';
        printf(buf, ms);
        printf(" ");
        printf(buf, mt);
        printf("\n");
    }
    return 0;
}
    
