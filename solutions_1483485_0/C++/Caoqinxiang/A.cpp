#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

char a[1000] = "";

char x[1000] = "a zoo | our language is impossible to understand | there are twenty six factorial possibilities | so it is okay if you want to just give up";
char y[1000] = "y qee | ejp mysljylc kd kxveddknmc re jsicpdrysi | rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd | de kr kd eoya kw aej tysr re ujdr lkgc jv";

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    
    
    for (int i = 0; i < strlen(x); ++ i)
        a[y[i]] = x[i];
    int flag = 0;
    for (int i = 'a'; i <= 'z'; ++ i)
        flag += (a[i] == 0);
    if (flag == 1)
    {
        flag = 0;
        for (int i = 'a'; i <= 'z'; ++ i)
            flag = flag + i - a[i];
        for (int i = 'a'; i <= 'z'; ++ i)
            if (a[i] == 0)
                a[i] = flag;
    }
    
    int t;
    scanf("%d\n", & t);
    for (int i = 1; i <= t; ++ i)
    {
        char s[1000] = "";
        scanf("%[^\n]%*c", s);
        printf("Case #%d: ", i);
        for (int j = 0; j < strlen(s); ++ j) 
            if (s[j] <= 'z' && s[j] >= 'a')
                printf("%c", a[s[j]]);
            else
                printf("%c", s[j]);
        printf("\n");
    }
    
//    fclose(stdout);
}


