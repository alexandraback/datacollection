#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <functional>
#include <deque>
#include <algorithm> 

#define PI 6*asin( 0.5 )
typedef long long LL;

using namespace std;
int canThisOverP(int buf,int p){

    if (buf==0) {
        if (p>0) {
            return 0;
        }else return 2;
    }else if(buf==1){
        if (p>1) {
            return 0;
        }else return 2;
        
    }
    
    switch (buf%3) {
        case 0:
            if(buf/3>=p) return 2;
            else if(buf/3+1>=p) return 1;
            else return 0;
            break;
        case 1:
            if (buf/3+1>=p) return 2;
            else return 0;
            break;
        case 2:
            if(buf/3+1>=p) return 2;
            else if(buf/3+2>=p) return 1;
            else return 0;
            break;
        default:
            break;
    }
}
int solv(int j){
    ofstream ofs("ans.txt",ios::app|ios::ate);
    
    cout<<"Case #"<<j+1<<": ";
    ofs<<"Case #"<<j+1<<": ";
    
    int N,S,p,res=0,border=0;
    
    cin>>N>>S>>p;
    for (int i=0; i<N ; i++) {
        int buf;
        cin>>buf;
        if (canThisOverP(buf,p)==2) {
            res++;
        }else if(canThisOverP(buf,p)==1){
            border++;
        }
    }
    res+=min(S,border);

    cout<<res<<endl;
    ofs<<res<<endl;
    
    
    return 0;
}

int main(){
    
    int t;cin>>t;
    for (int i=0; i< t ; i++) {
        solv(i);
    }
        
    return 0;
}


