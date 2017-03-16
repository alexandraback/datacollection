#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <map>
#include <functional>
#include <deque>
#include <algorithm> 

#define PI 6*asin( 0.5 )
typedef long long LL;

using namespace std;
bool isBetweenAB(LL,LL,LL,LL,vector<LL>);
LL queueToint(queue<int>);
int NumOfRecycledNum(LL,LL,LL);
int solv(int);


int main(){
    
    int t;cin>>t;
    for (int i=0; i< t ; i++) {
        solv(i);
    }
    
    return 0;
}

LL queueToint(queue<int> num){
    LL digit=1,res=0;
    while (num.size()) {
        res+=digit*num.front();num.pop();
        digit*=10;
    }
    
    return res;
}
int NumOfRecycledNum(LL i,LL a,LL b){
    queue<int> num;
    vector<LL> pairs;
    int digit=0,res=0;
    LL n=i;
    while (i>0) {
        num.push(i%10);
        i/=10;
        digit++;
    }
    for (int j=0; j<digit; j++) {
        num.push(num.front());num.pop();
        LL m=queueToint(num);
        
        if (isBetweenAB(n,m,a,b,pairs)) {
            res++;
            pairs.push_back(m);
        }  
    }
    
    return res;
    
}
bool isBetweenAB(LL n,LL m,LL a,LL b,vector<LL> pairs){//a<=n<=b is guaranteed
    if (m >=a && m <=b && n<m) {
        //cout<<"("<<n<<","<<m<<")"<<endl;
        for (int i=0; i<pairs.size(); i++) {
            if (pairs[i]==m) {
                return false;
            }
        }
        return true;
    }
    return false;
}
int solv(int j){
    ofstream ofs("ans.txt",ios::app|ios::ate);
    
    cout<<"Case #"<<j+1<<": ";
    ofs<<"Case #"<<j+1<<": ";
    
    LL a,b,res=0;
    
    cin>>a>>b;
    for (LL i=a; i<=b ; i++) {
        res+=NumOfRecycledNum(i,a,b);
    }
    
    cout<<res<<endl;
    ofs<<res<<endl;
    
    
    return 0;
}

