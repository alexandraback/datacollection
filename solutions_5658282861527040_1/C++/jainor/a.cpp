#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string.h>
#include <stdio.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
int da[33],db[33],dc[33];
int tama,tamb,tamc;
long long memo[33][2][2][2];

long long dp(int pos,bool ma,bool mb,bool mc){
    if(pos==-1)return 1;
    if(memo[pos][ma][mb][mc]!=-1)return memo[pos][ma][mb][mc];
    
    long long dev=0;
    if(mc){
        // 0 0 - 0 1- 1 0 - 1 1
        if(ma && mb)dev+=4*dp(pos-1,ma,mb,mc);
        if(ma && !mb){
            if(db[pos]==1)dev+=2*dp(pos-1,ma,1,mc)+2*dp(pos-1,ma,mb,mc);    
            if(db[pos]==0)dev+=2*dp(pos-1,ma,mb,mc);
        }
        
        if(!ma && mb){
            if(da[pos]==1)dev+=2*dp(pos-1,1,mb,mc)+2*dp(pos-1,ma,mb,mc);    
            if(da[pos]==0)dev+=2*dp(pos-1,ma,mb,mc);    
        }
        
        if(!ma && !mb){
            if(da[pos]==0 && db[pos]==0)dev+=dp(pos-1,ma,mb,mc);
            if(da[pos]==0 && db[pos]==1)dev+=dp(pos-1,ma,1,mc)+dp(pos-1,ma,mb,mc);
            if(da[pos]==1 && db[pos]==0)dev+=dp(pos-1,1,mb,mc)+dp(pos-1,ma,mb,mc);
            if(da[pos]==1 && db[pos]==1)dev+=dp(pos-1,1,1,mc)+dp(pos-1,ma,1,mc)
                                                +dp(pos-1,1,mb,mc)+dp(pos-1,ma,mb,mc);
        }
        
    }else{
        if(ma && mb){
            if(dc[pos]==0)dev+=3*dp(pos-1,ma,mb,mc);
            if(dc[pos]==1)dev+=3*dp(pos-1,ma,mb,1)+dp(pos-1,ma,mb,mc);
        }
        
        if(ma && !mb){
            if(db[pos]==1){
                if(dc[pos]==0)
                    dev+=2*dp(pos-1,ma,1,mc)+dp(pos-1,ma,mb,mc);    
                else
                    dev+=2*dp(pos-1,ma,1,1)+dp(pos-1,ma,mb,1)+dp(pos-1,ma,mb,mc);
            }
            
            if(db[pos]==0){
                if(dc[pos]==0)
                    dev+=2*dp(pos-1,ma,mb,mc);
                else
                    dev+=2*dp(pos-1,ma,mb,1);
            }
        }
        
        if(!ma && mb){
            if(da[pos]==1){
                if(dc[pos]==0)
                    dev+=2*dp(pos-1,1,mb,mc)+dp(pos-1,ma,mb,mc);    
                else
                    dev+=2*dp(pos-1,1,mb,1)+dp(pos-1,ma,mb,1)+dp(pos-1,ma,mb,mc);
            }
            
            if(da[pos]==0){
                if(dc[pos]==0)
                    dev+=2*dp(pos-1,ma,mb,mc);
                else
                    dev+=2*dp(pos-1,ma,mb,1);
            } 
        }
        
        
        if(!ma && !mb){
            if(da[pos]==0 && db[pos]==0){
                if(dc[pos]==0)
                    dev+=dp(pos-1,ma,mb,mc);
                else
                    dev+=dp(pos-1,ma,mb,1);
            }
            
            if(da[pos]==0 && db[pos]==1){
                if(dc[pos]==0)
                    dev+=dp(pos-1,ma,1,mc)+dp(pos-1,ma,mb,mc);
                else
                    dev+=dp(pos-1,ma,1,1)+dp(pos-1,ma,mb,1);
            }
            
            if(da[pos]==1 && db[pos]==0){
                if(dc[pos]==0)
                    dev+=dp(pos-1,1,mb,mc)+dp(pos-1,ma,mb,mc);
                else
                    dev+=dp(pos-1,1,mb,1)+dp(pos-1,ma,mb,1);
            }
            
            if(da[pos]==1 && db[pos]==1){
                if(dc[pos]==0){
                    dev+=dp(pos-1,1,1,mc)+dp(pos-1,ma,1,mc)
                                                    +dp(pos-1,1,mb,mc);
                }else{
                    dev+=dp(pos-1,1,1,1)+dp(pos-1,ma,1,1)
                                                    +dp(pos-1,1,mb,1)+dp(pos-1,ma,mb,mc);
                }
            }
        }
        
        
    }
    
    memo[pos][ma][mb][mc]=dev;
    return dev;
}


void f(int a,int b,int c){
    tama=0,tamb=0,tamc=0;
    memset(da,0,sizeof(da));
    memset(db,0,sizeof(db));
    memset(dc,0,sizeof(dc));
    
    if(a>0)
    while(a!=0){
        da[tama++]=a%2;
        a/=2;
    }    
    
    if(b>0)
    while(b!=0){
        db[tamb++]=b%2;
        b/=2;
    }    
    if(c>0)
    while(c!=0){
        dc[tamc++]=c%2;
        c/=2;
    }    
    
    if(a==0)da[tama++]=0;
    if(b==0)db[tamb++]=0;
    if(c==0)dc[tamc++]=0;
        
}

int main(){
    
    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        int A,B,C;
        cin>>A>>B>>C;
        A--;
        B--;
        C--;
        f(A,B,C);
        
        memset(memo,-1,sizeof(memo));
        cout<<dp(30,0,0,0)<<endl;
    }
    
    return 0;
}
