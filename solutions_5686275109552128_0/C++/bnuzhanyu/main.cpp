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


const int MAXN = 1001;
int P[MAXN];

bool judge(int t, int n)
{
    for(int k = 0; k < t; k++ )
    {
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
            pq.push(P[i]);
        int eat_time = t - k;
        int move = 0;
        while(!pq.empty() && move <= k){
             int c = pq.top();
             if( c <= eat_time) return true;
             move++;
             pq.pop();
             pq.push(c - eat_time);
        }
    }
    return false;
}

int main()
{
    useFile("B");
    int T;
    int S;
    int D;

    cin >> T;
    for(int ca=1; ca<=T; ca++)
    {
        cin >> D ;

        int maxP = 0;
        for(int i=0; i<D; i++){
            cin >> P[i];
            maxP = max(maxP, P[i]);
        }
        int left = 1, right = maxP;
        while(left < right){
            int mid = (left+right)/2;
            if(judge(mid, D)) right = mid;
            else left = mid + 1;
        }
        cout << "Case #" << ca << ": " << left << endl;

    }

    return 0;
}
