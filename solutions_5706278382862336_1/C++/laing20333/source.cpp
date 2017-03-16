#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
#include <stack>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <queue>
using namespace std;

typedef long long int ll;

int main (int argc, char * const argv[]){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("A-large.in", "r", stdin);
        freopen("A-large.out", "w", stdout);
    #endif // LOCAL


    int ntest;
    while(cin>>ntest){
        string tmp;
        for(int tt=0; tt<ntest; tt++){
            cin >> tmp;
            ll pp, qq;
            sscanf(tmp.c_str(), "%I64d/%I64d", &pp, &qq);

            ll f = __gcd(pp, qq);
            pp =pp / f; qq = qq/ f;
            double p = (double)(pp+1e-7);
            double q = (double)(qq+1e-7);
            double number = p/q;

            // check qq
            bool isok = false;
            ll t = 1;
            while(t < qq){
                t *= 2;
                if(t == qq) {
                    isok = true;
                    break;
                }
            }
            if(isok){
                int ans =0 ;
                while( (number + 1e-7 )< 1){
                    number *=2 ;
                    ans++;
                }
                printf("Case #%d: %d\n", tt+1, ans);
            }else {
                printf("Case #%d: impossible\n", tt+1);
            }
        }




    }





    return 0;
}
