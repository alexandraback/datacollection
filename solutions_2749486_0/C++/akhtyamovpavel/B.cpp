#include<cstdio>
#include<ctime>
#include<cmath>
#include<cctype>
#include<iomanip>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define FILEIN "B.in"
#define FILEOUT "B.txt"
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int t;
    cin>>t;
    for(int u=1;u<=t;++u){
        int x,y;
        cin>>x>>y;

        vector<char> res;


            for(int i=1;i<=abs(x);++i){
                if(x<0)
                {res.pb('E');
                res.pb('W');
                }
                else
                {res.pb('W');
                res.pb('E');
                }
            }
            for(int i=1;i<=abs(y);++i){
                if(y<0){
                    res.pb('N');
                    res.pb('S');
                }
                else{
                    res.pb('S');
                    res.pb('N');}
            }


        cout<<"Case #"<<u<<": ";
        for(int i=0;i<res.size();++i){
            cout<<res[i];
        }
        cout<<endl;

    }
    return 0;
}
