/*
 * =====================================================================================
 *
 *         Author:  KissBuaa.DS(AC)
 *        Company:  BUAA-ACMICPC-Group
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define LL long long
#define CLR(x) memset(x,0,sizeof(x))
#define typec double
#define sqr(x) ((x)*(x))
#define abs(x) ((x)<0?(-(x)):(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define PI acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define inf 100000000
//For C++
#include <cctype>
#include <ctime>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <cassert>
#include <complex>
using namespace std;
const double eps=1e-10;
int dblcmp(typec d) {
    if (fabs(d)<eps)
       return 0;
    return (d>0)?1:-1;
}
int T;
char str[5000]={"ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"};
char trs[5000]={"our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"};
int mp[27];
char s[5000];
int main(){
    //freopen("A-small-attempt2.in","r",stdin);
    //freopen("A.out","w",stdout);
    mp[25]='q'-'a';
    mp['q'-'a']='z'-'a';
    for (int i=0;i<strlen(str);++i)
        if (str[i]!=' ')
           mp[str[i]-'a']=trs[i]-'a';
    scanf("%d\n",&T);
    int icase=0;
    while (T--){
          gets(s);
          printf("Case #%d: ",++icase);
          for (int i=0;i<strlen(s);++i)
              if (s[i]<='z' && s[i]>='a') printf("%c",'a'+mp[s[i]-'a']);
              else printf("%c",s[i]);
          printf("\n");
    }
    //system("pause");
}
