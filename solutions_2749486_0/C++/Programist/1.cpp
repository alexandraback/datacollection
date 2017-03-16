#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <time.h>
#include <iterator>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

string doIt(int a, int b)
{
    string r="";
    int c=1;
    if(a>0)
    {
        int p=0;
        int co=1;
        while(p!=a)
        {
            if(co%2==1)
            {
                r+="W";
                p-=co;
            }
            else
            {
                r+="E";
                p+=co;
            }
            ++co;
            ++c;
        }
    }
    else
    {
        int p=0;
        int co=1;
        while(p!=a)
        {
            if(co%2!=1)
            {
                r+="W";
                p-=co;
            }
            else
            {
                r+="E";
                p+=co;
            }
            ++co;
            ++c;
        }
    }
    if(b>0)
    {
        int p = 0;
        int co = 1;
        while(p != b)
        {
            if(co % 2 == 1)
            {
                r += "S";
                p -= co;
            }
            else
            {
                r += "N";
                p += co;
            }
            ++co;
            ++c;
        }
    }
    else
    {
        int p = 0;
        int co = 1;
        while(p != b)
        {
            if(co %2 != 1)
            {
                r += "S";
                p -= co;
            }
            else
            {
                r += "N";
                p += co;
            }
            ++co;
            ++c;
        }
    }
    return r;
}





int main()
{
    ifstream cin ("in.txt");
    ofstream cout ("out.txt");
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        int a,b;
        cin >> a >> b;
        string ans = doIt(a,b);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}