#include <cstdio>
using namespace std;

// -------------------------------
// -------- DEBUG include --------
#include <cassert>
#include <cstring> // strcmp
bool DEBUG = false;
// -------------------------------
// -------------------------------
long long gcd(long long a, long long b){
    if(DEBUG) {printf("GCD for: (%I64d,%I64d) is --> ",a,b);}
    while(b>0){
        long long c = a%b;
        a = b;
        b = c;
    }
    if(DEBUG) {printf("%I64d!\n",a);}
    return a;
}

void lower_form(long long &p, long long &q){ // p < q
    long long gcd_pq = gcd(q,p);
    p /= gcd_pq ;
    q /= gcd_pq ;
}

int highest_bit(long long val){
    int i = 0;
    long long pow = 1;
    while(pow <= val){
        pow <<= 1;
        ++i;
    }
    return i-1;
}

void test_case(){
    long long p, q;
    scanf("%I64d/%I64d", &p,&q);
    if(DEBUG) {printf("\nSCANNED: %I64d / %I64d\n", p,q);}
    lower_form(p,q);
    if(DEBUG) {printf("changed to ---> %I64d / %I64d\n", p,q);}
    // find what power of two is q
    int log_q = highest_bit(q);
    if(DEBUG) {printf("log_q = %d\n", log_q);}
    if(q != (1LL<<log_q)){
        printf("impossible\n");
        return;
    }
    int log_p = highest_bit(p);
    if(DEBUG) {printf("log_p = %d\n", log_p);}
    int res = log_q - log_p;  //40 - ((40-log_q) + log_p);
    printf("%d\n",res);
    if(DEBUG) {printf("\n---\n");}
}

// ----------------------------------------
// -------------- MAIN DRAFT --------------
// ----------------------------------------

const bool LINE_AFTER_CASE = false;
int main(int argc, char *argv[]) {
    // recognise running mode
    if(argc >= 2 && !strcmp(argv[1],"DEBUG")){
        printf("switch DEBUG ON!\n");
        DEBUG = true;
    }
    // -------------------
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d:%s", t, LINE_AFTER_CASE ? "\n" : " ");
        test_case();
    }
    return 0;
}
