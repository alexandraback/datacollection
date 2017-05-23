#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool ispal(int num){
    int nnum=num;
    int n=0;
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
    vector <int> myvec;
    int maxVal=1000;
    for(int i=1;;++i){
        if(i*i>maxVal)
                break;
        if(ispal(i) && ispal(i*i)){
            myvec.push_back(i*i);
            //cout<<i*i<<endl;
        }
    }
    int t;
    scanf("%d", &t);
    for(int ii=1;ii<=t;++ii){
        int a,b;
        scanf("%d%d", &a, &b);
        int c=0;
        for(int i=0;i<myvec.size();++i){
            if(myvec[i]>=a && myvec[i]<=b)
                c++;
        }
        printf("Case #%d: %d\n", ii, c);
    }
}
