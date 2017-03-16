#include <iostream>   
#include <vector>   
#include <algorithm>   
#include <queue>   
#include <string>  
//#include <boost/multiprecision/cpp_int.hpp>  
//using namespace boost;
//using namespace boost::multiprecision;
using namespace std;   
#define rep(x,n) for(x=0;x<n;x++)   

typedef vector<int> vi;   
typedef pair<int, int> pii;   
typedef long long ll;   
typedef unsigned long long ull;   

int main() {
    scanf("%*d");
    ull r, t;
    int i, j, k, pn = 1;
    
    while (2 == scanf("%llu%llu", &r, &t)) {
        //ull n = sqrt(t);
        //while (n * n + 2 * r * n > t) {
        //    n--;
        //}
        ull need = 2 * r + 1;
        ull n = 0;
        while ((need = 2 * r + 1) <= t)
        {
            t -= need;
            r += 2, n++;
        }
        printf("Case #%d: %llu\n", pn++, n);
    }
    
}