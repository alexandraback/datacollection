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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

typedef int ttyp;
#define fors(bg,en) for(int i=bg;i<en;i++)
#define forso(j,bg,en) for(int j=bg;j<en;j++)
#define forz(n) for(int i=0;i<n;i++)
#define forzo(j,n) for(int j=0;j<n;j++)
#define forsz(v) for(int i=0;i<v.size();i++)
#define forszo(j,v) for(int j=0;j<v.size();j++)
#define MP make_pair
#define sz(v) v.size()


void doit(){
    int n, m, k, tot, rock, ret;
    cin>>n>>m>>k;
    ret = k;
    forz(n-1)
    forzo(j,m-1){
        tot = (i*j);
        rock = 0;
        if(i) rock += j*2;
        else rock += j;
        if(j) rock += i*2;
        else rock += i;
        if(tot+rock>=k)
            ret = min (ret, rock);
        else{
            ret = min(ret,k-tot);
        }
    }
    cout<<ret<<endl;
    return;
}
int main(){
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
      cout<<"Case #"<<i<<": ";
      doit();
    }
    return 0;
}
