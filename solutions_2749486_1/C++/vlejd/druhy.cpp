#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>

using namespace std;

#define For(Q,W) for(int Q=0;Q<W;Q++)
#define ForL(Q,W) for(long long Q=0;Q<W;Q++)
#define LLD long long
#define mkp make_pair
#define pf printf
#define sf scanf

//#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif

void solve(int kolko){
     int x,y;
     cin>>x>>y;
     int xx=x;
     int yy=y;
     
     int vzdial=(int) abs(x)+abs(y);
     double zlom=(-1+sqrt((double) 1+8*vzdial))/2;
     int tahov=(int)ceil(zlom);
     
     vector<char> tah;
     For(i,tahov){
                   int kolko= tahov-i;
                   if(abs(x)>abs(y)){
                                     if(x<0){
                                             tah.push_back('W');   
                                             x+=kolko;     
                                     }
                                     else {tah.push_back('E');
                                          x-=kolko;
                                          }      
                                     
                   }
                   else{
                      if(y<0){
                                             tah.push_back('S');   
                                             y+=kolko;     
                                     }
                                     else {tah.push_back('N');
                                          y-=kolko;
                                          }        
                   }
                   
                                 
     }
    db(x);
    db(y);
    dbn();
    
    while(x!=0 || y!=0){
            x=xx;
            y=yy;
            tahov++;
            tah.resize(0);
            For(i,tahov){
                   int kolko= tahov-i;
                   if(abs(x)>abs(y)){
                                     if(x<0){
                                             tah.push_back('W');   
                                             x+=kolko;     
                                     }
                                     else {tah.push_back('E');
                                          x-=kolko;
                                          }      
                                     
                   }
                   else{
                      if(y<0){
                                             tah.push_back('S');   
                                             y+=kolko;     
                                     }
                                     else {tah.push_back('N');
                                          y-=kolko;
                                          }        
                   }
                   
                                 
     }
            
            
    }
    
    db(x);
    db(y);
    dbn();
    if(x!=0||y!=0){
                   cout<<"panic";
                                  
    }
    cout<<"Case #"<<kolko<<": ";
     
     For(i,tah.size()) cout<<tah[tah.size()-1-i];
     cout<<endl;
}

int T;

int main(){
    cin>>T;
    For(t,T){
         solve(t+1);    
    }
    return 0;   
}
