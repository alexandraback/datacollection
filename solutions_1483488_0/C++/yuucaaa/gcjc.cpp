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
bool isBetweenAB(int,int,int,int);
int queueToint(queue<int>);
int NumOfRecycledNum(int,int,int);
int solv(int);


int main(){
    
    int t;cin>>t;
    for (int i=0; i< t ; i++) {
        solv(i);
    }
    
    return 0;
}

int queueToint(queue<int> num){
    int digit=1,res=0;
    while (num.size()) {
        res+=digit*num.front();num.pop();
        digit*=10;
    }
    
    return res;
}
int NumOfRecycledNum(int i,int a,int b){
    queue<int> num;
    int res=0,digit=0,n=i;
    while (i>0) {
        num.push(i%10);
        i/=10;
        digit++;
    }
    for (int j=0; j<digit; j++) {
        num.push(num.front());num.pop();
        int m;
        m=queueToint(num);
        
        if (isBetweenAB(n,m,a,b)) {
            res++;
        }  
    }
    
    return res;
    
}
bool isBetweenAB(int n,int m,int a,int b){//a<=n<=b is guaranteed
    if (m >=a && m <=b && n<m) {
        //cout<<"("<<n<<","<<m<<")"<<endl;
        return true;
    }
    return false;
}
int solv(int j){
    ofstream ofs("ans.txt",ios::app|ios::ate);
    
    cout<<"Case #"<<j+1<<": ";
    ofs<<"Case #"<<j+1<<": ";
    
    int a,b,res=0;
    
    cin>>a>>b;
    for (int i=a; i<=b ; i++) {
        res+=NumOfRecycledNum(i,a,b);
    }
    
    cout<<res<<endl;
    ofs<<res<<endl;
    
    
    return 0;
}

