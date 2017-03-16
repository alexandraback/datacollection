/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long int LL;
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define R(i,n,k) for(int i=n;i>=k;i--)
#define CLR(s,v) memset(s,v,sizeof(s))

int b[2000011];

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<":\n";
        int n;
        cin>>n;
        vector<int> v(n);
        F(i,n) cin>>v[i];
        sort(v.begin(),v.end());
        bool done = false;
        
        CLR(b,0);
        FF(mask,1,(1<<n)) {
            int sum=0;
            F(j,n) {
                if(mask & (1<<j)) {
                    sum += v[j];
                }
            }
            if(b[sum]) {
                done = true;
                int mask2 = b[sum];
                vector<int> st1,st2;
                F(i,n) {
                    int k1=0,k2=0;
                    if((1<<i) & mask) k1 = 1;
                    if((1<<i) & mask2) k2 = 1;
                    if(k1 && k2){
                    }
                    else if(k1){
                        st1.push_back(v[i]);
                    }
                    else if(k2){
                        st2.push_back(v[i]);
                    }
                }
                F(i,st1.size()){
                    cout<<st1[i]<<" ";
                }
                cout<<endl;
                
                F(i,st2.size()){
                    cout<<st2[i]<<" ";
                }
                cout<<endl;
                break;
            }
            b[sum] = mask;
        }
        
        
        
        if(!done) {
            cout<<"Impossible\n";
            continue;
        }
    }
    return 0;
}
