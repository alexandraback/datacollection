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


int main(){
    int T;
    cin>>T;
    _for(tt,1,T+1){
        int A,B,n;
        cin>>A>>B;
        double p[A];
        _for(i,0,A)
            cin>>p[i];

        n=ceil(((double)A)+2.0)/2.0 + 1;

        //hit enter first
        double res=B+2;
        //_dv(n)
        //_dv(res)
        _for(i,0,n){
            if(i>A) continue;
            //_dv(i)
            double sum=0.0;
            double tGood=2*i+B-A+1;
            double pGood=1.0;
            _for(j,0,A-i)
                pGood*=p[j];
            double tBad=tGood+B+1;
            double pBad=1.0-pGood;
            double aux=tGood*pGood+tBad*pBad;
            //_dv(tGood)_dv(tBad)
            //_dv(pGood)_dv(pBad)
            //_dv(aux)
            res = min(aux,res);
        }

        printf("Case #%d: %.6f\n",tt,res);
        //cout<<"Case #"<<tt<<": "<<res<<endl;
    }
    return 0;
}
