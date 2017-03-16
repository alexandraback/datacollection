#include<iostream>
#include <cmath>
using namespace std;

int t, n;
int dm[100], sm[100], st, d, nn;

int main()
{
    cin >> t;
    for(int cc = 1 ; cc <= t ; cc ++)
    {
        int nnn = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)
        {
            cin >> d >> nn >> st;
            for(int j = 0 ; j < nn ; j ++)
            {
                dm[++ nnn] = d;
                sm[nnn] = st+j;
            }
        }
        if(sm[0] == sm[1])
            cout<<"Case #" << (cc) << ": " << (0) <<endl;
        else
        {
            if(sm[0] < sm[1])
            {
                swap(sm[0], sm[1]);
                swap(dm[0], dm[1]);
            }
            int dis1 = (dm[1] > dm[0] ? 360 : 0) + abs(dm[1]-dm[0]);
            int dis2 = 360 - dm[1];
            cout<<"Case #" << (cc) << ": " << /*(dis1/(sm[0]-sm[1]) < dis2/sm[1])*/ (dis1*(sm[1]) < dis2*(sm[0]-sm[1]) ? 0 : 1)<<endl;
        }
    }
}
