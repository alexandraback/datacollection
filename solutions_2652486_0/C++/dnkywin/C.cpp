#include<iostream>
#include<fstream>
#include<assert.h>
using namespace std;

int main(){
    ifstream in("C.in"); ofstream out("C.out");
    int T;
    in>>T;
    int R,N,M,K;
    in>>R>>N>>M>>K;
    cout<<R<<N<<M<<K;
    int prod[K];
    out<<"Case #1:\n";
    for (int r=0;r<R;r++){
        for (int j=0;j<K;j++) in>>prod[j];
        double maxp = -1.0;
        int p = -1;
        for (int i=0;i<64;i++){
            int x[3] = {i%4+2, (i/4)%4+2, (i/16)+2};
            double pp = 1.0;
            for (int u=0;u<K;u++){
                double works = 0.0;
                for (int n=0;n<8;n++){
                    int pro = 1;
                    for (int m=0;m<3;m++){
                        if (n&(1<<m)) pro*=x[m];
                    }
                    if (pro == prod[u]){
                        works+=0.125;
                    }
                }
                pp*=works;
            }
            if (pp>maxp){
                maxp = pp;
                p = i;
            }
        }
        assert(maxp!=0.0);
        out<<p%4+2<<(p/4)%4+2<<p/16+2;
        out<<"\n";
    }
}
