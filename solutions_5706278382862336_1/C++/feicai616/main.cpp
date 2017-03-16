#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

#define MOD 1000000007
#define mp make_pair
#define pb push_back
typedef long long LL;
char  s1[10000];
long long  a1,a2;
LL gcd(LL a,LL b){//gcd(a,b);
    if (b==0) return a;
    return gcd(b, a % b);
}
inline LL cal(LL x){        //取出X里2进制1的个数

     x=(x & 0x55555555) + ((x >>1 ) & 0x55555555);
     x=(x & 0x33333333) + ((x >>2 ) & 0x33333333);
     x=(x & 0x0F0F0F0F) + ((x >>4 ) & 0x0F0F0F0F);
     x=(x & 0x00FF00FF) + ((x >>8 ) & 0x00FF00FF);
     x=(x & 0x0000FFFF) + ((x >>16) & 0x0000FFFF);
     return x;
}

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int casen;scanf("%d",&casen);
    for(int casei=1;casei<=casen;casei++){
        scanf("%s",s1);
        bool tell=0;a1=0;a2=0;
        for (int i=0;i<strlen(s1);i++){
            if (!tell){
                if (s1[i]=='/'){tell=1;}else{
                    a1=a1*10+s1[i]-'0';
                }
            }else{
                a2=a2*10+s1[i]-'0';
            }
        }
        LL hh=gcd(a1,a2);
        a2=a2/hh;
        LL kk=a2;
        //int ans=0;
        while (a2%2==0) {a2=a2/2;}
        if (a2==1){
             a1=a1/hh;
             int ans=0;
             while (kk>a1) {kk=kk/2;ans++;}
             printf("Case #%d: %lld\n",casei,ans);
        }
        else
        printf("Case #%d: impossible\n",casei);

    }

}
