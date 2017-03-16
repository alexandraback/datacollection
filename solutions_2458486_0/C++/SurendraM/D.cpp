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
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)
#define CLR(s,v) memset(s,v,sizeof(s))

int n,k;
int avail[201];
int keyType[201];
int keys[201][101];
int sz[201];
bool mem[(1<<20)+1];

int path[30];
bool fn(int mask, int pos) {
    if(pos==n) {
        return true;
    }
    if(mem[mask])   return false;
    mem[mask] = true;
    
    F(i,n) {
        if((mask & (1<<i))) continue;
        if(avail[keyType[i]]==0)    continue;
        avail[keyType[i]]--;
        F(j,sz[i])  avail[keys[i][j]]++;
        
        path[pos] = i+1;
        if(fn(mask|(1<<i), pos+1)) return true;
        avail[keyType[i]]++;
        F(j,sz[i])  avail[keys[i][j]]--;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        cin>>k>>n;
        CLR(avail,0);
        CLR(mem,0);
        int d;
        F(i,k) {
            cin>>d;
            avail[d]++;
        }
        F(i,n) {
            cin>>keyType[i];
            cin>>sz[i];
            F(j,sz[i])  cin>>keys[i][j];
        }
        
        if(fn(0,0)) {
            F(i,n)  cout<<path[i]<<" ";
            cout<<endl;
        } else {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
