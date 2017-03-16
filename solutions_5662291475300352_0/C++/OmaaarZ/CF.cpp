#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define M_PI 3.14159265358979323846
using namespace std;
int d[2], h[2],m[2];
int main()
{
  freopen("C-small-1-attempt3.in","r",stdin);
   freopen("output.in","w",stdout);
    cin.sync_with_stdio(false);
    int t ;
    int tc=1;
    cin >> t;
    //memset(dp,-1,sizeof dp);
    while(t--)
    {
        int n;
        cin >>n;
        for(int i = 0 ; i <n;i++)
            cin >> d[i]>> h[i]>>m[i];
        int res=0;
        if(n==1)
        {
            res = 0;
        }
        else
        {
            if(m[0]== m[1])
            {
                res =0;
            }
            else
            {
                int x = min(m[0],m[1]);
                int y = max(m[0],m[1]);
                double z = y * 1.0/x;
                bool done = false ;
                int counter =0;
                for(int i =  x; i <= y && counter <=10000000 ;i+=0.5,counter++ )
                {
                    double temp1 = 1.0/m[0] *i * 360;
                    double temp2 =  1.0 /m[1]*i*360;
                    if(!(temp1 > 2*360-d[0])  && !(temp1 + d[0] <360) && !(temp2 > 2*360-d[1])  && !(temp2 + d[1] <360))
                    {
                        done =true;
                        break;
                    }
                }
                if(done)
                    res = 0;
                else
                    res =1;

            }
        }
        cout << "Case #" <<tc++ <<": "<<res <<endl;
    }
    return 0;
}


