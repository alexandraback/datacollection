#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>

using namespace std;   

int d[10000000];



struct nodo{
    nodo(){}
    int a,b,c,d,e;
    nodo(int _a,int _b,int _c,int _d,int _e){
        a=_a;b=_b;c=_c;d=_d;e=_e;
    }    
};



bool operator <(nodo a,nodo b){
    if(a.c!=b.c)return a.c<b.c;
    if(a.e!=b.e)return a.e<b.e;
    
    if(a.a!=b.a)return a.a<b.a;
    if(a.b!=b.b)return a.b<b.b;
    return a.d<b.d;
}


int main(){      
    
    int tc;
    cin>>tc;
    
    for(int caso=1;caso<=tc;caso++){
        int N;
        cin>>N;
        vector<nodo>v;
        memset(d,0,sizeof(d));
        
        for(int i=0;i<N;i++){
            int di;
            int ni;
            cin>>di>>ni;
            
            int wi,ei,si,_di,_pi,_si;
            cin>>wi>>ei>>si>>_di>>_pi>>_si;
            ei*=2;
            wi*=2;
            _pi*=2;
            
            
            for(int j=0;j<ni;j++){
                
                v.push_back(nodo(wi,ei,di,si,i));
                
                di+=_di;
                si+=_si;
                ei+=_pi;
                wi+=_pi;
            }
                
        }
        
        
        sort(v.begin(),v.end());
        
        int dev=0;
        
        
        for(int i=0;i<v.size();i++){
            nodo x=v[i];
            int wi,ei,di,si,tribu;
            wi=x.a;
            ei=x.b;
            si=x.c;    
            
            wi+=1<<20;
            ei+=1<<20;
            
            bool ok=0;
            
            for(int j=wi;j<=ei;j++){
                if(d[j]<si)ok=1;
            }
            
            if(ok==1){
                dev++;
                for(int j=wi;j<=ei;j++){
                    d[j]=max(d[j],si);
                }
            
            }
            
        }
        
        cout<<"Case #"<<caso<<": "<<dev<<endl;    
    }
    
    
    return 0;
}
