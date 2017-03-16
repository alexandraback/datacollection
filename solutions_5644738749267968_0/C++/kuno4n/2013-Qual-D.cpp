#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

int n;
double a[110], b[110];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    
}

void solve() {
    int ptr1 = 0;
    int ptr21 = 0;
    int ptr22 = n-1;
    int res1 = 0;
    for(; ptr1 < n;){
        if(a[ptr1] < b[ptr21]) ptr1++, ptr22--;
        else{
            res1++;
            ptr1++, ptr21++;
        }
    }
    
    ptr1 = 0;
    int ptr2 = 0;
    int res2;
    for(; ptr1< n; ptr1++, ptr2++){
        while(ptr2 < n && a[ptr1] > b[ptr2]) ptr2++;
        if(ptr2 == n) break;
    }
    res2 = n - ptr1;
    
    gout << res1 << " " << res2 << endl;
}

int main() {
	init();
	int number_of_test_cases;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases){
		input();
		solve();
	}
	return 0;
}
