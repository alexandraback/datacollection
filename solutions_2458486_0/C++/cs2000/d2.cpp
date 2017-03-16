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
#include <queue>
using namespace std;  
struct swing{
	long long p,l;
    bool operator<(const swing ext) const{
    return (p<ext.p);
    }
};
    bool open[201];
    int seq[201],key[201],opc[201],nche[201],che[201][401],keynow[201];
    bool st[1048576];
    int last[1048576];
    int bin[21];
    queue<int> q;
bool canopen(int k){
     int a=opc[k];
     return key[a]>0;
}
int check(int k){
    int a=0;
    //cout<<"FAIL: ";

    for (int i=0; i<=k; ++i){
        //cout<<seq[i]<<" ";
        a+=bin[seq[i]];
    }
    //cout<<a<<endl;
    return a;
}
void setkey(int k){
     for (int i=0; i<=200; ++i)
        keynow[i]=key[i];
     for (int i=0; i<20; ++i){
         if ((k & bin[i])>0){
            keynow[opc[i]]--;
                     for (int j=0; j<nche[i]; ++j)
             keynow[che[i][j]]++;
         }

     }
}
int main(){
    int t,z,i,j,k,n,a;
    bin[0]=1;
    for (i=1; i<=20; ++i)
        bin[i]=bin[i-1]*2;
    //cout<< (10 & 4)<<endl;
    //cout<< (12 & 4)<<endl;
    cin>>t;
    for (z=1; z<=t; ++z){
        while (!q.empty())
              q.pop();
        memset(open,false,sizeof open);
        memset(seq,0,sizeof seq);
        memset(key,0,sizeof key);
        memset(opc,0,sizeof opc);
        memset(che,0,sizeof che);
        memset(st,false,sizeof st);
        cin>>k>>n;
        for (i=0; i<k; ++i){
            cin>>a;
            key[a]++;
        }
        for (i=0; i<n; ++i){
            cin>>opc[i];
            cin>>nche[i];
            for (j=0; j<nche[i]; ++j)
                cin>>che[i][j];
        }
        st[0]=true;
        last[0]=-1;
        q.push(0);
        while (!q.empty()){
            i=q.front();
            //cout<<i<<endl;
            q.pop();  
            if (st[i]){
               setkey(i);
               //cout<<"KEY: ";
               //for (k=1; k<=n; ++k)
               //cout<<keynow[k]<<" ";
               //cout<<endl;
               for (j=0; j<n; ++j){
                  // cout<<bin[j]<<" "<<(i & bin[j])<<" "<<opc[j]<<" "<<keynow[opc[j]]<<endl;
                   if (((i & bin[j])==0) && (keynow[opc[j]]>0)) {
                          //cout<<"OK: "<<j<<endl;
                      if (!st[i+bin[j]]){
                         st[i+bin[j]]=true;
                         last[i+bin[j]]=j;
                         q.push(i+bin[j]);
                      //cout<<j<<" "<<bin[j]<<endl;
                      }
                   }
               }
            }
        }
        if (st[bin[n]-1]){
           i=bin[n]-1;
           for (k=n-1; k>=0; --k){
               seq[k]=last[i];
               i=i-bin[last[i]];
           }
                 cout<<"Case #"<<z<<":";
                 for (j=0; j<n; ++j)
                     cout<<" "<<seq[j]+1;
                 cout<<endl;
        }
        else
          cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl; 
    }
    return 0;
}
