#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
int T,x,y;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int ta=1;
    cin >> T;
    while(T--)
    {
        cin >> x >> y;
        printf("Case #%d: ",ta++);
        char ch1,ch2;
        if(x > 0)
        {
            ch1 = 'W';   ch2 = 'E';
        }
        if(x < 0)
        {
            ch1 = 'E';   ch2 = 'W';
        }
        if(x)
        {
            for(int i=1; i<=abs(x); i++)
               printf("%c%c",ch1,ch2);
        }
        if(y > 0)
        {
            ch1 = 'S';    ch2 = 'N';
        }
        else
        if(y < 0)
        {
            ch1 = 'N';    ch2 = 'S';
        }
        for(int i=1; i<=abs(y); i++)
            printf("%c%c",ch1,ch2);
        printf("\n");
    }
    return 0;
}
