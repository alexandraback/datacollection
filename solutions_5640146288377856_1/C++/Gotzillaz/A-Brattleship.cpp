#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;

int main()
{
    int t, tt;
    cin >> tt; 
    t = 1;
    while(t<=tt)
    {
        int r,c,w;
        cin >> r >> c >> w;
        int count = c/w;
        int row = count;
        row *= r-1;
        if(c%w == 0)
            count--;
        /*
        int lf = 0;
        int rt = c+1;
        bool trg = true;
        while(rt-lf>=2*w)
        {
            if(trg) lf+=w;
            else rt-=w;
            trg = !trg;
            count++;
            cout << rt << " " << lf << endl;
        }
        */
        if(w != 1) 
            printf("Case #%d: %d\n",t,count+w+row);
        else
            printf("Case #%d: %d\n",t,c*r);
        t++;
    }
    return 0;
}
