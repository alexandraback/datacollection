#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
#define INF 1<<23

#define I1(a) scanf("%d",&a)
#define I2(a,b) scanf("%d %d",&a,&b)
#define I3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define rep(i,s,e) for(i=s;i<e;i++)
#define repr(i,s,e) for(i=s;i>e;i--)


#define in(a) freopen(a,"r",stdin)
#define out(a) freopen(a,"w",stdout)
#define ll long long
ll BigMod(ll B,ll P,ll M){  ll R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R%M;}
#define ull unsigned long long

int main()
{
    in("in.txt");
    out("out.txt");
    int T,caseno=1;
    cin>>T;
    while(T--){
        int R,C,W;
        cin>>R>>C>>W;
        cout<<"Case #"<<caseno++<<": ";
        if(W==1){
            cout<<R*C<<endl;
            continue;
        }
        if(W==C){
            if(R==1)
                cout<<C<<endl;
            else
                cout<<C+(R-1)<<endl;
            continue;
        }
        int colpoint=R*(C/W)+(W-1);
        if(C%W>0)colpoint++;
        cout<<colpoint<<endl;

    }
    return 0;
}













