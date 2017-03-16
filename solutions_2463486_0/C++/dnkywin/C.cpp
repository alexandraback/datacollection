#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

long long int pow[16];

bool ispal(long long int l){
    int size = 0; long long int tmp = l;
    while(tmp>0){
        size++;
        tmp/=10;
    }
    for (int i=0;i<size/2;i++){
        if ((l/pow[i])%10 != (l/pow[size-1-i])%10) return false;
    }
    return true;
}

int main(){
    vector<long long int> fsqnums;
    pow[0] = 1;
    for (int i=1;i<16;i++) pow[i] = pow[i-1]*10;
    for (long long int i=1;i<10000000;i++){
        if (ispal(i) && ispal(i*i)) fsqnums.push_back(i*i);
    }
    cout<<fsqnums.size()<<"\n";
    for (int i=0;i<fsqnums.size();i++) cout<<fsqnums[i]<<"\n";
    ifstream in("C.in"); ofstream out("C.out");
    int T;
    in>>T;
    int lo,hi;
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        long long int A,B;
        in>>A>>B;
        lo = 0;
        hi = fsqnums.size();
        while(lo<hi){
            int mid = (lo+hi)/2;
            if (fsqnums[mid]>=A) hi = mid;
            else lo = mid+1;
        }
        int start = lo;
        lo = 0;
        hi = fsqnums.size();
        while(lo<hi){
            int mid = (lo+hi)/2;
            if (fsqnums[mid]>B) hi = mid;
            else lo = mid+1;
        }
        int end = hi;
        //cout<<start<<" "<<end<<"\n";
        out<<(end-start)<<"\n";
    }

}
