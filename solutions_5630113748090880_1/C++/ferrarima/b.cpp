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


int main()
{
    int TN;cin>>TN;
    for (int TI=1;TI<=TN;TI++){
        int n;cin>>n;
        int rdx;
        map<int,int> ct;
        for (int i=0;i<2*n-1;i++){
            for (int j=0;j<n;j++){
                cin>>rdx;
                ct[rdx]++;
            }
        }
        vector<int> ans;
        for (auto pr: ct){
            if (pr.second%2==1){
                ans.push_back(pr.first);
            }
        }//cerr<<ans.size()<<endl;
        assert(ans.size()==n);
        sort(ans.begin(), ans.end());
        cout<<"Case #"<<TI<<": ";
        for (int i=0;i<n-1;++i){
            cout<<ans[i]<<' ';
        }
        cout<<ans[n-1]<<endl;
    }
    return 0;
}
