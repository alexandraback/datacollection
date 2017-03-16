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
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&a);
    for (int i=1;i<=a;i++){
        LL x=0;
        scanf("%s %d",t,&c);
        b=strlen(t);
        int left=-1;
        memset(memo,0,sizeof(memo));
        for (int j=0;j<b;j++){
            if (!vowel(t[j])){
                if (j)memo[j]=memo[j-1]+1;
                else memo[j]=1;
            }
        }
        for (int j=0;j<b;j++){
            if (memo[j]>=c){
                x+=((LL)(j-c-left+1)*(LL)(b-j));
                left=j-c+1;
            }
        }
                    
                
        printf("Case #%d: ",i);
        cout << x << endl;
    }
    return 0;
}
