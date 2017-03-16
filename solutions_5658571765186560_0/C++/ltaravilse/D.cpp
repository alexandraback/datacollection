#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<sstream>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define all(v)v.begin(),v.end()

int main()
{
    freopen("D-small.in","r",stdin);
    freopen("D-small.out","w",stdout);
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++)
    {
        int x,r,c;
        cin >> x >> r >> c;
        string res = "GABRIEL";
        if(x>r || x>c)
            res = "RICHARD";
        else if((r*c)%x!=0)
            res = "RICHARD";
        else if((r*c)%4!=2 && x %2 == 0 && x > 2)
            res = "RICHARD";
        cout << "Case #"<<casito <<": "<< res << endl;
    }
}
