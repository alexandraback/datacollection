#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d ",&t);
    for(int tt=1;tt<=t;tt++)
    {
        vector<int> hx(4),ho(4),vx(4),vo(4),dx(4),od(4);
        char buf[5];
        bool empty = false;
        for(int i=0;i<4;i++)
        {
            gets(buf);
            for(int j=0;j<4;j++)
            {
                if(buf[j]=='X' || buf[j]=='T')
                {
                    hx[i]++;
                    vx[j]++;
                    if(i==j)
                        dx[0]++;
                    if(i+j==3)
                        dx[1]++;
                }
                if(buf[j]=='O' || buf[j]=='T')
                {
                    ho[i]++;
                    vo[j]++;
                    if(i==j)
                        od[0]++;
                    if(i+j==3)
                        od[1]++;
                }
                if(buf[j]=='.')
                    empty = true;
            }
        }
        scanf(" ");
        bool xwon = false;
        bool owon = false;
        for(int i=0;i<4;i++)
        {
            if(hx[i]==4 || vx[i]==4 || dx[i]==4)
                xwon = true;
            if(ho[i]==4 || vo[i]==4 || od[i]==4)
                owon = true;
        }
        printf("Case #%d: %s\n",tt,xwon?"X won":owon?"O won":empty?"Game has not completed":"Draw");
    }
}
