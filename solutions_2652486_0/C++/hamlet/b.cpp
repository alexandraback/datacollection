#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
    
    
    
    int tc;
    cin>>tc;
       
    for(int caso=1;caso<=tc;caso++){
        
        cout<<"Case #"<<caso<<": "<<endl;   
        int R,N,M,K;
        cin>>R>>N>>M>>K;
        for(int testcases=0;testcases<R;testcases++){
            vector<int>v(K,0);
            for(int i=0;i<K;i++){
                cin>>v[i];
            }    
            
            bool ok=1;
            for(int i=2;i<=5 && ok;i++)
                for(int j=2;j<=5 && ok;j++)
                    for(int k=2;k<=5 && ok;k++){
                        set<int>S;
                        S.insert(1);
                        S.insert(i);
                        S.insert(j);
                        S.insert(k);
                        S.insert(i*j);
                        S.insert(i*k);
                        S.insert(j*k);
                        S.insert(i*j*k);
                        bool fin=1;
                        for(int m=0;m<K;m++){    
                            if(S.find(v[m])==S.end()){
                                fin=0;    
                            }
                        }
                        
                        if(fin){
                            cout<<i<<j<<k<<endl; 
                            ok=0;   
                            break;
                        }    
                    }
            
            if(ok)cout<<"111"<<endl;
        }
    }   
    
    return 0;
} 
