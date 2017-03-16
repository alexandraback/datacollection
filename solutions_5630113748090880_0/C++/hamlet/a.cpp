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
        int n;
        cin>>n;
        map<int,int>m;
        for(int i=0;i<2*n-1;i++){
            int aux;
            for(int j=0;j<n;j++){
                cin>>aux;
                m[aux]++;
            }
        }

        vector<pair<int,int> >v(m.begin(),m.end());
        vector<int>dev;
        for(int i=0;i<v.size();i++)
            if(v[i].second%2==1){
                dev.push_back(v[i].first);
            }
        sort(dev.begin(),dev.end());
        cout<<"Case #"<<caso<<":";
        for(int i=0;i<dev.size();i++)
            cout<<" "<<dev[i];
            
        cout<<endl;
    }

    
    return 0;
}





