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
string a[20],b[20];

int main(){

    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i];
            
        int dev=0;
        for(int mask=0;mask<(1<<n);mask++){
            vector<pair<string,string> >nuevo;
            vector<pair<string,string> >esta;

            set<string>S;
            for(int i=0;i<n;i++){
                if( (mask&(1<<i))!=0 ){
                    esta.push_back(make_pair(a[i],b[i]));
                }
                else nuevo.push_back(make_pair(a[i],b[i]));
            }
            
            bool ok=1;
            for(int i=0;i<nuevo.size();i++){
                bool p1=0;bool p2=0;
                for(int j=0;j<esta.size();j++){
                    if(nuevo[i].first==esta[j].first)p1=1;
                    if(nuevo[i].second==esta[j].second)p2=1;
                }
                
                if( !(p1==1 && p2==1) )ok=0;
            }
            
            if(ok)dev=max(dev,n-__builtin_popcount(mask));
        }
        
        cout<<dev<<endl;
    }


    return 0;
}





