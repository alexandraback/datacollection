#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
map <char ,map<char ,int> > tran;
int x,l;
char ch[10100];
char toChar(int xx)
{
    char t;
    if (xx < 0) t = (-xx);
    else
        t = xx;
    return t;
}
void init()
{
    tran['1']['1'] = '1';
    tran['1']['i'] = 'i';
    tran['1']['j'] = 'j';
    tran['1']['k'] = 'k';

    tran['i']['1'] = 'i';
    tran['i']['i'] = -1*'1';
    tran['i']['j'] = 'k';
    tran['i']['k'] = -1*'j';

    tran['j']['1'] = 'j';
    tran['j']['i'] = -1*'k';
    tran['j']['j'] = -1*'1';
    tran['j']['k'] = 'i';

    tran['k']['1'] = 'k';
    tran['k']['i'] = 'j';
    tran['k']['j'] = -1*'i';
    tran['k']['k'] = -1*'1';
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    init();
    int _;scanf("%d",&_);
    for (int __ = 1;__ <= _;__++)
    {
        scanf("%d %d",&l,&x);
        scanf("%s",ch);
        char now = '1';
        int mi = 1;
        int i = 0;
        int j = 1;
        int del = 1;
        int flag = 1;
        while (1)
        {
            int tmp = tran[now][ch[i]];
            now = toChar(tmp);
            if (tmp < 0) mi ^= 1;
            i++;
            if (i == l)
            {
                i = 0;
                j++;del++;
            }
            if (mi == 1 && now == 'i')
                break;
            if (del == 5)
            {
                flag = 0;break;
            }
        }
        if (j > x) flag = 0;
        if (flag == 0)
        {
            printf("Case #%d: NO\n",__);
            continue;
        }
        flag = 1;
        del = 1;
        now = '1';
        mi = 1;
        while (1)
        {
            int tmp = tran[now][ch[i]];
            now = toChar(tmp);
            if (tmp < 0) mi ^= 1;
            i++;
            if (i == l)
            {
                i = 0;
                j++;del++;
            }
            if (mi == 1 && now == 'j')
                break;
            if (del == 5)
            {
                flag = 0;break;
            }
        }
        if (j > x) flag = 0;
        if (flag == 0)
        {
            printf("Case #%d: NO\n",__);
            continue;
        }
        x -= j;
        x %= 4;
        now = '1';
        mi = 1;
        while (1)
        {
            int tmp = tran[now][ch[i]];
            now = toChar(tmp);
            if (tmp < 0) mi ^= 1;
            i++;
            if (i == l)
            {
                i = 0;
                x--;
            }
            if (x == -1)
            {
                break;
            }
        }
        if (now != 'k' || mi != 1)
        {
            printf("Case #%d: NO\n",__);
            continue;
        }
        printf("Case #%d: YES\n",__);
    }
}
