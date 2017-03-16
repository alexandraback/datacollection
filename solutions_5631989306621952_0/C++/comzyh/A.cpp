/*
* @Author: Comzyh
* @Date:   2016-04-16 08:57:57
* @Last Modified by:   Comzyh
* @Last Modified time: 2016-04-16 09:10:03
*/

#include <iostream>
#include <cstdio>
#include <list>
using namespace std;
int T;
char str[1009];
int main()
{
    scanf("%d", &T);
    for (int TT = 1; TT <= T; TT++)
    {
        scanf("%s", str);
        list<char> ans;
        ans.push_front(str[0]);
        for (int i = 1; str[i]; i++)
            if (str[i] >= ans.front())
                ans.push_front(str[i]);
            else
                ans.push_back(str[i]);
        printf("Case #%d: ", TT);
        for (auto it = ans.begin(); it != ans.end(); it ++)
            printf("%c", *it);
        printf("\n");
    }
    return 0;
}