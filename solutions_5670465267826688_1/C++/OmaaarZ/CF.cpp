#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define LL long long
using namespace std;


int main()
{
 freopen("C-large.in","r",stdin);freopen("output.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    int tc=1;
    while(t--)
    {
        long long x,l;
        cin >> l >> x;
        string s;
        cin >>s;
        cout << "Case #" <<tc++<<": " ;
        string t;
        bool done = false;
        int temp;
        for(int j = 0 ; j< min(x,10LL)&&!done;j++)
        {
        t+=s;
        int counter =0 ;
        int ac=1;
        for(int i = 0 ; i <t.size()&&!done;i++ )
        {
            if(t[i] == 'i')
            {
                if(ac == 1)
                    ac = 2;
                else if(ac == -1)
                    ac = -2;
                else if(ac == 2)
                    ac = -1;
                else if(ac == -2)
                    ac = 1;
                else if(ac == 3)
                    ac = -4;
                else if(ac == -3)
                    ac = 4;
                else if (ac ==4)
                    ac  = 3;
                else if(ac ==-4)
                    ac = -3;
            }
            else if(t[i]=='j')
            {
                if(ac == 1)
                    ac = 3;
                else if(ac == -1)
                    ac =-3;
                else if(ac == 3)
                    ac = -1;
                else if(ac == -3)
                    ac = 1;
                else if(ac == 2)
                    ac = 4;
                else if(ac == -2)
                    ac = -4;
                else if (ac ==-4)
                    ac  = 2;
                else if(ac ==4)
                    ac = -2;
            }
            else
            {
                if(ac == 1)
                    ac = 4;
                else if(ac == -1)
                    ac = -4;
                else if(ac == 4)
                    ac = -1;
                else if(ac == -4)
                    ac = 1;
                else if(ac == 2)
                    ac = -3;
                else if(ac == -2)
                    ac = 3;
                else if (ac ==3)
                    ac  = 2;
                else if(ac ==-3)
                    ac = -2;
            }
            if(ac == 2 && counter == 0)
                ac =1 , counter ++;
            else if(ac == 3 && counter ==1)
                ac = 1,counter ++;
            else if(ac == 4 && counter ==2)
                ac = 1,counter ++;
        }
        if(j==0)
        {
            if(ac == 2 && counter ==1)
                temp =-1;
            else if(ac == 3 && counter == 2)
                temp = -1;
            else if(counter == 0)
                temp =ac;
            else if(counter ==3 && ac ==1)
                temp = -1;
            else
                temp = 50;

        }
        if(counter ==3 && ac == 1 && ((((x)%(j+1)==0)&&((x-(j+1))/(j+1))%2 == 0)|| temp ==1 ||(x-(j+1))%4 == 0||(temp == -1 && (x-(j+1))%2 ==0)))
        {
            done = true;
            cout<<"YES"<<endl;
        }

    }
    if(!done)
        cout <<"NO"<<endl;

    }
    return 0;
}


