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

int N,M;
vector< pair<long,int> > boxes,toys;

long solve(int b,int t,long cb,long ct){
    //_dv(b)_dv(t)
    if(b==boxes.size() || t==toys.size()){
        //_ln
        return 0;
    }
    long r=0;
    //_dv(boxes[b].second)_dv(toys[t].second)
    if(boxes[b].second==toys[t].second){
        r=min(cb,ct);
        //return r+solve(b+1,t+1);
        if(cb==ct){
            //_ln
            return r+solve(b+1,t+1,boxes[b+1].first,toys[t+1].first);
        }
        else if(cb>ct){
            //boxes[b]=make_pair(boxes[b].first-toys[t].first,boxes[b].second);
            //_ln
            return r+solve(b,t+1,cb-ct,toys[t+1].first);
        }
        else{
            //toys[t]=make_pair(toys[t].first-boxes[b].first,toys[t].second);
            //_ln
            return r+solve(b+1,t,boxes[b+1].first,ct-cb);
        }
    }
    else{
        //_ln
        r=max(solve(b+1,t,boxes[b+1].first,ct),solve(b,t+1,cb,toys[t+1].first));
    }
    return r;
}

int main(){
    int T;
    cin>>T;
    _for(tt,1,T+1){
        boxes.clear();
        toys.clear();
        cin>>N>>M;
        _for(i,0,N){
            long a,b;
            cin>>a>>b;
            boxes.push_back(make_pair(a,b));
        }
        _for(i,0,M){
            long a,b;
            cin>>a>>b;
            toys.push_back(make_pair(a,b));
        }
        cout<<"Case #"<<tt<<": "<<solve(0,0,boxes[0].first,toys[0].first)<<endl;
    }
    return 0;
}
