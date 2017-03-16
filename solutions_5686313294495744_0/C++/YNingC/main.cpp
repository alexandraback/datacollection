//
//  main.cpp
//  GCJR1B316
//
//  Created by Ningchen Ying on 1/5/2016.
//  Copyright © 2016 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

string X[100][2];

int search(int h,vector<int> re){
    int cot= 0;
    for(int i=0;i<re.size();i++){
        int k = re[i];
        if((X[k][0] == X[h][0] && X[k][1]==X[h][1])||(X[k][1] == X[h][0] && X[k][0]==X[h][1])) cot++;
        if(cot>=2) break;
    }
    if(cot==1) return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //cout<<(1<<2)<<endl;
    
    
    int T;
    //cin>>T;
    freopen("/Users/yningc/Documents/code/GCJR1B316/GCJR1B316/C-small-attempt3.in","r",stdin);
    freopen("/Users/yningc/Documents/code/GCJR1B316/GCJR1B316/C-small-attempt3.out","w",stdout);
    cin>>T;
    for(int icase = 1;icase<=T;icase++){
        int N;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>X[i][0]>>X[i][1];
        }
        int mx = 1<<N;
        int tot = 0;
        for(int i=0;i<mx;i++){
            map<string,int> ync;
            ync.clear();
            int h = i;
            int fake = 0;
            vector<int> fk,re;
            fk.clear();
            re.clear();
            for(int j=0;j<N;j++){
                int yn = h%2;
                if(yn==1){
                    ync[X[j][0]] = ync[X[j][0]]+1;
                    ync[X[j][1]] = ync[X[j][1]]+1;
                    if(ync[X[j][0]]>=2 && ync[X[j][1]]>=2   && search(j,re)==0){
                        fake = 0;
                        break;
                    }
                    re.push_back(j);
                }else{
                    fake++;
                    fk.push_back(j);
                }
                h/=2;
            }
            for(int j=0;j<fk.size() && fake!=0;j++){
                int h = fk[j];
                int as = search(h,re);
                if(as==1 && ync[X[h][0]]==1 && ync[X[h][1]]==1){
                    fake = 0;
                    break;
                }
                if(ync[X[h][0]]==0 || ync[X[h][1]]==0){
                    fake = 0;
                    break;
                }
            }
            tot = max(tot,fake);
        }
        printf("Case #%d: %d\n",icase,tot);
        
    }
    return 0;
}
