#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
//    freopen("A-small-attempt0.in","r",stdin);
//    freopen("A-small-attempt0.out","w",stdout);
    int map[30];
    map[0] = 24;    map[1] = 7;    map[2] = 4;
    map[3] = 18;    map[4] = 14;    map[5] = 2;
    map[6] = 21;    map[7] = 23;    map[8] = 3;
    map[9] = 20;    map[10] = 8;    map[11] = 6;
    map[12] = 11;    map[13] = 1;    map[14] = 10;
    map[15] = 17;    map[16] = 25;    map[17] = 19;
    map[18] = 13;    map[19] = 22;    map[20] = 9;
    map[21] = 15;    map[22] = 5;    map[23] = 12;
    map[24] = 0;    map[25] = 16;
    int t;
    char str[105];
    scanf("%d",&t);getchar();
    for(int cases = 1;cases <= t;cases++)
    {
        gets(str);
        for(int i=0;str[i];++i)
        {
            if(str[i]!=' ')
                str[i] = map[str[i]-'a']+'a';
        }
        printf("Case #%d: %s\n",cases,str);
    }
    return 0;
}
