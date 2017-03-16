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

string c,s,cc,ss;

map<pair<string,string>,int> m;


bool fun(int i,string s){
    string ss=to_string(i);
    if(len(ss)>len(s))return 0;
    while(len(ss)<len(s))ss="0"+ss;
    bool flag=1;
    for(int i=0;i<len(s);i++){
        if(s[i]=='?')continue;
        if(s[i]!=ss[i])flag=0;
    }
    return flag;

}

string tos(int i){
    string ret=to_string(i);
    while(len(ret)<len(c))ret="0"+ret;
    return ret;
}



int main(){
    

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    
    int tst;
    cin>>tst;
    for(int test=1;test<=tst;test++){
        cin>>c>>s;

        int ret=inf;

        for(int i=0;i<=999;i++)for(int j=0;j<=999;j++){
            if(fun(i,c)&&fun(j,s)){
                if(abs(i-j)<ret){
                    ret=abs(i-j);
                    ss=tos(i);
                    cc=tos(j);
                }

            }
        }





        cout<<"Case #"<<test<<": "<<ss<<" "<<cc<<endl;
    } 

}


