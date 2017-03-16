#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  
struct swing{
	long long p,l;
    bool operator<(const swing ext) const{
    return (p<ext.p);
    }
};
int n,m;
    int ma[100][100];
bool checkx(int k,int a){
     int i;
     for (i=0; i<m; ++i){
         if (ma[k][i]>a)
            return false;
     }     
     return true;
}
bool checky(int k,int a){
     int i;
     for (i=0; i<n; ++i){
         if (ma[i][k]>a)
            return false;
     }     
     return true;
}

int main(){
    int i,j,k,t,z;
    cin>>t;
    for (z=1; z<=t; ++z){
        cin>>n>>m;
        for (i=0; i<n; ++i)
        for (j=0; j<m; ++j)
            cin>>ma[i][j];
        bool ok=true;
        for (i=0; i<n; ++i)
        for (j=0; j<m; ++j){
            ok=ok & (checkx(i,ma[i][j]) || checky(j,ma[i][j]));
            if (!ok)
               break;
        }
        cout<<"Case #"<<z<<": ";
        if (ok)
           cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
  
    }
    return 0;
}
