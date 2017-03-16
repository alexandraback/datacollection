#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <typeinfo>
#include <set>
#include <cctype>
#include <locale>
#include <utility>
#include <map>
#include <iterator>
#include <valarray>
#include <complex>
#include <sstream>
#include <bitset>
#include <ctime>
#include <list>
#include <numeric>

//#include <unordered_map>
//#include <unordered_set>
//#include <regex>

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define ifo(n,v) for(int i=v;i<n;++i)

using namespace std;

int in() {
    int a;
    scanf("%d", &a);
    return a;
}

double din() {
    double a;
    scanf("%lf", &a);
    return a;
}

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

const double eps = 1e-8;
const double pi = 3.14159265358979323;
const int INF = 999999999;

int qq(int a,int b){
    int c=a+b;
    int res=0;
    while(c%10==0){
        ++res;
        c/=10;
    }
    return res;
}
bool isa(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
    else return false;
}
bool isprime(int a){
    for(int i=2;i*i<=a;++i){
        if(a%i==0) return false;
    }
    return true;
}


int main() {
    freopen("input.txt", "r", stdin);
    //freopen("input.txt","w",stdout);

    return 0;
}
