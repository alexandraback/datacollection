#include <cstdio>
#include <string>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
char s[1000];
string a1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string a2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string a3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
string b1 = "our language is impossible to understand";
string b2 = "there are twenty six factorial possibilities";
string b3 = "so it is okay if you want to just give up";
map<char,char> m;
int main(void)
{
    //FILE *f1 = fopen("input.txt","r");
   // FILE *f2 = fopen("FACEBOOK_COOL","w");
    //freopen("input.txt","r",stdin);
   // freopen("OSTAPFACEBOOK","w",stdout);
   // int n;
    int n;
    //scanf("%d",&n);
    //printf("%d\n",n);
    for (int i = 0; i < a1.length(); i++)
        m[a1[i]] = b1[i];
    for (int i = 0; i < a2.length(); i++)
        m[a2[i]] = b2[i];
    for (int i = 0; i < a3.length(); i++)
        m[a3[i]] = b3[i];
    m['q'] = 'z';
    m['z'] = 'q';
    /*int ans = 0;
    for (char i = 'a'; i <= 'z'; i++)
        if (m.count(i))
        {
            printf("%c\n",i);
            ans++;
        }
    printf("%d\n",ans);*/
    //close("output.txt");
    scanf("%d\n",&n);
    for (int q = 1; q <= n; q++)
    {
        
        gets(s);
        printf("Case #%d: ", q);
        string a = (string) s;
        for (int i = 0 ; i < a.length(); i++)
            if (m.count(a[i]))
                printf("%c",m[a[i]]); else {
                    printf("?");
                }
        printf("\n");
    }
    return 0;
}