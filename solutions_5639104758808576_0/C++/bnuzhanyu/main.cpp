#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;



void useFile(string fname)
{
    if(fname == "std") return;
    freopen((fname+".in").c_str(), "r", stdin);
    freopen((fname+".out").c_str(), "w", stdout);
}




int main()
{
    useFile("A");
    int T;
    int S;
    string shy;
    cin >> T;

    for(int ca=1; ca<=T; ca++)
    {
        cin >> S >> shy;
        int ans = 0;
        int curStand = 0;
        for(int i=0; i<shy.size(); i++)
        {
            int num = shy[i] - '0';
            if(curStand < i){
                ans += i - curStand;
                curStand = i;
            }
            curStand += num;
        }
        cout << "Case #" << ca << ": " << ans << endl;

    }

    return 0;
}
