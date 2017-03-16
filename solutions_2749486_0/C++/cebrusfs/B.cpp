#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for(int Ti=1; Ti<=T; Ti++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        string ans;
        string op;
        if(x < 0)
            op = "EW";
        else 
            op = "WE";

        x = abs(x);
        for(int i=0; i<x; i++)
            ans += op;

        if(y < 0)
            op = "NS";
        else 
            op = "SN";

        y = abs(y);
        for(int i=0; i<y; i++)
            ans += op;

        printf("Case #%d: %s\n", Ti, ans.c_str());
    }
}
