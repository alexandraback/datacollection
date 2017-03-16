//
//  main.cpp
//  GCJR1B216
//
//  Created by Ningchen Ying on 1/5/2016.
//  Copyright © 2016 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ync1,ync2;

void dfs(string s,int tp,int ans,int d){
    
    //cout<<ans<<" ?"<<endl;
    if(d>=s.length()){
        //cout<<ans<<endl;
        if(tp==1){
            ync1.push_back(ans);
        }else{
            ync2.push_back(ans);
        }
        return;
    }
    if(s[d]=='?'){
        for(int i=0;i<=9;i++){
            dfs(s,tp,ans*10+i,d+1);
        }
    }else{
        dfs(s,tp,ans*10+s[d]-'0',d+1);
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("/Users/yningc/Documents/code/GCJR1B216/GCJR1B216/B-small-attempt0.in","r",stdin);
    freopen("/Users/yningc/Documents/code/GCJR1B216/GCJR1B216/B-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int icase = 1;icase<=T;icase++){
        string s1,s2;
        cin>>s1>>s2;
        
        ync1.clear();
        ync2.clear();
        dfs(s1,1,0,0);
        dfs(s2,2,0,0);
        int m = 1000;
        int sum = 100000;
        int f = 1000;
        int g = 0;
        //for(int i=0;i<ync1.size();i++) cout<<ync1[i]<<endl;
        //cout<<"======"<<endl;
        //for(int i=0;i<ync2.size();i++) cout<<ync2[i]<<endl;
        for(int i=0;i<ync1.size();i++){
            for(int j=0;j<ync2.size();j++){
                int vv =ync1[i]-ync2[j];
                //cout<<vv<<endl;
                if(abs(vv)<m){
                    m = abs(vv);
                    sum = ync1[i]+ync2[j];
                    f = ync2[j];
                    g = ync1[i];
                }else if(abs(vv)==m && sum>ync1[i]+ync2[j]){
                    sum = ync1[i]+ync2[j];
                    f = ync2[j];
                    g = ync1[i];
                }else if(abs(vv)==m && sum==ync1[i]+ync2[j] && f>ync2[j]){
                    f=ync2[j];
                    g = ync1[i];
                }
                //cout<<ync1[i]<<" "<<ync2[j]<<endl;
                //cout<<g<<" "<<f<<endl;
            }
            
        }
        string ans1,ans2;
        ans1="";
        ans2="";
        for(int i=0;i<s1.length();i++){
            string st = "";
            st += char(g%10+'0');
            ans1=st+ans1;
            g/=10;
        }
        for(int i=0;i<s2.length();i++){
            string st = "";
            st += char(f%10+'0');
            ans2=st+ans2;
            f/=10;
        }
        printf("Case #%d: ",icase);
        cout<<ans1<<" "<<ans2<<endl;
        
    }
    return 0;
}
