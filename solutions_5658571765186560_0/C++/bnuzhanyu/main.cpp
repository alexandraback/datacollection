#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
using namespace std;


void useFile(string fname)
{
    if(fname == "std") return;
    freopen((fname+".in").c_str(), "r", stdin);
    freopen((fname+".out").c_str(), "w", stdout);
}

bool judge(int x, int r, int c)
{
    if(r < c) swap(r, c);

    if(x > 6 || r*c % x != 0 || r < x) return false;
    if(c >= x) return true;

    int minC[7] = {0, 0, 0, 2, 3, 4, 4};
    return c >= minC[x];

}


int main()
{
    useFile("D");
    int T;
    cin >> T;
    int x, r, c;
    for(int ca=1; ca<=T; ca++)
    {

        cin >> x >> r >> c;


        cout << "Case #" << ca << ": " << (judge(x, r, c)?"GABRIEL":"RICHARD") << endl;

    }

    return 0;
}
