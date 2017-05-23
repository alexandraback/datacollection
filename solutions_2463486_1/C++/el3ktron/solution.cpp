#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool ispal(long long int num){
    long long int nnum=num;
    long long int n=0;
    while(num>0){
        n=n*10+num%10;
        num/=10;
    }
    if(n==nnum)
        return true;
    else
        return false;
}

int main(){
    vector <long long int> myvec;
    long long int maxVal=100000000000000;
    for(long long int i=1;;++i){
        if(i*i>maxVal)
                break;
        if(ispal(i) && ispal(i*i)){
            myvec.push_back(i*i);
            //cout<<i*i<<endl;
        }
    }
    //cout<<myvec.size()<<endl;
    int t;
    scanf("%d", &t);
    for(int ii=1;ii<=t;++ii){
        long long int a,b;
        scanf("%lld%lld", &a, &b);
        long long int c=0;
        for(int i=0;i<myvec.size();++i){
            if(myvec[i]>=a && myvec[i]<=b)
                c++;
        }
        printf("Case #%d: %lld\n", ii, c);
    }
}
