#include<iostream>
#include<algorithm>

using namespace std;

int findMax(const int e, const int r, const int n, const int v[], int curr, int curEn, int carryGain)
{

    curEn = curEn + r;

    if(curEn > e)
        curEn = e;

    if(curr == (n-1))
        return carryGain+(curEn*v[curr]);

    int gain = carryGain;
    int temp;
    int tempEn;

    for(int spend = 0; spend <= curEn; spend++)
    {
        gain = max(gain, findMax(e,r,n,v,(curr+1), curEn-spend, carryGain+spend*v[curr]));

    }

    return gain;
}

int main()
{
    int T;
    cin>>T;

    int e,r,n;
    int v[10];
    for(int cas=1; cas<=T; cas++)
    {
        cin>>e>>r>>n;

        for(int i=0;i<n;i++)
            cin>>v[i];

        cout<<"Case #"<<cas<<": "<<findMax(e,r,n,v,0,e,0)<<endl;
    }
    return 0;
}
