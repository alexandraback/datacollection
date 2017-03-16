#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
ofstream bug;
const bool DEBUG = true; 
const int MAXN = 2000+1;
const char PROBLEM[] = {"as"}; 
char *PROB;

int tests, test; 
int i, j, k, r, x, y, m, n; 
int C, I; 
int P[MAXN]; 
int q[MAXN], g[MAXN];
char f[MAXN]; 
string s; 
string model = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string answer = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

template <class T> void debug(T t){ if (DEBUG) bug << "[" << t << "]"; }
template <class T> void debug(T t, T t2){ if (DEBUG) bug << "[" << t << "," << t2 << "]"; }
template <class T> void debug(T t, T t2, T t3){ if (DEBUG) bug << "[" << t << "," << t2 << "," << t3 << "]"; }


int main(){
if (DEBUG) {
    PROB = new char[10];
    strcpy(PROB, PROBLEM); freopen(strcat(PROB, ".in"), "r", stdin); 
    strcpy(PROB, PROBLEM); freopen(strcat(PROB, ".out"), "w", stdout);
    strcpy(PROB, PROBLEM); bug.open(strcat(PROB, ".txt")); 
}
    
    scanf("%d", &tests);
    
    m = model.length(); 
    debug(m, (int)answer.length()); 
    
    for (int i = 0; i < m; ++i ){
        f[(int)model[i]] = answer[i]; 
    }
    
    f[int('z')] = 'q';
    f[int('q')] = 'z';
    //f[int('o')] = 'e';
    
    getline(cin, s); 
for (test = 1; test <= tests; ++test){
    int A, B; 
    if (DEBUG) bug << endl << "Case #" << test << ": " << endl; 
    scanf("%d%d", &A, &B); 
    double ans = B + 2; 
    double prob = 1; 
    double p; 
    for (int i = 0; i < A; ++i ){
        scanf("%lf", &p);
        prob *= p; 
        ans = min(ans, prob*(A-i + B-i-1) + (1-prob) * (A-i + B-i+B));
    }

	printf("Case #%d: %.6lf\n", test, ans);
}   
     
    return 0;  
}
