#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define len(x) ((int)(x.size()))
#define inf 1061109567



int main(){
    

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    
    int tst;
    cin>>tst;
    for(int test=1;test<=tst;test++){

        vector<string> v1,v2;
        int n;
        cin>>n;
        string s1,s2;
        for(int i=0;i<n;i++){
            cin>>s1>>s2;
            v1.push_back(s1);
            v2.push_back(s2);
        }

        int ans=0;

        for(int i=0;i<(1<<n);i++){
            map<string,int> m1,m2;
            map<string,int> sofar;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    m1[v1[j]]=1;
                    m2[v2[j]]=1;
                    sofar[v1[j]+" "+v2[j]]=1;
                }
            }

            int flag=1;
            int cnt=0;

            for(int j=0;j<n;j++){
                if((i&(1<<j))==0){
                    cnt++;
                    if(m2[v2[j]]&&m1[v1[j]]&&sofar[v1[j]+" "+v2[j]]==0){
                        sofar[v1[j]+" "+v2[j]]=1;
                        m1[v1[j]]=1;
                        m2[v2[j]]=1;
                    }
                    else{
                        flag=0;
                    }
                }
            }

            if(flag){
                ans=max(ans,cnt);
            }

        }




        cout<<"Case #"<<test<<": "<<ans<<endl;
    } 

}


