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

const double eps = 1e-9;
double tot;
bool used[1000];
double val;

void fn(vector<double>& v, double& mx) {
    int n=v.size();
    double lft=0.0, rgt=100.0, md=100.0;
    int firstPos = 0;
    F(i,n) if(used[i]==0){ firstPos=i;break; }
    F(i,1000) {
        md = (lft + rgt) / 2;
        
        val = v[firstPos]+md;
        if(val < mx) {
            lft = md;
            continue;
        }
        
        tot = 0;
        F(j,n) {
            if(used[j]) continue;
            tot += (val - v[j]);
        }
        
        if(tot > 100) {
            rgt = md;
        }
        else
            lft = md;
    }
}

bool isEqual(double x, double y) {
    return (x+eps > y && y+eps > x);
}

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        int n;
        cin>>n;
        vector<double> v(n);
        F(i,n) cin>>v[i];
        double sum=0;
        F(i,n) sum += v[i];
        F(i,n) v[i]=v[i]/sum * 100;
        
        CLR(used,0);
        tot = 1000.;
        while(tot - eps > 100.) {
            double mx = 0;
            F(i,n){
                if(used[i]) continue;
                mx = max(mx,v[i]);
            }
            fn(v,mx);
            
            if(tot - eps > 100.0){
                F(i,n) {
                    if(used[i]) continue;
                    if(isEqual(val, v[i]))
                        used[i]=true;
                }
            }
        }
        
        double k = val;
        F(i,n) {
            v[i] = k-v[i];
            v[i] = max(v[i],0.0);
            printf("%.8lf ",v[i]);
        }
     //   cout<<tot<<endl;
        
//        int ct=0;
 //       F(i,n) if(used[i]==0) ct++;
   //     cout<<ct<<endl;
        
        puts("");
    }
    return 0;
}
