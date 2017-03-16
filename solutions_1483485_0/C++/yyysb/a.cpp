#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
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
using namespace std;

//char a[30],b[30];
//char s1[1000],s2[1000];
//int main(){
//    for(int i=0;i<3;++i){
//        gets(s1);
//        gets(s2);
//
//        for(int j=0,l=strlen(s1);j<l;++j)
//            if(s1[j]!=' ') {
//                a[s1[j]-'a'] = s2[j];
//                b[s2[j]-'a'] = 1;
//            }
//    }
//    a[26]=0;
//    for(int i=0;i<26;++i)
//        printf("%c",i+'a');
//    puts("");
//    for(int i=0;i<26;++i)
//        printf("%c",a[i]!=0?a[i]:' ');
//    puts("");
//    for(int i=0;i<26;++i)
//        printf("%c",b[i]!=0?' ':i+'a');
//    return 0;
//}
char dict[30] = "yhesocvxduiglbkrztnwjpfmaq",s[200];
int T;
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    gets(s);
    for(int cs=1;cs<=T; ++cs){
        gets(s);
        printf("Case #%d: ",cs);
        for(int j=0,l=strlen(s);j<l;++j)
            printf("%c",s[j]!=' '?dict[s[j]-'a']:' ');
        puts("");
    }
}
