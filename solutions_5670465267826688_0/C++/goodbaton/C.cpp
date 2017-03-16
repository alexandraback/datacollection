#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int sign(int x){
    if(x>0){
        return 1;
    }else if(x<0){
        return -1;
    }else{
        return 0;
    }
}

int cal[5][5] ={
    { 0,0,0,0,0 },
    { 0,1,2,3,4 },
    { 0,2,-1,4,-3},
    { 0,3,-4,-1,2},
    { 0,4,3,-2,-1},
};


int main(){
    int T,L,X,Snum[10000],num,Fir,Sec,Thi[10001];
    string S;
    bool ans;
    
    scanf("%d",&T);
    
    
    for(int i=1;i<=T;i++){
        
        ans=false;
        
        scanf("%d%d",&L,&X);
        
        cin >> S;
        
        for(int i=0;i<L;i++){
            
            switch (S[i]) {
                case 'i':
                    Snum[i]=2;
                    break;
                case 'j':
                    Snum[i]=3;
                    break;
                case 'k':
                    Snum[i]=4;
                    break;
            }
            
            for(int j=1;j<X;j++){
                Snum[i+j*L]=Snum[i];
            }
            
        }
        
        Thi[L*X]=1;
        
        for(int i=L*X-1;i>=0;i--){
            Thi[i]=cal[Snum[i]][abs(Thi[i+1])]*sign(Thi[i+1]);
            
            
        }
        
        Fir=1;
        
        for(int i=0;i<L*X-2;i++){
            
            Sec=1;
            
            Fir=cal[abs(Fir)][Snum[i]]*sign(Fir);
            
            if(Fir!=2) continue;
            
            for(int j=i+1;j<L*X-1;j++){
                
                Sec=cal[abs(Sec)][Snum[j]]*sign(Sec);
                
                if(Sec!=3) continue;
                
                if(Thi[j+1]==4){
                    ans=true;
                }
                
            }
        }
        
        
        printf("Case #%d: ",i);
        
        if(ans){
            puts("YES");
        }else{
            puts("NO");
        }
        
    }
    
    return 0;
}
