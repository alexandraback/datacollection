#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cassert>
#include<queue>
using namespace std;


int main(){

    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        int n;
        cin>>n;

        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i]--;
        }

        vector<int>x;
        for(int i=0;i<n;i++)x.push_back(i);
        
        int dev=0;
        do{
            for(int i=2;i<=n;i++){
                bool ok=1;
                for(int j=0;j<i;j++){
                    if( v[x[j]] !=x[(j-1+i)%i] && v[x[j]] !=x[(j+1+i)%i]  ){
                        ok=0;
                    }
                }
                if(ok){
                    dev=max(dev,i);
                }
            }

        }while(next_permutation(x.begin(),x.end()));
        
        cout<<dev<<endl;
    }

    
    return 0;
}





