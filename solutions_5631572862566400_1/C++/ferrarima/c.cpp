// template.cpp : Defines the entry point for the console application.
//
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <list>
#include <tuple>
#include <ctime>
#include <cassert>
using namespace std;


//type shortcuts
typedef long long ll;
typedef vector<ll> VI;
typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;


//constants
const DOUBLE EPS=1e-9;
const DOUBLE PI = atan(1) * 4;
const ll M = 1000000007;


void calcdist(vector<int> &v2rt, vector<int> &v2r2, vector<int> &v2ds, vector<int> &a, int i){//cerr<<"rec"<<i<<endl;
    if (v2r2[i]>=-1) return;
    calcdist(v2rt, v2r2, v2ds ,a, a[i]);
    v2r2[i]=v2r2[a[i]];
    v2ds[i]=v2ds[a[i]]+1;
    v2rt[i]=v2rt[a[i]];
}
int solve(vector<int> &a){
    //findallr2
    //findallr3+
    //compute longest br for each r2
    //return max(max(r3), sum(brlen of r2))
    int n=a.size();
    int maxr3=0;
    int r2n=0;
    
    vector<int> v2r2(n,-2);//-2 unknown, -1 do not go to an r2, 0+ r2 index
    vector<int> v2rt(n,-2);//-2 unknown, -1 do not go to an r2, 0+ r2 index
    vector<int> v2ds(n,-2);
    
    vector<int> trip(n,-1);
    vector<int> arr(n,-1);
    int tm=0;
    int tripn=0;
    for (int i=0;i<n;++i){
        if (arr[i]>=0) continue;
        int j=i;
        while (true) {
            trip[j]=tripn;
            arr[j]=tm++;
            int nj=a[j];
            if (arr[nj]<0) {
                j=nj;
                continue;
            }
            if (trip[nj]==tripn){
                int rsize = tm-arr[nj];
                if (rsize==2) break;
                maxr3=max(maxr3,rsize);
                for (int k=0;k<rsize;++k){
                    v2r2[nj]=-1;
                    nj=a[nj];
                }
                break;
            }
            break;
        }
        ++tripn;
    }
    
    //for (int i=0;i<n;++i) cerr<<arr[i]<<' ';cerr<<endl;
    
    
    for (int i=0;i<n;++i){
        if (i<a[i] && a[a[i]]==i){
            v2r2[i]=v2r2[a[i]]=r2n;
            v2ds[i]=v2ds[a[i]]=0;
            v2rt[i]=i;
            v2rt[a[i]]=a[i];
            ++r2n;
        }
    }
    
    vector<int> v2arm(n);
    for (int i=0;i<n;++i){
        calcdist(v2rt, v2r2, v2ds, a,i);
        int rt=v2rt[i];
        if (rt<0) continue;
        v2arm[rt] = max(v2arm[rt], v2ds[i]);
    }
    
    
    
    
    
    vector<int> r2br(r2n);
    for (int i=0;i<n;++i){
        if (v2r2[i]>=0 && v2ds[i]==0) {
            int r2=v2r2[i];
            r2br[r2]+=1+v2arm[i];
        }
    }
    
    int sumr2=0;
    for (int i=0;i<r2n;++i){
        sumr2+=r2br[i];
    }
    return max(maxr3, sumr2);
}

int main()
{
    int TN;cin>>TN;
    for (int TI=1;TI<=TN;TI++){
        int n;cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;++i){
            cin>>a[i];
            --a[i];
        }
        int ans= solve(a);
        cout<<"Case #"<<TI<<": "<<ans<<endl;
    }
    return 0;
}
