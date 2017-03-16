#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define _for(i,x,n) for(int i=x;i<n;i++)
#define _ifor(i,x,n) for(int i=(n);i>=x;i++)
#define _forv(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)

#define _dv(var) cout<<"L"<<__LINE__<<": "<<#var<<": "<<var<<endl;
#define _dav(v) cout<<"L"<<__LINE__<<": "<<#v<<": "; dav((v).begin(),(v).end());
template<typename it> void dav(it i,it f)
	{ cout<<"[ "; while(i!=f) cout<<*(i++)	<<" "; cout<<"]"<<endl; }
#define _ln cout<<"_ln: "<<__LINE__<<endl;

int N;
bool arcs[1000][1000];
int memo[1000][1000];

int paths(int a, int b){
    //_dv(a)_dv(b)
    if(a==b) return 1;
    if(memo[a][b]!=-1){
        //_dv(memo[a][b]);
        return memo[a][b];
    }

    int r=0;
    _for(i,0,N)
        if(arcs[a][i]){
            r+=paths(i,b);
            if(r>1) break;
        }
    memo[a][b]=r;
    //_dv(r)
    return r;
}

int main(){
    int T;
    cin>>T;
    _for(tt,1,T+1){
        int x,y;
        cin>>N;
        _for(i,0,N)
            _for(j,0,N)
                memo[i][j]=-1,arcs[i][j]=false;
        _for(i,0,N){
            cin>>x;
            _for(j,0,x){
                cin>>y;
                arcs[i][y-1]=true;
            }
        }


        bool res=false;
        for(int i=0;i<N && !res;i++)
            _for(j,0,N)
                if(i!=j && paths(i,j)>1){
                    res=true;
                    break;
                }

        if(res)
            printf("Case #%d: Yes\n",tt);
        else
            printf("Case #%d: No\n",tt);
        //cout<<"Case #"<<tt<<": "<<res<<endl;
    }
    return 0;
}
