#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long int gcd (long long int a, long long int b)
{
  long long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

bool examQ(long long int in){
    long long int tmp = in;
    while( !(tmp % 2) )
        tmp /= 2;
    if( tmp == 1 )  return true;
    else            return false;
}

int main(void){
    
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, cc=0, ans;
    long long P, Q, common;
    
    cin >> cas;
    while( cas-- ){
        
        scanf("%I64d/%I64d", &P, &Q);
        common = gcd(P, Q);
        P /= common;
        Q /= common;
        ans = 0;
        
        if( examQ(Q) ){
            while( P<Q ){
                ++ans;
                Q /= 2;
            }
            printf("Case #%d: %d\n", ++cc, ans);
        }
        else{
            printf("Case #%d: impossible\n", ++cc);
        }
    }
    
    return 0;
}
