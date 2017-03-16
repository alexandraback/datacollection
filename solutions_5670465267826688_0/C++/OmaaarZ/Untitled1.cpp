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
  freopen("C-small-attempt2.in","r",stdin);
   freopen("out.in","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >>t;
    int tc=1;
    while(t--)
    {
        int x,l;
        cin >> l >> x;
        string s;
        cin >>s;
        int counter =0 ;
        int ac=1;
        string t;
        for(int i = 0 ; i <x;i++)
            t+=s;
        cout << "Case #" <<tc++<<": " ;
        for(int i = 0 ; i <l*x;i++ )
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


        if(counter ==3 && ac == 1)
            cout<<"YES"<<endl;
        else
        cout <<"NO"<<endl;

    }
    return 0;
}


