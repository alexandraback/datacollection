#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
int main()
{
    freopen("C:\\Users\\v-y\\Downloads\\B-small-attempt2.in","r",stdin);
    freopen("C:\\Users\\v-y\\Downloads\\B-small-attempt2.out","w",stdout);
    int t, cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        string s = "";
        for(int i = 0 ;i < abs(x) ; i ++)
        {
            if(x < 0)
            {
                s += "EW";
            }
            if(x > 0)
            {
                s += "WE";
            }
        }
        for(int i = 0 ;i < abs(y); i ++)
        {
            if(y < 0)
            {
                s += "NS";
            }
            if(y > 0)
            {
                s += "SN";
            }
        }
        printf("Case #%d: %s\n",cas ++,s.data());
    }
    return 0;
}
