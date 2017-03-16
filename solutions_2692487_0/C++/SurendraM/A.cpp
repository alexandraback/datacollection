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

int ar[1000010];
int a,n;
map<int,int> mem[110];
int fn(int val, int pos, bool isRemoved) {
    if(pos>=n)  return 0;
//    if(mem[pos].find(val)!=mem[pos].end())
//        return mem[pos][val];
  //  int& ret = mem[pos][val];
    int ret = 10000;
    
        if(val <= ar[pos]) {
            if(isRemoved==0) {
                int k = val-1;
                if(k>0) {
                    ret = 1 + fn(val + k, pos, 0);
                }
            }
            ret = min(ret, 1 + fn(val, pos+1, true));
        } else {
            ret = fn(val+ar[pos], pos+1, isRemoved);
        }
    return ret;
                      
}

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        F(i,110)    mem[i].clear();
        cin>>a>>n;
        F(i,n)  cin>>ar[i];
        sort(ar,ar+n);
        cout<<fn(a, 0, 0)<<endl;   
    }
    return 0;
}
