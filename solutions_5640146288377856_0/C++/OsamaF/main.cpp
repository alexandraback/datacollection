#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);


    int t;
    cin>>t;
    for(int f=1 ; f<=t ;f++){
        int r,c,w;
        cin>>r>>c>>w;
        int turns=c/w + w;
        if(c%w==0)turns --;

        /*
        int lo=0, hi=c;
        while(hi-lo<=w){
            turns++;
            lo+=w;
        }
        */
        cout<<"Case #"<<f<<": "<<turns*r<<endl;
    }
    return 0;
}
