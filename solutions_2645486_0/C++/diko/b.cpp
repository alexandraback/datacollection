#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
int e,r,n;
int vl[1027];
int ret;
int st[13][7];

int main(){
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);

    int gt,run;
    cin>>gt;
    //long long ret;
    for(int run=1;run<=gt;run++){
        cin>>e>>r>>n;
        for(int i=0;i<n;i++) cin>>vl[i];
        ret=0;

        memset(st,-1,sizeof(st));

        st[0][e]=0;


        for(int i=1;i<=n;i++){
            for(int j=0;j<=e;j++){
                if(st[i-1][j]==-1) continue;

                for(int x=j;x>=0;x--){
                    int y= j-x+r;
                    if(y>e) y=e;
                    //if(y<0) y=0;
                    int curmx= x*vl[i-1];
                    st[i][y]= max(st[i][y],curmx+st[i-1][j]);
                }
            }
        }

        for(int j=0;j<=e;j++) ret= max(ret, st[n][j]);


        cout<<"Case #"<<run<<": "<<ret<<endl;

    }
    return 0;
}




