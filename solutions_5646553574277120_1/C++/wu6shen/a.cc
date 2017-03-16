#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[1000];
int main()
{

    scanf("%s",str);
    int len = strlen(str);
    for (int i = 0 ; i < len ; i ++)
    {
        if (str[i]-'0' >= 5)
            str[i] = '9' - str[i] + '0';
    }
    //printf("%s\n",str);
    if (str[0] == '0') str[0] = '9';
    int st;
    for (int i = 0 ; i < len  ; i ++)
    {
        st = i;
        if (str[i] != '0')
            break;
    }

    for (int i = st ; i < len ; i ++)
        printf("%c",str[i]);
    printf("\n");

}
