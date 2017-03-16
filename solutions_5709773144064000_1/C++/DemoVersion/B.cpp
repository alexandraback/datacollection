#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
#define Author "DemoVersion"
int dx[]={0,0,-1,1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,1,-1,-1};
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
int main(){
        ios_base::sync_with_stdio(0);
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T,Z,mX,i;
    cin>>T;
    double C,F,X,bC,div,myMin;
    cout<<setprecision(10)<<fixed;
    for(Z=1;Z<=T;Z++){
        cin>>C>>F>>X;
        mX=int(X/C+1.0);
        bC=0.0;
        div=2.0;
        myMin=X/div;
        for(i=1;i<=mX;i++){
            bC+=C/div;
            div+=F;
            myMin=min(myMin,bC+X/div);
        }
        cout<<"Case #"<<Z<<": "<<myMin<<endl;
    }
    return 0;
}
