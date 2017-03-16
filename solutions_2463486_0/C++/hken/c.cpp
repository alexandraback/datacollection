#include <iostream>
#include <string>
#include <stdio.h>
#include <memory.h>

using namespace std;

int n;
string a[10000], b[10000];
int res[10000];

void input() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
}

void output() {
    for (int i=0; i<n; i++) printf("Case #%d: %d\n", (i+1), res[i]);
}

bool inbetween(const string& a, const string& b, int p2[], int k2)  {
    // if a<=p2
    if (a.length() > k2) return false;
    if (a.length() == k2) {
        for (int i=0; i<k2; i++) {
            if (a[i]-'0' > p2[i]) return false;
            if (a[i]-'0' < p2[i]) break;
        }
    }

    // if p2<=b
    if (b.length() < k2) return false;
    if (b.length() == k2) {
        for (int i=0; i<k2; i++) {
            if (b[i]-'0' > p2[i]) break;
            if (b[i]-'0' < p2[i]) return false;
        }
    }

    //
    return true;
}


void check_sqr(int p[], int k) {
    int p2[120], tmp[120]; 
    int k2 = k+k-1, t;
    
    //cerr << "p  = "; for (int i=0; i<k; i++) cerr << p[i]; cerr << endl;

    // sum of digits <= 9  (if there is a 2, this will always be valid)
    int sd = 0;
    for (int i=0; i<k; i++) sd += p[i];
    if (sd>9) return;

    // calculate p2 = p*p
    memset(p2, 0, sizeof(p2)); t = k2-1;
    for (int i=k-1; i>=0; i--) {
        if (p[i]>0) {
           for (int j=0; j<k; j++) p2[t-j] += p[k-j-1]*p[i];
        }
        t--; 
    }
    //cerr << "p2 = "; for (int i=0; i<k2; i++) cerr << p2[i]; cerr << endl;
    
    
    // TODO: need to check if p2 is a palindrome?

    // a <= p2 <= b?
    for (int i=0; i<n; i++) if (inbetween(a[i],b[i],p2,k2)) { 
        res[i]++;
    }
}


void process_even(int k) {
    int hk, d, p[60];

    //
    hk = k/2;

    // 200...002
    memset(p, 0, sizeof(p)); p[0] = p[k-1] = 2;
    check_sqr(p, k);

    // only 0 and 1
    p[0] = p[k-1] = 1;
    for (int mask=0; mask< ( 1<<(hk-1) ); mask++) {
        for (int i=0; i<(hk-1); i++) {
            d = (mask>>i) & 1;    
            p[hk-i-1] = p[hk+i] = d;
        }
        check_sqr(p, k);
    }
}

void process_odd(int k) {
    int hk, d, p[60];

    //
    hk = k/2;


    // 200..002
    memset(p, 0, sizeof(p)); p[0] = p[k-1] = 2;
    check_sqr(p, k);
    
    // 200..010..002
    p[hk] = 1;
    check_sqr(p, k);
    
    // 100..020..001 and may have two more 1s
    p[0] = p[k-1] = 1; p[hk] = 2;
    check_sqr(p, k);
    for (int i=1; i<hk; i++) {
        p[hk-i] = p[hk+i] = 1;
        check_sqr(p, k);
        p[hk-i] = p[hk+i] = 0;
    }

    // only 0 and 1
    for (int mask=0; mask< ( 1<<hk ); mask++) {
        for (int i=0; i<hk; i++) {
            d = (mask>>i) & 1;
            p[hk-i] = p[hk+i] = d;
        }
        check_sqr(p, k);
    }
}

void process() {
    //
    memset(res, 0, sizeof(res));

    // single-digit p2 (also p)
    for (int i=0; i<n; i++) if (a[i].length() == 1) {
        res[i] = 1;                     // 9
        if (a[i][0] <= '1') res[i]++;   // 1
        if (a[i][0] <= '4') res[i]++;   // 4
    }
    for (int i=0; i<n; i++) if (b[i].length() == 1) {
        if (b[i][0] < '9') res[i]--;
        if (b[i][0] < '4') res[i]--;
    }
    //for (int i=0; i<n; i++) cerr << res[i] << endl;

    
    //for (int i=2; i<=50; i++) {  // number of digits of p
    for (int i=2; i<=50; i++) {  // number of digits of p
        cerr << "p num digit = " << i << endl;
        if (i%2 == 0) process_even(i); else process_odd(i);
        //for (int i=0; i<n; i++) cerr << res[i] << endl;
    }
}


int main() {
    input(); 
    process();
    output();
    return 0;
}
