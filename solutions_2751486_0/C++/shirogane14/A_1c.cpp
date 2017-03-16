//Template of CyberKasumi (Jennifer Santoso a.k.a. Liang Qiuxia)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
using namespace std;

#define LL long long
#define inf 2123123123
#define MOD 1000000007


int a;
int b,c;
char t[1000002];
int memo[1000002];
bool vowel(char pp){
    if (pp=='a')return true;
    if (pp=='e')return true;
    if (pp=='i')return true;
    if (pp=='u')return true;
    if (pp=='o')return true;
    return false;
}
int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    scanf("%d",&a);
    for (int i=1;i<=a;i++){
        LL x=0;
        scanf("%s %d",t,&c);
        memset(memo,0,sizeof(memo));
        b=strlen(t);
        for (int j=0;j<b;j++){
            int cons=0;
            for (int k=j;k<b;k++){
                if (!vowel(t[k])){
                    cons++;
                    if (cons==c){
                        x+=(b-k);
                        break;
                    }
                }
                else{
                    cons=0;
                }
            }
        }
                
        printf("Case #%d: %lld\n",i,x);
    }
    return 0;
}
