#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int wins(int N, int* nm, int* kn){
    //assume arrays are sorted;

    int lo = 0, hi=N;

    while(lo<hi){
        int mid = (lo+hi+1)/2;
        bool works = true;
        for(int i=0;i<mid;i++){
            if (kn[i] > nm[i+N-mid]){
                works = false;
                break;
            }
        }
        if (works) lo = mid;
        else hi = mid-1;
    }
    return lo;

}

int main(){
    ifstream in("D.in"); ofstream out("D.out");
    int T;
    in>>T;
    int nm[1000], kn[1000];
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        int N;
        in>>N;
        for (int i=0;i<N;i++){
            double c;
            in>>c;
            nm[i] = int(100000*c + 0.5);
        }
        for (int i=0;i<N;i++){
            double c;
            in>>c;
            kn[i] = int(100000*c + 0.5);
        }
        sort(nm,nm+N);
        sort(kn,kn+N);
        //for (int i=0;i<N;i++) cout<<nm[i]<<"\n";
        out<<wins(N,nm,kn)<<" "<<N-wins(N,kn,nm);
        out<<"\n";
    }

}
