#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<long long>fairs;
bool ispalin(long long x){
     string str;
     while (x>0){
           str+=(x%10);
           x/=10;
     }
     int len=str.size();
     for (int i=0;i<len/2;++i){
         if (str[i]!=str[len-(i+1)]) return 0;
     }
     return 1;
}
long long getpalineven(int x){
     long long ret=(long long)x;
     int len=0;
     if (x>0) len=1;
     if (x>9) len=2;
     if (x>99) len=3;
     if (x>999) len=4;
     if (x>9999) len=5;
     if (x>99999) len=6;
     long long ctr=1;
     for (int i=0;i<len;++i) ctr*=10;
     ret*=ctr;
     ctr=0;
     while (x>0){
           ctr=(ctr*10)+(long long)(x%10);
           x/=10;
     }
     return ret+ctr;
}
long long getpalinodd(int x,int y){
     long long ret=(long long)x;
     int len=0;
     if (x>0) len=1;
     if (x>9) len=2;
     if (x>99) len=3;
     if (x>999) len=4;
     if (x>9999) len=5;
     if (x>99999) len=6;
     long long ctr=1;
     for (int i=0;i<len;++i) ctr*=10;
     ret=(ret*10)+(long long)y;
     ret*=ctr;
     
     ctr=0;
     while (x>0){
           ctr=(ctr*10)+(long long)(x%10);
           x/=10;
     }
     return ret+ctr;
}
int main(){
    long long ctr,tmp;
    for (int i=0;i<3200;++i){
        
        ctr=getpalineven(i);
        tmp=ctr*ctr;
        if (ispalin(tmp)) fairs.push_back(tmp);
        
        for (int j=0;j<10;++j){
            ctr=getpalinodd(i,j);
            tmp=ctr*ctr;
            if (ispalin(tmp)) fairs.push_back(tmp);
        }
    }
    sort(fairs.begin(),fairs.end());
    /*
    for (int i=0;i<fairs.size();++i){
        cout << fairs[i] << endl;
    }
    */
    int ntest;
    long long a,b;
    vector<long long>::iterator ia,ib;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        scanf("%I64d %I64d",&a,&b);
        ia=lower_bound(fairs.begin(),fairs.end(),a);
        ib=upper_bound(fairs.begin(),fairs.end(),b);
        printf("Case #%d: %d\n",test,ib-ia);
    }
    return 0;
}
