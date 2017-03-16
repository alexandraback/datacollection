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
long long toi(string s){
    long long dev=0;
    for(int i=0;i<s.size();i++)
        dev=dev*10+(s[i]-'0');
    return dev;
}
string a,b;
long long dif=1<<30;
string first="999999";string second="999999";

void dfs(int id){
    if(id==a.size()){
        long long p= abs(toi(a)-toi(b));
        if(p<dif){
            dif=p;
            first=a;
            second=b;
        }else{
            if(p==dif){
                if(a<first){
                    first=a;
                    second=b;
                }else{
                    if(a==first){
                        second=min(second,b);
                    }
                }
            }
        }
        return ;
    }

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            char aux1=a[id];
            char aux2=b[id];
            if(a[id]=='?')a[id]=('0'+i);
            if(b[id]=='?')b[id]=('0'+j);
            dfs(id+1);
            a[id]=aux1;
            b[id]=aux2;
        }
}

int main(){


 
    int tc;
    cin>>tc;
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        cin>>a>>b;
         dif=1<<30;
         first="999999"; second="999999";

        dfs(0);
        cout<<first<<" "<<second<<endl;
    }

    
    return 0;
}





